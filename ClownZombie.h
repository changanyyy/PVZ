#pragma once
#include "AbstractZombie.h"
class ClownZombie :
    public AbstractZombie
{
public:
    //���캯��
    ClownZombie(int r);
    //��������
    ~ClownZombie();
    //�ض��幥������
    Attack AttackEnemy(int time);
    //�ض������ƺ���
    string GetName()const { return string("С��"); }

    void Update() { }
private:
};

