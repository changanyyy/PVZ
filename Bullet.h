#pragma once



class Bullet
{

public:
	Bullet(int _ATK, int r, int c);
	~Bullet();
	//�����˺�ֵ
	void SetATK(int atk) { ATK = atk; }
	//������
	void SetRow(int r) { row = r; }
	//������
	void SetCol(int c) { col = c; }
	//�����ٶ�
	void SetSpeed(int sp) { speed = sp; }
	//����˺�ֵ
	int GetATK()const { return ATK; }
	//�������
	int GetRow()const { return row; }
	//�������
	int GetCol()const { return col; }
	//����ٶ�
	int GetSpeed()const { return speed; }

private:
	//�ӵ��˺�ֵ
	int ATK;
	//�У���
	int row,col;
	//�ӵ��ٶ�
	int speed;
};

