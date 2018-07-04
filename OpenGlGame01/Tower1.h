#ifndef _TOWER1_H
#define _TOWER1_H
#include "Tower.h"
#include "Damage.h"
#include "Texture.h"
class Tower1 : public Tower
{
public:
	Tower1(int x, int y, Texture* texture, int size,int radius);
	Tower1(int x, int y, Texture* texture, float damage, int type, int size,int radius);
	~Tower1();
	void UpgradeRange();
	void UpgradeDamage();
};

#endif