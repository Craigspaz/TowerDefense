#include "Enemy8.h"


Enemy8::Enemy8(float x, float y, Texture* texture, int size) : Enemy(x, y, 8, Enemy8Damage, Enemy8Health, texture, size)
{

}
void Enemy8::draw()
{
	GFX::drawRect(_size, _size, _x, _y, _texture->getTexture());
}

Enemy8::~Enemy8()
{

}
