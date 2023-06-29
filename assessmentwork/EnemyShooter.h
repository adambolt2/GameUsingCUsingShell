#pragma once
#include "ObjectManager.h"
#include "mysoundengine.h"
#include "shapes.h"
#include "spaceship.h"
#include "bullet.h"

// Author:W20000343
// Flying enemies in first and second level
class mainchar;
class EnemyShooter : public GameObj {
public:
	Vector2D velocity_;
	ObjectManager* POM;
	mainchar* player;
	float delay;
	float currentimg;
	int temp = 0;
	bool deafultmovement = true;

	float delay2;
	int options;
	float const SHOOTIME = 3;
	//int health_ = 30;
	int amount_;
	PictureIndex index_;
	SoundIndex Death;
	Circle2D Cshape;
public:

	void shoot(float frametime);
	void render();
	void update(float frametime);

	void initialize(ObjectManager* Pom_);
	SoundIndex shootSound;
	virtual ~EnemyShooter() {}
	IShape2D& GetShape();
	
	void CheckCollisions(GameObj& other);
	void setMainchar(mainchar* mainplayer);
	void HandleMessage(Message msg);
};