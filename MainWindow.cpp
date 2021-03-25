#include "MainWindow.h"
#include"Config.h"
#include<iostream>
using namespace std;

MainWindow::MainWindow():gamewindow(new GameWindow()),optionwindow(new OptionWindow()) {
	
}
MainWindow::~MainWindow() {
	delete gamewindow;
	delete optionwindow;
}

void MainWindow::show() {
	system("cls");
	cout << "***********************************************" << endl;
	cout << "+   Welcome To My PLANTS And ZOMBIES World!   +" << endl;
	cout << "***********************************************" << endl;
	cout << "����ѡ��   1.������Ϸ    2.����    3.�˳���Ϸ" << endl;
	int n;
	
	while (cin >> n) {
		switch (n) {
		case 1:
			gamewindow -> Show();
			break;
		case 2:

			break;
		case 3:
			exitMainWindow();
			break;
		default:
			set_std_color(FOREGROUND_RED);
			cout << "�������˴������֣�����������" << endl;
			reset_std_color();
			Sleep(600);
			show();
			break;
		}
	}
}


void MainWindow::exitMainWindow() {
	system("cls");
	cout << "***********************************************" << endl;
	cout << "+           ��л���ʹ�ã��´��ټ�!           +" << endl;
	cout << "***********************************************" << endl;
	cout << endl << endl;
	set_std_color(FOREGROUND_RED|FOREGROUND_GREEN);
	cout << "Game Designed by YXZ from NJUCS19" << endl;
	reset_std_color();
	Sleep(2000);
	exit(1);
}