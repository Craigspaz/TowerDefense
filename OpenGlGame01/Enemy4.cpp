#include "Enemy4.h"


Enemy4::Enemy4(float x, float y, Texture* texture, int size) : Enemy(x, y, 4, Enemy4Damage, Enemy4Health, texture, size)
{

}
void Enemy4::draw()
{
	GFX::drawRect(_size, _size, _x, _y, _texture->getTexture());
}

Enemy4::~Enemy4()
{

}
