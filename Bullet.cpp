#include "Bullet.h"

Bullet::Bullet(int _ATK, int r, int c) {
	speed = 1;//�ӵ��ٶȶ���1
	ATK = _ATK;
	row = r;
	col = c;
	ice = false;
}

Bullet::~Bullet() {

}