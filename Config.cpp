#include"Config.h"

void set_std_color(int color) {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);;
    SetConsoleTextAttribute(hConsole, color);
}

void reset_std_color() {
    set_std_color(FOREGROUND_BLUE | FOREGROUND_RED | FOREGROUND_GREEN);
}


void set_std_pos(int x, int y)
{
    HANDLE winHandle;//���
    COORD pos = { x,y };
    winHandle = GetStdHandle(STD_OUTPUT_HANDLE);
    //���ù��λ�� 
    SetConsoleCursorPosition(winHandle, pos);
}