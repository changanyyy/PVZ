#include "PeaShooter.h"

//���캯��
PeaShooter::PeaShooter(int hp,int r,int c)
	:
	AbstractPlant(hp,r,c)//������ֲ��
{

}

//��������
PeaShooter::~PeaShooter() {

}

//�㶹���ֵĹ�������
//����һ��ATKΪ1���ӵ���
Attack PeaShooter::AttackEnemy() {
	Attack atk(Attack::PeaShooter);
	Bullet* blt = new Bullet(1,row,col);
	atk.SetBullet(blt);
	return atk;
}