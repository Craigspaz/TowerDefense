#include "Enemy1.h"


Enemy1::Enemy1(float x, float y, Texture* texture,int size) : Enemy(x,y,1,Enemy1Damage,Enemy1Health,texture,size)
{

}
void Enemy1::draw()
{
	GFX::drawRect(_size, _size, _x, _y, _texture->getTexture());
}

Enemy1::~Enemy1()
{

}
