#pragma once
#include"Object.h"
#include"AbstractPlant.h"
#include"AbstractZombie.h"
#include"PeaShooter.h"
#include"NormalZombie.h"
#include"BarricadesZombie.h"
#include"PaperZombie.h"
#include"PolesZombie.h"
#include<vector>
using namespace std;

class ChessBoard
{
public:
	//���캯��
	ChessBoard();
	//��������
	~ChessBoard();
	//����״̬
	bool Update();
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
	Object* GetObject(int r, int c,int i) { return yard[r][c][i]; }
	//�õ�i,j�ؿ�
	int GetPlotSize(int r, int c) { return yard[r][c].size(); }
	//�õ���ǰ���е��ӵ�ָ��
	Bullet* GetBullet(int r, int c) { return bulletyard[r][c]; }
	//������е��ӵ�
	void ClearBullet(int r, int c);
	//�����ǰ���е�Obj
	void ClearObj(int i, int j, int k);
	//���ʱ��
	unsigned int GetTime()const { return timecounter; }
	//��ȡ����
	int GetScore()const { return score; }
private:
	//�鿴��ʬ�Ƿ��ʺ�ǰ��,�����ƶ��ٶ�
	int CheckPos(int r,int c,AbstractZombie* zmb);
	//��ʬ�����ƶ�
	void ZombieMove(int i, int j, int k);
	//�ӵ������ƶ�
	void BulletMove(int i, int j);
	//����һ��ʱ�������ʬ
	void CreateZombie();
	void TimeUp();
	void ScoreUp() { score++; }
	int score;
	unsigned int timecounter;
	//�������
	int maxrow;
	//�������
	int maxcol;
	//������ֱ�ϵĲ��
	int square_height;
	//����ˮƽ�ϵĲ��
	int square_width;
	//�洢�����ϵ�ֲ��ͽ�ʬ
	vector<vector<vector<Object*>>> yard;
	//������һ���ӵ�yard�洢�ӵ�
	vector<vector<Bullet*>> bulletyard;
};

