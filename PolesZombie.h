#pragma once
#include "AbstractZombie.h"
class PolesZombie :
    public AbstractZombie
{
public:
    //���캯��
    PolesZombie(int r);
    //��������
    ~PolesZombie();
    //�ض��幥������
    Attack AttackEnemy(int time);
    //�ض������ƺ���
    string GetName()const { return string("�Ÿ�"); }
    void Update() { }
    bool IsInit()const { return init; }
    void ChangeInit() { init = false; }
private:
    bool init;
};

