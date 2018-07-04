#include "AirBlock.h"


AirBlock::AirBlock(float x, float y, Texture* texture) : Block(x,y,texture,2)
{

}


AirBlock::~AirBlock()
{

}

void AirBlock::draw()
{
	GFX::drawRect(_size, _size, _x, _y, _texture->getTexture());
}