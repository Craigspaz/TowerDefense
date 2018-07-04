#ifndef _ITEM_H
#define _ITEM_H
#include <iostream>
#include "Texture.h"
#include "GFX.h"
class Item
{
public:
	Item(int x, int y, Texture* texture,int size);
	Item(int x, int y, Texture* texture, int size, int type);
	~Item();
	void draw();
	int getX();
	int getY();
	void setX(int a);
	void setY(int a);
	int getType();
	void setType(int a);
protected:
	int _x;
	int _y;
	Texture* _texture;
	int _size;
	int _type;
};

#endif