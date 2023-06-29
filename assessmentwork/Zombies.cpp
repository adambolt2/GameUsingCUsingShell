#include "Zombies.h"


void Zombies::initialize(ObjectManager* Pom_) {
	setactive(true);
	temp = 0;
	sethealth(4);
	currentimg = 0;
	POM = Pom_;
	upperbound = rand() % (2000 - 400 + 1) + 400;
	lowerbound = rand() % (-600 - (-1400) + 1) - 1400;
	MyDrawEngine* pDE = MyDrawEngine::GetInstance();

		index_[0] = pDE->LoadPicture(L"Zrun1.bmp");
		index_[1] = pDE->LoadPicture(L"Zrun2.bmp");
		index_[2] = pDE->LoadPicture(L"Zrun3.bmp");
		index_[3] = pDE->LoadPicture(L"Zrun4.bmp");
	
		index_[4] = pDE->LoadPicture(L"Zrun1RIGHT.bmp");
		index_[5] = pDE->LoadPicture(L"Zrun2RIGHT.bmp");
		index_[6] = pDE->LoadPicture(L"Zrun3RIGHT.bmp");
		index_[7] = pDE->LoadPicture(L"Zrun4RIGHT.bmp");
	
}

void Zombies::render() {
	if (getactive()) {
	
		
		MyDrawEngine* pDE = MyDrawEngine::GetInstance();
		if (left) { 
			pDE->DrawAt(getpos(), index_[temp], 4.0f); 
		}
		if(!left) {
			pDE->DrawAt(getpos(), index_[RIGHTtemp], 4.0f); 
		}
		//pDE->FillCircle(Cshape.GetCentre(), Cshape.GetRadius(), pDE->LIGHTGREEN);
	}
}




void Zombies::update(float frametime) {



	if (getactive()) {
		currentimg = currentimg + frametime *10;
		if (currentimg > 1 && left) {
			currentimg = 0;
			
			temp = temp + 1;
			if (temp == 4) {
				temp = 0;
			
			}
		}

		if (currentimg > 1 && !left) {
			currentimg = 0;

			RIGHTtemp = RIGHTtemp + 1;
			if (RIGHTtemp == 7) {
				RIGHTtemp = 4;

			}
		}

		if (getpos().XValue <= -1500 || player->getpos().XValue - getpos().XValue >= upperbound) {
			// allows zombies to chase you but not to stack
			
			options = 1;
		
		}
		if (getpos().XValue >= 1510 || player->getpos().XValue - getpos().XValue <= lowerbound) {
			// allows zombies to chase you but not to stack
			options = 0;
	
		}
		if (options == 0) {
			setpos(walkLeft(getpos()));
			left = true;
		}
		if (options == 1) {
			setpos(walkRight(getpos()));
			left = false;
		}
		Cshape.PlaceAt(getpos(), 40);
	}


	if (gethealth() <= 0) {
		
		Message m;
		m.Psource = this;
		m.location = this->getpos();
		m.type = EventType::EnemyDead;
		POM->SendMessageW(m);
		setactive(false);
	};
}


IShape2D& Zombies::GetShape() {
	return Cshape;
}


void Zombies::CheckCollisions(GameObj &other) {
	if (typeid(other) == typeid(bullet)) {
		bullet* bullet_ptr = dynamic_cast<bullet*>(&other);
		if (bullet_ptr->getbazooka()) {
		
			setdmg(1000);
		}
		setdmg(1);

	

	}
}



void Zombies::HandleMessage(Message msg) {

}


void Zombies::setplayer(mainchar* mainplayer) {
	player = mainplayer;
}