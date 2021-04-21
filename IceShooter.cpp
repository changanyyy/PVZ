#include "IceShooter.h"

//���캯��
IceShooter::IceShooter(int r, int c)
	:
	AbstractPlant(HP_ICESHOOTER, r, c),//������ֲ��
	timegap(TIME_GAP_ICESHOOTER_ATTACK)
{
}

//��������
IceShooter::~IceShooter() {

}

//�㶹���ֵĹ�������
//����һ��ATKΪ1���ӵ���
Attack IceShooter::AttackEnemy(int time) {
	if (time % TIME_GAP_ICESHOOTER_ATTACK == 0) {
		Attack atk(Attack::IceShooter_t);
		Bullet* blt = new Bullet(1, row, col);
		blt->SetIce();
		atk.SetBullet(blt);
		return atk;
	}
	else
		return Attack(Attack::None);
}