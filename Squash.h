#pragma once
#include "AbstractPlant.h"
class Squash :
    public AbstractPlant
{
public:
    //���캯��
    Squash(int r = -1, int c = -1);
    //��������
    ~Squash();
    //�ض��幥������
    Attack AttackEnemy(int time);
    //�ض����ȡ��������
    string GetName()const { return string("����"); }
    void Update() {}
private:
    
};

