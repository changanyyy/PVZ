#pragma once
#include "AbstractPlant.h"
class Garlic :
    public AbstractPlant
{
public:
    //���캯��
    Garlic(int r = -1, int c = -1);
    //��������
    ~Garlic();
    //�ض��幥������
    Attack AttackEnemy(int time);
    //�ض����ȡ��������
    string GetName()const { return string("����"); }
    void Update() {}


};

