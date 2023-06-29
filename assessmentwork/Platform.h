#include "vector2D.h"
#include "mydrawengine.h"
#include "mysoundengine.h"
#include "Gameobject.h"
#include "MousePointer.h"
#include "ObjectManager.h"
#include "shapes.h"
#include "Lava.h"
#pragma once
class Platform : public  GameObj {

private:
	
	Rectangle2D Cshape;

	Vector2D Corner;


public:
	
	void initialize();
	IShape2D& GetShape();
	void CheckCollisions(GameObj& other);
	
	PictureIndex index_;
	void render();
	Vector2D Getcorner();
	void update(float frametime);
	void HandleMessage(Message msg);
	int GetCollisionPos(Vector2D targetPos); // 1 = top 2 = top right 3 = right etc...
};