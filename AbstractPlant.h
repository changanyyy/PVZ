#pragma once
#include"Object.h"

//�̳������࣬���������й�ֲ�ﹲ�Ե�����
class AbstractPlant
	:public Object
{
public:
    enum {
        PeaShooter_t,
        SunFlower_t,
        NutWall_t,
        HighNut_t,
        DoubleShooter_t,
        IceShooter_t,
        Squash_t,
        Cherry_t,
        Garlic_t,
        Pumpkin_t
    };

    AbstractPlant(int pt, int hp, int r, int c);//������Ĭ�Ϲ��캯��
	~AbstractPlant();

    int GetPlantType()const { return planttype; }
protected:
    int planttype;
};

