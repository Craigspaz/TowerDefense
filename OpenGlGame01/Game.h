#ifndef _GAME_H
#define _GAME_H
#include <iostream>
#include <fstream>
#include "dirent.h"
#include <stdio.h>
#include <string>
#include <GLFW\glfw3.h>
#include <stdio.h>
#include <cstdlib>
#include <string.h>
#include <fstream>
#include "Keyboard.h"
#include "Texture.h"
#include "Textures.h"
#include "GFX.h"
#include "Block.h"
#include "AirBlock.h"
#include "Mouse.h"
#include "World.h"
#include "Player.h"
#include "Tower.h"
#include "Tower1.h"
#include "Tower2.h"
#include "Tower3.h"
#include "Tower4.h"
#include "Waves.h"
#include "Cost.h"
#include "Radius.h"
#include "KillPoints.h"
class Game
{
public:
	Game(int width,int height);

	void update();
	void render();
	~Game();

private:
	int _width;
	int _height;
	Keyboard* _keyboard;
	Mouse* _mouse;
	Block* testBlock;
	Player* player;

	Textures* textures;
	Block** world;
	int worldSize;
	enum State {MAIN_MENU, GAME,OPTIONS, PAUSE_MENU,CHOOSE_LEVEL};
	State state;
	World* worldLoader;

	Waves* wave;
	Enemy** enemies;
	std::vector<Enemy*>* enemiesInWorld;
	int enemiesLoadingIndex;
	int enemyLoadingCounter;


	Tower** _towers;
	Tower* _upgradeTower;
	int upgradeTowerIndex;
	int currentTowersIndex;

	int textureWidth;
	int textureHeight;


	bool isWaveRunning;
	bool hoverOverPlayButton_Main_Menu;
	bool hoverOverExitButton_Main_Menu;
	bool hoverOverExitButton_Pause_Menu;
	bool hoverOverWaveStartButton_Game;
	bool hoverOverResumeButton_Pause_Menu;

	bool overTower1;
	bool overTower2;
	bool overTower3;
	bool overTower4;

	std::string levelList[256];
	bool hoverList[256];
	int levelListCounter;

	int gameLoopIndex;
};

#endif