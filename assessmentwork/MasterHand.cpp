#include "MasterHand.h"


void MasterHand::initialize(ObjectManager* Pom_) {
	setactive(true);
	temp = 0;
	sethealth(25);
	currentimg = 0;
	POM = Pom_;
	MyDrawEngine* pDE = MyDrawEngine::GetInstance();
	upperbound = (pDE->GetScreenWidth() - 200);
	// bounds using actual screen info, just in case differnt resolutions, Dont know if thats an issue but better safe
	// than sorry
	lowerbound = -(pDE->GetScreenWidth() - 200);
	
	
	
	if (Left) {
		index_[0] = pDE->LoadPicture(L"IdleHand.png");
		index_[1] = pDE->LoadPicture(L"IdleTofist.png");
		index_[2] = pDE->LoadPicture(L"IdleTofist2.png");
		index_[3] = pDE->LoadPicture(L"IdleTofist3.png");
		index_[4] = pDE->LoadPicture(L"IdleTogun1.png");
		index_[5] = pDE->LoadPicture(L"IdleTogun2.png");
		index_[6] = pDE->LoadPicture(L"IdleTogun3.png");
	
	}
	if (!Left) {
		index_[0] = pDE->LoadPicture(L"RIGHTIdleHand.png");
		index_[1] = pDE->LoadPicture(L"RIGHTIdleTofist.png");
		index_[2] = pDE->LoadPicture(L"RIGHTIdleTofist2.png");
		index_[3] = pDE->LoadPicture(L"RIGHTIdleTofist3.png");
		index_[4] = pDE->LoadPicture(L"RIGHTIdleTogun1.png");
		index_[5] = pDE->LoadPicture(L"RIGHTIdleTogun2.png");
		index_[6] = pDE->LoadPicture(L"RIGHTIdleTogun3.png");
	}
	
	}

void MasterHand::render() {
	if (getactive()) {
		if (Left) {
			MyDrawEngine::GetInstance()->WriteInt(Vector2D(500, 500), gethealth(), MyDrawEngine::RED);
		}
		if (!Left) {
			MyDrawEngine::GetInstance()->WriteInt(Vector2D(800, 500), gethealth(), MyDrawEngine::LIGHTGREEN);
		}
		MyDrawEngine* pDE = MyDrawEngine::GetInstance();
		
		if (!attack)
		{
	
			pDE->DrawAt(getpos(), index_[temp], 4.0f,genangle());
			
		}
		if (attack) {
			if (attacktype == 1) {
				pDE->DrawAt(getpos(), index_[Numattack], 4.0f, genangle());
			}
			if (attacktype == 2) {
				pDE->DrawAt(getpos(), index_[Gunattack], 4.0f, genangle());
			}
			if (attacktype == 3) {
				pDE->DrawAt(getpos(), index_[6], 4.0f, genangle());
			}
		}
	//	pDE->FillCircle(Cshape.GetCentre(), Cshape.GetRadius(), pDE->LIGHTGREEN);
	}
}




void MasterHand::update(float frametime) {

	if (getactive()) {

		if (getactive() && !attack) {
			currentimg = currentimg + frametime * 10;
			if (currentimg > 1) {
				currentimg = 0;
				temp = temp + 1;
				if (temp == 1) {
					temp = 0;

				}
			}


			if (delay >= 4) {
				if (player->getpos().XValue <= getpos().XValue) {
					setpos(walkLeft(getpos()) - Vector2D(2, 0));
					if (getpos().XValue <= player->getpos().XValue + 1) { // Check if within range
						delay = 0;
						attack = true;
						attacktype = rand() % 2 + 1;
						//attacktype = 2;
					}
				}
				else if (player->getpos().XValue >= getpos().XValue) {
					setpos(walkRight(getpos()) + Vector2D(2, 0));
					if (getpos().XValue >= player->getpos().XValue - 1) { // Check if within range
						delay = 0;
						//attacktype = 2;
						attacktype = rand() % 2 + 1;
						attack = true;

					}
				}
			}
			else {

				if (randTimer <= 0) {
					attack = false;

					int rand_bit = rand() % 2;
					options = rand_bit;
					randTimer = 1;
				}
				if (options == 1 )
				{
					setpos(walkLeft(getpos()) - Vector2D(2, 0));

					if (getpos().XValue <=lowerbound) {
						options = 0;
					}

				}
				if (options == 0)
				{
					setpos(walkRight(getpos()) + Vector2D(2, 0));
					if (getpos().XValue >= upperbound) {
						options = 1;
					}


				}
				randTimer -= frametime;
				delay += frametime; // increment delay counter
			}



		}







	


		if (attack && attacktype ==1) {

			currentimg = currentimg + frametime * 5;
			if (currentimg > 1) {

				currentimg = 0;
				Numattack = Numattack + 1;
				if (Numattack == 4) {
					Numattack = 3;
					//attack = false;
				}


			}
			if (Numattack == 3) {


				if (getpos().YValue >= -910 && !HasReached) {
					setpos(getpos() - Vector2D(0, 6));
				
					if (getpos().YValue <=-900) {
						HasReached = true;
					
					}
				}


				if (screenshake >0 && HasReached) {

					MyDrawEngine::GetInstance()->theCamera.PlaceAt(Vector2D(rand() % 24 - 12.f, rand() % 24 - 12.f));
					screenshake  -=frametime;
				}
				if (screenshake <= 0) {

					MyDrawEngine::GetInstance()->theCamera.PlaceAt(Vector2D(0, 0));
				}
				

				if (HasReached && getpos().YValue <= 0 && punchDelay <= 0) {
					setpos(getpos() + Vector2D(0, 5));
				
				}
			}

			if (getpos().YValue == -900 && Numattack == 3) {

				punchDelay -= frametime;
			}
			if (getpos().YValue == 0 && Numattack == 3) {
				attack = false;
				screenshake = 10;
				HasReached = false;
				Numattack = 1;
				attacktype = 0;
				punchDelay = 1.f;
			}
		}








		if (attack && attacktype == 2 || attacktype == 3) {
		
			if(laserTimer <2){
		currentimg = currentimg + frametime * 5;
		if (currentimg > 1) {

			currentimg = 0;
			Gunattack = Gunattack + 1;
			if (Gunattack == 6) {
				Gunattack = 5;
				//attack = false;
			}
		}

			

			}







			if (Gunattack== 5) {


				if (getpos().YValue >= -910 && !HasReached) {
					setpos(getpos() - Vector2D(0, 6));

					if (getpos().YValue <= -900) {
						HasReached = true;

					}
				}

				if (HasReached && getpos().YValue <= 0 && punchDelay <= 0) {
					setpos(getpos() + Vector2D(0, 5));
					attacktype = 2;
					if (getpos().YValue == 0) {
						attack = false;
						

						HasReached = false;
						Gunattack = 4;
						attacktype = 0;
						punchDelay = 0.7;
						laserTimer = 0;
					}
				}
			}

			if (getpos().YValue == -900 && Gunattack == 5) {
				
				if (laserTimer >= 0) {
					if (Left) {
						MyDrawEngine::GetInstance()->DrawLine(getpos(), getpos() - Vector2D(4000, 0), MyDrawEngine::WHITE);
					}
					if (!Left) {
						MyDrawEngine::GetInstance()->DrawLine(getpos(), getpos() + Vector2D(4000, 0), MyDrawEngine::WHITE);
					}
					laserTimer = laserTimer + frametime;
				
					
					if (laserTimer >= 1){
						if (Left) {
							MyDrawEngine::GetInstance()->DrawLine(getpos(), getpos() - Vector2D(4000, 0), MyDrawEngine::GREEN);
						}
						if (!Left) {
							MyDrawEngine::GetInstance()->DrawLine(getpos(), getpos() +Vector2D(4000, 0), MyDrawEngine::GREEN);
						}
						laserTimer = laserTimer + frametime;
					}
					
					
					if (laserTimer >= 2) {
						attacktype = 3;
						
						if (Left) {
							MyDrawEngine::GetInstance()->DrawLine(getpos(), getpos() - Vector2D(4000, 0), MyDrawEngine::RED);
						}
						if (!Left) {
							MyDrawEngine::GetInstance()->DrawLine(getpos(), getpos() + Vector2D(4000, 0), MyDrawEngine::RED);
						}
					
					
						
						laserTimer = laserTimer + frametime;

						Rectangle2D test;
						if (Left) {
							test.PlaceAt(getpos().YValue + 10, getpos().XValue, getpos().YValue - 10, getpos().XValue - 3550);
						}
						if (!Left) {
							test.PlaceAt(getpos().YValue + 10, getpos().XValue, getpos().YValue - 10, getpos().XValue +3550);;
						}
						MyDrawEngine* pDE = MyDrawEngine::GetInstance();
						
						if (test.Intersects(player->GetShape())) {
							player->setdmg(10000);
						}

					
						punchDelay -= frametime;
					
					}
					
					
				}
				
			}
		
			if (getpos().YValue == 0 && attacktype == 3) {
			
				attack = false;

				HasReached = false;
				Gunattack = 4;
				attacktype = 0;
				punchDelay = 0.7;
				laserTimer = 0;
			}
		}















		Cshape.PlaceAt(getpos(), 100);
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


IShape2D& MasterHand::GetShape() {
	return Cshape;
}


void MasterHand::CheckCollisions(GameObj& other) {
	if (typeid(other) == typeid(bullet)) {
		bullet* bullet_ptr = dynamic_cast<bullet*>(&other);
		if (bullet_ptr->getbazooka()) {
		
			setdmg(10);
			
		}
		
		
		setdmg(1);



	}
}



void MasterHand::HandleMessage(Message msg) {

}


void MasterHand::setMainchar(mainchar* mainplayer) {
	
	player = mainplayer;
}


void MasterHand::setdirection(bool Left_) {
	Left = Left_;
}