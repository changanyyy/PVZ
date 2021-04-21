#include "AbstractZombie.h"


//构造函数
AbstractZombie::AbstractZombie(int hp, int r,int gap)
	:
	//设置基类构造函数
	//僵尸从来都在最后一列出现！所以僵尸初始化时候没有把列作为参数
	Object(hp, hp, r, COL_NUM-2 ),
	movegap(gap)
{
	mytype = Object::Zombie_t;
	speeddown = false;
}

//析构函数
AbstractZombie::~AbstractZombie() {
}