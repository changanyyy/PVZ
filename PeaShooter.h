#pragma once
#include "AbstractPlant.h"
class PeaShooter :
    public AbstractPlant
{
public:
    //���캯��
    PeaShooter(int hp, int r = -1, int c = -1);
    //��������
    ~PeaShooter();
    //�ض��幥������
    Attack AttackEnemy(int time);
    //�ض����ȡ��������
    string GetName()const { return string("�㶹��"); }

    void Update(){}
private:
    int timegap;
};

