#pragma once
#include"AbstractPlant.h"


class NutWall
	:public AbstractPlant
{
public:
	//���캯��
	NutWall(int r = -1, int c = -1);
	//��������
	~NutWall();
	//�ض��幥������
	Attack AttackEnemy(int time);
	//�ض������ƺ���
	string GetName()const { return string("���ǽ"); }

	void Update() { }
};

