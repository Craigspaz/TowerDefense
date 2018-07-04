#ifndef _STONEBLOCK_H
#define _STONEBLOCK_H
#include "Block.h"
#include "GFX.h"
class StoneBlock : public Block
{
public:
	StoneBlock(float x, float y, Texture* texture);
	~StoneBlock();
	void draw();
};

#endif