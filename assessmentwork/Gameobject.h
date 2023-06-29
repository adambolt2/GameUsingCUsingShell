#pragma once
#include "vector2D.h"
#include "mydrawengine.h"
#include "shapes.h"
#include "Message.h"
#include "ObjectManager.h"

// Author:W20000343
// Game Object superclass
class GameObj {
private:
	
	Vector2D position_;
	int dmg_;
	float angle;

	bool active;
	int health_;
	static float movespeed_;
public:
	static void SetMoveSpeed(float speed);
	virtual void render()=0;
	virtual void update(float frametime) = 0;
	float genangle();
	float setangle(float tangle);
	void sethealth(int health);
	Vector2D getpos();
	void setpos(Vector2D position);
	Vector2D walkLeft(Vector2D startpos);
	Vector2D walkRight(Vector2D startpos);
	bool setactive(bool x);
	void setdmg(int dmg);
	bool getactive();
	int gethealth();
	virtual IShape2D& GetShape() = 0;
	virtual void CheckCollisions(GameObj& other) ;
	virtual ~GameObj();
	virtual void HandleMessage(Message msg) =0;

	
		
};