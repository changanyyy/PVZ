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

void hide_std() {
    HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO CursorInfo;
    GetConsoleCursorInfo(handle, &CursorInfo);//��ȡ����̨�����Ϣ
    CursorInfo.bVisible = false; //���ؿ���̨���
    SetConsoleCursorInfo(handle, &CursorInfo);//���ÿ���̨���״̬

}

//����row��col���x��y
Pos GetPos(int row, int col) { return Pos(1 + col * SQUARE_WIDTH, 2 + row * SQUARE_HEIGHT); }

//�ж��Ƿ񳬽�
bool judge_pos(int row, int col) {
    return (row >= 0 && col >= 0 && row < ROW_NUM&& col < COL_NUM);
}

//�����������Max����������ֵ
int random_num(int Max) {
    srand(time(NULL));
    return rand() % Max;
}

//����ĳ���������������
int random_num_based_seed(int Max, int seed) {
    srand(seed);
    return rand() % Max;
}