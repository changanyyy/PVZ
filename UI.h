#pragma once
#include"ChessBoard.h"
#include"PlantShop.h"
#include<conio.h>




class UI
{

public:

	//**************************��ͨ��ʾUI
	//չʾ����
	void ShowChessboard(ChessBoard* chessbd);
	//��������ʾһЩ��Ϣ
	void ShowInfo(ChessBoard* chessbd, PlantShop* pshop);


	//**********************shop��UI
	//����ֲ���UI
	void BuyPlant(ChessBoard* chessbd, PlantShop* pshop);
	void WrongInput();
	bool Confirm(int n);
	const RCPair SelectArea(ChessBoard* chessbd);
	void PrintSelectBox(int r, int c);
	void ShowShop();


private:


};

