#pragma once
#include "Object.h"

//������йؽ�ʬ�Ĺ�������
class AbstractZombie 
    :public Object
{
public:
    //���캯��
    AbstractZombie(int hp,int r,int gap);
    //��������
    ~AbstractZombie();
    bool CanMove(unsigned timercount)const { return (timercount % movegap == 0); }

protected:
    //��ʬ�ƶ����ٶ�(ʱ����)
    int movegap;
};

