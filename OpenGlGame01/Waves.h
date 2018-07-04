#ifndef _WAVES_H
#define _WAVES_H
#include <iostream>
#include "Enemy.h"
#include "Enemy1.h"
#include "Enemy2.h"
#include "Enemy3.h"
#include "Enemy4.h"
#include "Enemy5.h"
#include "Enemy6.h"
#include "Enemy7.h"
#include "Enemy8.h"
#include "Textures.h"
class Waves
{
public:
	Waves(int* startPointsX, int* startPointsY,int index, Textures* textures, int size);
	~Waves();
	Enemy** loadCurrentWave();
	int getCurrentWave();
	void incrementWave();
	float getWaveSpeed();
	int getCurrentWaveEnemiesNumber();
private:
	Enemy** _enemies;
	int currentEnemyCounter;
	int _currentWave;

	float waveSpeed;

	Textures* _textures;
	
	int _size;
	int _startPointsX[32];
	int _startPointsY[32];
	int _index;
};

#endif