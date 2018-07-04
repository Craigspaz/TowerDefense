#ifndef _TOWER_H
#define _TOWER_H
#include "Item.h"
#include "GFX.h"
#include "Damage.h"
#include "Radius.h"
class Tower : public Item
{
public:
	Tower(int x, int y, Texture* texture,int size,int radius,int reloadSpead);
	Tower(int x, int y, Texture* texture, float damage,int type,int size,int radius,int reloadSpeed);
	~Tower();
	virtual void UpgradeRange() = 0;
	virtual void UpgradeDamage() = 0;
	float getDamage();
	int getKills();
	int getUpgradeRangeLevel();
	int getUpgradeDamageLevel();
	bool isFireable();
	void setFirable(bool a);
	void reloadTower();
	void fire(int x, int y, int xx, int yy, Texture* texture);
	bool getFire();
	void setFire(bool a);
	void drawFire();
	int getRadius();
	void setRadius(int r);
	void addKill();
	void setUpgradeRangeLevel(int a);
	void setUpgradeDamageLevel(int a);

protected:
	float _damage;
	int _radius;
private:
	int _kills;
	int _upgradeRangeLevel;
	int _upgradeDamageLevel;
	int _size;
	bool canAttack;
	float firableCounter;
		
	bool _fire;

	int sx;
	int sy;
	int ex;
	int ey;
	Texture* e; 

	int _reloadSpeed;

};

#endif