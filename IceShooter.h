#pragma once
#include "AbstractPlant.h"
class IceShooter :
    public AbstractPlant
{
public:
    //���캯��
    IceShooter(int r = -1, int c = -1);
    //��������
    ~IceShooter();
    //�ض��幥������
    Attack AttackEnemy(int time);
    //�ض����ȡ��������
    string GetName()const { return string("������"); }
    void Update() {}
private:
    int timegap;
};

