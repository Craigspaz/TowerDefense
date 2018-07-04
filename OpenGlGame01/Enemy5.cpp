#include "Enemy5.h"


Enemy5::Enemy5(float x, float y, Texture* texture, int size) : Enemy(x, y, 5, Enemy5Damage, Enemy5Health, texture, size)
{

}
void Enemy5::draw()
{
	GFX::drawRect(_size, _size, _x, _y, _texture->getTexture());
}

Enemy5::~Enemy5()
{

}
