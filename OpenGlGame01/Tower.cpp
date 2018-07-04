#include "Tower.h"


Tower::Tower(int x, int y, Texture* texture, int size, int radius, int reloadSpeed) : Item(x, y, texture, size), _damage(10), _fire(false), _radius(radius), _reloadSpeed(reloadSpeed), _upgradeRangeLevel(0), _upgradeDamageLevel(0)
{

}

Tower::Tower(int x, int y, Texture* texture, float damage, int type, int size, int radius, int reloadSpeed) : Item(x, y, texture, size, type), _damage(damage), canAttack(true), firableCounter(0), _fire(false), _radius(radius), _reloadSpeed(reloadSpeed), _upgradeRangeLevel(0), _upgradeDamageLevel(0)
{

}


Tower::~Tower()
{

}

void Tower::addKill()
{
	_kills++;
}


float Tower::getDamage()
{
	return _damage;
}
int Tower::getKills()
{
	return _kills;
}

bool Tower::isFireable()
{
	return canAttack;
}
void Tower::setFirable(bool a)
{
	canAttack = a;
}
void Tower::reloadTower()
{
	if (firableCounter >= _reloadSpeed)
	{
		std::cout << "FireCounter is at " << _reloadSpeed << std::endl;
		canAttack = true;
		firableCounter = 0;
	}
	else
	{
		canAttack = false;
		firableCounter += 1;
	}
}

void Tower::fire(int x, int y, int xx, int yy, Texture* texture)
{
	_fire = true;
	canAttack = false;
	sx = x;
	sy = y;
	ex = xx;
	ey = yy;
	e = texture;
}

bool Tower::getFire()
{
	return _fire;
}


void Tower::setFire(bool a)
{
	_fire = a;
}


void Tower::drawFire()
{
	GFX::drawLine((float)sx, (float)sy, (float)ex, (float)ey, e->getTexture());
	GFX::drawLine((float)sx + 1, (float)sy, (float)ex + 1, (float)ey, e->getTexture());
	GFX::drawLine((float)sx, (float)sy + 1, (float)ex, (float)ey + 1, e->getTexture());
	GFX::drawLine((float)sx - 1, (float)sy, (float)ex - 1, (float)ey, e->getTexture());
	GFX::drawLine((float)sx, (float)sy - 1, (float)ex, (float)ey - 1, e->getTexture());
	GFX::drawLine((float)sx + 2, (float)sy, (float)ex + 2, (float)ey, e->getTexture());
	GFX::drawLine((float)sx, (float)sy + 2, (float)ex, (float)ey + 2, e->getTexture());
	GFX::drawLine((float)sx - 2, (float)sy, (float)ex - 2, (float)ey, e->getTexture());
	GFX::drawLine((float)sx, (float)sy - 2, (float)ex, (float)ey - 2, e->getTexture());
	//GFX::drawRect(32, 2, (float)sx, (float)sy, e->getTexture());
}



int Tower::getRadius()
{
	return _radius;
}
void Tower::setRadius(int r)
{
	_radius = r;
}


int Tower::getUpgradeRangeLevel()
{
	return _upgradeRangeLevel;
}
int Tower::getUpgradeDamageLevel()
{
	return _upgradeDamageLevel;
}

void Tower::setUpgradeRangeLevel(int a)
{
	_upgradeRangeLevel = a;
	if (_type == 1)
	{
		_radius += Tower1RadiusUpgrade;
	}
	else if (_type == 2)
	{
		_radius += Tower2RadiusUpgrade;
	}
	else if (_type == 3)
	{
		_radius += Tower3RadiusUpgrade;
	}
	else if (_type == 4)
	{
		_radius += Tower4RadiusUpgrade;
	}
}
void Tower::setUpgradeDamageLevel(int a)
{
	_upgradeDamageLevel = a;
	if (_type == 1)
	{
		_damage += Tower1DamageUpgrade;
	}
	else if (_type == 2)
	{
		_damage += Tower2DamageUpgrade;
	}
	else if (_type == 3)
	{
		_damage += Tower3DamageUpgrade;
	}
	else if (_type == 4)
	{
		_damage += Tower4DamageUpgrade;
	}
}