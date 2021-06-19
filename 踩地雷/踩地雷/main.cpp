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
        mine.assign_initial(cells);                             //將格子內資訊初始化為0
        mine.print_blanks();                                    //印出遊戲初始的格子 
        mine.open_cell(&open_x, &open_y);                       //請使用者輸入要打開的位置
        mine.put_mine(cells, open_x, open_y);                   //放置地雷
        mine.calculate_num_of_cells(cells);                     //計算非地雷區附近有幾彈地雷
        mine.assign_inf_after_open(cells, open_x, open_y);      //改變使用者打開的位置之資訊
        mine.check_no_mine(cells, open_x, open_y);              //檢查附近的區域有沒有地雷，並將無地雷的區域打開
        over = mine.check_over(cells, open_x, open_y);          //檢查遊戲是否結束(輸或贏)
        mine.print_cells(cells, open_x, open_y, over);          //印出目前的狀況
        while (over == 0) {
            mine.open_cell(&open_x, &open_y);
            mine.assign_inf_after_open(cells, open_x, open_y);  //請使用者輸入要打開的位置
            mine.check_no_mine(cells, open_x, open_y);          //檢查附近的區域有沒有地雷，並將無地雷的區域打開
            over = mine.check_over(cells, open_x, open_y);      //檢查遊戲是否結束(輸或贏)
            mine.print_cells(cells, open_x, open_y, over);      //印出目前的狀況
        }
        cout << "還要再玩一次嗎？\n要再玩一次的話請輸入Y，或輸入N關閉程式。";
        cin >> again;
    } while (again == 'Y' || again == 'y');

    return(0);
}