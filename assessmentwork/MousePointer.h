#include "ObjectManager.h"
#include "Gameobject.h"

#include "myinputs.h"
#pragma once
// Author:W20000343
// mouse pointer class, allows maincharacter to aim
class MousePointer : public GameObj {
private:
	Vector2D Mpos;
	Circle2D m_shape;
	PictureIndex img;
public:
	void initiliase();
	void update(float frametime);
	void render();
	void click();
	IShape2D& GetShape();
	void HandleMessage(Message msg);
	
	
};



