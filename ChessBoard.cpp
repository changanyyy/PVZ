#include "ChessBoard.h"
#include"Config.h"


//���캯��
ChessBoard::ChessBoard()
	://��ʼ���б� һЩ��������
	row_num(ROW_NUM), //����
	col_num(COL_NUM), //����
	square_height(SQUARE_HEIGHT),//������ֱ���
	square_width(SQUARE_WIDTH)//����ˮƽ���
{
	for (int i = 0; i < row_num; i++) {//�����������ʼ��
		vector<Object*> row;
		vec.push_back(row);
		for (int j = 0; j < col_num; j++) {
			//��ʼӦ��ȫ��nullptr
			Object* p = nullptr;
			//Object* p = new Object(0,100);//*********************************************************
			vec[i].push_back(p);
		}
	}
}
//����
ChessBoard::~ChessBoard() {
	for (int i = 0; i < row_num; i++) {//�ͷ�����ֲ��ͽ�ʬ�Ŀռ�
		for (int j = 0; j < col_num; j++) {
			if (vec[i][j] != nullptr) {
				delete vec[i][j];
			}
		}
	}
}

//��ʾ����
void ChessBoard::Show() {
	for (int i = 0; i < 4; i++) {//�ָ���
		cout << "*****************************************************************************"<<endl<<endl<<endl;
	}
	Update();//����״̬
	set_std_pos(0, 1);
	for (int i = 0; i < row_num; i++) {//��ʾ���ڵ����������
		for (int j = 0; j < col_num; j++) {
			set_std_pos(j * square_width,2+ i * square_height);
			if (vec[i][j] != nullptr) {
				cout<<vec[i][j]->GetName();
			}
			else {
				cout << "None";
			}
		}
	}
}
//����״̬
void ChessBoard::Update() {
	for (int i = 0; i < row_num; i++) {
		for (int j = 0; j < col_num; j++) {
			set_std_pos(i * square_height, j * square_width);
			if (vec[i][j] != nullptr) {
				if (vec[i][j]->GetStatus() == Object::Dead) {
					Object* del = vec[i][j];
					vec[i][j] = nullptr;
					delete[] del;
				}
			}
		}
	}
}
