#pragma once
#include "AbstractZombie.h"
class NormalZombie :
    public AbstractZombie
{
public:
    //���캯��
    NormalZombie(int hp,int r);
    //��������
    ~NormalZombie();
    //�ض��幥������
    Attack AttackEnemy(int time);
    //�ض������ƺ���
    string GetName()const { return string("��ʬ"); }
    void Update(){ }
private:
};

