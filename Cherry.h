#pragma once
#include "AbstractPlant.h"
class Cherry :
    public AbstractPlant
{
public:
    //���캯��
    Cherry(int r = -1, int c = -1);
    //��������
    ~Cherry();
    //�ض��幥������
    Attack AttackEnemy(int time);
    //�ض����ȡ��������
    string GetName()const { if (timeleft > 2) return string("ӣ��"); else return string("��ӣ��"); }
    void Update() {}
    int GetTimeLeft()const { return timeleft; }
private:
    int timeleft;
};

