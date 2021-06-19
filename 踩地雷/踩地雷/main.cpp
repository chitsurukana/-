#include"Mine.h"

int main()
{
    int  cells[11][11],
        open_x=0, open_y=0,
        over=0;
    char again;

    Mine mine(cells[11][11], open_x, open_y,over);

    do {
        system("cls");
        mine.assign_initial(cells);                             //�N��l����T��l�Ƭ�0
        mine.print_blanks();                                    //�L�X�C����l����l 
        mine.open_cell(&open_x, &open_y);                       //�ШϥΪ̿�J�n���}����m
        mine.put_mine(cells, open_x, open_y);                   //��m�a�p
        mine.calculate_num_of_cells(cells);                     //�p��D�a�p�Ϫ��񦳴X�u�a�p
        mine.assign_inf_after_open(cells, open_x, open_y);      //���ܨϥΪ̥��}����m����T
        mine.check_no_mine(cells, open_x, open_y);              //�ˬd���񪺰ϰ즳�S���a�p�A�ñN�L�a�p���ϰ쥴�}
        over = mine.check_over(cells, open_x, open_y);          //�ˬd�C���O�_����(���Ĺ)
        mine.print_cells(cells, open_x, open_y, over);          //�L�X�ثe�����p
        while (over == 0) {
            mine.open_cell(&open_x, &open_y);
            mine.assign_inf_after_open(cells, open_x, open_y);  //�ШϥΪ̿�J�n���}����m
            mine.check_no_mine(cells, open_x, open_y);          //�ˬd���񪺰ϰ즳�S���a�p�A�ñN�L�a�p���ϰ쥴�}
            over = mine.check_over(cells, open_x, open_y);      //�ˬd�C���O�_����(���Ĺ)
            mine.print_cells(cells, open_x, open_y, over);      //�L�X�ثe�����p
        }
        cout << "�٭n�A���@���ܡH\n�n�A���@�����ܽп�JY�A�ο�JN�����{���C";
        cin >> again;
    } while (again == 'Y' || again == 'y');

    return(0);
}