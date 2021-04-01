#pragma once
#include<string>
#include"Config.h"
#include"Attack.h"
#include"Bullet.h"
using namespace std;

/*
* �����塱�����
*  ���ö�̬��һ��object pointer����ָ���κ�ֲ����߽�ʬ
*  ֲ��ͽ�ʬ�Ļ���AbstractPlant��AbstractZombie�̳���
*/



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
	int GetType()const { return mytype; }
	//��õ�ǰ״̬
	int GetStatus()const { return mystatus; }
	//��õ�ǰ����
	RCPair GetRC()const { return RCPair(row, col); }
	//������
	int SetRow(int r) { row = r; }
	//������
	int SetCol(int c) { col = c; }
	//�����
	int GetRow()const { return row; }
	//�����
	int GetCol()const { return col; }
	//��������,���麯������ͬ��ֲ�ｩʬ��Ҫ���¶��壡
	virtual Attack AttackEnemy() = 0;
	//�յ�������һ��Ѫ
	void Isattacked(int hurt);
	//��ȥ���ı�״̬
	void die();
	//�����к���
	void SetRC(int r,int c) { row = r; col = c; }
protected:
	//�ҵ�����ֵ
	int myhp;
	//�ҵ����࣬���涨����ö������
	Type mytype;
	//�ҵ�״̬������or����������������������ֲ��ͽ�ʬ
	Status mystatus;
	//�У���
	int row, col;
};

