#ifndef _DIRTBLOCK_H
#define _DIRTBLOCK_H
#include "Texture.h"
#include "Block.h"
#include "GFX.h"
class DirtBlock : public Block
{
public:
	DirtBlock(float x, float y, Texture* texture);
	~DirtBlock();
	void draw();
};

#endif