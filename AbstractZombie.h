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
    void SpeedDown() { if (!speeddown) { movegap *= 2; speeddown = true; } }
protected:
    //��ʬ�ƶ����ٶ�(ʱ����)
    int movegap;
    bool speeddown;
};

