#pragma once
#include "vector2D.h"
#include "mydrawengine.h"
#include "mysoundengine.h"
#include "Gameobject.h"
#include "ObjectManager.h"
#include "MousePointer.h"

#include "shapes.h"	

#include "zombies.h"
#include "EnemyShooter.h"
#include "MasterHand.h"
#include "MasterHead.h"
#include<typeinfo>

// Author:W20000343
// Bullets which user can shoot, has different stances

class bullet : public GameObj {
private:
	Vector2D velocity_;

	float delay;
	bool bazooka = false;
	bool explode = false;
	MousePointer *Aim;
	Circle2D Cshape;
	int temp = 1;
	bool hascollided;
	SoundIndex Bazooka;
	bool play;
	float currentimg;
	int setshape ;
	float explodedelay;
	PictureIndex Img_[10];
	float desiredang;
public:
	void initiliase(Vector2D startpos, Vector2D startVel, MousePointer *ppm);
	void update(float frametime);
	void render() ;


	void isbazooka(bool ans);
	IShape2D& GetShape();
	void CheckCollisions(GameObj& other);
	void HandleMessage(Message msg);
	bool getbazooka();
	bool getexplode();
	void Setshape(int newsize);

};