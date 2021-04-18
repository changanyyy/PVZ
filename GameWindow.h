#pragma once
#include"ChessBoard.h"
#include"GameControl.h"
#include"PlantShop.h"
#include"UI.h"
#include<Windows.h>
#include<iostream>

using namespace std;
class GameWindow
{
public:
	//���캯��
	GameWindow();
	//��������
	~GameWindow();
	//��Ϸ������ͨ��һ��ѭ����ÿ�θ������̺�ˢ����Ļ
	void Play();
	//���º���������gamectrl������chessbd
	void Update();
	//ˢ����Ļ
	void Show();
	void Pause();
	void GameOver();
	void PlayMusic();
private:
	GameControl* gamectrl;
	ChessBoard* chessbd;
	PlantShop* pshop;
	UI* ui;
};