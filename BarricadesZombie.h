#pragma once
#include "AbstractZombie.h"
class BarricadesZombie 
    :public AbstractZombie
{

public:
    //���캯��
    BarricadesZombie(int r);
    //��������
    ~BarricadesZombie();
    //�ض��幥������
    Attack AttackEnemy(int time);
    //�ض������ƺ���
    string GetName()const { return string("·��"); }
    void Update() { }
private:

};

