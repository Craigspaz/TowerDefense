#include "Enemy2.h"


Enemy2::Enemy2(float x, float y, Texture* texture, int size) : Enemy(x, y, 2, Enemy2Damage, Enemy2Health, texture, size)
{

}
void Enemy2::draw()
{
	GFX::drawRect(_size, _size, _x, _y, _texture->getTexture());
}

Enemy2::~Enemy2()
{

}
