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
    Attack AttackEnemy();
    //�ض������ƺ���
    string GetName()const { return string("NorZombie"); }
private:
};

