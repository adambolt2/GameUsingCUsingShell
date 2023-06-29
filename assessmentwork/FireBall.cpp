
#include "FireBall.h"





void FireBall::initiliase(Vector2D startpos, Vector2D startVel) {

	MyDrawEngine* pDE = MyDrawEngine::GetInstance();
	Img_ = pDE->LoadPicture(L"FireBall.png");
	delay = 5.f;
	velocity_ = startVel;
	setpos(startpos);
	setactive(true);
	setangle(startVel.angle() - 1.57);


}


void FireBall::update(float frametime) {


	const float turnrate = 5.0f;



	if (getactive()) {

		setpos(getpos() + velocity_ * frametime);
		Cshape.PlaceAt(getpos(), 30);


	}
	delay = delay - frametime;
	if (delay < 0) {
		setactive(false);
	}
}

void FireBall::render() {

	MyDrawEngine* pDE = MyDrawEngine::GetInstance();

	if (getactive()) {
		pDE->DrawAt(getpos(), Img_, 0.1f, genangle());


	}

}


IShape2D& FireBall::GetShape() {
	return Cshape;
}

void FireBall::CheckCollisions(GameObj& other) {

	if (typeid(other) == typeid(mainchar)) {
		setactive(false);
	}


}


void FireBall::HandleMessage(Message msg) {

}