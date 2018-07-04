#ifndef _BLOCK_H
#define _BLOCK_H
#include <iostream>
#include <fstream>
#include "Texture.h"
#include "Textures.h"
#include <GLFW\glfw3.h>
#include <vector>
class Block
{
public:
	Block(float x, float y,Texture* texture,int type);
	~Block();

	virtual void draw() = 0;

	float getX();
	float getY();
	void setX(float a);
	void setY(float a);
	int getType();
	Texture* getTexture();
	float getSize();
	static Block* getBlock(int x, int y,Block** world,int size,Textures* textures);
protected:
	float _x, _y;
	Texture* _texture;
	float _size; 

private:
	GLFWmonitor* primary;
	const GLFWvidmode* mode;
	int _type;
};

#endif