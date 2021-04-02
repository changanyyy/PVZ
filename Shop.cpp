#include "Shop.h"
#include<conio.h>


//���캯��
Shop::Shop() {

}

//��������
Shop::~Shop() {

}

//�����߼�����
void Shop::BuyPlant(ChessBoard* chessbd) {
	this->Show();
	int n = -1;
	cin >> n;
	Object* obj = nullptr;
	if (Confirm(n)) {//�Ƿ�ȷ�Ϲ���
		switch (n)
		{
		case 1://̫����
			obj = new SunFlower(10);//hp��10
			SettlePlant(obj, chessbd);
			break;
		case 2://�㶹����
			obj = new PeaShooter(10);//����Ĭ�ϲ����б���������λ��
			SettlePlant(obj, chessbd);
			break;
		default:
			WrongInput();//�������룬��ʾ�����Ϣ�������½���
			BuyPlant(chessbd);
			break;
		}
	}
	else {
		BuyPlant(chessbd);
		return;
	}
	
}

//���ͷ
void Shop::Show() {
	system("cls");
	cout << "************************************" << endl;
	cout << "      Welcome to Plant Shop!!!      " << endl;
	cout << "************************************" << endl;
	cout << "You can buy any plant if you have enough money!" << endl;
	cout << "The optional plants are as follows <^*^>" << endl;
	cout << "1.SunFlower" << " "
		 << "2.PeaShooter" << " "
		 << endl;
	cout << "Please input your choice:";
}

//������Ϣ��ʾ
void Shop::WrongInput() {
	cout << endl << endl;
	set_std_color(FOREGROUND_RED);
	cout << "Illegal Input������ Please reinput������";
	reset_std_color();
}

//��ʾȷ����Ϣ�����ǲ������Ҫ�����ֲ�
bool Shop::Confirm(int n) {
	string plantname;
	switch (n)
	{
	case 1: plantname = "SunFlower"; break;
	case 2: plantname = "PeaShooter"; break;
	default: break;
	}
	cout << "Are you sure to buy No." << n << " " << plantname << "��" << endl;
	cout << "Input ��y�� or ��n�� ��";
	string a;
	cin >> a;
	if (a == "y")return true;
	else return false;
}

//����ֲ�����ѡ��ؿ�֮���
void Shop::SettlePlant(Object* obj, ChessBoard* chessbd) {
	RCPair rcp=SelectArea(chessbd);
	bool flag = chessbd->AddPlant(static_cast<AbstractPlant*>(obj), rcp.row, rcp.col);
	if (!flag) {//������Ų��˵Ļ���˵������rc��ռ���ˣ�����Ҫ����ѡ��
		cout << "Position Occupied��Reselect��" << endl;
		SettlePlant(obj, chessbd);
	}
	return;
}

//ѡ��ؿ�
const RCPair Shop::SelectArea(ChessBoard* chessbd) {
	RCPair rcp(-1,-1);

	char chInput;//����һ��char�ͱ����洢���°�����ֵ
	int r=0, c=0;
	Pos pos = GetPos(r, c);
	set_std_pos(pos.x, pos.y);
	while (1) {
		system("cls");
		chessbd->Show();
		PrintSelectBox(r, c);
		if (_kbhit())//����а�������
		{
			chInput = _getch();//��ȡ���µİ���
			switch (chInput) {//���ݰ��µİ�����������Ӧ�Ĺ���ƶ�
			case 72://��
				if (judge_pos(r - 1, c)) {
					r--;
					pos = GetPos(r , c);
					set_std_pos(pos.x, pos.y);
				}
				break;
			case 80://��
				if (judge_pos(r + 1, c)) {
					r++;
					pos = GetPos(r, c);
					set_std_pos(pos.x, pos.y);
				}
				break;
			case 75://��
				if (judge_pos(r , c-1)) {
					c--;
					pos = GetPos(r, c);
					set_std_pos(pos.x, pos.y);
				}
				break;
			case 77://��
				if (judge_pos(r , c+1)) {
					c++;
					pos = GetPos(r, c);
					set_std_pos(pos.x, pos.y);
				}
				break;
			case 13://�س�����ʾȷ��,ֱ�ӷ���
				return RCPair(r, c);
				break;
			default:
				break;
			}
		}
	}
	
}


void Shop::PrintSelectBox(int r, int c) {
	Pos pos = GetPos(r, c);
	int x = pos.x, y = pos.y;
	set_std_color(FOREGROUND_RED);
	set_std_pos(x - 1, y - 1);
	cout << "###";
	set_std_pos(x - 1, y);
	cout << "#";
	set_std_pos(x + 1, y);
	cout << "#";
	set_std_pos(x - 1, y + 1);
	cout << "###";
	reset_std_color();
}