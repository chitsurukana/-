#ifndef MINE_H
#define MINE_H
#include<iostream>
#include<iomanip>
#include<time.h>
using namespace std;

class Mine
{
public:
	Mine();
	Mine(int,int,int,int);
	void assign_initial(int cells[][11]);					//將格子內資訊初始化為0
	void print_blanks(void);								//印出遊戲初始的格子 
	void open_cell(int*, int*);								//請使用者輸入要打開的位置
	void put_mine(int cells[][11], int, int);				//放置地雷
	void calculate_num_of_cells(int cells[][11]);			//計算非地雷區附近有幾顆地雷 
	void assign_inf_after_open(int cells[][11], int, int);	//改變使用者打開的位置之資訊
	void open_surrounding(int cells[][11], int, int);		//打開附近的區域（當格子附近無地雷時）
	void check_no_mine(int cells[][11], int, int);			//檢查附近的區域有沒有地雷 
	int  check_over(int cells[][11], int, int);				//檢查遊戲是否結束(輸或贏)
	void print_cells(int cells[][11], int, int, int);		//印出目前的狀況
	void print_condition_playing(int cells[][11]);			//印出尚未結束的狀況
	void print_condition_over(int cells[][11], int);		//印出遊戲結束的狀況(每個格子之資訊) 
private:
	int  cells[11][11],
		open_x, open_y,
		over;
};

#endif // !MINE_H
