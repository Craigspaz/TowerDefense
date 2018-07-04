#ifndef _ENEMY1_H
#define _ENEMY1_H
#include <iostream>
#include "Damage.h"
#include "Health.h"
#include "Enemy.h"
class Enemy1 : public Enemy
{
public:
	Enemy1(float x, float y, Texture* texture,int size);
	void draw();
	~Enemy1();
};

#endif