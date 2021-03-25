#pragma once
#include<string>
using namespace std;

class Object
{
public:
	//״̬��������������ÿ�θ���ʱ�����̻���״̬������������Ƴ�����
	enum Status { Healthy, Dead };
	//Object�����࣬����ֲ��ͽ�ʬ
	enum Type { Plant, Zombies, Pea, Flower };

	//���캯��������Ϊ����
	Object(int ty,int Hp);
	//��������
	~Object();
	//����������������֣��Ա����
	virtual string GetName()const;
	//��õ�ǰ����
	int GetType()const;
	//��õ�ǰ״̬
	int GetStatus()const;
	//��������
	virtual void Attack() = 0;
	//�յ�������һ��Ѫ
	void Isattacked();
	//��ȥ���ı�״̬
	void die();
private:
	int myhp;
	Type mytype;
	Status mystatus;
};

