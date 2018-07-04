#include "Tower1.h"


Tower1::Tower1(int x, int y, Texture* texture, int size,int radius) : Tower(x, y, texture,Tower1Damage,1, size,radius,32)
{
	
}
Tower1::Tower1(int x, int y, Texture* texture, float damage, int type, int size,int radius) : Tower(x,y,texture,damage,type,size,radius,32)
{

}


Tower1::~Tower1()
{

}

void Tower1::UpgradeDamage()
{
	_damage += 3;
}

void Tower1::UpgradeRange()
{
	_radius += 3;
}
