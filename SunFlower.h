#pragma once


#include"AbstractPlant.h"
#include"Attack.h"

class SunFlower :
	public AbstractPlant
{
public:
	//���캯��
	SunFlower(int hp, int r = -1, int c = -1);
	//��������
	~SunFlower();
	//�ض��幥������
	Attack AttackEnemy(int time);
	//�ض������ƺ���
	string GetName()const { return string("̫����"); }

	void Update(){ }
private:
};

