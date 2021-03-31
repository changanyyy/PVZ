#pragma once
#include"Object.h"
#include"AbstractPlant.h"
#include"AbstractZombie.h"
#include"PeaShooter.h"
#include"NormalZombie.h"
#include<vector>
using namespace std;

class ChessBoard
{
public:
	struct Pos {
		int x, y;
		Pos(int _x, int _y) { x = _x; y = _y; }
	};
	Pos GetPos(int row, int col) { return Pos(col * square_width, 2 + row * square_height); }
	
	
	//���캯��
	ChessBoard();
	//��������
	~ChessBoard();
	//��ʾ����
	void Show();
	//����״̬
	void Update();
	bool AddPlant(AbstractPlant* plant,int row,int col);
	void AddZombie(AbstractZombie* zombie,int row);
	void AddBullet(Bullet* blt);
	int GetMaxRow()const { return maxrow; }
	int GetMaxCol()const { return maxcol; }
	Object* GetObject(int r, int c) { return yard[r][c]; }
	Bullet* GetBullet(int r, int c) { return bulletyard[r][c]; }
	void ClearBullet(int r, int c);
private:
	void ClearObj(int i,int j);

	bool CheckPos(int r,int c);
	void ZombieMove(int i, int j);
	void BulletMove(int i, int j);

	int maxrow;
	int maxcol;
	int square_height;
	int square_width;
	//�洢�����ϵ�ֲ��ͽ�ʬ
	vector<vector<Object*>> yard;
	vector<vector<Bullet*>> bulletyard;
};

