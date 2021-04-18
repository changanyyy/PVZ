#pragma once
#include<Windows.h>
#include<iostream>
#include<time.h>

//����������������
const int ROW_NUM = 3;
const int COL_NUM = 32;
//�к���֮�����²�࣬���Ҳ��
const int SQUARE_HEIGHT = 4;
const int SQUARE_WIDTH = 3;
//��ʬ��������
const int MAX_KINDS_ZOMBIES = 3;
//��ʬ������ʱ��gap
const int TIME_GAP_CREATE_ZOMBIE = 10;

//��ͨ��ʬ�ƶ���gap
const int TIME_GAP_NORMAL_ZOMBIE = 2;
//·�Ͻ�ʬ�ƶ�gap
const int TIME_GAP_BARRICADES_ZOMBIE = 2;
//������ʬ�ƶ�gap
const int TIME_GAP_PAPER_ZOMBIE = 2;

//��ͨ��ʬ��������
const int HP_NORMAL_ZOMBIE = 10;
//·�Ͻ�ʬ��������
const int HP_BARRICADES_ZOMBIE = 30;
//������ʬ��������
const int HP_PAPER_ZOMBIE = 20;




//ֲ�﹥��gap
const int TIME_GAP_PEASHOOTER_ATTACK = 2;
//��������gap
const int TIME_GAP_CREATESUN = 20;
//��ʼ��������Ŀ
const int INIT_SUN = 500;



//������ɫ
void set_std_color(int color);
//������ɫ
void reset_std_color();
//���ù��λ��
void set_std_pos(int x, int y);
//���ع��
void hide_std();

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

//�����
int random_num(int Max);
int random_num_based_seed(int Max,int seed);