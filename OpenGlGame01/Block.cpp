#include "Block.h"
#include "AirBlock.h"
#include "DirtBlock.h"
#include "GrassBlock.h"
#include "StoneBlock.h"

Block::Block(float x, float y, Texture* texture,int type)
: _x(x), _y(y), _texture(texture), _type(type)
{
	//primary = glfwGetPrimaryMonitor();
	//mode = glfwGetVideoMode(primary);
	int width = 1366;
	int height = 768;
	std::ifstream file("settings.txt");
	if (file.is_open())
	{
		std::string line;
		int l = 0;
		while (std::getline(file, line))
		{
			if (l == 0)
			{
				width = std::stoi(line);
			}
			if (l == 1)
			{
				height = std::stoi(line);
			}
			l++;
		}
	}
	file.close();
	//int width = mode->width;
	//int height = mode->height;
	double ratio = width / height;
	if (width == 1920)
	{
		_size = 32;
	}
	else if (width == 1366)
	{
		_size = 16;
	}
	else
	{
		_size = 8;
	}

}


Block::~Block()
{
	
}

int Block::getType()
{
	return _type;
}

float Block::getSize()
{
	return _size;
}

float Block::getX()
{
	return _x;
}

float Block::getY()
{
	return _y;
}

void Block::setX(float a)
{
	_x = a;
}

void Block::setY(float a)
{
	_y = a;
}


Texture* Block::getTexture()
{
	return _texture;
}


Block* Block::getBlock(int x, int y,Block** world,int size,Textures* textures)
{
	for (int i = 0; i < size; i++)
	{
		if ((int)world[i]->getX() == x && (int)world[i]->getY() == y)
		{
			if (world[i]->getType() == 0)
			{
				std::cout << "Block got DirtBlock\n";
				return new DirtBlock(x, y, textures->getDirtTexture());
			}
			else if (world[i]->getType() == 1)
			{
				std::cout << "Block got GrassBlock\n";
				return new GrassBlock(x, y, textures->getGrassTopTexture());
			}
			else if (world[i]->getType() == 2)
			{
				std::cout << "Block got AirBlock\n";
				return new AirBlock(x, y, textures->getAirTexture());
			}
			else if (world[i]->getType() == 3)
			{
				std::cout << "Block got StoneBlock\n";
				return new StoneBlock(x, y, textures->getStoneTexture());
			}
		}
	}
}
