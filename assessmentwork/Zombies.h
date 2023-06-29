#pragma once
#include "Gameobject.h"
#include "ObjectManager.h"
#include "mysoundengine.h"
#include "shapes.h"
#include "bullet.h"

#include "spaceship.h"
// author: w200000343
// This is the zombies class, first level enemies
class mainchar;
class Zombies : public GameObj {
public:
	float upperbound;
	float lowerbound;
	Vector2D velocity_;
	ObjectManager* POM;
	float delay;
	float currentimg;
	int temp = 0;
	mainchar* player;
	int RIGHTtemp = 4;
	int options;
	bool left ;
	float velocityY_;
	//int health_=30;
	int deadZombieCount;
	int amount_;
	PictureIndex index_[10];

	Circle2D Cshape;
public:
	
	
	void render();
	void update(float frametime);

	void initialize(ObjectManager* Pom_);

	virtual ~Zombies() {}
	IShape2D& GetShape();
	void setplayer(mainchar* mainplayer);
	void CheckCollisions(GameObj &other);
	void HandleMessage(Message msg);
};