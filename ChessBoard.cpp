#include "ChessBoard.h"
#include"Config.h"


//���캯��
ChessBoard::ChessBoard()
	://��ʼ���б� һЩ��������
	maxrow(ROW_NUM), //����
	maxcol(COL_NUM), //����
	square_height(SQUARE_HEIGHT),//������ֱ���
	square_width(SQUARE_WIDTH)//����ˮƽ���
{
	for (int i = 0; i < maxrow; i++) {//�����������ʼ��
		vector<Object*> Orow;
		vector<Bullet*> Brow;
		yard.push_back(Orow);
		bulletyard.push_back(Brow);
		for (int j = 0; j < maxcol; j++) {
			//��ʼӦ��ȫ��nullptr��Ҫ��ʼ������yard������
			Object* p = nullptr;
			Bullet* bp = nullptr;
			//Object* p = new Object(0,100);//*********************************************************
			yard[i].push_back(p);
			bulletyard[i].push_back(bp);
		}
	}
	PeaShooter* ps = new PeaShooter(10, 1, 0);
	yard[1][0] = ps;
	NormalZombie* pz = new NormalZombie(10, 1);
	RCPair rc = pz->GetRC();
	yard[rc.row][rc.col] = pz;
}

//����
ChessBoard::~ChessBoard() {
	for (int i = 0; i < maxrow; i++) {//�ͷ�����ֲ��ͽ�ʬ�Ŀռ�
		for (int j = 0; j < maxcol; j++) {
			if (yard[i][j] != nullptr) {
				delete yard[i][j];//�ͷ�ֲ��ͽ�ʬ
				yard[i][j] = nullptr;
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
	if (yard[row][col] == nullptr) {
		yard[row][col] = plant;
	}
	else return false;
}

//��ӽ�ʬ
void ChessBoard::AddZombie(AbstractZombie* zombie,int row) {//���һ����ʬ
	yard[row][maxcol - 1] = zombie;
}


void ChessBoard::AddBullet(Bullet* blt) {
	bulletyard[blt->GetRow()][blt->GetCol()] = blt;
}

//��ʾ����
void ChessBoard::Show() {
	ios::sync_with_stdio(false);
	//cin.tie(0);
	for (int i = 0; i < 4; i++) {//�ָ���
		cout << "*****************************************************************************"<<endl<<endl<<endl;
	}
	Update();//����״̬
	set_std_pos(0, 1);
	for (int i = 0; i < maxrow; i++) {//��ʾ���ڵ����������
		for (int j = 0; j < maxcol; j++) {
			Pos pos = GetPos(i, j);
			set_std_pos(pos.x,pos.y);
			if (yard[i][j] != nullptr) {
				cout<<yard[i][j]->GetName();//���ֲ��ͽ�ʬ
			}
			else {
				//cout << "N";
			}
			set_std_pos(pos.x, pos.y);
			if (bulletyard[i][j] != nullptr) {
				cout << "*";//����ӵ���
			}
		}
	}
}
//����״̬
void ChessBoard::Update() {
	
	for (int i = 0; i < maxrow; i++) {
		for (int j = 0; j < maxcol; j++) {
			if (yard[i][j] != nullptr) {
				if (yard[i][j]->GetStatus() == Object::Dead) {//����ǲ������ˣ����˾����
					ClearObj(i, j);
					continue;
				}
				if (yard[i][j]->GetType() == Object::Zombie_t) {//����ǲ��ǽ�ʬ����ʬ�����ƶ�
					if (j == 0)cout << "��Ϸ������";
					ZombieMove(i, j);
				}
				
			}
		}
	}

	for (int i = 0; i < maxrow; i++) {
		for (int j = maxcol-1; j >=0; j--) {
			if (bulletyard[i][j] != nullptr) {
				BulletMove(i, j);
			}
		}
	}
}


void ChessBoard::ClearObj(int i, int j) {
	Object* del = yard[i][j];//������˾������
	yard[i][j] = nullptr;
	delete del;
}

void ChessBoard::ClearBullet(int r, int c) {
	Bullet* blt = bulletyard[r][c];
	bulletyard[r][c] = nullptr;
	delete blt;
}

//��齩ʬ�Ƿ��ʺ��ƶ������λ��
bool ChessBoard::CheckPos(int r,int c) {
	if (c < 0)return false;
	if (yard[r][c] == nullptr)return true;
	else return false;

}

void ChessBoard::ZombieMove(int i,int j) {
	AbstractZombie* zmb = static_cast<AbstractZombie*>(yard[i][j]);
	int currow = i;
	int curcol = j;
	int nextrow = currow;
	int nextcol = curcol - zmb->GetSpeed();
	if (CheckPos(nextrow, nextcol)) {//����ʬ�����ƶ��Ļ������ƶ�
		zmb->SetRC(nextrow, nextcol);//�޸Ľ�ʬλ��
		yard[nextrow][nextcol] = yard[currow][curcol];//�޸�����
		yard[currow][curcol] = nullptr;
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