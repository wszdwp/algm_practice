/*
原文：
Write an algorithm to print all ways of arranging eight queens on a chess board 
so that none of them share the same row, column or diagonal.

译文：
经典的八皇后问题，即在一个8*8的棋盘上放8个皇后，使得这8个皇后无法互相攻击( 任意2个皇后不能处于同一行，同一列或是对角线上)，输出所有可能的摆放情况。
*/
 
#include <iostream>
#include <cmath>
#include <cstring>
using namespace std;

int board[8][8];
int column_for_row[8];
//memset(board, 0, sizeof(board));

void init(){
	for(int i = 0; i < 8; i++){
		column_for_row[i] = 0;
		for(int j = 0; j < 8; j++)
			board[i][j] = 0;
	}
}

void printBoard(){
	cout << "The board is "<< endl;
	for(int i = 0; i < 8; i++){
		for(int j = 0; j < 8; j++){
			cout << board[i][j] << '\t';
		}
		cout << endl;
	}
	cout << endl;
}

bool check(int row){
	for(int i = 0; i < row; ++i){
		int diff = abs(column_for_row[i] - column_for_row[row]);
		if(diff == 0 || diff == row - i) return false;
	}
	return true;
}

void place_queen(int row){
	if(row == 8){
		printBoard();
		return;
	}
	for(int i = 0; i < 8; i++){
		column_for_row[row] = i;
		if(check(row)){
			place_queen(row+1);
		}
	}
}

int main(){
	int row = 3;
	init();
	place_queen(2);

}