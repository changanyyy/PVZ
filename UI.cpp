#include "UI.h"


//������չʾһЩ������Ϣ
void UI::ShowInfo(ChessBoard* chessbd, PlantShop* pshop) {
	Pos pos = GetPos(ROW_NUM,0);
	set_std_pos(pos.x, pos.y);
	cout << "��������:" << pshop->GetSun() << "     ";
	cout << "�÷�����:" << chessbd->GetScore() << endl;
}


//�������
void UI::ShowChessboard(ChessBoard* chessbd) {
	ios::sync_with_stdio(false);
	//cin.tie(0);
	for (int i = 0; i < 4; i++) {//�ָ���
		cout << "************************************************************************************************" << endl << endl << endl << endl;
	}
	set_std_pos(0, 1);
	Object* obj=nullptr;
	Bullet* blt = nullptr;
	for (int i = 0; i < ROW_NUM; i++) {//��ʾ���ڵ����������
		for (int j = 0; j < COL_NUM; j++) {
			Pos pos = GetPos(i, j);
			for (int k = 0; k < chessbd->GetPlotSize(i,j); k++) {
				obj = nullptr;
				obj = chessbd->GetObject(i, j, k);
				
				set_std_pos(pos.x, pos.y);
				if (obj != nullptr) {
					cout << obj->GetName();//���ֲ��ͽ�ʬ
				}
				else {
					//cout << "N";
				}
			}
			blt = chessbd->GetBullet(i, j);
			set_std_pos(pos.x, pos.y);
			if (blt != nullptr) {
				cout << "*";//����ӵ���
			}
		}
	}
}





//��ֲ���UI
void UI::BuyPlant(ChessBoard* chessbd, PlantShop* pshop) {
	system("cls");
	this->ShowShop();
	//this->ShowChessboard(chessbd);
	int n = -1;
	cin >> n;
	Object* obj = nullptr;
	RCPair rcp(-1,-1);
	bool Success = false;
	if (Confirm(n)) {//�Ƿ�ȷ�Ϲ���
		rcp=SelectArea(chessbd);
		switch (n)
		{
		case 1://̫����
			obj = new SunFlower(10);//hp��10
			if (pshop->CheckEnough(PlantShop::SunFlower_t)) {
				Success=pshop->SettlePlant(obj, chessbd, rcp.row, rcp.col);
				if(Success)pshop->SubSun(PlantShop::SunFlower_t);
				return;
			}
			break;
		case 2://�㶹����
			obj = new PeaShooter(10);//����Ĭ�ϲ����б���������λ��
			if (pshop->CheckEnough(PlantShop::PeaShooter_t)) {
				Success=pshop->SettlePlant(obj, chessbd, rcp.row, rcp.col);
				if(Success)pshop->SubSun(PlantShop::PeaShooter_t);
				return;
			}
			break;
		default:
			WrongInput();//�������룬��ʾ�����Ϣ�������½���
			BuyPlant(chessbd,pshop);
			break;
		}
	}
	BuyPlant(chessbd,pshop);
	return;
}

//������Ϣ��ʾ
void UI::WrongInput() {
	cout << endl << endl;
	set_std_color(FOREGROUND_RED);
	cout << "Illegal Input������ Please reinput������";
	reset_std_color();
}

//��ʾȷ����Ϣ�����ǲ������Ҫ�����ֲ�
bool UI::Confirm(int n) {
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

//ѡ��ؿ�
const RCPair UI::SelectArea(ChessBoard* chessbd) {
	RCPair rcp(-1, -1);

	char chInput;//����һ��char�ͱ����洢���°�����ֵ
	int r = 0, c = 0;
	Pos pos = GetPos(r, c);
	set_std_pos(pos.x, pos.y);
	while (1) {
		system("cls");
		this->ShowChessboard(chessbd);
		PrintSelectBox(r, c);
		if (_kbhit())//����а�������
		{
			chInput = _getch();//��ȡ���µİ���
			switch (chInput) {//���ݰ��µİ�����������Ӧ�Ĺ���ƶ�
			case 72://��
				if (judge_pos(r - 1, c)) {
					r--;
					pos = GetPos(r, c);
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
				if (judge_pos(r, c - 1)) {
					c--;
					pos = GetPos(r, c);
					set_std_pos(pos.x, pos.y);
				}
				break;
			case 77://��
				if (judge_pos(r, c + 1)) {
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


void UI::PrintSelectBox(int r, int c) {
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


void UI::ShowShop() {
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