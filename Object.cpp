#include "Object.h"

//���캯��
Object::Object(int ty, int Hp,int r,int c) {
	mytype = (Type)ty;
	mystatus = (Status)Healthy;
	myhp = Hp;
	row = r;
	col = c;
	myhpmax = Hp;
}

//��������
Object::~Object() {

}

//������֣��������
string Object::GetName()const {
	return string("Plant");
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