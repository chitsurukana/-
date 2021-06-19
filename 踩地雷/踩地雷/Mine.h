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
	void assign_initial(int cells[][11]);					//�N��l����T��l�Ƭ�0
	void print_blanks(void);								//�L�X�C����l����l 
	void open_cell(int*, int*);								//�ШϥΪ̿�J�n���}����m
	void put_mine(int cells[][11], int, int);				//��m�a�p
	void calculate_num_of_cells(int cells[][11]);			//�p��D�a�p�Ϫ��񦳴X���a�p 
	void assign_inf_after_open(int cells[][11], int, int);	//���ܨϥΪ̥��}����m����T
	void open_surrounding(int cells[][11], int, int);		//���}���񪺰ϰ�]���l����L�a�p�ɡ^
	void check_no_mine(int cells[][11], int, int);			//�ˬd���񪺰ϰ즳�S���a�p 
	int  check_over(int cells[][11], int, int);				//�ˬd�C���O�_����(���Ĺ)
	void print_cells(int cells[][11], int, int, int);		//�L�X�ثe�����p
	void print_condition_playing(int cells[][11]);			//�L�X�|�����������p
	void print_condition_over(int cells[][11], int);		//�L�X�C�����������p(�C�Ӯ�l����T) 
private:
	int  cells[11][11],
		open_x, open_y,
		over;
};

#endif // !MINE_H
