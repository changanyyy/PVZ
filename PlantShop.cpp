#include "PlantShop.h"
#include<conio.h>


//���캯��
PlantShop::PlantShop() {
	sun = INIT_SUN;
}

//��������
PlantShop::~PlantShop() {

}



//����ֲ�����ѡ��ؿ�֮���
bool PlantShop::SettlePlant(Object* obj, ChessBoard* chessbd,int r,int c) {
	return chessbd->AddPlant(static_cast<AbstractPlant*>(obj), r, c);
}

