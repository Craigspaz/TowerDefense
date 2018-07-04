#include "Enemy6.h"


Enemy6::Enemy6(float x, float y, Texture* texture, int size) : Enemy(x, y, 6, Enemy6Damage, Enemy6Health, texture, size)
{

}
void Enemy6::draw()
{
	GFX::drawRect(_size, _size, _x, _y, _texture->getTexture());
}

Enemy6::~Enemy6()
{

}
