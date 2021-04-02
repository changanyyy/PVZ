#include"Config.h"

//���������ɫ
void set_std_color(int color) {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);;
    SetConsoleTextAttribute(hConsole, color);
}

//���������ɫ
void reset_std_color() {
    set_std_color(FOREGROUND_BLUE | FOREGROUND_RED | FOREGROUND_GREEN);
}

//���ù��λ��
void set_std_pos(int x, int y)
{
    HANDLE winHandle;//���
    COORD pos = { x,y };
    winHandle = GetStdHandle(STD_OUTPUT_HANDLE);
    //���ù��λ�� 
    SetConsoleCursorPosition(winHandle, pos);
}

//����row��col���x��y
Pos GetPos(int row, int col) { return Pos(col * SQUARE_WIDTH, 2 + row * SQUARE_HEIGHT); }

//�ж��Ƿ񳬽�
bool judge_pos(int row, int col) {
    return (row >= 0 && col >= 0 && row < ROW_NUM&& col < COL_NUM);
}