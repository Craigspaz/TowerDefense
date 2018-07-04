#include "Tower3.h"


Tower3::Tower3(int x, int y, Texture* texture, int size,int radius) : Tower(x,y,texture,Tower3Damage,3,size,radius,50)
{

}
Tower3::Tower3(int x, int y, Texture* texture, float damage, int type, int size,int radius) : Tower(x,y,texture,damage,type,size,radius,50)
{

}


Tower3::~Tower3()
{
}

void Tower3::UpgradeDamage()
{
	_damage += 3;
}

void Tower3::UpgradeRange()
{
	_radius += 3;
}