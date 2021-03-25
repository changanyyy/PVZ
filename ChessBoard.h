#pragma once
#include"Object.h"
#include<vector>
using namespace std;

class ChessBoard
{
public:
	//���캯��
	ChessBoard();
	//��������
	~ChessBoard();
	//��ʾ����
	void Show();
private:
	//����״̬
	void Update();

	int row_num;
	int col_num;
	int square_height;
	int square_width;
	//�洢�����ϵ�ֲ��ͽ�ʬ
	vector<vector<Object*>> vec;
};

