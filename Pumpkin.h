#pragma once
#include "AbstractPlant.h"
class Pumpkin :
    public AbstractPlant
{
public:
	//���캯��
	Pumpkin(int r = -1, int c = -1);
	//��������
	~Pumpkin();
	//�ض��幥������
	Attack AttackEnemy(int time);
	//�ض������ƺ���
	string GetName()const { return string("�Ϲ�"); }
	void Update() { }

};

