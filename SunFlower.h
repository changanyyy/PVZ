#pragma once


#include"AbstractPlant.h"

class SunFlower :
	public AbstractPlant
{
public:
	//���캯��
	SunFlower(int hp, int r = -1, int c = -1);
	//��������
	~SunFlower();
	//�ض��幥������
	Attack AttackEnemy();
	//�ض������ƺ���
	string GetName()const { return string("SunFlower"); }
private:
};

