#pragma once

#include "Gameobject.h"
#include "vector2D.h"

// Author:W20000343

//messaging system which is then controlled by object manager
class GameObj;

enum class EventType { OBJECT_DESTROYED, EXPLOSION, EnemyDead, LEVEL_START,FlyerDead, IsOnPlat ,Level3Start,HandDead};

struct Message {
	EventType type;
	Vector2D location;
	int otherdata;
	GameObj* Psource;
};

