#pragma once
#include "AbstractPlant.h"
class DoubleShooter :
    public AbstractPlant
{
public:
    //���캯��
    DoubleShooter(int r = -1, int c = -1);
    //��������
    ~DoubleShooter();
    //�ض��幥������
    Attack AttackEnemy(int time);
    //�ض����ȡ��������
    string GetName()const { return string("˫����"); }
    void Update() {}
private:
    int timegap;
};

