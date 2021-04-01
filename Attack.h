#pragma once
#include "Bullet.h"



/*
* ������!
* object�Ĺ�����������һ�����������
* �����и��ֲ�ͬ�Ĺ���
*/



class Attack
{
public:
	enum {
		Plant,
		Zombie,
		PeaShooter,
		NormalZombie
	};

	Attack(int _attacktype) { attacktype = _attacktype; }
	Attack(const Attack& rh) {
		attacktype = rh.attacktype;
		bullet = rh.bullet;
	}
	Attack& operator=(const Attack& rh) {
		attacktype = rh.attacktype;
		bullet = rh.bullet;
	}
	//�����ӵ���ĳ��ֲ�����ӵ�
	void SetBullet(Bullet* _bullet) { bullet = _bullet; }
	//��ȡ�ӵ�����controlģ�鷢����
	Bullet* GetBullet() { return bullet; }
	//��ȡ��������
	int GetAttackType()const { return attacktype; }
	//���ù���ֵ
	void SetATK(int atk) { ATK = atk; }
	//��ù���ֵ
	int GetATK()const { return ATK; }

private:
	//��������
	int attacktype;
	//����ֵ
	int ATK;
	//�ӵ�
	Bullet* bullet;
};

