#include "UI.h"


//������չʾһЩ������Ϣ
void UI::ShowInfo(ChessBoard* chessbd, PlantShop* pshop) {
	Pos pos = GetPos(ROW_NUM,0);
	set_std_pos(pos.x, pos.y);
	cout << "+----------------------+---------------------+" << endl;
	cout << "|��������|" << pshop->GetSun() << "  |�÷�����|" << chessbd->GetScore() << endl;
	cout << "+----------------------+---------------------+";
}


//�������
void UI::ShowChessboard(ChessBoard* chessbd) {
	ios::sync_with_stdio(false);
	set_std_pos(0, 0);
	for (int i = 0; i < 4; i++) {//�ָ���
		cout << "+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+" << endl;
		if (i != 3) {
			cout << "|        |        |        |        |        |        |        |        |        |        |" << endl;
			cout << "                                                                                           " << endl;
			cout << "|        |        |        |        |        |        |        |        |        |        |" << endl;
		}
	}
	set_std_pos(0, 1);
	Object* obj=nullptr;
	Bullet* blt = nullptr;
	for (int i = 0; i < ROW_NUM; i++) {//��ʾ���ڵ����������
		for (int j = 0; j < COL_NUM; j++) {
			Pos pos = GetPos(i, j);

			set_std_pos(pos.x, pos.y);
			blt = chessbd->GetBullet(i, j);
			if (blt != nullptr) {
				cout << "��";//����ӵ���
			}

			//if (chessbd->GetPlotSize(i, j) == 0) {
			//	continue;
			//	set_std_pos(pos.x, pos.y);
			//	cout << "   "; 
			//}
			for (int k = 0; k < chessbd->GetPlotSize(i,j); k++) {
				obj = nullptr;
				obj = chessbd->GetObject(i, j, k);
				set_std_pos(pos.x - 3, pos.y - 1);
				cout << "" << (100*obj->GetHp()) / obj->GetMaxHp() << "%";
				set_std_pos(pos.x-2, pos.y);
				cout << obj->GetName();//���ֲ��ͽ�ʬ
			}
			
			
		}
	}
	ShowShop();
	hide_std();
}





//��ֲ���UI
void UI::BuyPlant(ChessBoard* chessbd, PlantShop* pshop) {
	//this->ShowShop();
	char ch;
	while (1) {
		if (_kbhit()) {
			ch = _getch();//��ȡ���µİ���
			if(ch>='1'&&ch<='3')break;
		}
		Sleep(200);
	}
	Object* obj = nullptr;
	RCPair rcp(-1,-1);
	bool Success = false;
	rcp=SelectArea(chessbd);
	switch (ch)
	{
	case '1'://̫����
		obj = new SunFlower(10);//hp��10
		if (pshop->CheckEnough(PlantShop::SunFlower_t)) {
			Success=pshop->SettlePlant(obj, chessbd, rcp.row, rcp.col);
			if(Success)pshop->SubSun(PlantShop::SunFlower_t);
			return;
		}
		break;
	case '2'://�㶹����
		obj = new PeaShooter(10);//����Ĭ�ϲ����б���������λ��
		if (pshop->CheckEnough(PlantShop::PeaShooter_t)) {
			Success=pshop->SettlePlant(obj, chessbd, rcp.row, rcp.col);
			if(Success)pshop->SubSun(PlantShop::PeaShooter_t);
			return;
		}
		break;
	case '3'://���ǽ
		obj = new NutWall();
		if (pshop->CheckEnough(PlantShop::NutWall_t)) {
			Success = pshop->SettlePlant(obj, chessbd, rcp.row, rcp.col);
			if (Success)pshop->SubSun(PlantShop::NutWall_t);
			return;
		}
	default:
		BuyPlant(chessbd,pshop);
		break;
	}
	//BuyPlant(chessbd,pshop);
	return;
}




//ѡ��ؿ�
const RCPair UI::SelectArea(ChessBoard* chessbd) {
	RCPair rcp(-1, -1);

	char chInput;//����һ��char�ͱ����洢���°�����ֵ
	int r = 0, c = 1;
	Pos pos = GetPos(r, c);
	set_std_pos(pos.x, pos.y);
	while (1) {
		Sleep(150);
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
				if (judge_pos(r, c - 3)) {
					c-=3;
					pos = GetPos(r, c);
					set_std_pos(pos.x, pos.y);
				}
				break;
			case 77://��
				if (judge_pos(r, c + 3)) {
					c+=3;
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
	set_std_color(FOREGROUND_GREEN);
	set_std_pos(x - 4, y - 2);
	cout << "+--------+";
	set_std_pos(x - 4, y - 1);
	cout << "|";
	set_std_pos(x - 4, y + 1);
	cout << "|";
	set_std_pos(x + 5, y - 1);
	cout << "|";
	set_std_pos(x + 5, y + 1);
	cout << "|";
	set_std_pos(x - 4, y + 2);
	cout << "+--------+";
	reset_std_color();
}

void UI::ShowShop() {
	Pos pos = GetPos(ROW_NUM+1, 0);
	set_std_pos(pos.x, pos.y);
	cout << "��ӭ����ֲ���̵�" << endl;
	cout << "+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+" << endl;
	cout << "|   1    |   2    |   3    |        |        |        |        |        |        |        |" << endl;
	cout << "| ̫���� |�㶹����| ���ǽ |        |        |        |        |        |        |        |" << endl;
	cout << "|  ��75  | ��100  |  ��60  |        |        |        |        |        |        |        |" << endl;
	cout << "+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+" << endl;
}