#ifndef _ENEMY5_H
#define _ENEMY5_H
#include <iostream>
#include "Damage.h"
#include "Health.h"
#include "Enemy.h"
class Enemy5 : public Enemy
{
public:
	Enemy5(float x, float y, Texture* texture, int size);
	void draw();
	~Enemy5();
};

#endif