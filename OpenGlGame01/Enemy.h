#ifndef _ENEMY_H
#define _ENEMY_H
#include <iostream>
#include "Texture.h"
#include "GFX.h"
class Enemy
{
public:
	Enemy(float x, float y, int type, int damage, int health, Texture* texture, int size);
	virtual void draw() = 0;
	void setX(float a);
	void setY(float a);
	void setType(int a);
	void setDamage(int a);
	void setHealth(int a);
	void setIsAlive(bool a);
	float getX();
	float getY();
	int getType();
	int getDamage();
	int getHealth();
	bool isAlive();
	Texture* getTexture();
	void setTexture(Texture* texture);
	~Enemy();
	int getPreviousDirection();
	void setPreviousDirection(int a);

	bool isUp();
	bool isDown();
	bool isLeft();
	bool isRight();
	void setUp(bool a);
	void setDown(bool a);
	void setLeft(bool a);
	void setRight(bool a);
protected:
	int _x;
	int _y;
	int _type;
	int _damage;
	int _health;
	bool _isAlive;
	int _size;
	Texture* _texture;
	bool _up;
	bool _down;
	bool _left;
	bool _right;
private:
	int previousDirection;
};

#endif