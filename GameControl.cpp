#include "GameControl.h"



//���������������״̬����ʼ������
//�������ϵ�������й���
void GameControl::UpdateChessbd(ChessBoard* chessbd) {

	//�����������з�����б���
	for (int i = 0; i < ROW_NUM; i++) {
		for (int j = 0; j < COL_NUM; j++) {

			//���������ӵ�
			Bullet* blt = chessbd->GetBullet(i, j);
			if (blt != nullptr)BulletControl(blt, chessbd);
			
			//������������
			Object* obj = chessbd->GetObject(i, j);//���i��j�е�����
			if (obj == nullptr)continue;
			switch (obj->GetType())
			{
			case Object::Plant_t://���������ֲ��Ļ�����ô��ת��ֲ��Ŀ���ģ��
				PlantControl(obj,chessbd);
				break;
			case Object::Zombie_t://��������ǽ�ʬ�Ļ�����ôת����ʬ�Ŀ���ģ��
				ZombieControl(obj,chessbd);
				break;
			default:
				break;
			}


		}
	}
}

//����ֲ�﹥����Ŀǰֻ���㶹����
void GameControl::PlantControl(Object* obj,ChessBoard* chessbd) {
	//RCPair rc = obj->GetRC();
	Attack attack=obj->AttackEnemy();
	switch (attack.GetAttackType())
	{
	case Attack::PeaShooter:
		chessbd->AddBullet(attack.GetBullet());
		break;
	default:
		break;
	}
}


//���ƽ�ʬ������Ŀǰֻ����ͨ��ʬ
void GameControl::ZombieControl(Object* obj,ChessBoard* chessbd) {
	Attack attack = obj->AttackEnemy();
	RCPair rc = obj->GetRC();
	int ATK = 0;
	Object* enemy = nullptr;
	switch (attack.GetAttackType())
	{
	case Attack::Zombie:
		ATK = attack.GetATK();
		enemy = chessbd->GetObject(rc.row, rc.col-1);//�ҵ�ǰ���ֲ�
		if (obj != nullptr) {
			if (obj->GetType() == Object::Plant_t) {
				obj->Isattacked(ATK);
			}
		}
		break;

	default:
		break;
	}
}

//�����ӵ����й�������ס��������ǰ��ǰ���һ���ˣ���Ϊ��ʬ���ӵ�ͬʱ��
void GameControl::BulletControl(Bullet* blt, ChessBoard* chessbd) {
	int r = blt->GetRow();
	int c = blt->GetCol();
	Object* obj = chessbd->GetObject(r,c);//��ǰ��
	if (obj != nullptr) {
		if (obj->GetType() == Object::Zombie_t) {
			obj->Isattacked(blt->GetATK());
		}
		chessbd->ClearBullet(r, c);
	}
	obj = chessbd->GetObject(r, c + 1);//�ӵ�ǰ���һ��
	if (obj != nullptr) {
		if (obj->GetType() == Object::Zombie_t) {
			obj->Isattacked(blt->GetATK());
		}
		chessbd->ClearBullet(r, c);
	}
}

