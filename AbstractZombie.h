#pragma once
#include "Object.h"
class AbstractZombie :
    public Object
{
public:
    //���캯��
    AbstractZombie(int hp,int r);
    //��������
    ~AbstractZombie();
    void SetSpeed(int sp) { speed = sp; }
    int GetSpeed()const { return speed; }
private:
    int speed;
};

