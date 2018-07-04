#ifndef _ENEMY8_H
#define _ENEMY8_H
#include <iostream>
#include "Damage.h"
#include "Health.h"
#include "Enemy.h"
class Enemy8 : public Enemy
{
public:
	Enemy8(float x, float y, Texture* texture, int size);
	void draw();
	~Enemy8();
};

#endif