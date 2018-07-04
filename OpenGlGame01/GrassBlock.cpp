#include "GrassBlock.h"


GrassBlock::GrassBlock(float x, float y, Texture* texture) : Block(x, y, texture,0)
{

}


GrassBlock::~GrassBlock()
{
}


void GrassBlock::draw()
{
	GFX::drawRect(_size, _size, _x, _y, _texture->getTexture());
}