#pragma once
#include "AbstractPlant.h"
class HighNut :
    public AbstractPlant
{

public:
	//���캯��
	HighNut(int r = -1, int c = -1);
	//��������
	~HighNut();
	//�ض��幥������
	Attack AttackEnemy(int time);
	//�ض������ƺ���
	string GetName()const { return string("�߼��"); }
	void Update() { }
};

