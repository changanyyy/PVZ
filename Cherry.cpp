#include "Cherry.h"


//���캯��
Cherry::Cherry(int r, int c)
	:
	AbstractPlant(Cherry_t,HP_SQUASH, r, c)//������ֲ��
{
	timeleft = 10;
	
}

//��������
Cherry::~Cherry() {

}

//�㶹���ֵĹ�������
//����һ��ATKΪ1���ӵ���
Attack Cherry::AttackEnemy(int time) {
	timeleft--;
	Attack atk(Attack::Cherry_t);
	if (timeleft <= 0) {
		atk.SetATK(10000);
	}
	else {
		atk.SetType(Attack::None);
	}
	return atk;
}