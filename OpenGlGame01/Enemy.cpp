#include "Enemy.h"


Enemy::Enemy(float x, float y, int type, int damage, int health, Texture* texture, int size) :
_x(x),
_y(y),
_type(type),
_damage(damage),
_health(health),
_texture(texture),
_size(size),
_isAlive(true),
_up(false),
_down(false),
_left(false),
_right(false)
{
	previousDirection = 5;
}
void Enemy::setX(float a)
{
	_x = a;
}
void Enemy::setY(float a)
{
	_y = a;
}
void Enemy::setType(int a)
{
	_type = a;
}
void Enemy::setDamage(int a)
{
	_damage = a;
}
void Enemy::setHealth(int a)
{
	_health = a;
}
void Enemy::setIsAlive(bool a)
{
	_isAlive = a;
}
float Enemy::getX()
{
	return _x;
}
float Enemy::getY()
{
	return _y;
}
int Enemy::getType()
{
	return _type;
}
int Enemy::getDamage()
{
	return _damage;
}
int Enemy::getHealth()
{
	return _health;
}
bool Enemy::isAlive(){
	return _isAlive;
}

Enemy::~Enemy()
{
}


Texture* Enemy::getTexture()
{
	return _texture;
}
void Enemy::setTexture(Texture* texture)
{
	_texture = texture;
}

int Enemy::getPreviousDirection()
{
	return previousDirection;
}
void Enemy::setPreviousDirection(int a)
{
	previousDirection = a;
}


bool Enemy::isUp()
{
	return _up;
}
bool Enemy::isDown()
{
	return _down;
}
bool Enemy::isLeft()
{
	return _left;
}
bool Enemy::isRight()
{
	return _right;
}
void Enemy::setUp(bool a)
{
	_up = a;
}
void Enemy::setDown(bool a)
{
	_down = a;
}
void Enemy::setLeft(bool a)
{
	_left = a;
}
void Enemy::setRight(bool a)
{
	_right = a;
}
