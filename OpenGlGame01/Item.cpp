#include "Item.h"


Item::Item(int x, int y, Texture* texture, int size) : _x(x), _y(y), _texture(texture), _size(size)
{

}


Item::Item(int x, int y, Texture* texture, int size, int type) :_x(x), _y(y), _texture(texture), _size(size), _type(type)
{

}
Item::~Item()
{

}

void Item::draw()
{
	GFX::drawRect(_size, _size, _x * _size, _y * _size, _texture->getTexture());
}


int Item::getX()
{
	return _x;
}
int Item::getY()
{
	return _y;
}
void Item::setX(int a)
{
	_x = a;
}
void Item::setY(int a)
{
	_y = a;
}


int Item::getType()
{
	return _type;
}
void Item::setType(int a)
{
	_type = a;
}
