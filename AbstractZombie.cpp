#include "AbstractZombie.h"


//���캯��
AbstractZombie::AbstractZombie(int hp, int r)
	:
	//���û��๹�캯��
	//��ʬ�����������һ�г��֣����Խ�ʬ��ʼ��ʱ��û�а�����Ϊ����
	Object(hp, hp, r, COL_NUM-2 )
{
	mytype = Object::Zombie_t;
}

//��������
AbstractZombie::~AbstractZombie() {

}