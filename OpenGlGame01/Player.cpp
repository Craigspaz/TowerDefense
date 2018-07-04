#include "Player.h"


Player::Player(int health, int money) : _health(health), _money(money), _itemSelected(false), _item(nullptr)
{

}


Player::~Player()
{

}
int Player::getHealth()
{
	return _health;
}
int Player::getMoney()
{
	return _money;
}
bool Player::isItemSelected()
{
	if (_item == nullptr || _item == NULL)
	{
		return false;
	}
	return true;
}

void Player::draw()
{
	_item->draw();
}
Item* Player::getItemSelected()
{
	return _item;
}
void Player::setItemSelected(Item* item)
{
	_item = item;
}

void Player::removeSelectedItem()
{
	_item = nullptr;
}


void Player::setHealth(int a)
{
	_health = a;
}
void Player::setMoney(int a)
{
	_money = a;
}