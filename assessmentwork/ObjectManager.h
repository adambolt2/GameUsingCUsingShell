

#pragma once
#include <list>;
#include "vector2D.h"
#include "Gameobject.h";
#include "Message.h";
// author: W20000343
// This is how the game loads and handles objects
class ObjectManager {

private:
	std::list<GameObj*>	PgameObjs;
public:
	void AddObject(GameObj* pnewobject);
	void updateall(float frametime);
	void renderall();
	void deletall();
	void deleteinactive();
	void CheckCollisions();
	void SendMessage(Message msg);
	std::list<GameObj*> Getobjs();
};

