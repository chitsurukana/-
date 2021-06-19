#include"Mine.h"

Mine::Mine()
{
    cells[11][11] = 0,
    open_x = 0;
    open_y = 0;
    over = 0;
}
Mine::Mine(int a,int b,int c,int d)
{
    cells[11][11] = a,
    open_x = b;
    open_y = c;
    over = d;
}
void Mine::assign_initial(int cells[][11]) { //�N��l����T��l�Ƭ�0 
    int i, j;

    for (i = 0; i < 11; i++)
    {
        for (j = 0; j < 11; j++)
        {
            cells[i][j] = 0;
        }
    }
}
void Mine::print_blanks() { //�L�X�C����l����l 
    int i, j;
    
    cout << "              �C�������G" << endl;
    cout << "---------------------------------------" << endl;
    cout << "�� �n�}�ҳ̥��W������п�J1 1" << endl;
    cout << "   ���U�@��h���䪺��+1(��J�G2 1)" << endl;
    cout << "   ���k�@��h�k�䪺��+1(��J�G1 2)" << endl;
    cout << "   ��l�H�������A�q1 1 ~ 9 9" << endl;
    cout << "   ��J�榡���G�Ʀr�Ů�Ʀr�A�p�G8 2" << endl << endl;
    cout << "�� �i�@����J�h��y�СA" << endl;
    cout << "   �y�ж��u�ݥH�D�Ʀr�Ÿ��j�}�N�i�H�F�I" << endl;
    cout << "   ���z�C���r�֡I:)" << endl;
    cout << "---------------------------------------" << endl << endl;
    
    cout << endl;
    cout << "    ";
    for (i = 1; i <= 9; i++)
    {
        cout << setw(2) << i;
    }
    cout << endl;
    for (i = 1; i <= 9; i++)
    {
        for (j = 0; j <= 9; j++) {
            if (j == 0)
                cout << setw(4) << i;
            else
                cout << "�f";
        }
        cout << endl;
    }
}
void Mine::open_cell(int* op_x, int* op_y) { //�ШϥΪ̿�J�n���}����m
    int x, y;
    cout << endl;
    cout << "��J�z�n�}�Ҫ��y�� >> ";
    cin >> *op_x >> *op_y;
}
void Mine::put_mine(int cells[][11], int op_x, int op_y) { //��m�a�p
    srand(time(NULL));          //  �üƺؤl 
    int  n = 0,
        rand_num,
        cell_x,
        cell_y;

    do {
        rand_num = rand() % 81;     // ( rand() % (�̤j��-�̤p��+1)) + �̤p��
        cell_x = (rand_num % 9) + 1;
        cell_y = ((rand_num - cell_x) / 9) + 1;
        if (cells[cell_x][cell_y] != -1 && !(cell_x == op_x && cell_y == op_y))
        {
            cells[cell_x][cell_y] = -1;
            n++;
        }
    } while (n < 10);
}
void Mine::calculate_num_of_cells(int cells[][11]) { //�p��D�a�p�Ϫ��񦳴X�u�a�p 
    int i, j, u, v;
    for (i = 1; i <= 9; i++)
        for (j = 1; j <= 9; j++)
            if (cells[i][j] == 0)
                for (u = i - 1; u <= i + 1; u++)
                    for (v = j - 1; v <= j + 1; v++)
                        if (cells[u][v] == -1)
                            cells[i][j]++;
}
void Mine::assign_inf_after_open(int cells[][11], int op_x, int op_y) { //���ܨϥΪ̥��}����m����T 
    if (cells[op_x][op_y] == -1)
        cells[op_x][op_y] = -2;
    if (cells[op_x][op_y] >= 0 && cells[op_x][op_y] <= 8)
        cells[op_x][op_y] += 10;
}
void Mine::open_surrounding(int cells[][11], int op_x, int op_y) { //���}���񪺰ϰ�]���l����L�a�p�ɡ^ 
    int i, j;
    for (i = op_x - 1; i <= op_x + 1; i++) {
        for (j = op_y - 1; j <= op_y + 1; j++) {
            if (cells[i][j] >= 0 && cells[i][j] <= 8 && i % 10 != 0 && j % 10 != 0) {
                cells[i][j] += 10;
                check_no_mine(cells, i, j);
            }
        }
    }
}
void Mine::check_no_mine(int cells[][11], int op_x, int op_y) { //�ˬd���񪺰ϰ즳�S���a�p
    if (cells[op_x][op_y] == 10)        //����S�a�p 
        open_surrounding(cells, op_x, op_y);
}
void Mine::print_condition_playing(int cells[][11]) { //�L�X�|�����������p
    int i, j;
    cout << "      ";
    for (i = 1; i <= 9; i++)
        cout << setw(2) << i;
    cout << endl;
    cout << "    �z�СССССССС� �{" << endl;
    for (i = 1; i <= 9; i++) {
        for (j = 0; j <= 9; j++) {
            if (j == 0)
                cout << setw(4) << i << "�U";
            else if (cells[i][j] < 10)
                cout << "�f";
            else if (cells[i][j] == 10)
                cout << " 0";
            else if (cells[i][j] > 10 && cells[i][j] <= 18)
                cout << setw(2) << cells[i][j] - 10;
            if (j == 9)
                cout << "�U" << i;
        }
        cout << endl;
    }
    cout << "    �|�СССССССС� �}" << endl;
    cout << "      ";
    for (i = 1; i <= 9; i++)
        cout << setw(2) << i;
    cout << endl;
}
void Mine::print_condition_over(int cells[][11], int over) { //�L�X�C�����������p(�C�Ӯ�l����T) 
    int i, j;
    cout << "  �z�СССССССС� �{" << endl;
    for (i = 1; i <= 9; i++) {
        for (j = 0; j <= 10; j++) {
            if (j == 0)
                cout << "  �U";
            else if (j == 10)
                cout << "�U";
            else if (cells[i][j] % 10 == 0)
                cout << "�D";
            else if (cells[i][j] == -1)
                cout << " *";
            else if (cells[i][j] == -2)
                cout << "��";
            else
                cout << setw(2) << cells[i][j] % 10;
        }
        cout << endl;
    }
    cout << "  �|�СССССССС� �}" << endl;
    if (over == 1)
        cout << "�z�㮥�ߧA���Ĺ�FOuO�I" << endl << endl;
    else
        cout << "�����z�F�K�K " << endl << endl;
    cout << "�Ʀr�N��P��K��a�p�`�ƶq" << endl;
    cout << "*�N��a�p" << endl;
    cout << "�D�N��P��S�a�p" << endl;
    cout << "��N���z�����a�p�C" << endl;
    cout << "�P�±z���������" << endl;
}
void Mine::print_cells(int cells[][11], int op_x, int op_y, int over) { //�L�X�ثe�����p
    system("cls");
    cout << endl;
    if (over == 0) {
        print_condition_playing(cells);
    }
    else
        print_condition_over(cells, over);
}
int  Mine::check_over(int cells[][11], int op_x, int op_y) { //�ˬd�C���O�_����(���Ĺ)
    //result == 0 ->�|�������Aresult == 1 ->Ĺ�Aresult == -1 ->��
    int i, j, result = 1;
    if (cells[op_x][op_y] == -2) {
        result = -1;
    }
    else {
        for (i = 1; i <= 9 && result == 1; i++)
            for (j = 1; j <= 9 && result == 1; j++)
                if ((cells[i][j] >= 0 && cells[i][j] <= 8))
                    result = 0;
    }
    return(result);
}