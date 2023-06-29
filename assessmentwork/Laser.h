#pragma once
#pragma once
#include "vector2D.h"
#include "mydrawengine.h"
#include "mysoundengine.h"
#include "Gameobject.h"
#include "MousePointer.h"
#include "ObjectManager.h"
#include "shapes.h"
#pragma once
// Author:W20000343
// Pretty useless but it creates the laser in level 2, couldve been hard coded, not included in architecture 
// Hardcoded instead with masterhands
class Laser : public  GameObj {

private:
	
	Rectangle2D Cshape;
	ObjectManager* Pom;

	float ColHeight = 15;
	float height = 1;
public:

	void initialize(ObjectManager* Pom_);
	IShape2D& GetShape();
	void CheckCollisions(GameObj& other);

	void setheight(float PublicHeight, float PublicColHeight);
	float getHeight();
	float getColheight();

	PictureIndex index_;
	void render();
	
	void update(float frametime);
	void HandleMessage(Message msg);

};

// im not gonna lie, this class is almost useless, 
//its used once, and i couldve just made a box for it in the levelmanager, Might delete it later :)
