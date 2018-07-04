#include "Tower4.h"


Tower4::Tower4(int x, int y, Texture* texture, int size,int radius) : Tower(x, y, texture, Tower4Damage, 4, size,radius,128)
{

}
Tower4::Tower4(int x, int y, Texture* texture, float damage, int type, int size,int radius) : Tower(x, y, texture, damage, type, size,radius,128)
{

}


Tower4::~Tower4()
{
}

void Tower4::UpgradeDamage()
{
	_damage += 3;
}

void Tower4::UpgradeRange()
{
	_radius += 3;
}
