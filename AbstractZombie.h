#pragma once
#include "Object.h"


//������йؽ�ʬ�Ĺ�������

class AbstractZombie :
    public Object
{
public:
    //���캯��
    AbstractZombie(int hp,int r);
    //��������
    ~AbstractZombie();
    //�����ٶ�ֵ
    void SetSpeed(int sp) { speed = sp; }
    //��ȡ�ٶ�ֵ
    int GetSpeed()const { return speed; }

private:
    //��ʬ�ƶ����ٶ�
    int speed;
};

