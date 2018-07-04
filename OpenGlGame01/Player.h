#ifndef _PLAYER_H
#define _PLAYER_H
#include "Item.h"
class Player
{
public:
	Player(int health, int money);
	~Player();

	int getHealth();
	int getMoney();
	void setHealth(int a);
	void setMoney(int a);
	bool isItemSelected();
	Item* getItemSelected();
	void setItemSelected(Item* item);
	void draw();
	void removeSelectedItem();
private:
	int _health;
	int _money;
	bool _itemSelected;
	Item* _item;
};

#endif