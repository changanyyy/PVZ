#pragma once
#include<Windows.h>
#include<iostream>
#include<time.h>

//最大行数和最大列数
const int ROW_NUM = 3;
const int COL_NUM = 32;
//行和行之间上下差距，左右差距
const int SQUARE_HEIGHT = 4;
const int SQUARE_WIDTH = 3;

//僵尸种类上限
const int MAX_KINDS_ZOMBIES = 1;

//僵尸产生的时间gap
const int TIME_GAP_CREATE_ZOMBIE = 10;

//植物攻击gap
const int TIME_GAP_PEASHOOTER_ATTACK = 3;

//产生阳光gap
const int TIME_GAP_CREATESUN = 4;

//初始化阳光数目
const int INIT_SUN = 500;

//设置颜色
void set_std_color(int color);

//重置颜色
void reset_std_color();

//设置光标位置
void set_std_pos(int x, int y);



//结构体，行和列
struct RCPair{
	int row, col;
	RCPair(int r, int c) { row = r; col = c; }
};

//结构体，x和y
struct Pos {
	int x, y;
	Pos(int _x, int _y) { x = _x; y = _y; }
};
//获得实际位置，是（x，y）二元组
Pos GetPos(int row, int col);

//判断是不是超界了
bool judge_pos(int row, int col);


//随机数

int random_num(int Max);

int random_num_based_seed(int Max,int seed);