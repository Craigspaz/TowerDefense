#include "Enemy7.h"


Enemy7::Enemy7(float x, float y, Texture* texture, int size) : Enemy(x, y, 7, Enemy7Damage, Enemy7Health, texture, size)
{

}
void Enemy7::draw()
{
	GFX::drawRect(_size, _size, _x, _y, _texture->getTexture());
}

Enemy7::~Enemy7()
{

}
