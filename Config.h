#pragma once
#include<Windows.h>
#include<iostream>


const int ROW_NUM = 3;
const int COL_NUM = 32;
const int SQUARE_HEIGHT = 3;
const int SQUARE_WIDTH = 2;

//������ɫ
void set_std_color(int color);
//������ɫ
void reset_std_color();

//���ù��λ��
void set_std_pos(int x, int y);


struct RCPair{
	int row, col;
	RCPair(int r, int c) { row = r; col = c; }
};