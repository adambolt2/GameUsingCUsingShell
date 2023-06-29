#include "vector2D.h"
#include "mydrawengine.h"
#include "mysoundengine.h"
#include "Gameobject.h"
#include "MousePointer.h"
#include "ObjectManager.h"
#include "shapes.h"
#include "Zombies.h"
#include "Spaceship.h"
#include "MousePointer.h"	
#include "EnemyShooter.h"
#include "Lava.h"
#include "Laser.h"
#include "Platform.h"
#include "MasterHand.h"
#include "MasterHead.h"
#pragma once
// Author:W20000343
// Level manager to control gameplay
// you can control what the player gets in terms of ammo and health at the start of the level
// W A S D controls, MouseWheel changes guns, space bar jumps, Aim using cursor

class LevelManager : public GameObj {

private:
	int LevelNumber =1;
	float laserTimer ;
	int score;
	int laserdeath = 2;
	bool Lasertrig = false;
	int AmountOfEnemies;
	float respawnTimer;
	bool playeralive;
	int playerLives= 3;
	float timer;
	float flyertimer;
	float flyertimer2;
	float spawnInterval;
	int handsdead;
	int numZombiesSpawned;
	int permaScore;
	int FlyersSpawned;
	int FlyersSpawned2;
	bool lavaSwitch;
	ObjectManager *Pom_;
	Circle2D Cshape;
	int ZombiesDead;
	int flyersdead;
	Vector2D pos;

	mainchar *player;
	int lavaspawned;
	int zombiesnotdead;
	int flyersnotdead;
	int lavatimer =600;
	Vector2D lavapos;
	Vector2D lavapos2;
	Vector2D lavapos3;
	Vector2D lavapos4;
	 MousePointer *mouse;

public:
	void StartLevel(ObjectManager *Pom);
	void update(float frametime);
	void render();
	void AddScore();
	void DeathHandler();
	void playerDeath(float frametime);
	IShape2D& GetShape();
	void HandleMessage(Message msg);
};