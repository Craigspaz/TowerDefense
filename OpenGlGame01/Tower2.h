#ifndef _TOWER2_H
#define _TOWER2_H
#include "Tower.h"
#include "Texture.h"
#include "Damage.h"
class Tower2 : public Tower
{
public:
	Tower2(int x, int y, Texture* texture, int size,int radius);
	Tower2(int x, int y, Texture* texture, float damage, int type, int size,int radius);
	~Tower2();
	void UpgradeRange();
	void UpgradeDamage();
};

#endif