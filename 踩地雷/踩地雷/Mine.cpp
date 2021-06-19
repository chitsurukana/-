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
void Mine::assign_initial(int cells[][11]) { //將格子內資訊初始化為0 
    int i, j;

    for (i = 0; i < 11; i++)
    {
        for (j = 0; j < 11; j++)
        {
            cells[i][j] = 0;
        }
    }
}
void Mine::print_blanks() { //印出遊戲初始的格子 
    int i, j;
    
    cout << "              遊戲說明：" << endl;
    cout << "---------------------------------------" << endl;
    cout << "※ 要開啟最左上角那格請輸入1 1" << endl;
    cout << "   往下一格則左邊的值+1(輸入：2 1)" << endl;
    cout << "   往右一格則右邊的值+1(輸入：1 2)" << endl;
    cout << "   其餘以此類推，從1 1 ~ 9 9" << endl;
    cout << "   輸入格式為：數字空格數字，如：8 2" << endl << endl;
    cout << "※ 可一次輸入多格座標，" << endl;
    cout << "   座標間只需以非數字符號隔開就可以了！" << endl;
    cout << "   祝您遊戲愉快！:)" << endl;
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
                cout << "口";
        }
        cout << endl;
    }
}
void Mine::open_cell(int* op_x, int* op_y) { //請使用者輸入要打開的位置
    int x, y;
    cout << endl;
    cout << "輸入您要開啟的座標 >> ";
    cin >> *op_x >> *op_y;
}
void Mine::put_mine(int cells[][11], int op_x, int op_y) { //放置地雷
    srand(time(NULL));          //  亂數種子 
    int  n = 0,
        rand_num,
        cell_x,
        cell_y;

    do {
        rand_num = rand() % 81;     // ( rand() % (最大值-最小值+1)) + 最小值
        cell_x = (rand_num % 9) + 1;
        cell_y = ((rand_num - cell_x) / 9) + 1;
        if (cells[cell_x][cell_y] != -1 && !(cell_x == op_x && cell_y == op_y))
        {
            cells[cell_x][cell_y] = -1;
            n++;
        }
    } while (n < 10);
}
void Mine::calculate_num_of_cells(int cells[][11]) { //計算非地雷區附近有幾彈地雷 
    int i, j, u, v;
    for (i = 1; i <= 9; i++)
        for (j = 1; j <= 9; j++)
            if (cells[i][j] == 0)
                for (u = i - 1; u <= i + 1; u++)
                    for (v = j - 1; v <= j + 1; v++)
                        if (cells[u][v] == -1)
                            cells[i][j]++;
}
void Mine::assign_inf_after_open(int cells[][11], int op_x, int op_y) { //改變使用者打開的位置之資訊 
    if (cells[op_x][op_y] == -1)
        cells[op_x][op_y] = -2;
    if (cells[op_x][op_y] >= 0 && cells[op_x][op_y] <= 8)
        cells[op_x][op_y] += 10;
}
void Mine::open_surrounding(int cells[][11], int op_x, int op_y) { //打開附近的區域（當格子附近無地雷時） 
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
void Mine::check_no_mine(int cells[][11], int op_x, int op_y) { //檢查附近的區域有沒有地雷
    if (cells[op_x][op_y] == 10)        //附近沒地雷 
        open_surrounding(cells, op_x, op_y);
}
void Mine::print_condition_playing(int cells[][11]) { //印出尚未結束的狀況
    int i, j;
    cout << "      ";
    for (i = 1; i <= 9; i++)
        cout << setw(2) << i;
    cout << endl;
    cout << "    ┌－－－－－－－－－ ┐" << endl;
    for (i = 1; i <= 9; i++) {
        for (j = 0; j <= 9; j++) {
            if (j == 0)
                cout << setw(4) << i << "｜";
            else if (cells[i][j] < 10)
                cout << "口";
            else if (cells[i][j] == 10)
                cout << " 0";
            else if (cells[i][j] > 10 && cells[i][j] <= 18)
                cout << setw(2) << cells[i][j] - 10;
            if (j == 9)
                cout << "｜" << i;
        }
        cout << endl;
    }
    cout << "    └－－－－－－－－－ ┘" << endl;
    cout << "      ";
    for (i = 1; i <= 9; i++)
        cout << setw(2) << i;
    cout << endl;
}
void Mine::print_condition_over(int cells[][11], int over) { //印出遊戲結束的狀況(每個格子之資訊) 
    int i, j;
    cout << "  ┌－－－－－－－－－ ┐" << endl;
    for (i = 1; i <= 9; i++) {
        for (j = 0; j <= 10; j++) {
            if (j == 0)
                cout << "  ｜";
            else if (j == 10)
                cout << "｜";
            else if (cells[i][j] % 10 == 0)
                cout << "．";
            else if (cells[i][j] == -1)
                cout << " *";
            else if (cells[i][j] == -2)
                cout << "⊕";
            else
                cout << setw(2) << cells[i][j] % 10;
        }
        cout << endl;
    }
    cout << "  └－－－－－－－－－ ┘" << endl;
    if (over == 1)
        cout << "哇～恭喜你～～贏了OuO！" << endl << endl;
    else
        cout << "ˊˋ爆了…… " << endl << endl;
    cout << "數字代表周圍八格地雷總數量" << endl;
    cout << "*代表地雷" << endl;
    cout << "．代表周圍沒地雷" << endl;
    cout << "⊕代表爆掉的地雷。" << endl;
    cout << "感謝您的賞光～～～" << endl;
}
void Mine::print_cells(int cells[][11], int op_x, int op_y, int over) { //印出目前的狀況
    system("cls");
    cout << endl;
    if (over == 0) {
        print_condition_playing(cells);
    }
    else
        print_condition_over(cells, over);
}
int  Mine::check_over(int cells[][11], int op_x, int op_y) { //檢查遊戲是否結束(輸或贏)
    //result == 0 ->尚未結束，result == 1 ->贏，result == -1 ->輸
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