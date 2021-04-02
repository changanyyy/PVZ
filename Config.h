#pragma once
#include<Windows.h>
#include<iostream>

//����������������
const int ROW_NUM = 3;
const int COL_NUM = 32;
//�к���֮�����²�࣬���Ҳ��
const int SQUARE_HEIGHT = 3;
const int SQUARE_WIDTH = 2;

//������ɫ
void set_std_color(int color);

//������ɫ
void reset_std_color();

//���ù��λ��
void set_std_pos(int x, int y);



//�ṹ�壬�к���
struct RCPair{
	int row, col;
	RCPair(int r, int c) { row = r; col = c; }
};

//�ṹ�壬x��y
struct Pos {
	int x, y;
	Pos(int _x, int _y) { x = _x; y = _y; }
};
//���ʵ��λ�ã��ǣ�x��y����Ԫ��
Pos GetPos(int row, int col);

//�ж��ǲ��ǳ�����
bool judge_pos(int row, int col);