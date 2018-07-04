#ifndef _ENEMY6_H
#define _ENEMY6_H
#include <iostream>
#include "Damage.h"
#include "Health.h"
#include "Enemy.h"
class Enemy6 : public Enemy
{
public:
	Enemy6(float x, float y, Texture* texture, int size);
	void draw();
	~Enemy6();
};

#endif