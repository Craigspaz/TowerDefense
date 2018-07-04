#include "Waves.h"


Waves::Waves(int* startPointsX, int* startPointsY, int index, Textures* textures, int size) : currentEnemyCounter(0), _size(size), _textures(textures), _currentWave(1)
{
	_enemies = new Enemy*[500];
	for (int i = 0; i < index; i++)
	{
		_startPointsX[i] = startPointsX[i];
		_startPointsY[i] = startPointsY[i];
	}
	waveSpeed = 2.0f;
}


Waves::~Waves()
{
	delete _enemies;
}


float Waves::getWaveSpeed()
{
	waveSpeed = 2.0f;
	return waveSpeed;
}

int Waves::getCurrentWaveEnemiesNumber()
{
	/*if (_currentWave < 3)
	{
		return 10;
	}
	else if (_currentWave < 10)
	{
		return 25;
	}
	else if (_currentWave < 14)
	{
		return 56;
	}
	else if (_currentWave < 20)
	{
		return 75;
	}
	else if (_currentWave < 28)
	{
		return 100;
	}
	else if (_currentWave < 36)
	{
		return 126;
	}
	else if (_currentWave < 43)
	{
		return 154;
	}
	else if (_currentWave < 62)
	{
		return 200;
	}
	else
	{
		return 500;
	}*/
	return 500;
}


Enemy** Waves::loadCurrentWave()
{
	//for (int i = 0; i < currentEnemyCounter; i++)
	//{
	//	_enemies[i] = nullptr;
	//}
	//currentEnemyCounter = 0;
	/*if (_currentWave < 3)
	{
		for (int i = 0; i < 10; i++)
		{
			_enemies[i] = new Enemy1(_startPointsX[0], _startPointsY[0], _textures->getEnemy1Texture(), _size);
			currentEnemyCounter++;
		}
	}
	else if (_currentWave < 10)
	{
		for (int i = 0; i < 25; i++)
		{
			int rand = (std::rand() % (100 - 0 + 1));
			if (rand > 60)
			{
				_enemies[i] = new Enemy1(_startPointsX[0], _startPointsY[0], _textures->getEnemy1Texture(), _size);
			}
			else
			{
				_enemies[i] = new Enemy2(_startPointsX[0], _startPointsY[0], _textures->getEnemy2Texture(), _size);
			}
			currentEnemyCounter++;
		}
	}
	else if (_currentWave < 14)
	{
		for (int i = 0; i < 56; i++)
		{
			int rand = (std::rand() % (100 - 0 + 1));
			if (rand > 80)
			{
				_enemies[i] = new Enemy1(_startPointsX[0], _startPointsY[0], _textures->getEnemy1Texture(), _size);
			}
			else if (rand <= 80 && rand >= 47)
			{
				_enemies[i] = new Enemy2(_startPointsX[0], _startPointsY[0], _textures->getEnemy2Texture(), _size);
			}
			else
			{
				_enemies[i] = new Enemy3(_startPointsX[0], _startPointsY[0], _textures->getEnemy3Texture(), _size);
			}
			currentEnemyCounter++;
		}
	}
	else if (_currentWave < 20)
	{
		for (int i = 0; i < 75; i++)
		{
			int rand = (std::rand() % (100 - 0 + 1));
			if (rand > 77)
			{
				_enemies[i] = new Enemy1(_startPointsX[0], _startPointsY[0], _textures->getEnemy1Texture(), _size);
			}
			else if (rand <= 77 && rand >= 52)
			{
				_enemies[i] = new Enemy2(_startPointsX[0], _startPointsY[0], _textures->getEnemy2Texture(), _size);
			}
			else if (rand < 52 && rand >= 34)
			{
				_enemies[i] = new Enemy3(_startPointsX[0], _startPointsY[0], _textures->getEnemy3Texture(), _size);
			}
			else
			{
				_enemies[i] = new Enemy4(_startPointsX[0], _startPointsY[0], _textures->getEnemy4Texture(), _size);
			}
			currentEnemyCounter++;
		}
	}
	else if (_currentWave < 28)
	{
		for (int i = 0; i < 108; i++)
		{
			int rand = (std::rand() % (100 - 0 + 1));
			if (rand > 86)
			{
				_enemies[i] = new Enemy1(_startPointsX[0], _startPointsY[0], _textures->getEnemy1Texture(), _size);
			}
			else if (rand <= 86 && rand >= 51)
			{
				_enemies[i] = new Enemy2(_startPointsX[0], _startPointsY[0], _textures->getEnemy2Texture(), _size);
			}
			else if (rand < 51 && rand >= 42)
			{
				_enemies[i] = new Enemy3(_startPointsX[0], _startPointsY[0], _textures->getEnemy3Texture(), _size);
			}
			else if (rand < 42 && rand >= 23)
			{
				_enemies[i] = new Enemy4(_startPointsX[0], _startPointsY[0], _textures->getEnemy4Texture(), _size);
			}
			else
			{
				_enemies[i] = new Enemy5(_startPointsX[0], _startPointsY[0], _textures->getEnemy5Texture(), _size);
			}
			currentEnemyCounter++;
		}
	}
	else if (_currentWave < 36)
	{
		for (int i = 0; i < 126; i++)
		{
			int rand = (std::rand() % (100 - 0 + 1));
			if (rand > 86)
			{
				_enemies[i] = new Enemy1(_startPointsX[0], _startPointsY[0], _textures->getEnemy1Texture(), _size);
			}
			else if (rand <= 86 && rand >= 51)
			{
				_enemies[i] = new Enemy2(_startPointsX[0], _startPointsY[0], _textures->getEnemy2Texture(), _size);
			}
			else if (rand < 51 && rand >= 42)
			{
				_enemies[i] = new Enemy3(_startPointsX[0], _startPointsY[0], _textures->getEnemy3Texture(), _size);
			}
			else if (rand < 42 && rand >= 29)
			{
				_enemies[i] = new Enemy4(_startPointsX[0], _startPointsY[0], _textures->getEnemy4Texture(), _size);
			}
			else if (rand < 29 && rand >= 15)
			{
				_enemies[i] = new Enemy5(_startPointsX[0], _startPointsY[0], _textures->getEnemy5Texture(), _size);
			}
			else
			{
				_enemies[i] = new Enemy6(_startPointsX[0], _startPointsY[0], _textures->getEnemy6Texture(), _size);
			}
			currentEnemyCounter++;
		}
	}
	else if (_currentWave < 43)
	{
		for (int i = 0; i < 154; i++)
		{
			int rand = (std::rand() % (100 - 0 + 1));
			if (rand > 90)
			{
				_enemies[i] = new Enemy1(_startPointsX[0], _startPointsY[0], _textures->getEnemy1Texture(), _size);
			}
			else if (rand <= 90 && rand >= 67)
			{
				_enemies[i] = new Enemy2(_startPointsX[0], _startPointsY[0], _textures->getEnemy2Texture(), _size);
			}
			else if (rand < 67 && rand >= 53)
			{
				_enemies[i] = new Enemy3(_startPointsX[0], _startPointsY[0], _textures->getEnemy3Texture(), _size);
			}
			else if (rand < 53 && rand >= 39)
			{
				_enemies[i] = new Enemy4(_startPointsX[0], _startPointsY[0], _textures->getEnemy4Texture(), _size);
			}
			else if (rand < 39 && rand >= 27)
			{
				_enemies[i] = new Enemy5(_startPointsX[0], _startPointsY[0], _textures->getEnemy5Texture(), _size);
			}
			else if (rand < 27 && rand >= 19)
			{
				_enemies[i] = new Enemy6(_startPointsX[0], _startPointsY[0], _textures->getEnemy6Texture(), _size);
			}
			else
			{
				_enemies[i] = new Enemy7(_startPointsX[0], _startPointsY[0], _textures->getEnemy7Texture(), _size);
			}
			currentEnemyCounter++;
		}
	}
	else if (_currentWave < 62)
	{
		for (int i = 0; i < 200; i++)
		{
			int rand = (std::rand() % (100 - 0 + 1));
			if (rand > 90)
			{
				_enemies[i] = new Enemy1(_startPointsX[0], _startPointsY[0], _textures->getEnemy1Texture(), _size);
			}
			else if (rand <= 90 && rand >= 77)
			{
				_enemies[i] = new Enemy2(_startPointsX[0], _startPointsY[0], _textures->getEnemy2Texture(), _size);
			}
			else if (rand < 77 && rand >= 63)
			{
				_enemies[i] = new Enemy3(_startPointsX[0], _startPointsY[0], _textures->getEnemy3Texture(), _size);
			}
			else if (rand < 63 && rand >= 49)
			{
				_enemies[i] = new Enemy4(_startPointsX[0], _startPointsY[0], _textures->getEnemy4Texture(), _size);
			}
			else if (rand < 49 && rand >= 37)
			{
				_enemies[i] = new Enemy5(_startPointsX[0], _startPointsY[0], _textures->getEnemy5Texture(), _size);
			}
			else if (rand < 37 && rand >= 29)
			{
				_enemies[i] = new Enemy6(_startPointsX[0], _startPointsY[0], _textures->getEnemy6Texture(), _size);
			}
			else if (rand < 29 && rand >= 17)
			{
				_enemies[i] = new Enemy7(_startPointsX[0], _startPointsY[0], _textures->getEnemy7Texture(), _size);
			}
			else
			{
				_enemies[i] = new Enemy8(_startPointsX[0], _startPointsY[0], _textures->getEnemy8Texture(), _size);
			}
			currentEnemyCounter++;
		}
	}
	else*/
	//{
		for (int i = 0; i < 500; i++)
		{
			/*int rand = (std::rand() % (100 - 0 + 1));
			if (rand > 90)
			{
				_enemies[i] = new Enemy6(_startPointsX[0], _startPointsY[0], _textures->getEnemy1Texture(), _size);
			}
			else if (rand <= 90 && rand >= 77)
			{
				_enemies[i] = new Enemy7(_startPointsX[0], _startPointsY[0], _textures->getEnemy2Texture(), _size);
			}
			else if (rand < 77 && rand >= 63)
			{
				_enemies[i] = new Enemy8(_startPointsX[0], _startPointsY[0], _textures->getEnemy3Texture(), _size);
			}
			else if (rand < 63 && rand >= 49)
			{
				_enemies[i] = new Enemy6(_startPointsX[0], _startPointsY[0], _textures->getEnemy4Texture(), _size);
			}
			else if (rand < 49 && rand >= 37)
			{
				_enemies[i] = new Enemy7(_startPointsX[0], _startPointsY[0], _textures->getEnemy5Texture(), _size);
			}
			else if (rand < 37 && rand >= 29)
			{
				_enemies[i] = new Enemy8(_startPointsX[0], _startPointsY[0], _textures->getEnemy6Texture(), _size);
			}
			else if (rand < 29 && rand >= 17)
			{
				_enemies[i] = new Enemy7(_startPointsX[0], _startPointsY[0], _textures->getEnemy7Texture(), _size);
			}
			else*/
			{
				_enemies[i] = new Enemy8(_startPointsX[0], _startPointsY[0], _textures->getEnemy8Texture(), _size);
			}
			currentEnemyCounter++;
		}
	//}
	return _enemies;
}
int Waves::getCurrentWave()
{
	return _currentWave;
}


void Waves::incrementWave()
{
	_currentWave++;
}
