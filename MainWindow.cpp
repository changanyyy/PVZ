#include "MainWindow.h"
#include"Config.h"
#include<iostream>
using namespace std;


//���캯��
MainWindow::MainWindow():gamewindow(new GameWindow()),optionwindow(new OptionWindow()) {
	
}

//��������
MainWindow::~MainWindow() {
	delete gamewindow;//����������gamewindow����
	delete optionwindow;//����������optionwindow����
}

//�����ڿ���̨
void MainWindow::show() {
	system("cls");
	ShowWindowHead();
	int n;
	while (cin >> n) {
		switch (n) {
		case 1://��Ϸ����
			gamewindow -> Play();break;
		case 2://��û��ã�
			break;
		case 3://�˳�����
			exitMainWindow();break;
		default://��������
			WrongInput();break;
		}
	}
}

//�������֣���β�ʵ�Ŷ
void MainWindow::PlayMusic() {
	::PlaySound(TEXT("PVZ.wav"), NULL, SND_LOOP);
}


//�˳�����
void MainWindow::exitMainWindow() {
	system("cls");
	cout << "***********************************************" << endl;
	cout << "+           ��л���ʹ�ã��´��ټ�!           +" << endl;
	cout << "***********************************************" << endl;
	cout << endl << endl;
	set_std_color(FOREGROUND_RED|FOREGROUND_GREEN);
	cout << "Game Designed by YXZ from NJUCS19" << endl;
	reset_std_color();
	PlayMusic();
	Sleep(60000);
	exit(1);
}

//չʾ��ͷ
void MainWindow::ShowWindowHead() {
	cout << "***********************************************" << endl;
	cout << "+   Welcome To My PLANTS And ZOMBIES World!   +" << endl;
	cout << "***********************************************" << endl;
	cout << "����ѡ��   1.������Ϸ    2.����    3.�˳���Ϸ" << endl;
}


//������ֵĺ������ʾ������Ϣ��Ȼ��������ʾ
void MainWindow::WrongInput() {
	set_std_color(FOREGROUND_RED);
	cout << "�������˴������֣�����������" << endl;
	reset_std_color();
	Sleep(600);
	show();
}