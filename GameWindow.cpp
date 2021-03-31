#include "GameWindow.h"

//���캯��
GameWindow::GameWindow():chessbd(new ChessBoard()),gamectrl(new GameControl()) {

}

//��������
GameWindow::~GameWindow() {
	delete chessbd;
	delete gamectrl;
}

//��Ϸ������ͨ��һ��ѭ����ÿ�θ������̺�ˢ����Ļ
void GameWindow::Play() {
	while (1) {
		this->Update();
		this->Show();
		Sleep(500);//ÿ��0.5��ˢ��һ��
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