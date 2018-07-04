#ifndef _ENEMY3_H
#define _ENEMY3_H
#include <iostream>
#include "Damage.h"
#include "Health.h"
#include "Enemy.h"
class Enemy3 : public Enemy
{
public:
	Enemy3(float x, float y, Texture* texture, int size);
	void draw();
	~Enemy3();
};

#endif