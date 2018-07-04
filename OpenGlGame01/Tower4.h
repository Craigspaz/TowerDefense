#ifndef _TOWER4_H
#define _TOWER4_H
#include "Tower.h"
#include "Texture.h"
#include "Damage.h"
class Tower4 : public Tower
{
public:
	Tower4(int x, int y, Texture* texture, int size,int radius);
	Tower4(int x, int y, Texture* texture, float damage, int type, int size,int radius);
	~Tower4();
	void UpgradeRange();
	void UpgradeDamage();
};

#endif