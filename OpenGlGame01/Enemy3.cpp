#include "Enemy3.h"


Enemy3::Enemy3(float x, float y, Texture* texture, int size) : Enemy(x, y, 3, Enemy3Damage, Enemy3Health, texture, size)
{

}
void Enemy3::draw()
{
	GFX::drawRect(_size, _size, _x, _y, _texture->getTexture());
}

Enemy3::~Enemy3()
{

}
