#pragma once
#include"ChessBoard.h"
#include"PlantShop.h"
#include<conio.h>

class UI
{
public:
	//**************************��ͨ��ʾUI
	//չʾ����
	void ShowChessboard(ChessBoard* chessbd,PlantShop* pshop);
	//��������ʾһЩ��Ϣ
	void ShowInfo(ChessBoard* chessbd, PlantShop* pshop);
	//**********************shop��UI
	//����ֲ���UI
	void BuyPlant(ChessBoard* chessbd, PlantShop* pshop);
	bool Confirm(int n);
	const RCPair SelectArea(ChessBoard* chessbd,PlantShop* pshop);
	void PrintSelectBox(int r, int c);
	void ShowShop(PlantShop* pshop);
private:
};

