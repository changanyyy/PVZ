#include "GameControl.h"

//���������������״̬����ʼ���������������ϵ�������й���
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
	case Attack::IceShooter_t:
	case Attack::DoubleShooter_t:
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
	int rnum=0;
	if (rc.col == 0)return;
	switch (attack.GetAttackType())
	{
	case Attack::CastZombie_Car_t:
	case Attack::NormalZombie_t:
	case Attack::BarricadesZombie_t:
	case Attack::PaperZombie_t:
	case Attack::PolesZombie_t:
		if (chessbd->GetPlotSize(rc.row, rc.col - 1) > 0)enemy = chessbd->GetObject(rc.row, rc.col - 1, 0);//�ҵ�ǰ���ֲ�
		if (enemy != nullptr) {
			if (enemy->GetType() == Object::Plant_t) {
				enemy->Isattacked(attack.GetATK());
			}
		}
		break;
	case Attack::ClownZombie_t:
		rnum=random_num(100);
		if (rnum == 0||rc.col<=6) {
			for (int i = -1; i <= 1; i++) {//����3x3
				for (int j = -6; j <= 6; j++) {
					if (chessbd->GetPlotSize(rc.row + i, rc.col + j) > 0) {
						enemy = chessbd->GetObject(rc.row + i, rc.col + j, 0);
						enemy->Isattacked(attack.GetATK());//С��Ҳ���Լ�ը��
					}
				}
			}
		}
		break;
	case Attack::CastZombie_Cast_t:
		for (int i = 0; i < rc.col; i++) {//�ҵ���ǰ������ߵ�ֲ��
			if (chessbd->GetPlotSize(rc.row, i) > 0) {
				enemy = chessbd->GetObject(rc.row, i, 0);
				if (enemy->GetType() == Object::Plant_t) {
					enemy->Isattacked(attack.GetATK());
				}
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
			if (blt->IsIce())static_cast<AbstractZombie*>(obj)->SpeedDown();
			flag = true;
		}
	}
	obj = nullptr;
	if (chessbd->GetPlotSize(r, c + 1) > 0)obj = chessbd->GetObject(r, c + 1, 0);//�ӵ�ǰ���һ��
	if (obj != nullptr) {
		if (obj->GetType() == Object::Zombie_t) {
			obj->Isattacked(blt->GetATK());
			if (blt->IsIce())static_cast<AbstractZombie*>(obj)->SpeedDown();
			flag = true;
		}
	}
	if(flag)chessbd->ClearBullet(r, c);
}

