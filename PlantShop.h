#pragma once
#include"PeaShooter.h"
#include"SunFlower.h"
#include"ChessBoard.h"


class PlantShop
{
public:
	enum Type {
		None_t,
		Plant_t,
		Zombie_t,
		PeaShooter_t,
		NormalZombie_t,
		SunFlower_t
	};



	PlantShop();
	~PlantShop();
	
	//�������
	void AddSun(int x) { sun += x; }
	//��ȡ����
	int GetSun()const { return sun; }

	void SubSun(Type type);

	bool CheckEnough(Type type);

	bool SettlePlant(Object* obj, ChessBoard* chessbd, int r, int c);




private:

	int sun;

};

