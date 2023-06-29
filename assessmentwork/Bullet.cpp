
#include "Bullet.h"
void bullet::initiliase(Vector2D startpos, Vector2D startVel, MousePointer *ppm) {
	Aim = ppm;
	setshape = 160;
	MyDrawEngine* pDE = MyDrawEngine::GetInstance();
	Img_[0] = pDE->LoadPicture(L"bullet.bmp");
	Img_[1] = pDE->LoadPicture(L"explosion1.bmp");
	Img_[2] = pDE->LoadPicture(L"explosion2.bmp");
	Img_[3] = pDE->LoadPicture(L"explosion3.bmp");
	Img_[4] = pDE->LoadPicture(L"explosion4.bmp");
	Img_[5] = pDE->LoadPicture(L"explosion5.bmp");
	Img_[6] = pDE->LoadPicture(L"explosion6.bmp");
	Img_[7] = pDE->LoadPicture(L"explosion7.bmp");
	Img_[8] = pDE->LoadPicture(L"explosion8.bmp");
	MySoundEngine* pSE = MySoundEngine::GetInstance();
	Bazooka = pSE->LoadWav(L"explosion1.wav");
	
	if (!bazooka) {
		delay = 4.f;
	}
	if (bazooka) {
		delay =1.5f;
	}

	play = true;

	velocity_ = startVel;
	setpos(startpos);
	setactive(true);
	setangle(startVel.angle()-1.57);


}


void bullet::update(float frametime) {
	
	const float turnrate = 5.0f;
	


	if (getactive()&& !explode&& !hascollided) {
		
		setpos (getpos() + velocity_ * frametime);
		Cshape.PlaceAt(getpos(), 30);
	
		
	}
	delay = delay - frametime;
	if (delay < 0 && !bazooka) {
		setactive(false);
	}


	if ((delay < 0 && bazooka) ||explode) {
		
		if (play) {
			MySoundEngine* pSE = MySoundEngine::GetInstance();
			pSE->Play(Bazooka);
			play = false;
		}//setactive(false);

		if (!hascollided) {
			Cshape.PlaceAt(getpos(), setshape);
		}
		
		
		explode = true;
		currentimg = currentimg + frametime * 10;
		if (currentimg > 1) {

			Setshape(0);
			
			// this allows the explosion to only make a hitbox for 10 frames, making it so it ddosent keep kiilling everything
						// currently 1 shots the boss cuz the hitbox still exists although very small
						// gonna fix that
			currentimg = 0;
			temp = temp + 1;
			if (temp == 9) {
				temp = 8;
				setactive(false);
			}
		}
	}

}

void bullet::render() {
	
	MyDrawEngine* pDE = MyDrawEngine::GetInstance();
	
	if (getactive()) { 
		if (!bazooka && !explode) {
			pDE->DrawAt(getpos(), Img_[0], 0.1f, genangle());
		}
		if (bazooka && !explode) {
			pDE->DrawAt(getpos(), Img_[0], 0.5, genangle());
		}
		if (bazooka && explode) {
			pDE->DrawAt(getpos(), Img_[temp], 9, genangle());
		}
	}

}		


IShape2D& bullet::GetShape() {
	return Cshape;
}

void bullet::CheckCollisions(GameObj& other) {

	
	if (typeid(other) == typeid(Zombies)) {
		if (!bazooka) {
			setactive(false);
		}if (bazooka) {
			explode = true;
		}

	}
	if (typeid(other) == typeid(EnemyShooter)) {
		if (!bazooka) {
			setactive(false);
		}
		if (bazooka) {
			explode = true;
		}
	}
	if (typeid(other) == typeid(MasterHand)) {
		if (!bazooka) {
			setactive(false);
		}
		if (bazooka) {

			explode = true;
			hascollided = true;
			Cshape.PlaceAt(Vector2D(-11000, 11000), 0); // i mean this works, but dosent allow damage to be shared between hands and player cant kill himself, but what can ya do.
														// must be a way to just straight up delete something
		}
	}


	if (typeid(other) == typeid(MasterHead)) {
		if (!bazooka) {
			setactive(false);
		}
		if (bazooka) {
			explode = true;
			hascollided = true;
			Cshape.PlaceAt(Vector2D(-11000, 11000), 0);
			
		}

	}

}




void bullet::HandleMessage(Message msg) {

}



void bullet::isbazooka(bool ans) {
	
	if (ans == NULL) {
		bazooka = false;
	}
	bazooka = ans;
}
bool bullet::getbazooka() {
	return bazooka;
}

bool bullet::getexplode() {
	return explode;
}

void bullet::Setshape(int newsize) {
	setshape = newsize;
}



