#pragma once
#include"PeaShooter.h"
#include"SunFlower.h"
#include"ChessBoard.h"

class Shop
{
public:
	Shop();
	~Shop();
	//ͨ���̵����������ֲ�����
	void BuyPlant(ChessBoard* chessbd);
private:
	void Show();
	void WrongInput();
	bool Confirm(int n);
	void SettlePlant(Object* obj, ChessBoard* chessbd);

	void PrintSelectBox(int r,int c);

	//����һ����row,col����Ԫ�飬��ʾ��ŵ�λ��
	const RCPair SelectArea(ChessBoard* chessbd);
};

