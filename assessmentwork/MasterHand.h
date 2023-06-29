#pragma once

#include "Gameobject.h"
#include "ObjectManager.h"
#include "mysoundengine.h"
#include "spaceship.h"	
#include "shapes.h"
#include "Laser.h"
#include "MasterHead.h"
// Author:W20000343
// first boss in Level 3

class mainchar;
class MasterHand : public GameObj {
public:
	Vector2D velocity_;
	ObjectManager* POM;
	float delay;
	float currentimg;
	int temp = 0;
	mainchar* player;
	float velocityY_;
	//int health_=30;
	float upperbound;
	float lowerbound;
	int amount_;
	int options;
	bool Left;
	bool HasReached;
	bool move;
	bool attack;
	int screenshake =10 ;
	float punchDelay = 0.7f;
	int Numattack = 1;
	int Gunattack = 4;
	float laserTimer;
	int attacktype;
	//int ded = 2;

	float randTimer = 1;
	Circle2D Cshape;
public:

	void setdirection(bool Left_ );
	void render();
	void update(float frametime);
	PictureIndex index_[14];
	SoundIndex Death;
	void initialize(ObjectManager* Pom_);

	virtual ~MasterHand() {}
	IShape2D& GetShape();
	void setMainchar(mainchar* mainplayer);
	void CheckCollisions(GameObj& other);
	void HandleMessage(Message msg);
};