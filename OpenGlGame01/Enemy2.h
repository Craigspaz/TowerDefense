#ifndef _ENEMY2_H
#define _ENEMY2_H
#include <iostream>
#include "Damage.h"
#include "Health.h"
#include "Enemy.h"
class Enemy2 : public Enemy
{
public:
	Enemy2(float x, float y, Texture* texture, int size);
	void draw();
	~Enemy2();
};

#endif