#pragma once

#include "Gameobject.h"
#include "ObjectManager.h"
#include "mysoundengine.h"
#include "spaceship.h"
#include "shapes.h"
#include "bullet.h"
// Author:W20000343
// Second boss in Level 3
class mainchar; 
class MasterHead : public GameObj {
public:

	ObjectManager* POM;
	float delay;
	float currentimg;
	int temp = 0;
	mainchar* player;

	bool firstanim = true;
	bool keepgoing = true;
	float animDelay = 2.f;
	//int health_=30;
	int deadZombieCount;
	float delay2;
	float resettimer;
	bool attack;
	int options;
	float randTimer = 2;
	float shootdelay = 5.f;
	bool angry = false;
	float angerTimer = 1.f;
	float const SHOOTIME = 0.5;
	int amount_;
	PictureIndex index_[8];
	Circle2D Cshape;
public:

	void shoot(float frametime);
	void render();
	void update(float frametime);


	void initialize(ObjectManager* Pom_);

	virtual ~MasterHead() {}
	IShape2D& GetShape();
	void setMainchar(mainchar* mainplayer);

	void CheckCollisions(GameObj& other);
	void HandleMessage(Message msg);
};