#include "StoneBlock.h"

StoneBlock::StoneBlock(float x, float y, Texture* texture) : Block(x, y, texture,3)
{

}
StoneBlock::~StoneBlock()
{

}
void StoneBlock::draw()
{
	GFX::drawRect(_size, _size, _x, _y, _texture->getTexture());
}
