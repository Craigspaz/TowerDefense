#ifndef _ENEMY4_H
#define _ENEMY4_H
#include <iostream>
#include "Damage.h"
#include "Health.h"
#include "Enemy.h"
class Enemy4 : public Enemy
{
public:
	Enemy4(float x, float y, Texture* texture, int size);
	void draw();
	~Enemy4();
};

#endif