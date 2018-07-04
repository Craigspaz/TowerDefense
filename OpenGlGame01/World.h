#ifndef _WORLD_H
#define _WORLD_H
#include <iostream>
#include <vector>
#include "Block.h"
#include "AirBlock.h"
#include "DirtBlock.h"
#include "GrassBlock.h"
#include "StoneBlock.h"
#include <sstream>
#include <string>
#include <fstream>
class World
{
public:
	World(Textures* textures);
	void loadTestWorld();
	void loadWorldFromFile(std::string filename);
	~World();
	Block** getWorld();
	int getWorldSizeX();
	int getWorldSizeY();

	int* getStartPointX();
	int* getStartPointY();
	int getStartCounter();
private:
	Block** world;
	int _worldSizeX;
	int _worldSizeY;
	Textures* _textures;
	float _textureSize;
	Block* tempSizeBlock;
	int startPointX[32];
	int startPointY[32];
	int startCounter;
};

#endif