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
const int MAX_KINDS_ZOMBIES = 6;
//��ʬ������ʱ��gap
const int TIME_GAP_CREATE_ZOMBIE = 10;

//��ͨ��ʬ�ƶ���gap
const int TIME_GAP_NORMAL_ZOMBIE = 2;
//·�Ͻ�ʬ�ƶ�gap
const int TIME_GAP_BARRICADES_ZOMBIE = 2;
//������ʬ�ƶ�gap
const int TIME_GAP_PAPER_ZOMBIE = 2;
//�Ÿ˽�ʬ�ƶ�gap
const int TIME_GAP_POLES_ZOMBIE = 2;
//С��ʬ�ƶ�gap
const int TIME_GAP_CLOWN_ZOMBIE = 2;
//Ͷʯ��ʬ�ƶ�gap
const int TIME_GAP_CAST_ZOMBIE = 2;

//��ͨ��ʬ��������
const int HP_NORMAL_ZOMBIE = 10;
//·�Ͻ�ʬ��������
const int HP_BARRICADES_ZOMBIE = 30;
//������ʬ��������
const int HP_PAPER_ZOMBIE = 10;
//�Ÿ˽�ʬ��������
const int HP_POLES_ZOMBIE = 10;
//С��ʬ��������
const int HP_CLOWN_ZOMBIE = 10;
//Ͷʯ��ʬ��������
const int HP_CAST_ZOMBIE = 15;


//Ͷʯ��ʬͶ��gap
const int TIME_GAP_CAST = 2;

//Ͷʯ��ʬ��ʼ������
const int NUM_OF_BALL = 3;


//�㶹���ֳ�ʼhp
const int HP_PEASHOOTER = 15;
//̫������ʼhp
const int HP_SUNFLOWER = 20;
//���ǽ��ʼhp
const int HP_NUTWALL = 120;
//˫�����ֳ�ʼhp
const int HP_DOUBLESHOOTER = 20;
//�������ֳ�ʼhp
const int HP_ICESHOOTER = 20;
//�߼��
const int HP_HIGHNUT = 240;
//����
const int HP_SQUASH = 10;
//ӣ��
const int HP_CHERRY = 20;



//�㶹���ֹ���gap
const int TIME_GAP_PEASHOOTER_ATTACK = 4;
//��������gap
const int TIME_GAP_CREATESUN = 20;
//˫������
const int TIME_GAP_DOUBLESHOOTER_ATTACK = 4;
//��������
const int TIME_GAP_ICESHOOTER_ATTACK = 4;


const int DOUBLESHOOTER_COST = 150;
const int NUTWALL_COST = 60;
const int PEASHOOTER_COST =100;
const int SUNFLOWER_COST = 75;
const int ICESHOOTER_COST = 120;
const int HIGHNUT_COST = 200;
const int SQUASH_COST = 80;
const int CHERRY_COST = 100;


//��ʼ��������Ŀ
const int INIT_SUN = 5000;



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