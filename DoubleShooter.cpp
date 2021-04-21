#include "DoubleShooter.h"


//���캯��
DoubleShooter::DoubleShooter(int r, int c)
	:
	AbstractPlant(HP_DOUBLESHOOTER, r, c),//������ֲ��
	timegap(TIME_GAP_DOUBLESHOOTER_ATTACK)
{
}

//��������
DoubleShooter::~DoubleShooter() {

}

//�㶹���ֵĹ�������
//����һ��ATKΪ1���ӵ���
Attack DoubleShooter::AttackEnemy(int time) {
	if (time % TIME_GAP_DOUBLESHOOTER_ATTACK == 0|| time % TIME_GAP_DOUBLESHOOTER_ATTACK == 1) {
		Attack atk(Attack::DoubleShooter_t);
		Bullet* blt = new Bullet(1, row, col);
		atk.SetBullet(blt);
		return atk;
	}
	else
		return Attack(Attack::None);
}