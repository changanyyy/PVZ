#include "AbstractPlant.h"

//���캯��
AbstractPlant::AbstractPlant(int pt,int hp,int r,int c)
	:
	Object(0,hp,r,c)//���û��๹�캯���� 
{
	planttype = pt;
	mytype = Object::Plant_t;//�����ҵ�������ֲ��
}
//��������
AbstractPlant::~AbstractPlant() {
}