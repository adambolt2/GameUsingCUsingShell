
#include "EnemyBullet.h"




void Enemybullet::initiliase(Vector2D startpos, Vector2D startVel){
	
	MyDrawEngine* pDE = MyDrawEngine::GetInstance();
	Img_ = pDE->LoadPicture(L"bullet.bmp");
	delay = 5.f;
	velocity_ = startVel;
	setpos(startpos);
	setactive(true);
	setangle(startVel.angle() - 1.57);


}


void Enemybullet::update(float frametime) {

	const float turnrate = 5.0f;



	if (getactive()) {

		 setpos( getpos()+ velocity_ * frametime);
		Cshape.PlaceAt(getpos(), 30);


	}
	delay = delay - frametime;
	if (delay < 0) {
		setactive(false);
	}
}

void Enemybullet::render() {

	MyDrawEngine* pDE = MyDrawEngine::GetInstance();

	if (getactive()) {
		pDE->DrawAt(getpos(), Img_, 0.1f, genangle());


	}

}


IShape2D& Enemybullet::GetShape() {
	return Cshape;
}

void Enemybullet::CheckCollisions(GameObj& other) {

	if (typeid(other) == typeid(mainchar)) {
		 setactive(false); 
	}


}


void Enemybullet::HandleMessage(Message msg) {

	if (msg.type == EventType::LEVEL_START) {
	
	
		setactive(false);
	}
}