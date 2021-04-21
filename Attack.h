#pragma once
#include "Bullet.h"

/*������! object�Ĺ�����������һ����������� �����и��ֲ�ͬ�Ĺ���*/
class Attack
{
public:
	enum {//�������ͣ���ʱ��controlģ����ݹ�������ȷ������Ĺ���
		None,
		NormalZombie_t,
		BarricadesZombie_t,
		PaperZombie_t,
		PolesZombie_t,
		ClownZombie_t,
		CastZombie_Cast_t,
		CastZombie_Car_t,
		PeaShooter_t,
		SunFlower_t,
		NutWall_t,
		HighNut_t,
		DoubleShooter_t,
		IceShooter_t
	};
	//���캯���������ǹ�������
	Attack(int _attacktype);
	//�������캯��
	Attack(const Attack& rh);
	//��ֵ����
	Attack& operator=(const Attack& rh);
	//��ȡ��������
	int GetAttackType()const { return attacktype; }
	//�����ӵ���ĳ��ֲ�����ӵ�
	void SetBullet(Bullet* _bullet) { bullet = _bullet; }
	//��ȡ�ӵ�����controlģ�鷢����
	Bullet* GetBullet() { return bullet; }
	//���ù���ֵ
	void SetATK(int atk) { ATK = atk; }
	//��ù���ֵ
	int GetATK()const { return ATK; }
	//���ù�������
	void SetType(int ty) { attacktype = ty; }
private:
	//��������
	int attacktype;
	//����ֵ
	int ATK;
	//�ӵ�
	Bullet* bullet;
};