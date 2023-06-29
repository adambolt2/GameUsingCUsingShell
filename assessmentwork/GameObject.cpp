#include "vector2D.h"
#include "Gameobject.h"
float GameObj::movespeed_;
void GameObj::SetMoveSpeed(float speed)
{
	movespeed_ = speed;
}

float GameObj::genangle() {

	return angle;
}

void GameObj::sethealth(int health) {
	health_ = health < 0 ? 0 : health;
}
Vector2D GameObj::walkLeft(Vector2D startpos) {
	position_ = startpos;
	position_ = position_ + Vector2D(-movespeed_, 0.f)  ;
	return position_;
}
Vector2D GameObj::walkRight(Vector2D startpos) {
	{	
		
		position_ = startpos;
		position_ = position_ + Vector2D(movespeed_, 0.f);
		return position_;
	}
}
bool GameObj::setactive(bool x) {
	active = x;

	return active;
}


bool GameObj::getactive() {
	return active;
}

void GameObj::setdmg(int dmg) {
	dmg_ = dmg;
	health_ = health_ - dmg;
	sethealth(health_);
	/*if (health_ <= 0) {

		setactive(false);
		

	}
	*/
}
float GameObj::setangle(float tangle) {
	angle = tangle;
	return angle;
}

Vector2D GameObj::getpos() {
	return position_;
}
void GameObj::setpos(Vector2D position) {
	position_ = position;
	
}

void GameObj::CheckCollisions(GameObj& other) {

}
int GameObj::gethealth() {
	return health_;
}

GameObj::~GameObj(){

}


