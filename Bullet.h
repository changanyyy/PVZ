#pragma once

class Bullet
{
public:
	Bullet(int _ATK, int r, int c);
	~Bullet();
	//������
	void SetRow(int r) { row = r; }
	//������
	void SetCol(int c) { col = c; }
	//��������
	void SetRC(int r, int c) { row = r; col = c; }
	//�������
	int GetRow()const { return row; }
	//�������
	int GetCol()const { return col; }
	//�����ٶ�
	void SetSpeed(int sp) { speed = sp; }
	//����ٶ�
	int GetSpeed()const { return speed; }
	//�����˺�ֵ
	void SetATK(int atk) { ATK = atk; }
	//����˺�ֵ
	int GetATK()const { return ATK; }
	void SetIce() { ice = true; }
	bool IsIce() { return ice; }
private:
	//�ӵ��˺�ֵ
	int ATK;
	//�У���
	int row,col;
	//�ӵ��ٶ�
	int speed;
	bool ice;
};