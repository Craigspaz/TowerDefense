#ifndef _ENEMY7_H
#define _ENEMY7_H
#include <iostream>
#include "Damage.h"
#include "Health.h"
#include "Enemy.h"
class Enemy7 : public Enemy
{
public:
	Enemy7(float x, float y, Texture* texture, int size);
	void draw();
	~Enemy7();
};

#endif