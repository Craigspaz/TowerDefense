#include "DirtBlock.h"


DirtBlock::DirtBlock(float x, float y, Texture* texture) : Block(x, y, texture,1)
{

}


DirtBlock::~DirtBlock()
{
}


void DirtBlock::draw()
{
	GFX::drawRect(_size, _size, _x, _y, _texture->getTexture());
}