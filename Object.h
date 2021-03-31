#pragma once
#include<string>
#include"Config.h"
#include"Attack.h"
#include"Bullet.h"
using namespace std;

class Object
{
public:
	//״̬��������������ÿ�θ���ʱ�����̻���״̬������������Ƴ�����
	enum Status { Healthy, Dead };
	//Object�����࣬����ֲ��ͽ�ʬ
	enum Type { Plant_t, Zombie_t,Bullet_t };

	//���캯��������Ϊ����
	Object(int ty,int Hp,int r,int c);
	//��������
	~Object();
	//����������������֣��Ա����
	virtual string GetName()const;
	//��õ�ǰ����
	int GetType()const;
	//��õ�ǰ״̬
	int GetStatus()const;
	//��õ�ǰ����
	RCPair GetRC()const { return RCPair(row, col); }
	//��������
	virtual Attack AttackEnemy() = 0;
	//�յ�������һ��Ѫ
	void Isattacked(int hurt);
	//��ȥ���ı�״̬
	void die();
	void SetRC(int r,int c) { row = r; col = c; }
protected:
	int myhp;
	Type mytype;
	Status mystatus;
	int row, col;
};

