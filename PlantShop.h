#pragma once
#include"PeaShooter.h"
#include"SunFlower.h"
#include"ChessBoard.h"


class PlantShop
{
public:
	PlantShop();
	~PlantShop();
	
	//�������
	void AddSun(int x) { sun += x; }
	//��ȡ����
	int GetSun()const { return sun; }

	bool SettlePlant(Object* obj, ChessBoard* chessbd, int r, int c);




private:

	int sun;

};

