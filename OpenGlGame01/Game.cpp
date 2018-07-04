#include "Game.h"
#include <thread>
#include <chrono>


Game::Game(int width, int height) :
_width(width), _height(height),
_keyboard(&Keyboard::getKeyboard()),
_mouse(&Mouse::getMouse()),
state(MAIN_MENU),
isWaveRunning(false),
hoverOverExitButton_Main_Menu(false),
hoverOverExitButton_Pause_Menu(false),
hoverOverPlayButton_Main_Menu(false),
hoverOverWaveStartButton_Game(false),
textureWidth(256),
textureHeight(64),
hoverOverResumeButton_Pause_Menu(false),
currentTowersIndex(0),
overTower1(false),
overTower2(false),
overTower3(false),
overTower4(false),
levelListCounter(0),
enemiesLoadingIndex(0),
enemyLoadingCounter(0),
gameLoopIndex(0),
upgradeTowerIndex(-1)
{
	if (_width == 1920)
	{
		textureWidth = 512;
	}
	if (_height == 1080)
	{
		textureHeight = 128;
	}
	for (int i = 0; i < 256; i++)
	{
		hoverList[i] = false;
	}
	textures = new Textures();
	worldLoader = new World(textures);
	player = new Player(100, 50);
	testBlock = new AirBlock(300,100,textures->getTower1Texture());
	worldSize = worldLoader->getWorldSizeX() * worldLoader->getWorldSizeY();
	_towers = new Tower*[worldLoader->getWorldSizeX() * worldLoader->getWorldSizeY()];
	enemiesInWorld = new std::vector<Enemy*>();
	_upgradeTower = nullptr;
	//create levelList
	DIR* dir;
	struct dirent *ent;
	if ((dir = opendir(".\\level\\")) != NULL)
	{
		int i = 0;
		while ((ent = readdir(dir)) != NULL)
		{
			if (ent->d_name != "." && ent->d_name != "..")
			{
				std::string finalString = ent->d_name;
				
				levelList[i] = finalString;
				levelListCounter++;
				i++;
			}
		}
		closedir(dir);
	}
	else
	{
		perror("Could not find Levels!\n");
		exit(EXIT_FAILURE);
	}
	
}


Game::~Game()
{
	delete world;
	_keyboard->destroyKeyboard();
	_mouse->destroyMouse();
	delete worldLoader;
}
void Game::update()
{
	if (state == MAIN_MENU)
	{
		if (_mouse->getX() > _width / 2 - (textureWidth / 2) && _mouse->getX() < _width / 2 + (textureWidth / 2) && _mouse->getY() > _height / 3 - (textureHeight / 2) && _mouse->getY() < _height / 3 + (textureHeight / 2))
		{
			hoverOverPlayButton_Main_Menu = true;
			if (_mouse->getMouseState(GLFW_MOUSE_BUTTON_1) == true)
			{
				std::cout << "Play Button Pressed\n";
				std::this_thread::sleep_for(std::chrono::milliseconds(500));
				hoverOverPlayButton_Main_Menu = false;
				hoverOverExitButton_Main_Menu = false;
				hoverOverExitButton_Pause_Menu = false;
				hoverOverWaveStartButton_Game = false;
				hoverOverResumeButton_Pause_Menu = false;
				state = CHOOSE_LEVEL;
			}
		}
		else
		{
			hoverOverPlayButton_Main_Menu = false;
		}
		if (_mouse->getX() > _width / 2 - (textureWidth / 2) && _mouse->getX() < _width / 2 + (textureWidth / 2) && _mouse->getY() > 2 * _height / 3 - (textureHeight / 2) && _mouse->getY() < 2 * _height / 3 + (textureHeight / 2))
		{
			hoverOverExitButton_Main_Menu = true;
			if (_mouse->getMouseState(GLFW_MOUSE_BUTTON_1) == true)
			{
				std::cout << "Exit Button Pressed\n";
				hoverOverPlayButton_Main_Menu = false;
				hoverOverExitButton_Main_Menu = false;
				hoverOverExitButton_Pause_Menu = false;
				hoverOverWaveStartButton_Game = false;
				hoverOverResumeButton_Pause_Menu = false;
				exit(0);
			}
		}
		else
		{
			hoverOverExitButton_Main_Menu = false;
		}

		if (_mouse->getX() > 0 && _mouse->getX() < testBlock->getSize() * 2 && _mouse->getY() > 0 && _mouse->getY() < testBlock->getSize() * 2 && _mouse->getMouseState(GLFW_MOUSE_BUTTON_1) == true)
		{
			state = OPTIONS;
		}
	}
	else if (state == GAME)
	{

		if (_mouse->getX() > (worldLoader->getWorldSizeX()) * testBlock->getSize() && _mouse->getX() < (worldLoader->getWorldSizeX()) * testBlock->getSize() + testBlock->getSize() && _mouse->getY() > 75 && _mouse->getY() < 75 + testBlock->getSize() && !isWaveRunning)
		{
			hoverOverWaveStartButton_Game = true;
			if (_mouse->getMouseState(GLFW_MOUSE_BUTTON_1) == true)
			{
				gameLoopIndex = 0;
				enemiesLoadingIndex = 0;
				enemyLoadingCounter = 0;
				enemies = wave->loadCurrentWave();
				isWaveRunning = true;
				std::this_thread::sleep_for(std::chrono::milliseconds(500));
			}
		}
		else
		{
			hoverOverWaveStartButton_Game = false;
		}

		for (int i = 0; i < currentTowersIndex; i++)
		{
			if (_mouse->getMouseState(GLFW_MOUSE_BUTTON_1) == true && _mouse->getX() > _towers[i]->getX() * testBlock->getSize() && _mouse->getX() < _towers[i]->getX() * testBlock->getSize() + testBlock->getSize() && _mouse->getY() > _towers[i]->getY() * testBlock->getSize() && _mouse->getY() < _towers[i]->getY() * testBlock->getSize() + testBlock->getSize())
			{
				_upgradeTower = _towers[i];
				upgradeTowerIndex = i;
			}
		}


		if (isWaveRunning)
		{
			if (enemyLoadingCounter >= 30)
			{
				if (enemiesLoadingIndex < wave->getCurrentWaveEnemiesNumber())
				{
					(enemiesInWorld)->push_back(enemies[enemiesLoadingIndex]);
					std::cout << "Enemy added!\n";
					enemiesLoadingIndex++;
				}
				enemyLoadingCounter = 0;
			}
			else
			{
				enemyLoadingCounter++;
			}
			if (enemiesInWorld->empty() == true && gameLoopIndex >= 60)
			{
				isWaveRunning = false;
				wave->incrementWave();
			}
			if (gameLoopIndex >= 60)
			{
				gameLoopIndex = 0;
			}
			//PreviousDirection left = 0, up = 1, right = 2, down = 3
			float waveSpeed = wave->getWaveSpeed();
			int i = 0;
			for (std::vector<Enemy*>::iterator iterator = enemiesInWorld->begin(); iterator != enemiesInWorld->end(); iterator++)
			{
				Enemy* e = enemiesInWorld->at(i);
				int x = (int)((e->getX() / testBlock->getSize()));
				int y = (int)((e->getY() / testBlock->getSize()));
				//std::cout << "EnemyX : " << x << std::endl;
				//std::cout << "EnemyY : " << y << std::endl;
				Block* down = new GrassBlock(0,0,textures->getAirTexture());
				Block* up = new GrassBlock(0, 0, textures->getAirTexture());
				Block* right = new GrassBlock(0, 0, textures->getAirTexture());
				Block* left = new GrassBlock(0, 0, textures->getAirTexture());
				Block* currentBlock = new GrassBlock(0, 0, textures->getAirTexture());
				for (int ix = 0; ix < worldSize; ix++)
				{
					int worldX = (int)world[ix]->getX() / testBlock->getSize();
					int worldY = (int)world[ix]->getY() / testBlock->getSize();
					if (((int)(e->getX() / testBlock->getSize())) == worldX && ((int)((e->getY() / testBlock->getSize()) - 0.015)) == worldY){
						up = world[ix];
						//System.out.println("BlockUP: at " + x + ", " + y + ", Type = " + blockUp.getType());
					}
					if (((int)(e->getX() / testBlock->getSize())) == worldX && ((int)((e->getY() / testBlock->getSize())) + 1) == worldY){
						down = world[ix];
						//System.out.println("BlockDown: at " + x + ", " + y + ", Type = " + blockDown.getType());
					}
					if (((int)((e->getX() / testBlock->getSize()) + 1)) == worldX && ((int)(e->getY() / testBlock->getSize())) == worldY){
						right = world[ix];
						//System.out.println("BlockRight: at " + x + ", " + y + ", Type = " + blockRight.getType());
					}
					if (((int)((e->getX() / testBlock->getSize()) - 0.015)) == worldX && ((int)(e->getY() / testBlock->getSize())) == worldY){
						left = world[ix];
						//System.out.println("BlockLeft: at " + x + ", " + y + ", Type = " + blockLeft.getType());
					}
					if (((int)(e->getX() / testBlock->getSize())) == worldX && ((int)(e->getY() / testBlock->getSize())) == worldY){
						currentBlock = world[ix];
					}
					
				}

				if (e->isUp() == false && e->isLeft() == false && e->isRight() == false && (down->getType() != 0) && e->getPreviousDirection() != 0){
					e->setY(e->getY() + waveSpeed);
					//System.out.println("Down");
					e->setDown(true);
					e->setPreviousDirection(1);
				}
				else if (e->isDown() == false && e->isLeft() == false && e->isRight() == false && (up->getType() != 0) && e->getPreviousDirection() != 1){
					e->setY(e->getY() - waveSpeed);
					//System.out.println("Up");
					e->setUp(true);
					e->setPreviousDirection(0);
				}
				else if (e->isLeft() == false && e->isUp() == false && e->isDown() == false && (right->getType() != 0) && e->getPreviousDirection() != 2){
					e->setX(e->getX() + waveSpeed);
					//System.out.println(e.getX());
					//System.out.println("Right");
					e->setRight(true);
					e->setPreviousDirection(3);
				}
				else if (e->isRight() == false && e->isDown() == false && e->isUp() == false && (left->getType() != 0) && e->getPreviousDirection() != 3){
					e->setX(e->getX() - waveSpeed);
					//System.out.println("Left");
					e->setLeft(true);
					e->setPreviousDirection(2);
				}
				else{
					e->setUp(false);
					e->setDown(false);
					e->setLeft(false);
					e->setRight(false);
				}
				if (currentBlock->getType() == 3){
					if (e->getType() == 1){
						player->setHealth(player->getHealth() - e->getDamage());
						e->setIsAlive(false);
					}
					else if (e->getType() == 2){
						player->setHealth(player->getHealth() - e->getDamage());
						e->setIsAlive(false);
					}
					else if (e->getType() == 3){
						player->setHealth(player->getHealth() - e->getDamage());
						e->setIsAlive(false);
					}
					else if (e->getType() == 4){
						player->setHealth(player->getHealth() - e->getDamage());
						e->setIsAlive(false);
					}
					else if (e->getType() == 5){
						player->setHealth(player->getHealth() - e->getDamage());
						e->setIsAlive(false);
					}
					else if (e->getType() == 6){
						player->setHealth(player->getHealth() - e->getDamage());
						e->setIsAlive(false);
					}
					else if (e->getType() == 7){
						player->setHealth(player->getHealth() - e->getDamage());
						e->setIsAlive(false);
					}
					else if (e->getType() == 8){
						player->setHealth(player->getHealth() - e->getDamage());
						e->setIsAlive(false);
					}
				}
				i++;
			}
			enemiesInWorld->shrink_to_fit();
			int xi = 0;
			for (std::vector<Enemy*>::iterator iterator = enemiesInWorld->begin(); iterator != enemiesInWorld->end();)
			{
				if ((*iterator)->isAlive() == false)
				{
					{
						*(&iterator) = enemiesInWorld->erase(enemiesInWorld->begin() + xi);
						std::cout << "Deleting Enemy\n";
						break;
					}
				}
				++xi;
				++iterator;
			}
			int ix = 0;
			bool breakOut = false;
			for (int i = 0; i < currentTowersIndex; i++)
			{
				if (_towers[i]->getFire() == true)
				{
					_towers[i]->setFire(false);
					_towers[i]->setFirable(false);
				}
				if (_towers[i]->isFireable() == false)
				{
					_towers[i]->reloadTower();
				}
				
				for (std::vector<Enemy*>::iterator iterator = enemiesInWorld->begin(); iterator != enemiesInWorld->end();)
				{
					Enemy* enemy = (*iterator);
					int currentTowerX = _towers[i]->getX() * testBlock->getSize();
					int currentTowerY = _towers[i]->getY() * testBlock->getSize();
					int enemyX = enemy->getX();
					int enemyY = enemy->getY();

					int centerX = currentTowerX + (testBlock->getSize() / 2);
					int centerY = currentTowerY + (testBlock->getSize() / 2);

					int radius = _towers[i]->getRadius() * testBlock->getSize();

					if (centerX - radius < enemyX && centerX + radius > enemyX && centerY - radius < enemyY && centerY + radius > enemyY && _towers[i]->isFireable())
					{
						_towers[i]->fire(centerX, centerY, (enemyX+(testBlock->getSize()/2)), (enemyY+(testBlock->getSize()/2)), textures->getLaserTexture());
						if (_towers[i]->getType() == 1)
						{
							enemy->setHealth(enemy->getHealth() - Tower1Damage);
						}
						else if (_towers[i]->getType() == 2)
						{
							enemy->setHealth(enemy->getHealth() - Tower2Damage);
						}
						else if (_towers[i]->getType() == 3)
						{
							enemy->setHealth(enemy->getHealth() - Tower3Damage);
						}
						else if (_towers[i]->getType() == 4)
						{
							enemy->setHealth(enemy->getHealth() - Tower4Damage);
						}
						if (enemy->getHealth() <= 0)
						{
							_towers[i]->addKill();
							enemy->setIsAlive(false); 
							if (_towers[i]->getType() == 1)
							{
								player->setMoney(player->getMoney() + Enemy1Points);
							}
							else if (_towers[i]->getType() == 2)
							{
								player->setMoney(player->getMoney() + Enemy1Points);
							}
							else if (_towers[i]->getType() == 3)
							{
								player->setMoney(player->getMoney() + Enemy1Points);
							}
							else if (_towers[i]->getType() == 4)
							{
								player->setMoney(player->getMoney() + Enemy1Points);
							}
						}
						break;
					}
					ix++;
					++iterator;
				}
				if (breakOut)
				{
					break;
				}
			}
			gameLoopIndex++;
		}
		
		


		if (_mouse->getX() > worldLoader->getWorldSizeX() * testBlock->getSize() && _mouse->getX() < (worldLoader->getWorldSizeX() * testBlock->getSize()) + testBlock->getSize() && _mouse->getY() > 6 * testBlock->getSize() + testBlock->getSize() && _mouse->getY() < 6 * testBlock->getSize() + (testBlock->getSize() * 2) && !player->isItemSelected())
		{
			overTower1 = true;
			overTower2 = false;
			overTower3 = false;
			overTower4 = false;
			if (_mouse->getMouseState(GLFW_MOUSE_BUTTON_1) == true)
			{
				//std::this_thread::sleep_for(std::chrono::milliseconds(500));
				Tower1* tower = new Tower1(_mouse->getX() / testBlock->getSize(), _mouse->getY() / testBlock->getSize(),textures->getTower1Texture(), testBlock->getSize(),Tower1Radius);
				player->setItemSelected(tower);
			}
		}
		else if (_mouse->getX() > worldLoader->getWorldSizeX() * testBlock->getSize() && _mouse->getX() < (worldLoader->getWorldSizeX() * testBlock->getSize()) + testBlock->getSize() && _mouse->getY() > 6 * testBlock->getSize() + testBlock->getSize() * 2 && _mouse->getY() < ((6 * testBlock->getSize()) + ((3 * testBlock->getSize()))) && !player->isItemSelected())
		{
			overTower1 = false;
			overTower2 = true;
			overTower3 = false;
			overTower4 = false;
			if (_mouse->getMouseState(GLFW_MOUSE_BUTTON_1) == true)
			{
				//std::this_thread::sleep_for(std::chrono::milliseconds(500));
				Tower2* tower = new Tower2(_mouse->getX() / testBlock->getSize(), _mouse->getY() / testBlock->getSize(), textures->getTower2Texture(), testBlock->getSize(), Tower2Radius);
				player->setItemSelected(tower);
			}
		}
		else if (_mouse->getX() > worldLoader->getWorldSizeX() * testBlock->getSize() && _mouse->getX() < (worldLoader->getWorldSizeX() * testBlock->getSize()) + testBlock->getSize() && _mouse->getY() > 6 * testBlock->getSize() + testBlock->getSize() * 3 && _mouse->getY() < ((6 * testBlock->getSize()) + ((testBlock->getSize()) * 4)) && !player->isItemSelected())
		{
			overTower1 = false;
			overTower2 = false;
			overTower3 = true;
			overTower4 = false;
			if (_mouse->getMouseState(GLFW_MOUSE_BUTTON_1) == true)
			{
				//std::this_thread::sleep_for(std::chrono::milliseconds(500));
				Tower3* tower = new Tower3(_mouse->getX() / testBlock->getSize(), _mouse->getY() / testBlock->getSize(), textures->getTower3Texture(), testBlock->getSize(), Tower3Radius);
				player->setItemSelected(tower);
			}
		}
		else if (_mouse->getX() > worldLoader->getWorldSizeX() * testBlock->getSize() && _mouse->getX() < (worldLoader->getWorldSizeX() * testBlock->getSize()) + testBlock->getSize() && _mouse->getY() > 6 * testBlock->getSize() + testBlock->getSize() * 4 && _mouse->getY() < ((6 * testBlock->getSize()) + ((testBlock->getSize()) * 5)) && !player->isItemSelected())
		{
			overTower1 = false;
			overTower2 = false;
			overTower3 = false;
			overTower4 = true;
			if (_mouse->getMouseState(GLFW_MOUSE_BUTTON_1) == true)
			{
				//std::this_thread::sleep_for(std::chrono::milliseconds(500));
				Tower4* tower = new Tower4(_mouse->getX() / testBlock->getSize(), _mouse->getY() / testBlock->getSize(), textures->getTower4Texture(), testBlock->getSize(), Tower4Radius);
				player->setItemSelected(tower);
			}
		}
		else
		{
			overTower1 = false;
			overTower2 = false;
			overTower3 = false;
			overTower4 = false;
		}
		if (_mouse->getX() > worldLoader->getWorldSizeX() * testBlock->getSize() && _mouse->getX() < (worldLoader->getWorldSizeX() * testBlock->getSize()) + testBlock->getSize() && _mouse->getY() > 6 * testBlock->getSize() + testBlock->getSize() * 6 && _mouse->getY() < ((6 * testBlock->getSize()) + ((testBlock->getSize()) * 7)) && player->isItemSelected())
		{
			if (_mouse->getMouseState(GLFW_MOUSE_BUTTON_1) == true)
			{
				//std::this_thread::sleep_for(std::chrono::milliseconds(500));
				player->removeSelectedItem();
			}
		}
		
		if (player->isItemSelected())
		{
			player->getItemSelected()->setX(_mouse->getX() / testBlock->getSize());
			player->getItemSelected()->setY(_mouse->getY() / testBlock->getSize());
			//std::cout << _mouse->getX() / testBlock->getSize() << std::endl;
			if (_mouse->getMouseState(GLFW_MOUSE_BUTTON_1))
			{
				bool isTowerThere = false;
				for (int i = 0; i < currentTowersIndex; i++)
				{
					int x = (int)_towers[i]->getX();
					int y = (int)_towers[i]->getY();
					if (x == (int)(_mouse->getX() / testBlock->getSize()) && y == (int)(_mouse->getY() / testBlock->getSize()))
					{
						isTowerThere = true;
					}
				}
				bool isPlaceableThere = false;
				for (int i = 0; i < worldSize;i++)
				{
					if ((int)(_mouse->getX() / testBlock->getSize()) == (int)(world[i]->getX() / testBlock->getSize()) && (int)(_mouse->getY() / testBlock->getSize()) == (int)(world[i]->getY() / testBlock->getSize()))
					{
						if (world[i]->getType() == 0)
						{
							isPlaceableThere = true;
						}
						else{
							isPlaceableThere = false;
						}
					}
				}
				int type = player->getItemSelected()->getType();
				if (_mouse->getX() / testBlock->getSize() < worldLoader->getWorldSizeX() && _mouse->getY() / testBlock->getSize() < worldLoader->getWorldSizeY() && _mouse->getX() >= 0 && _mouse->getY() >= 0 && !isTowerThere && isPlaceableThere)
				{
					int type = player->getItemSelected()->getType();
					if (type == 1 && player->getMoney() - Tower1Cost >= 0)
					{
						_towers[currentTowersIndex] = new Tower1(_mouse->getX() / testBlock->getSize(), _mouse->getY() / testBlock->getSize(), textures->getTower1Texture(), testBlock->getSize(), Tower1Radius);
						currentTowersIndex++;
						player->removeSelectedItem();
						player->setMoney(player->getMoney() - Tower1Cost);
					}
					else if (type == 2 && player->getMoney() - Tower2Cost >= 0)
					{
						_towers[currentTowersIndex] = new Tower2(_mouse->getX() / testBlock->getSize(), _mouse->getY() / testBlock->getSize(), textures->getTower2Texture(), testBlock->getSize(), Tower2Radius);
						currentTowersIndex++;
						player->removeSelectedItem();
						player->setMoney(player->getMoney() - Tower2Cost);
					}
					else if (type == 3 && player->getMoney() - Tower2Cost >= 0)
					{
						_towers[currentTowersIndex] = new Tower3(_mouse->getX() / testBlock->getSize(), _mouse->getY() / testBlock->getSize(), textures->getTower3Texture(), testBlock->getSize(), Tower3Radius);
						currentTowersIndex++;
						player->removeSelectedItem();
						player->setMoney(player->getMoney() - Tower3Cost);
					}
					else if (type == 4 && player->getMoney() - Tower4Cost >= 0)
					{
						_towers[currentTowersIndex] = new Tower4(_mouse->getX() / testBlock->getSize(), _mouse->getY() / testBlock->getSize(), textures->getTower4Texture(), testBlock->getSize(), Tower4Radius);
						currentTowersIndex++;
						player->removeSelectedItem();
						player->setMoney(player->getMoney() - Tower4Cost);
					}
				}
			}
		}
		
		if (_keyboard->getKeyState(GLFW_KEY_ESCAPE))
		{
			std::this_thread::sleep_for(std::chrono::milliseconds(500));
			state = PAUSE_MENU;
			std::cout << "Open Pause Menu\n";
		}
	}
	else if (state == CHOOSE_LEVEL)
	{
		for (int i = 0; i < levelListCounter; i++)
		{
			if (_mouse->getY() > i * testBlock->getSize() - 24 && _mouse->getY() < (i * testBlock->getSize()))
			{
				hoverList[i] = true;
				if (_mouse->getMouseState(GLFW_MOUSE_BUTTON_1) == true)
				{
					std::cout << "Loading Level...\n";
					std::string level = levelList[i];
					if (level == "." || level == "..")
					{
						hoverList[i] = false;
					}
					else
					{
						worldLoader->loadWorldFromFile("level/" + level);
						world = worldLoader->getWorld();
						wave = new Waves(worldLoader->getStartPointX(), worldLoader->getStartPointY(), worldLoader->getStartCounter(), textures, testBlock->getSize());
						state = GAME;
					}
				}
			}
			else
			{
				hoverList[i] = false;
			}
		}
	}
	else if (state == OPTIONS)
	{
		if (_mouse->getX() > 0 && _mouse->getX() < testBlock->getSize() * 6)
		{
			if (_mouse->getY() > testBlock->getSize() * 2 && _mouse->getY() < testBlock->getSize() * 4 && _mouse->getMouseState(GLFW_MOUSE_BUTTON_1))
			{
				std::ofstream file;
				file.open("settings.txt");
				file << "1366\n";
				file << "768\n";
				file.close();
				GFX::drawString(_width / 2, _height / 2, "You must restart to take effect!", 1.0f, 1.0f, 1.0f);
			}
			else if (_mouse->getY() > testBlock->getSize() * 4 && _mouse->getY() < testBlock->getSize() * 6 && _mouse->getMouseState(GLFW_MOUSE_BUTTON_1))
			{
				std::ofstream file;
				file.open("settings.txt");
				file << "1920\n";
				file << "1080\n";
				file.close();
				GFX::drawString(_width / 2, _height / 2, "You must restart to take effect!", 1.0f, 1.0f, 1.0f);
			}
		}
	}
	else if (state == PAUSE_MENU)
	{
		if (_mouse->getX() > 0 && _mouse->getX() < testBlock->getSize() * 2 && _mouse->getY() > 0 && _mouse->getY() < testBlock->getSize() * 2 && _mouse->getMouseState(GLFW_MOUSE_BUTTON_1) == true)
		{
			state = OPTIONS;
		}
		if (_mouse->getX() > _width / 2 - (textureWidth / 2) && _mouse->getX() < _width / 2 + (textureWidth / 2) && _mouse->getY() > _height / 3 - (textureHeight / 2) && _mouse->getY() < _height / 3 + (textureHeight / 2))
		{
			hoverOverResumeButton_Pause_Menu = true;
			if (_mouse->getMouseState(GLFW_MOUSE_BUTTON_1) == true)
			{
				std::this_thread::sleep_for(std::chrono::milliseconds(500));
				hoverOverPlayButton_Main_Menu = false;
				hoverOverExitButton_Main_Menu = false;
				hoverOverExitButton_Pause_Menu = false;
				hoverOverWaveStartButton_Game = false;
				hoverOverResumeButton_Pause_Menu = false;
				state = GAME;
				std::cout << "Resume Clicked\n";
			}
		}
		else
		{
			hoverOverResumeButton_Pause_Menu = false;
		}
		if (_mouse->getX() > _width / 2 - (textureWidth / 2) && _mouse->getX() < _width / 2 + (textureWidth / 2) && _mouse->getY() > 2 * _height / 3 - (textureHeight / 2) && _mouse->getY() < 2 * _height / 3 + (textureHeight / 2))
		{
			hoverOverExitButton_Pause_Menu = true;
			if (_mouse->getMouseState(GLFW_MOUSE_BUTTON_1) == true)
			{
				std::this_thread::sleep_for(std::chrono::milliseconds(500));
				hoverOverPlayButton_Main_Menu = false;
				hoverOverExitButton_Main_Menu = false;
				hoverOverExitButton_Pause_Menu = false;
				hoverOverWaveStartButton_Game = false;
				hoverOverResumeButton_Pause_Menu = false;
				state = MAIN_MENU;
				std::cout << "Exit Clicked\n";
			}
		}
		else
		{
			hoverOverExitButton_Pause_Menu = false;
		}
		//if (_keyboard->getKeyState(GLFW_KEY_ESCAPE))
		//{
		//	std::this_thread::sleep_for(std::chrono::milliseconds(500));
		//	std::cout << "Open Game\n";
		//	state = GAME;
		//}
	}

	if (_keyboard->getKeyState(GLFW_KEY_1))
	{
		exit(0);
	}
}

void Game::render()
{
	if (state == MAIN_MENU)
	{
		GFX::drawRect(_width, _height, 0, 0, textures->getBackgroundTestTexture()->getTexture());
		GFX::drawRect(textureWidth, textureHeight, _width / 2 - (textureWidth / 2), _height / 3 - (textureHeight / 2), textures->getPlayFirstTexture()->getTexture());
		if (hoverOverPlayButton_Main_Menu)
		{
			GFX::drawRect(textureWidth, textureHeight, _width / 2 - (textureWidth / 2), _height / 3 - (textureHeight / 2), textures->getPlaySecondTexture()->getTexture());
		}
		GFX::drawRect(textureWidth, textureHeight, _width / 2 - (textureWidth / 2), 2 * _height / 3 - (textureHeight / 2), textures->getExitFirstTexture()->getTexture());
		if (hoverOverExitButton_Main_Menu)
		{
			GFX::drawRect(textureWidth, textureHeight, _width / 2 - (textureWidth / 2), 2 * _height / 3 - (textureHeight / 2), textures->getExitSecondTexture()->getTexture());
		}
		GFX::drawRect(testBlock->getSize() * 2, testBlock->getSize() * 2, 0.0f, 0.0f, textures->getSettings()->getTexture());
	}
	else if (state == GAME)
	{
		for (int i = 0; i < worldSize; i++)
		{
			world[i]->draw();
		}
		if (upgradeTowerIndex != -1){
			std::cout << "Displaying upgrade!\n";
			if (_towers[upgradeTowerIndex]->getType() == 1){
				if (_towers[upgradeTowerIndex]->getUpgradeRangeLevel() == 1)
				{
					GFX::drawRect(testBlock->getSize() * 4, testBlock->getSize() * 2, testBlock->getSize() * 3, worldLoader->getWorldSizeY() * testBlock->getSize() + testBlock->getSize(), textures->getUpgradeRange2Texture()->getTexture());
					GFX::drawString(testBlock->getSize() * 3, worldLoader->getWorldSizeY() * testBlock->getSize() + testBlock->getSize() * 4, "Purchased!", 1.0f, 1.0f, 1.0f);
				}
				else
				{
					GFX::drawRect(testBlock->getSize() * 4, testBlock->getSize() * 2, testBlock->getSize() * 3, worldLoader->getWorldSizeY() * testBlock->getSize() + testBlock->getSize(), textures->getUpgradeRangeTexture()->getTexture());
					char temp[32];
					sprintf(temp, "%d", Tower1UpgradeRange);
					char cost[64] = "Cost: ";
					strcat(cost, temp);
					GFX::drawString(testBlock->getSize() * 3, worldLoader->getWorldSizeY() * testBlock->getSize() + testBlock->getSize() * 4, cost, 1.0f, 1.0f, 1.0f);
					if (_mouse->getX() > testBlock->getSize() * 3 && _mouse->getX() < testBlock->getSize() * 3 + testBlock->getSize() * 4 && _mouse->getY() > (worldLoader->getWorldSizeY() * testBlock->getSize() + testBlock->getSize()) && _mouse->getY() <  worldLoader->getWorldSizeY() * testBlock->getSize() + testBlock->getSize() * 4 && _mouse->getMouseState(GLFW_MOUSE_BUTTON_1) == true && player->getMoney() >= Tower1UpgradeRange)
					{
						player->setMoney(player->getMoney() - Tower1UpgradeRange);
						_towers[upgradeTowerIndex]->setUpgradeRangeLevel(1);
					}
				}
				if (_towers[upgradeTowerIndex]->getUpgradeDamageLevel() == 1)
				{
					GFX::drawRect(testBlock->getSize() * 4, testBlock->getSize() * 2, testBlock->getSize() * 8, worldLoader->getWorldSizeY() * testBlock->getSize() + testBlock->getSize(), textures->getUpgradeDamage2Texture()->getTexture()); 
					GFX::drawString(testBlock->getSize() * 8, worldLoader->getWorldSizeY() * testBlock->getSize() + testBlock->getSize() * 4, "Purchased!", 1.0f, 1.0f, 1.0f);
				}
				else
				{
					GFX::drawRect(testBlock->getSize() * 4, testBlock->getSize() * 2, testBlock->getSize() * 8, worldLoader->getWorldSizeY() * testBlock->getSize() + testBlock->getSize(), textures->getUpgradeDamageTexture()->getTexture());
					char temp[32];
					sprintf(temp, "%d", Tower1UpgradeDamage);
					char cost[64] = "Cost: ";
					strcat(cost, temp);
					GFX::drawString(testBlock->getSize() * 8, worldLoader->getWorldSizeY() * testBlock->getSize() + testBlock->getSize() * 4, cost, 1.0f, 1.0f, 1.0f);
					if (_mouse->getX() > testBlock->getSize() * 8 && _mouse->getX() < testBlock->getSize() * 8 + testBlock->getSize() * 4 && _mouse->getY() > (worldLoader->getWorldSizeY() * testBlock->getSize() + testBlock->getSize()) && _mouse->getY() <  worldLoader->getWorldSizeY() * testBlock->getSize() + testBlock->getSize() * 4 && _mouse->getMouseState(GLFW_MOUSE_BUTTON_1) == true && player->getMoney() >= Tower1UpgradeDamage)
					{
						player->setMoney(player->getMoney() - Tower1UpgradeDamage);
						_towers[upgradeTowerIndex]->setUpgradeDamageLevel(1);
					}
				}
				
				char temp[32];
				sprintf(temp, "%d", _towers[upgradeTowerIndex]->getKills());
				char kills[128] = "Kills: ";
				strcat(kills, temp);
				GFX::drawString(testBlock->getSize(), worldLoader->getWorldSizeY() * testBlock->getSize() + testBlock->getSize(), kills, 1.0f, 1.0f, 1.0f);
				GFX::drawCircle((_towers[upgradeTowerIndex]->getX() * testBlock->getSize()) + testBlock->getSize() / 2, (_towers[upgradeTowerIndex]->getY() * testBlock->getSize()) + testBlock->getSize() / 2, _towers[upgradeTowerIndex]->getRadius() * testBlock->getSize());
			}
			else if (_towers[upgradeTowerIndex]->getType() == 2){
				if (_towers[upgradeTowerIndex]->getUpgradeRangeLevel() == 1)
				{
					GFX::drawRect(testBlock->getSize() * 4, testBlock->getSize() * 2, testBlock->getSize() * 3, worldLoader->getWorldSizeY() * testBlock->getSize() + testBlock->getSize(), textures->getUpgradeRange2Texture()->getTexture());
					GFX::drawString(testBlock->getSize() * 3, worldLoader->getWorldSizeY() * testBlock->getSize() + testBlock->getSize() * 4, "Purchased!", 1.0f, 1.0f, 1.0f);
				}
				else
				{
					GFX::drawRect(testBlock->getSize() * 4, testBlock->getSize() * 2, testBlock->getSize() * 3, worldLoader->getWorldSizeY() * testBlock->getSize() + testBlock->getSize(), textures->getUpgradeRangeTexture()->getTexture());
					char temp[32];
					sprintf(temp, "%d", Tower2UpgradeRange);
					char cost[64] = "Cost: ";
					strcat(cost, temp);
					GFX::drawString(testBlock->getSize() * 3, worldLoader->getWorldSizeY() * testBlock->getSize() + testBlock->getSize() * 4, cost, 1.0f, 1.0f, 1.0f);
					if (_mouse->getX() > testBlock->getSize() * 3 && _mouse->getX() < testBlock->getSize() * 3 + testBlock->getSize() * 4 && _mouse->getY() > (worldLoader->getWorldSizeY() * testBlock->getSize() + testBlock->getSize()) && _mouse->getY() <  worldLoader->getWorldSizeY() * testBlock->getSize() + testBlock->getSize() * 4 && _mouse->getMouseState(GLFW_MOUSE_BUTTON_1) == true && player->getMoney() >= Tower2UpgradeRange)
					{
						player->setMoney(player->getMoney() - Tower2UpgradeRange);
						_towers[upgradeTowerIndex]->setUpgradeRangeLevel(1);
					}
				}
				if (_towers[upgradeTowerIndex]->getUpgradeDamageLevel() == 1)
				{
					GFX::drawRect(testBlock->getSize() * 4, testBlock->getSize() * 2, testBlock->getSize() * 8, worldLoader->getWorldSizeY() * testBlock->getSize() + testBlock->getSize(), textures->getUpgradeDamage2Texture()->getTexture());
					GFX::drawString(testBlock->getSize() * 8, worldLoader->getWorldSizeY() * testBlock->getSize() + testBlock->getSize() * 4, "Purchased!", 1.0f, 1.0f, 1.0f);
				}
				else
				{
					GFX::drawRect(testBlock->getSize() * 4, testBlock->getSize() * 2, testBlock->getSize() * 8, worldLoader->getWorldSizeY() * testBlock->getSize() + testBlock->getSize(), textures->getUpgradeDamageTexture()->getTexture());
					char temp[32];
					sprintf(temp, "%d", Tower2UpgradeDamage);
					char cost[64] = "Cost: ";
					strcat(cost, temp);
					GFX::drawString(testBlock->getSize() * 8, worldLoader->getWorldSizeY() * testBlock->getSize() + testBlock->getSize() * 4, cost, 1.0f, 1.0f, 1.0f);
					if (_mouse->getX() > testBlock->getSize() * 8 && _mouse->getX() < testBlock->getSize() * 8 + testBlock->getSize() * 4 && _mouse->getY() > (worldLoader->getWorldSizeY() * testBlock->getSize() + testBlock->getSize()) && _mouse->getY() <  worldLoader->getWorldSizeY() * testBlock->getSize() + testBlock->getSize() * 4 && _mouse->getMouseState(GLFW_MOUSE_BUTTON_1) == true && player->getMoney() >= Tower2UpgradeDamage)
					{
						player->setMoney(player->getMoney() - Tower2UpgradeDamage);
						_towers[upgradeTowerIndex]->setUpgradeDamageLevel(1);
					}
				}

				char temp[32];
				sprintf(temp, "%d", _towers[upgradeTowerIndex]->getKills());
				char kills[128] = "Kills: ";
				strcat(kills, temp);
				GFX::drawString(testBlock->getSize(), worldLoader->getWorldSizeY() * testBlock->getSize() + testBlock->getSize(), kills, 1.0f, 1.0f, 1.0f);
				GFX::drawCircle((_towers[upgradeTowerIndex]->getX() * testBlock->getSize()) + testBlock->getSize() / 2, (_towers[upgradeTowerIndex]->getY() * testBlock->getSize()) + testBlock->getSize() / 2, _towers[upgradeTowerIndex]->getRadius() * testBlock->getSize());
			}
			else if (_towers[upgradeTowerIndex]->getType() == 3){
				if (_towers[upgradeTowerIndex]->getUpgradeRangeLevel() == 1)
				{
					GFX::drawRect(testBlock->getSize() * 4, testBlock->getSize() * 2, testBlock->getSize() * 3, worldLoader->getWorldSizeY() * testBlock->getSize() + testBlock->getSize(), textures->getUpgradeRange2Texture()->getTexture());
					GFX::drawString(testBlock->getSize() * 3, worldLoader->getWorldSizeY() * testBlock->getSize() + testBlock->getSize() * 4, "Purchased!", 1.0f, 1.0f, 1.0f);
				}
				else
				{
					GFX::drawRect(testBlock->getSize() * 4, testBlock->getSize() * 2, testBlock->getSize() * 3, worldLoader->getWorldSizeY() * testBlock->getSize() + testBlock->getSize(), textures->getUpgradeRangeTexture()->getTexture());
					char temp[32];
					sprintf(temp, "%d", Tower3UpgradeRange);
					char cost[64] = "Cost: ";
					strcat(cost, temp);
					GFX::drawString(testBlock->getSize() * 3, worldLoader->getWorldSizeY() * testBlock->getSize() + testBlock->getSize() * 4, cost, 1.0f, 1.0f, 1.0f);
					if (_mouse->getX() > testBlock->getSize() * 3 && _mouse->getX() < testBlock->getSize() * 3 + testBlock->getSize() * 4 && _mouse->getY() > (worldLoader->getWorldSizeY() * testBlock->getSize() + testBlock->getSize()) && _mouse->getY() <  worldLoader->getWorldSizeY() * testBlock->getSize() + testBlock->getSize() * 4 && _mouse->getMouseState(GLFW_MOUSE_BUTTON_1) == true && player->getMoney() >= Tower3UpgradeRange)
					{
						player->setMoney(player->getMoney() - Tower3UpgradeRange);
						_towers[upgradeTowerIndex]->setUpgradeRangeLevel(1);
					}
				}
				if (_towers[upgradeTowerIndex]->getUpgradeDamageLevel() == 1)
				{
					GFX::drawRect(testBlock->getSize() * 4, testBlock->getSize() * 2, testBlock->getSize() * 8, worldLoader->getWorldSizeY() * testBlock->getSize() + testBlock->getSize(), textures->getUpgradeDamage2Texture()->getTexture());
					GFX::drawString(testBlock->getSize() * 8, worldLoader->getWorldSizeY() * testBlock->getSize() + testBlock->getSize() * 4, "Purchased!", 1.0f, 1.0f, 1.0f);
				}
				else
				{
					GFX::drawRect(testBlock->getSize() * 4, testBlock->getSize() * 2, testBlock->getSize() * 8, worldLoader->getWorldSizeY() * testBlock->getSize() + testBlock->getSize(), textures->getUpgradeDamageTexture()->getTexture());
					char temp[32];
					sprintf(temp, "%d", Tower3UpgradeDamage);
					char cost[64] = "Cost: ";
					strcat(cost, temp);
					GFX::drawString(testBlock->getSize() * 8, worldLoader->getWorldSizeY() * testBlock->getSize() + testBlock->getSize() * 4, cost, 1.0f, 1.0f, 1.0f);
					if (_mouse->getX() > testBlock->getSize() * 8 && _mouse->getX() < testBlock->getSize() * 8 + testBlock->getSize() * 4 && _mouse->getY() > (worldLoader->getWorldSizeY() * testBlock->getSize() + testBlock->getSize()) && _mouse->getY() <  worldLoader->getWorldSizeY() * testBlock->getSize() + testBlock->getSize() * 4 && _mouse->getMouseState(GLFW_MOUSE_BUTTON_1) == true && player->getMoney() >= Tower3UpgradeDamage)
					{
						player->setMoney(player->getMoney() - Tower3UpgradeDamage);
						_towers[upgradeTowerIndex]->setUpgradeDamageLevel(1);
					}
				}

				char temp[32];
				sprintf(temp, "%d", _towers[upgradeTowerIndex]->getKills());
				char kills[128] = "Kills: ";
				strcat(kills, temp);
				GFX::drawString(testBlock->getSize(), worldLoader->getWorldSizeY() * testBlock->getSize() + testBlock->getSize(), kills, 1.0f, 1.0f, 1.0f);
				GFX::drawCircle((_towers[upgradeTowerIndex]->getX() * testBlock->getSize()) + testBlock->getSize() / 2, (_towers[upgradeTowerIndex]->getY() * testBlock->getSize()) + testBlock->getSize() / 2, _towers[upgradeTowerIndex]->getRadius() * testBlock->getSize());
			}
			else if (_towers[upgradeTowerIndex]->getType() == 4){
				if (_towers[upgradeTowerIndex]->getUpgradeRangeLevel() == 1)
				{
					GFX::drawRect(testBlock->getSize() * 4, testBlock->getSize() * 2, testBlock->getSize() * 3, worldLoader->getWorldSizeY() * testBlock->getSize() + testBlock->getSize(), textures->getUpgradeRange2Texture()->getTexture());
					GFX::drawString(testBlock->getSize() * 3, worldLoader->getWorldSizeY() * testBlock->getSize() + testBlock->getSize() * 4, "Purchased!", 1.0f, 1.0f, 1.0f);
				}
				else
				{
					GFX::drawRect(testBlock->getSize() * 4, testBlock->getSize() * 2, testBlock->getSize() * 3, worldLoader->getWorldSizeY() * testBlock->getSize() + testBlock->getSize(), textures->getUpgradeRangeTexture()->getTexture());
					char temp[32];
					sprintf(temp, "%d", Tower4UpgradeRange);
					char cost[64] = "Cost: ";
					strcat(cost, temp);
					GFX::drawString(testBlock->getSize() * 3, worldLoader->getWorldSizeY() * testBlock->getSize() + testBlock->getSize() * 4, cost, 1.0f, 1.0f, 1.0f);
					if (_mouse->getX() > testBlock->getSize() * 3 && _mouse->getX() < testBlock->getSize() * 3 + testBlock->getSize() * 4 && _mouse->getY() > (worldLoader->getWorldSizeY() * testBlock->getSize() + testBlock->getSize()) && _mouse->getY() <  worldLoader->getWorldSizeY() * testBlock->getSize() + testBlock->getSize() * 4 && _mouse->getMouseState(GLFW_MOUSE_BUTTON_1) == true && player->getMoney() >= Tower4UpgradeRange)
					{
						player->setMoney(player->getMoney() - Tower4UpgradeRange);
						_towers[upgradeTowerIndex]->setUpgradeRangeLevel(1);
					}
				}
				if (_towers[upgradeTowerIndex]->getUpgradeDamageLevel() == 1)
				{
					GFX::drawRect(testBlock->getSize() * 4, testBlock->getSize() * 2, testBlock->getSize() * 8, worldLoader->getWorldSizeY() * testBlock->getSize() + testBlock->getSize(), textures->getUpgradeDamage2Texture()->getTexture());
					GFX::drawString(testBlock->getSize() * 8, worldLoader->getWorldSizeY() * testBlock->getSize() + testBlock->getSize() * 4, "Purchased!", 1.0f, 1.0f, 1.0f);
				}
				else
				{
					GFX::drawRect(testBlock->getSize() * 4, testBlock->getSize() * 2, testBlock->getSize() * 8, worldLoader->getWorldSizeY() * testBlock->getSize() + testBlock->getSize(), textures->getUpgradeDamageTexture()->getTexture());
					char temp[32];
					sprintf(temp, "%d", Tower4UpgradeDamage);
					char cost[64] = "Cost: ";
					strcat(cost, temp);
					GFX::drawString(testBlock->getSize() * 8, worldLoader->getWorldSizeY() * testBlock->getSize() + testBlock->getSize() * 4, cost, 1.0f, 1.0f, 1.0f);
					if (_mouse->getX() > testBlock->getSize() * 8 && _mouse->getX() < testBlock->getSize() * 8 + testBlock->getSize() * 4 && _mouse->getY() > (worldLoader->getWorldSizeY() * testBlock->getSize() + testBlock->getSize()) && _mouse->getY() <  worldLoader->getWorldSizeY() * testBlock->getSize() + testBlock->getSize() * 4 && _mouse->getMouseState(GLFW_MOUSE_BUTTON_1) == true && player->getMoney() >= Tower4UpgradeDamage)
					{
						player->setMoney(player->getMoney() - Tower4UpgradeDamage);
						_towers[upgradeTowerIndex]->setUpgradeDamageLevel(1);
					}
				}

				char temp[32];
				sprintf(temp, "%d", _towers[upgradeTowerIndex]->getKills());
				char kills[128] = "Kills: ";
				strcat(kills, temp);
				GFX::drawString(testBlock->getSize(), worldLoader->getWorldSizeY() * testBlock->getSize() + testBlock->getSize(), kills, 1.0f, 1.0f, 1.0f);
				GFX::drawCircle((_towers[upgradeTowerIndex]->getX() * testBlock->getSize()) + testBlock->getSize() / 2, (_towers[upgradeTowerIndex]->getY() * testBlock->getSize()) + testBlock->getSize() / 2, _towers[upgradeTowerIndex]->getRadius() * testBlock->getSize());
			}
		}
		char h[32];
		sprintf(h, "%d",player->getHealth());
		char m[32];
		sprintf(m, "%d", player->getMoney());
		char c[32];
		sprintf(c, "%d", wave->getCurrentWave());
		char health[64] = "Player Health : ";
		char money[64] = "Player Money : ";
		char currentWave[64] = "Wave : ";
		strcat(health, h);
		strcat(money, m);
		strcat(currentWave, c);
		GFX::drawString((worldLoader->getWorldSizeX()) * testBlock->getSize(), 25, health, 1.0f, 1.0f, 1.0f);
		GFX::drawString((worldLoader->getWorldSizeX()) * testBlock->getSize(), 50, money, 1.0f, 1.0f, 1.0f);
		GFX::drawString((worldLoader->getWorldSizeX()) * testBlock->getSize(), 75, currentWave, 1.0f, 1.0f, 1.0f);

		GFX::drawRect(testBlock->getSize(), testBlock->getSize(), (worldLoader->getWorldSizeX()) * testBlock->getSize(), 75, textures->getPlayTexture()->getTexture());
		if (hoverOverWaveStartButton_Game)
		{
			GFX::drawRect(testBlock->getSize(), testBlock->getSize(), (worldLoader->getWorldSizeX()) * testBlock->getSize(), 75, textures->getPlay1Texture()->getTexture());
		}

		if (overTower1)
		{
			GFX::drawRect(testBlock->getSize(), testBlock->getSize(), worldLoader->getWorldSizeX() * testBlock->getSize(), 6 * testBlock->getSize() + testBlock->getSize(), textures->getHighlightedAreaTexture()->getTexture());
		}
		if (overTower2)
		{
			GFX::drawRect(testBlock->getSize(), testBlock->getSize(), worldLoader->getWorldSizeX() * testBlock->getSize(), 6 * testBlock->getSize() + testBlock->getSize() * 2, textures->getHighlightedAreaTexture()->getTexture());
		}
		if (overTower3)
		{
			GFX::drawRect(testBlock->getSize(), testBlock->getSize(), worldLoader->getWorldSizeX() * testBlock->getSize(), 6 * testBlock->getSize() + testBlock->getSize() * 3, textures->getHighlightedAreaTexture()->getTexture());
		}
		if (overTower4)
		{
			GFX::drawRect(testBlock->getSize(), testBlock->getSize(), worldLoader->getWorldSizeX() * testBlock->getSize(), 6 * testBlock->getSize() + testBlock->getSize() * 4, textures->getHighlightedAreaTexture()->getTexture());
		}
		GFX::drawRect(testBlock->getSize(), testBlock->getSize(), worldLoader->getWorldSizeX() * testBlock->getSize(), 6 * testBlock->getSize() + testBlock->getSize(), textures->getTower1Texture()->getTexture());
		char tower1Cost[16] = "";
		char t[16];
		sprintf(t, "%d", Tower1Cost);
		strcat(tower1Cost, t);

		char tower2Cost[16] = "";
		char t2[16];
		sprintf(t2, "%d", Tower2Cost);
		strcat(tower2Cost, t2);


		char tower3Cost[16] = "";
		char t3[16];
		sprintf(t3, "%d", Tower3Cost);
		strcat(tower3Cost, t3);


		char tower4Cost[16] = "";
		char t4[16];
		sprintf(t4, "%d", Tower4Cost);
		strcat(tower4Cost, t4);
		GFX::drawString(worldLoader->getWorldSizeX() * testBlock->getSize() + testBlock->getSize(), 6 * testBlock->getSize() + testBlock->getSize() * 2,tower1Cost,1.0f, 1.0f,1.0f);

		GFX::drawRect(testBlock->getSize(), testBlock->getSize(), worldLoader->getWorldSizeX() * testBlock->getSize(), 6 * testBlock->getSize() + testBlock->getSize() * 2, textures->getTower2Texture()->getTexture());

		GFX::drawString(worldLoader->getWorldSizeX() * testBlock->getSize() + testBlock->getSize(), 6 * testBlock->getSize() + testBlock->getSize() * 3, tower2Cost, 1.0f, 1.0f, 1.0f);

		GFX::drawRect(testBlock->getSize(), testBlock->getSize(), worldLoader->getWorldSizeX() * testBlock->getSize(), 6 * testBlock->getSize() + testBlock->getSize() * 3, textures->getTower3Texture()->getTexture()); 

		GFX::drawString(worldLoader->getWorldSizeX() * testBlock->getSize() + testBlock->getSize(), 6 * testBlock->getSize() + testBlock->getSize() * 4, tower3Cost, 1.0f, 1.0f, 1.0f);

		GFX::drawRect(testBlock->getSize(), testBlock->getSize(), worldLoader->getWorldSizeX() * testBlock->getSize(), 6 * testBlock->getSize() + testBlock->getSize() * 4, textures->getTower4Texture()->getTexture());

		GFX::drawString(worldLoader->getWorldSizeX() * testBlock->getSize() + testBlock->getSize(), 6 * testBlock->getSize() + testBlock->getSize() * 5, tower4Cost, 1.0f, 1.0f, 1.0f);

		GFX::drawRect(testBlock->getSize(), testBlock->getSize(), worldLoader->getWorldSizeX() * testBlock->getSize(), 6 * testBlock->getSize() + testBlock->getSize() * 6, textures->getTrashTexture()->getTexture());


		if (player->isItemSelected() == true)
		{
			player->draw();
			//std::cout << "Drawing player item\n";
		}
		for (int i = 0; i < currentTowersIndex; i++)
		{
			_towers[i]->draw();
			if (_towers[i]->getFire() == true)
			{
				_towers[i]->drawFire();
				_towers[i]->drawFire();
				_towers[i]->drawFire();
				_towers[i]->drawFire();
				std::cout << "Drawing Fire!\n";
			}
		}
		for (std::vector<Enemy*>::iterator iterator = enemiesInWorld->begin(); iterator != enemiesInWorld->end(); iterator++)
		{
			(*iterator)->draw();
		}
	}
	else if (state == CHOOSE_LEVEL)
	{
		for (int i = 0; i < levelListCounter; i++)
		{
			std::string level = levelList[i];
			if (level == "." || level == "..")
			{

			}
			else
			{
				if (hoverList[i] == true)
				{
					GFX::drawRect(256, 24, _width / 2 - 128, i * testBlock->getSize() - 24, textures->getHighlightedAreaTexture()->getTexture());
				}
				const char* leve = level.c_str();
				GFX::drawString(_width / 2 - 128, i * testBlock->getSize(), leve, 1.0f, 1.0f, 1.0f);
			}

		}
	}
	else if (state == OPTIONS)
	{
		GFX::drawString(0, testBlock->getSize() * 4, "1366 X 768", 1.0f, 1.0f, 1.0f);
		GFX::drawString(0, testBlock->getSize() * 6, "1920 X 1080", 1.0f, 1.0f, 1.0f);
	}
	else if (state == PAUSE_MENU)
	{
		int textureWidth = 256;
		int textureHeight = 64;
		if (_width == 1920)
		{
			textureWidth = 512;
		}
		if (_height == 1080)
		{
			textureHeight = 128;
		}
		GFX::drawRect(textureWidth, textureHeight, _width / 2 - (textureWidth / 2), _height / 3 - (textureHeight / 2), textures->getResumeFirstTexture()->getTexture());
		if (hoverOverResumeButton_Pause_Menu)
		{
			GFX::drawRect(textureWidth, textureHeight, _width / 2 - (textureWidth / 2), _height / 3 - (textureHeight / 2), textures->getResumeSecondTexture()->getTexture());
		}
		GFX::drawRect(textureWidth, textureHeight, _width / 2 - (textureWidth / 2), 2 * _height / 3 - (textureHeight / 2), textures->getExitFirstTexture()->getTexture());
		if (hoverOverExitButton_Pause_Menu)
		{
			GFX::drawRect(textureWidth, textureHeight, _width / 2 - (textureWidth / 2), 2 * _height / 3 - (textureHeight / 2), textures->getExitSecondTexture()->getTexture());
		}
		GFX::drawRect(testBlock->getSize() * 2, testBlock->getSize() * 2, 0.0f, 0.0f, textures->getSettings()->getTexture());
	}
	
}