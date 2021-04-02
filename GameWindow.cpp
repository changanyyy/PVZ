#include "GameWindow.h"
#include<conio.h>


//���캯��
GameWindow::GameWindow()
	:
	chessbd(new ChessBoard()),
	gamectrl(new GameControl()),
	shop(new Shop())
{

}

//��������
GameWindow::~GameWindow() {
	delete chessbd;
	delete gamectrl;
	delete shop;
}

//��Ϸ������ͨ��һ��ѭ����ÿ�θ������̺�ˢ����Ļ
void GameWindow::Play() {
	while (1) {
		if (_kbhit()) {
			if (_getch() == 'b') {
				shop->BuyPlant(chessbd);
			}
		}
		this->Update();
		this->Show();
		Sleep(200);//ÿ��0.5��ˢ��һ��
	}
}

//���º���������gamectrl������chessbd
void GameWindow::Update() {
	gamectrl->UpdateChessbd(chessbd);//��ֲ���Object״̬���и���
	chessbd->Update();//���̵����ݽ��и���
}

//ˢ����Ļ
void GameWindow::Show() {
	system("cls");
	chessbd->Show();//������ʾ
}