#include "PeaShooter.h"


PeaShooter::PeaShooter(int hp,int r,int c)
	:
	AbstractPlant(hp,r,c)//������ֲ��
{

}

PeaShooter::~PeaShooter() {

}

Attack PeaShooter::AttackEnemy() {
	Attack atk(Attack::PeaShooter);
	Bullet* blt = new Bullet(1,row,col);
	atk.SetBullet(blt);
	return atk;
}