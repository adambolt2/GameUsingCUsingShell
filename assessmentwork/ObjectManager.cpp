#pragma once
#include "ObjectManager.h";

std::list<GameObj*>::iterator it1;
std::list<GameObj*>::iterator it2;
void ObjectManager::AddObject(GameObj* pnewobject) {
	PgameObjs.push_back(pnewobject);
}
void ObjectManager::updateall(float frametime) {
	if (frametime > 0.1) {
		frametime = 0.1;
	}// we can now pause :)
	
	GameObj::SetMoveSpeed(150*frametime);
	for (GameObj *nextObj : PgameObjs) {
		
		if (nextObj != nullptr) 
		{ nextObj->update(frametime); 
		}
	}
}

void ObjectManager::renderall() {
	for (GameObj* nextObj : PgameObjs) {

		if (nextObj)
		{
			nextObj->render();
		}
	}
}



void ObjectManager::deletall() {
	for (GameObj*& nextObj : PgameObjs) {
		
		
		delete nextObj;
		nextObj = nullptr;
		
	}
	PgameObjs.clear();
}

void ObjectManager::deleteinactive() {
	for (GameObj*& nextObj : PgameObjs) {
		if (nextObj && !nextObj->getactive()) {
		
			delete nextObj;
			nextObj = nullptr;
		}
	}
	PgameObjs.remove(nullptr);
}


void ObjectManager::CheckCollisions() {
	for (it1 = PgameObjs.begin(); it1 != PgameObjs.end(); it1++) {
		for (it2 = std::next(it1); it2 != PgameObjs.end(); it2++) {
			if ((*it1)->GetShape().Intersects((*it2)->GetShape())) {
				(*it1)->CheckCollisions((**it2));
				(*it2)->CheckCollisions((**it1));
			}
		}

	}
}

std::list<GameObj*> ObjectManager::Getobjs() {
	return PgameObjs;
}


void ObjectManager::SendMessage(Message msg) { 
	
	for (GameObj* pNext : PgameObjs) { 
		if (pNext)pNext->HandleMessage(msg); 
	} 
};