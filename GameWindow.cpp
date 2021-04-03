#include "GameWindow.h"
#include<conio.h>


//���캯��
GameWindow::GameWindow()
	:
	chessbd(new ChessBoard()),
	gamectrl(new GameControl()),
	pshop(new PlantShop()),
	ui(new UI())

{

}

//��������
GameWindow::~GameWindow() {
	//�ֱ�����
	delete chessbd;
	delete gamectrl;
	delete pshop;
	delete ui;
}

//��Ϸ������ͨ��һ��ѭ����ÿ�θ������̺�ˢ����Ļ
void GameWindow::Play() {
	while (1) {
		if (_kbhit()) {
			if (_getch() == 'b') {
				ui->BuyPlant(chessbd, pshop);
			}
		}
		this->Update();
		this->Show();
		Sleep(500);//ÿ��0.5��ˢ��һ��
	}
}

//���º���������gamectrl������chessbd
void GameWindow::Update() {
	gamectrl->UpdateChessbd(chessbd,pshop);//��ֲ���Object״̬���и���
	bool flag = chessbd->Update();//���̵����ݽ��и���
	if (!flag)GameOver();
}

//ˢ����Ļ
void GameWindow::Show() {
	system("cls");
	//chessbd->Show();//������ʾ
	ui->ShowChessboard(chessbd);
	ui->ShowInfo(chessbd, pshop);
}


//��Ϸ����
void GameWindow::GameOver() {
	system("cls");
	cout << "***********************************************" << endl;
	cout << "+            ��ʬ����������ӣ�����           +" << endl;
	cout << "+                ��Ϸ����������               +" << endl;
	cout << "***********************************************" << endl;
	cout << endl << endl;
	set_std_color(FOREGROUND_RED | FOREGROUND_GREEN);
	cout << "Game Designed by YXZ from NJUCS19" << endl;
	reset_std_color();
	PlayMusic();
	Sleep(60000);
	exit(1);
}

//�������֣���β�ʵ�Ŷ
void GameWindow::PlayMusic() {
	::PlaySound(TEXT("PVZ.wav"), NULL, SND_LOOP);
}
