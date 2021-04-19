#include "ChessBoard.h"
#include"Config.h"


//���캯��
ChessBoard::ChessBoard()
	://��ʼ���б� һЩ��������
	maxrow(ROW_NUM), //����
	maxcol(COL_NUM), //����
	square_height(SQUARE_HEIGHT),//������ֱ���
	square_width(SQUARE_WIDTH),//����ˮƽ���
	timecounter(0)//��ʱ��
{
	for (int i = 0; i < maxrow+2; i++) {//�����������ʼ��
		vector<vector<Object*>>Orow;//����һ�еؿ飬һ�����ÿ���ؿ鶼��������һ��vector
		vector<Bullet*> Brow;//�ӵ���
		
		yard.push_back(Orow);
		bulletyard.push_back(Brow);
		for (int j = 0; j < maxcol + 5; j++) {
			vector<Object*> objvec;//ÿһ���ؿ鶼��һ��vector����Ϊ��Ҫ��Ŷ����ʬ
			yard[i].push_back(objvec);//���еؿ�ÿһ�ж���һ��������

			Bullet* bullet = nullptr;
			bulletyard[i].push_back(bullet);//���ӵ��е�ÿһ�ж���һ��nullptr
		}
	}
}

//����
ChessBoard::~ChessBoard() {
	for (int i = 0; i < maxrow; i++) {//�ͷ�����ֲ��ͽ�ʬ�Ŀռ�
		for (int j = 0; j < maxcol; j++) {
			
			for (int k = 0; k < yard[i][j].size(); k++) {
				if (yard[i][j][k] != nullptr) {
					delete yard[i][j][k];//�ͷ�ֲ��ͽ�ʬ
					yard[i][j][k] = nullptr;
				}
			}

			if (bulletyard[i][j] != nullptr) {
				delete bulletyard[i][j];//�ͷ��ӵ�
				bulletyard[i][j] = nullptr;
			}
		}
	}
}

//���ֲ��
bool ChessBoard::AddPlant(AbstractPlant* plant,int row,int col) {
	plant->SetRow(row);
	plant->SetCol(col);
	//�������ؿ������ǿյĻ�����push��ȥֲ��,��Ϊֲ�ﲻ���ص��ţ�ֲ��ͽ�ʬ�����ص���
	if (yard[row][col].empty()) {
		yard[row][col].push_back(plant);
		return true;
	}
	else return false;
}

//��ӽ�ʬ
void ChessBoard::AddZombie(AbstractZombie* zombie,int row) {//���һ����ʬ
	yard[row][maxcol - 1].push_back(zombie);
}


void ChessBoard::AddBullet(Bullet* blt) {
	bulletyard[blt->GetRow()][blt->GetCol()] = blt;
}


//����״̬
bool ChessBoard::Update() {
	//ÿ�θ���ʱ��Ҫ��ʱ���1
	TimeUp();
	CreateZombie();
	//��i��j�н��б���
	for (int i = 0; i < maxrow; i++) {
		for (int j = 0; j < maxcol; j++) {
			
			for (int k = yard[i][j].size() - 1; k >= 0; k--) {
				if (yard[i][j][k]->GetStatus() == Object::Dead) {//����ұ������������
					if (yard[i][j][k]->GetType() == Object::Zombie_t)ScoreUp();
					ClearObj(i, j, k);
					continue;
				}
			}


			for (int k = yard[i][j].size() - 1; k >= 0; k--) {//������ǲ�������֮�󣬼���ǲ��ǽ�ʬ���Ǿ��ƶ�
				if (yard[i][j][k]->GetType() == Object::Zombie_t) {
					if (j == 0)return false;//���Խ�����Ϸ����
					ZombieMove(i, j, k);
				}
			}

		}
	}

	//�ӵ����������������Ϊ�ӵ������ƣ�Ȼ���ٴα����ͻ������ǰ�ߣ�����bug
	for (int i = 0; i < maxrow; i++) {
		for (int j = maxcol-1; j >=0; j--) {
			if (bulletyard[i][j] != nullptr) {
				BulletMove(i, j);
			}
		}
	}
}

//���Obj
void ChessBoard::ClearObj(int i, int j,int k) {
	delete yard[i][j][k];//�ͷţ�*it��ָ��Ŀռ�
	yard[i][j].erase(yard[i][j].begin()+k);//ɾ��it
}

//����ӵ�
void ChessBoard::ClearBullet(int r, int c) {
	Bullet* blt = bulletyard[r][c];
	bulletyard[r][c] = nullptr;
	delete blt;
}

//��齩ʬ�Ƿ��ʺ��ƶ������λ��
int ChessBoard::CheckPos(int r,int c,AbstractZombie* zmb) {//���ջ����ǽ�ʬ����ʬ�ʺ��ƶ�������
	if (c < 0)return false;
	if (yard[r][c].empty())return true;
	else if (yard[r][c][0]->GetType() == Object::Zombie_t)return 1;
	else if (yard[r][c][0]->GetType() == Object::Plant_t) {
		if (zmb->AttackEnemy(0).GetAttackType() == Attack::PolesZombie_t) {//���ù�����������ǲ��ǳŸ˽�ʬ
			PolesZombie* pz = static_cast<PolesZombie*>(zmb);
			if (pz->IsInit()) {//�����û����ֲ���
				pz->ChangeInit(); return 2;
			}
			else return 0;
		}
		else return 0;
	}
	else return 0;
}

void ChessBoard::ZombieMove(int i,int j, int k) {
	AbstractZombie* zmb = static_cast<AbstractZombie*>(yard[i][j][k]);
	if (!(zmb->CanMove(timecounter)))return;
	int currow = i;
	int curcol = j;
	int nextrow = currow;
	int nextcol = curcol - 1;
	int speed = CheckPos(nextrow, nextcol, zmb);
	nextcol = curcol - speed;
	if (speed) {//����ʬ�����ƶ��Ļ������ƶ�
		zmb->SetRC(nextrow, nextcol);//�޸Ľ�ʬλ��
		yard[nextrow][nextcol].push_back(zmb);//�޸�����
		yard[currow][curcol].erase(yard[i][j].begin() + k);
	}
}

void ChessBoard::BulletMove(int i, int j) {
	Bullet* blt = bulletyard[i][j];
	int sp = blt->GetSpeed();
	if (sp + j >= maxcol-2) {//����ӵ������ˣ��������
		delete blt;
	}
	else {//û������ƶ�
		blt->SetCol(j + sp);
		bulletyard[i][j + sp] = blt;
	}
	bulletyard[i][j] = nullptr;
}

void ChessBoard::TimeUp() {
	timecounter++;
}

void ChessBoard::CreateZombie() {
	Object* obj = nullptr;
	NormalZombie* pz = nullptr;
	if (timecounter % TIME_GAP_CREATE_ZOMBIE==0) {
		int Row = random_num(ROW_NUM);
		switch ( random_num(MAX_KINDS_ZOMBIES) )
		{
		case 0:
			obj = new NormalZombie(Row);
			break;
		case 1:
			obj = new BarricadesZombie(Row);
			break;
		case 2:
			obj = new PaperZombie(Row);
			break;
		case 3:
			obj = new PolesZombie(Row);
		default:
			break;
		}

		RCPair rc = obj->GetRC();
		yard[rc.row][rc.col].push_back(obj);
	}
}


