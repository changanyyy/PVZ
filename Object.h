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
	virtual string GetName()const=0;
	//��õ�ǰ����
	int GetType()const { return mytype; }
	//��õ�ǰ״̬
	int GetStatus()const { return mystatus; }
	//��õ�ǰ����
	RCPair GetRC()const { return RCPair(row, col); }
	//������
	void SetRow(int r) { row = r; }
	//������
	void SetCol(int c) { col = c; }
	//��������
	void SetRC(int r, int c) { row = r; col = c; }
	//�����
	int GetRow()const { return row; }
	//�����
	int GetCol()const { return col; }
	int GetHp()const { return myhp; }
	int GetMaxHp()const { return myhpmax; }
	//��������,���麯������ͬ��ֲ�ｩʬ��Ҫ���¶��壡
	virtual Attack AttackEnemy(int time) = 0;
	//virtual void Update();
	//�յ�������һ��Ѫ
	virtual void Isattacked(int hurt);
	//��ȥ���ı�״̬
	void die();
	//�����к���

	bool operator==(const Object* rhs)const { return (mytype == rhs->mytype && row == rhs->row && col == rhs->col); }

protected:
	//�ҵ�����ֵ
	int myhp;
	int myhpmax;
	//�ҵ����࣬���涨����ö������
	Type mytype;
	//�ҵ�״̬������or����������������������ֲ��ͽ�ʬ
	Status mystatus;
	//�У���
	int row, col;
};

