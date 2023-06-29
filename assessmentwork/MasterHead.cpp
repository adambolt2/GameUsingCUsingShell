#include "MasterHead.h"


void MasterHead::initialize(ObjectManager* Pom_) {
	setactive(true);
	temp = 0;
	sethealth(50);
	currentimg = 0;
	POM = Pom_;
	MyDrawEngine* pDE = MyDrawEngine::GetInstance();

	index_[0] = pDE->LoadPicture(L"Neutral.png");
	index_[1] = pDE->LoadPicture(L"OpenMouth.png");
	index_[2] = pDE->LoadPicture(L"Neutral.png");
	index_[3] = pDE->LoadPicture(L"Neutral_Left.png");
	index_[4] = pDE->LoadPicture(L"Neutral_Right.png");
	index_[5] = pDE->LoadPicture(L"Smile.png");
	index_[6] = pDE->LoadPicture(L"OpenMouth.png");
	index_[7] = pDE->LoadPicture(L"Angry.png");
}

void MasterHead::render() {
	if (getactive()) {
		MyDrawEngine::GetInstance()->WriteInt(Vector2D(500, 900), gethealth(), MyDrawEngine::RED);
		// in further implementations, I would like to represent this number as a health bar and not number
		MyDrawEngine* pDE = MyDrawEngine::GetInstance();
		if (!firstanim && !attack && !angry) {
			if (player->getpos().XValue - getpos().XValue <= -300) {
				pDE->DrawAt(getpos(), index_[3], 1.0f);
			}

			if (player->getpos().XValue - getpos().XValue >= 300) {
				pDE->DrawAt(getpos(), index_[4], 0.8f);
			}
			if (player->getpos().XValue - getpos().XValue > -300 && player->getpos().XValue - getpos().XValue < 300)  {
				pDE->DrawAt(getpos(), index_[0], 1.0f);
			}
		}

		if (firstanim && !attack && !angry) {
			pDE->DrawAt(getpos(), index_[5], 1.0f);
			const int SHIELDRADIUS = 150;
			const int SHIELDRADIUSSQUARED = SHIELDRADIUS * SHIELDRADIUS;
			const int MAXPIXELS = 1600;
			Vector2D pixles[MAXPIXELS];
			unsigned int colour[MAXPIXELS];
			int nextPixel = 0;
			for (int i = -SHIELDRADIUS; i < SHIELDRADIUS; i += 2) {
				for (int f = -SHIELDRADIUS; f < SHIELDRADIUS; f += 2) {
					if (rand() % 1000 < 50.0f * 1.5 && (i * i + f * f < SHIELDRADIUSSQUARED)) {
						if (nextPixel >= MAXPIXELS) break;
						colour[nextPixel] = MyDrawEngine::WHITE;
						pixles[nextPixel++].set(getpos().XValue + i, getpos().YValue + f);
					}
				}
			}

			MyDrawEngine::GetInstance()->DrawPointList(pixles, colour, nextPixel);
		}
		if (attack && !angry) {
			pDE->DrawAt(getpos(), index_[6], 1.0f);
			const int SHIELDRADIUS = 150;
			const int SHIELDRADIUSSQUARED = SHIELDRADIUS * SHIELDRADIUS;
			const int MAXPIXELS = 1600;
			Vector2D pixles[MAXPIXELS];
			unsigned int colour[MAXPIXELS];
			int nextPixel = 0;
			for (int i = -SHIELDRADIUS; i < SHIELDRADIUS; i += 2) {
				for (int f = -SHIELDRADIUS; f < SHIELDRADIUS; f += 2) {
					if (rand() % 1000 < 50.0f *1.5 && (i*i+f*f<SHIELDRADIUSSQUARED)) {
						if (nextPixel >= MAXPIXELS) break;
						colour[nextPixel] = MyDrawEngine::WHITE;
						pixles[nextPixel++].set(getpos().XValue + i, getpos().YValue + f);
					}
				}
			}

			MyDrawEngine::GetInstance()->DrawPointList(pixles, colour, nextPixel);
		}
		//pDE->FillCircle(Cshape.GetCentre(), Cshape.GetRadius(), pDE->LIGHTGREEN);
	
	
		if (angry) {
			pDE->DrawAt(getpos(), index_[7], 1.0f);
	}
	
	}
}




void MasterHead::update(float frametime) {

	if (!firstanim) {
		if (shootdelay >= 0) {
			attack = true;
			shoot(frametime);
			shootdelay -= frametime;
			
		}

		if (shootdelay <= 0) {
				resettimer += frametime;
				attack = false;
		}
		if (resettimer >= 5) {
			shootdelay = 5.f;
			resettimer = 0.f;
		}
		
		
		
	
	
	}

	if (getactive()) {


		if (firstanim) {
			animDelay -= frametime;
			if (animDelay <= 0) {
				firstanim = false;
			}
		}

		Cshape.PlaceAt(getpos(), 150);
	}


	if (gethealth() <= 25) {
		
		
		if (angerTimer >= 0) {
			angry = true;
			angerTimer -= frametime;
			if (angerTimer <= 0) {
				angry = false;
			}
		}
		
		
		if (randTimer <= 0 && !angry) {
			int rand_bit = rand() % 2;
			options = rand_bit;
			randTimer = 2.f;
			keepgoing = true;
		
		}
		if (options == 1 && !firstanim && getpos().XValue > -1500 && !angry)
		{
			if (getpos().XValue >= 1300) {
				setpos(walkLeft(getpos()));
				keepgoing = false;
				randTimer = 0.f;
			}

			if (getpos().XValue <= -1300) {
				setpos(walkRight(getpos()));
				keepgoing = false;
				randTimer = 0.f;
			}


			if (getpos().YValue >= 900) {
				setpos(getpos() - Vector2D(0, 3));
				keepgoing = false;
				randTimer = 0.f;
			}

			if (getpos().YValue <= -900) {
				setpos(getpos() + Vector2D(0, 3));
				keepgoing = false;
				randTimer = 0.f;
			}
			if ( keepgoing) {
				setpos(walkRight(getpos()) + Vector2D(2, rand() % 2 - 2));
				
			
			}
	
		}
		if (options == 0 && !firstanim && getpos().XValue < 1500 && !angry)
		{
			if (getpos().XValue >= 1300) {
				setpos(walkLeft(getpos()));
				keepgoing = false;
				randTimer = 0.f;
			}

			if (getpos().XValue <= -1300) {
				setpos(walkRight(getpos()));
				keepgoing = false;
				randTimer = 0.f;
			}


			if (getpos().YValue >= 900) {
				setpos(getpos() - Vector2D(0, 3));
				keepgoing = false;
				randTimer = 0.f;
			}


			if (getpos().YValue <= -900) {
				setpos(getpos() + Vector2D(0, 3));
				keepgoing = false;
				randTimer = 0.f;

			}

			if ( keepgoing) {
				setpos(walkLeft(getpos()) - Vector2D(2, rand() % 2 - 2));
			}

		

		}


	




		randTimer -= frametime;
	}




	if (gethealth() <= 0) {

		Message m;
		m.Psource = this;
		m.location = this->getpos();
		m.type = EventType::HandDead;
		POM->SendMessageW(m);
		setactive(false);
	};
}


IShape2D& MasterHead::GetShape() {
	return Cshape;
}


void MasterHead::CheckCollisions(GameObj& other) {
	if (typeid(other) == typeid(bullet)) {
		if (!attack && !firstanim) {
			bullet* bullet_ptr = dynamic_cast<bullet*>(&other);
			if (bullet_ptr->getbazooka()) {

				setdmg(10);
			}
			setdmg(1);
		}


	}
}



void MasterHead::HandleMessage(Message msg) {

}


void MasterHead::setMainchar(mainchar* mainplayer) {
	player = mainplayer;
}



#include "FireBall.h"

void MasterHead::shoot(float frametime) {
	Vector2D temppos;
	const float turnrate = 5.0f;
	//MySoundEngine* pSE = MySoundEngine::GetInstance();
	//pSE->Play(shootSound);
	// Create a new bullet instance
	if (delay2 < 0) {
		FireBall* newBullet = new FireBall();


		Vector2D startPos;
		Vector2D startVel;
		temppos = getpos();
		POM->AddObject(newBullet);
		Vector2D direction = player->getpos() - getpos();
		float bulletang = newBullet->genangle();
		float desiredangle = direction.angle();
		float angdiff = bulletang - desiredangle;
		Vector2D acc;
		acc.setBearing(desiredangle, 1200.f);
		newBullet->setangle(desiredangle);
		startVel.set(acc);
		if (angdiff > 3.141f) angdiff - +6.242f;
		if (angdiff < 3.141f) angdiff + 6.242f;

		if (angdiff > 0) {
			bulletang = bulletang - turnrate * frametime;
		}
		else {
			bulletang = bulletang + turnrate * frametime;
		}
		temppos = temppos + Vector2D(3.f, 2.f) + acc.unitVector() * 50;

		startPos.set(temppos);
		newBullet->initiliase(startPos, startVel);
		delay2 = SHOOTIME;


	}
	delay2 = delay2 - frametime;
}