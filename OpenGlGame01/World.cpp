#include "World.h"


World::World(Textures* textures) : _worldSizeX(52), _worldSizeY(28), _textures(textures)
{
	world = new Block*[_worldSizeX * _worldSizeY];
	tempSizeBlock = new DirtBlock(1,1,_textures->getDirtTexture());
	_textureSize = tempSizeBlock->getSize();
	//loadTestWorld();
	delete tempSizeBlock;
	startCounter = 0;
}


void World::loadTestWorld()
{
	int counter = 0;
	for (int x = 0; x < _worldSizeX; x++)
	{
		for (int y = 0; y < _worldSizeY; y++)
		{
			double ran = rand() % 1;
			if (ran == 0)
			{
				world[counter] = new DirtBlock(x * _textureSize, y * _textureSize, _textures->getDirtTexture());
			}
			else 
			{
				world[counter] = new AirBlock(x * _textureSize, y * _textureSize, _textures->getAirTexture());
			}
			counter++;
		}
	}
}


void World::loadWorldFromFile(std::string filename)
{
	std::ifstream file(filename);
	int counter = 0;
	int lineCounter = 0;
	std::string line;
	while (std::getline(file, line))
	{
		std::istringstream buf(line);
		std::istream_iterator<std::string> beg(buf), end;
		std::vector<std::string> tokens(beg, end);
		int colCounter = 0;
		for (auto& s : tokens)
		{
			if (s == "0")
			{
				world[counter] = new GrassBlock(colCounter * _textureSize, lineCounter * _textureSize, _textures->getGrassTopTexture());
				//std::cout << "Add DirtBlock at : (" << colCounter * _textureSize << "," << lineCounter * _textureSize << ")\n";
			}
			else if (s == "1")
			{
				world[counter] = new DirtBlock(colCounter * _textureSize, lineCounter * _textureSize, _textures->getDirtTexture());
				//std::cout << "Add AirBlock at : (" << colCounter * _textureSize << "," << lineCounter * _textureSize << ")\n";
			}
			else if (s == "2")
			{
				world[counter] = new AirBlock(colCounter * _textureSize, lineCounter * _textureSize, _textures->getAirTexture());
				startPointX[startCounter] = colCounter * _textureSize;
				startPointY[startCounter] = lineCounter * _textureSize;
				startCounter++;
			}
			else
			{
				world[counter] = new StoneBlock(colCounter * _textureSize, lineCounter * _textureSize, _textures->getStoneTexture());
			}
			counter++;
			colCounter++;
		}
		//std::cout << "ColCounter : " << colCounter << std::endl;
		lineCounter++;
	}
	//std::cout << "Counter : " << counter << std::endl;
	//std::cout << "LineCounter : " << lineCounter << std::endl;
}

Block** World::getWorld()
{
	return world;
}


World::~World()
{
	delete world;
}


int World::getWorldSizeX()
{
	return _worldSizeX;
}
int World::getWorldSizeY()
{
	return _worldSizeY;
}


int* World::getStartPointX()
{
	return startPointX;
}
int* World::getStartPointY()
{
	return startPointY;
}
int World::getStartCounter()
{
	return startCounter;
}


