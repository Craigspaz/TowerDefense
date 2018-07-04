#include "Tower2.h"


Tower2::Tower2(int x, int y, Texture* texture, int size,int radius) : Tower(x,y,texture,Tower2Damage,2,size,radius,64)
{

}
Tower2::Tower2(int x, int y, Texture* texture, float damage, int type, int size,int radius) : Tower(x,y,texture,damage,type,size,radius,64)
{

}

Tower2::~Tower2()
{
}

void Tower2::UpgradeDamage()
{
	_damage += 3;
}

void Tower2::UpgradeRange()
{
	_radius += 3;
}
