#pragma once
#include "AbstractZombie.h"
class PaperZombie :
    public AbstractZombie
{
public:
    //���캯��
    PaperZombie(int r);
    //��������
    ~PaperZombie();
    //�ض��幥������
    Attack AttackEnemy(int time);
    //�ض������ƺ���
    string GetName()const { return string("����"); }

    void Isattacked(int hurt);
    void Update() { }
private:
};

