#pragma once
#include <cstdlib>
#include <windows.h>
#include"GameWindow.h"
#include"OptionWindow.h"
#include <windows.h>
#include <mmsystem.h>
#pragma comment(lib, "winmm.lib")

class MainWindow
{
public:
	//���캯������ʼ������������
	MainWindow();
	//��������
	~MainWindow();
	//��������ʾ
	void show();
private:
	void PlayMusic();
	//�Ѵ�������չʾ
	void ShowWindowHead();
	//ѡ3���˳�����
	void exitMainWindow();
	//���������
	void WrongInput();
	//game����ָ�룬��С������
	GameWindow* gamewindow;
	//option����ָ��
	OptionWindow* optionwindow;
};

