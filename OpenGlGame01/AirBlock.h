#ifndef _AIRBLOCK_H
#define _AIRBLOCK_H
#include "Block.h"
#include "GFX.h"

class AirBlock : public Block
{
public:
	AirBlock(float x, float y, Texture* texture);
	~AirBlock();
	void draw();
};

#endif