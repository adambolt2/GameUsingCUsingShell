#pragma once
#include "vector2D.h"
#include "mydrawengine.h"
#include "mysoundengine.h"
#include "Gameobject.h"
#include "ObjectManager.h"
#include "spaceship.h"
#include<typeinfo>
#include "shapes.h"
#pragma once
// author: w20000343
// The bullet which masterhead spawn
class FireBall : public GameObj{
private:
	Vector2D velocity_;

	float delay;


	PictureIndex Img_;
	Circle2D Cshape;
public:
	void initiliase(Vector2D startpos, Vector2D startVel);
	void update(float frametime);
	void render();
	float desiredang;

	IShape2D& GetShape();
	void CheckCollisions(GameObj& other);
	void HandleMessage(Message msg);
};