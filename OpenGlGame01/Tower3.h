#ifndef _TOWER3_H
#define _TOWER3_H
#include "Tower.h"
#include "Texture.h"
#include "Damage.h"
class Tower3 : public Tower
{
public:
	Tower3(int x, int y, Texture* texture, int size,int radius);
	Tower3(int x, int y, Texture* texture, float damage, int type, int size,int radius);
	~Tower3();
	void UpgradeRange();
	void UpgradeDamage();
};

#endif