#include "Squash.h"

//���캯��
Squash::Squash(int r, int c)
	:
	AbstractPlant(HP_SQUASH, r, c)//������ֲ��
{
}

//��������
Squash::~Squash() {

}

//�㶹���ֵĹ�������
//����һ��ATKΪ1���ӵ���
Attack Squash::AttackEnemy(int time) {
	Attack atk(Attack::Squash_t);
	atk.SetATK(10000);
	return atk;
}
