#pragma once
#include "AbstractZombie.h"
class CastZombie :
    public AbstractZombie
{
public:
    //���캯��
    CastZombie(int r);
    //��������
    ~CastZombie();
    //�ض��幥������
    Attack AttackEnemy(int time);
    //�ض������ƺ���
    string GetName()const { return string("Ͷ��"); }

    void Update() { }
private:
    int ball;
    int castgap;
};

