#pragma once
#include<Windows.h>
#include<iostream>


const int ROW_NUM = 3;
const int COL_NUM = 7;
const int SQUARE_HEIGHT = 3;
const int SQUARE_WIDTH = 8;


void set_std_color(int color);

void reset_std_color();


void set_std_pos(int x, int y);