#pragma once
#include "vector2D.h"
#include "mydrawengine.h"
#include "mysoundengine.h"
#include "Gameobject.h"
#include "MousePointer.h"
#include "ObjectManager.h"
#include "shapes.h"
#pragma once

// author: w200000343
// This is the lava class, Second level lava, mydrawengine needed to be edited
class Lava : public  GameObj {

private:
	
	Rectangle2D Cshape;

	Vector2D Corner;
	PictureIndex index_;
	float ColHeight = 15;
	float height = 1;
public:

	void initialize();
	IShape2D& GetShape();
	void CheckCollisions(GameObj& other);
	
	void setheight(float PublicHeight,float PublicColHeight);
	float getHeight();
	float getColheight();


	void render();

	void update(float frametime);
	void HandleMessage(Message msg);

};