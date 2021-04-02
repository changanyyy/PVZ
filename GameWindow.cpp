#include "GameWindow.h"
#include<conio.h>


//构造函数
GameWindow::GameWindow()
	:
	chessbd(new ChessBoard()),
	gamectrl(new GameControl()),
	shop(new Shop())
{

}

//析构函数
GameWindow::~GameWindow() {
	delete chessbd;
	delete gamectrl;
	delete shop;
}

//游戏函数，通过一个循环，每次更新棋盘和刷新屏幕
void GameWindow::Play() {
	while (1) {
		if (_kbhit()) {
			if (_getch() == 'b') {
				shop->BuyPlant(chessbd);
			}
		}
		this->Update();
		this->Show();
		Sleep(500);//每隔0.5秒刷新一次
	}
}

//更新函数，利用gamectrl来控制chessbd
void GameWindow::Update() {
	gamectrl->UpdateChessbd(chessbd);//对植物等Object状态进行更新
	bool flag = chessbd->Update();//棋盘的内容进行更新
	if (!flag)GameOver();
}

//刷新屏幕
void GameWindow::Show() {
	system("cls");
	chessbd->Show();//棋盘显示
}


//游戏结束
void GameWindow::GameOver() {
	system("cls");
	cout << "***********************************************" << endl;
	cout << "+            僵尸吃了你的脑子！！！           +" << endl;
	cout << "+                游戏结束！！！               +" << endl;
	cout << "***********************************************" << endl;
	cout << endl << endl;
	set_std_color(FOREGROUND_RED | FOREGROUND_GREEN);
	cout << "Game Designed by YXZ from NJUCS19" << endl;
	reset_std_color();
	PlayMusic();
	Sleep(60000);
	exit(1);
}

//播放音乐！结尾彩蛋哦
void GameWindow::PlayMusic() {
	::PlaySound(TEXT("PVZ.wav"), NULL, SND_LOOP);
}
