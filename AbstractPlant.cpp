#include "AbstractPlant.h"

//���캯��
AbstractPlant::AbstractPlant(int hp,int r,int c)
	:
	Object(0,hp,r,c)//���û��๹�캯���� 
{
	mytype = Object::Plant_t;//�����ҵ�������ֲ��
}
//��������
AbstractPlant::~AbstractPlant() {
}