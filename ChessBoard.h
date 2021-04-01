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
	//���ʵ��λ�ã��ǣ�x��y����Ԫ��
	Pos GetPos(int row, int col) { return Pos(col * square_width, 2 + row * square_height); }
	
	
	//���캯��
	ChessBoard();
	//��������
	~ChessBoard();
	//��ʾ����
	void Show();
	//����״̬
	void Update();
	//��ĳλ�����ֲ�������з���false
	bool AddPlant(AbstractPlant* plant,int row,int col);
	//��ĳ����ӽ�ʬ
	void AddZombie(AbstractZombie* zombie,int row);
	//���ĳ���ӵ�
	void AddBullet(Bullet* blt);
	//����������
	int GetMaxRow()const { return maxrow; }
	//����������
	int GetMaxCol()const { return maxcol; }
	//�õ���ǰ���е�Objectָ��
	Object* GetObject(int r, int c) { return yard[r][c]; }
	//�õ���ǰ���е��ӵ�ָ��
	Bullet* GetBullet(int r, int c) { return bulletyard[r][c]; }
	//������е��ӵ�
	void ClearBullet(int r, int c);
private:
	//�����ǰ���е�Obj
	void ClearObj(int i,int j);
	//�鿴��ʬ�Ƿ��ʺ�ǰ��
	bool CheckPos(int r,int c);
	//��ʬ�����ƶ�
	void ZombieMove(int i, int j);
	//�ӵ������ƶ�
	void BulletMove(int i, int j);


	//�������
	int maxrow;
	//�������
	int maxcol;
	//������ֱ�ϵĲ��
	int square_height;
	//����ˮƽ�ϵĲ��
	int square_width;
	//�洢�����ϵ�ֲ��ͽ�ʬ
	vector<vector<Object*>> yard;
	//������һ���ӵ�yard�洢�ӵ�
	vector<vector<Bullet*>> bulletyard;
};

