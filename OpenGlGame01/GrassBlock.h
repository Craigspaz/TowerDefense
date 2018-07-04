#ifndef _GRASSBLOCK_H
#define _GRASSBLOCK_H
#include "Texture.h"
#include "Block.h"
#include "GFX.h"
class GrassBlock : public Block
{
public:
	GrassBlock(float x, float y, Texture* texture);
	~GrassBlock();
	void draw();
};

#endif