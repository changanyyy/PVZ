#include "Object.h"


//���캯��
Object::Object(int ty, int Hp,int r,int c) {
	mytype = (Type)ty;
	mystatus = (Status)Healthy;
	myhp = Hp;
	row = r;
	col = c;
}

//��������
Object::~Object() {

}

//������֣��������
string Object::GetName()const {
	switch (mytype)
	{
	case Plant_t:return string("Plant"); break;
	case Zombie_t:return string("Zombie"); break;
	case Bullet_t:return string("*"); break;//��ʵ����û�ã���û��Bullet�̳�Object
	default:
		break;
	}
}



//�ܵ�����
void Object::Isattacked(int hurt) {
	myhp -= hurt;
	if (myhp <= 0)die();
}

//��������״̬
void Object::die() {
	mystatus = Dead;
}