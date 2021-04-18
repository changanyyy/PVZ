#include "GameControl.h"



//���������������״̬����ʼ������
//�������ϵ�������й���
void GameControl::UpdateChessbd(ChessBoard* chessbd,PlantShop* pshop) {

	//�����������з�����б���
	for (int i = 0; i < ROW_NUM; i++) {
		for (int j = 0; j < COL_NUM; j++) {



			//���������ӵ�
			Bullet* blt = chessbd->GetBullet(i, j);
			if (blt != nullptr)BulletControl(blt, chessbd);
			
			for (int k = 0; k < chessbd->GetPlotSize(i, j); k++) {

				//������������
				Object* obj = chessbd->GetObject(i, j, k);//���i��j�е�����
				switch (obj->GetType())
				{

				case Object::Plant_t://���������ֲ��Ļ�����ô��ת��ֲ��Ŀ���ģ��
					PlantControl(obj, chessbd, pshop);
					break;
				case Object::Zombie_t://��������ǽ�ʬ�Ļ�����ôת����ʬ�Ŀ���ģ��
					ZombieControl(obj, chessbd);
					break;
				default:
					break;

				}

			}
		}
	}
}

//����ֲ�﹥����Ŀǰֻ���㶹����
void GameControl::PlantControl(Object* obj,ChessBoard* chessbd,PlantShop* pshop) {
	//����ù�������
	Attack attack=obj->AttackEnemy(chessbd->GetTime());
	//������ֹ�������ɶҲ���Ǿ�return
	if (attack.GetAttackType() == Attack::None)return;
	switch (attack.GetAttackType())
	{

	case Attack::PeaShooter_t:
		chessbd->AddBullet(attack.GetBullet());
		break;
	case Attack::SunFlower_t:
		pshop->AddSun(attack.GetATK());
		break;
	case Attack::NutWall_t:
		break;
	default:
		break;
	}
}


//���ƽ�ʬ������Ŀǰֻ����ͨ��ʬ
void GameControl::ZombieControl(Object* obj,ChessBoard* chessbd) {
	Attack attack = obj->AttackEnemy(chessbd->GetTime());
	RCPair rc = obj->GetRC();
	Object* enemy = nullptr;
	switch (attack.GetAttackType())
	{

	case Attack::NormalZombie_t:
		if (rc.col == 0)return;
		if (chessbd->GetPlotSize(rc.row, rc.col - 1) > 0)enemy = chessbd->GetObject(rc.row, rc.col - 1, 0);//�ҵ�ǰ���ֲ�
		if (enemy != nullptr) {
			if (enemy->GetType() == Object::Plant_t) {
				enemy->Isattacked(attack.GetATK());
			}
		}
		break;
	case Attack::BarricadesZombie_t:
		if (rc.col == 0)return;
		if (chessbd->GetPlotSize(rc.row, rc.col - 1) > 0)enemy = chessbd->GetObject(rc.row, rc.col - 1, 0);//�ҵ�ǰ���ֲ�
		if (enemy != nullptr) {
			if (enemy->GetType() == Object::Plant_t) {
				enemy->Isattacked(attack.GetATK());
			}
		}
		break;
	case Attack::PaperZombie_t:
		if (rc.col == 0)return;
		if (chessbd->GetPlotSize(rc.row, rc.col - 1) > 0)enemy = chessbd->GetObject(rc.row, rc.col - 1, 0);//�ҵ�ǰ���ֲ�
		if (enemy != nullptr) {
			if (enemy->GetType() == Object::Plant_t) {
				enemy->Isattacked(attack.GetATK());
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
	
	bool flag = false;

	Object* obj = nullptr;
	if (chessbd->GetPlotSize(r, c) > 0) obj = chessbd->GetObject(r, c, 0);
	if (obj != nullptr) {
		if (obj->GetType() == Object::Zombie_t) {
			obj->Isattacked(blt->GetATK());
			flag = true;
		}
	}
	obj = nullptr;
	if (chessbd->GetPlotSize(r, c + 1) > 0)obj = chessbd->GetObject(r, c + 1, 0);//�ӵ�ǰ���һ��
	if (obj != nullptr) {
		if (obj->GetType() == Object::Zombie_t) {
			obj->Isattacked(blt->GetATK());
			flag = true;
		}
	}
	if(flag)chessbd->ClearBullet(r, c);

}

