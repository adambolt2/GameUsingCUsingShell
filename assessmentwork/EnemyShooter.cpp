#include "EnemyShooter.h"


void EnemyShooter::initialize(ObjectManager* Pom_) {
	setactive(true);
	temp = 0;
	sethealth(4);
	currentimg = 0;
	POM = Pom_;
	MyDrawEngine* pDE = MyDrawEngine::GetInstance();

	index_ = pDE->LoadPicture(L"AlienShooter.bmp");

}

void EnemyShooter::render() {
	if (getactive()) {


		MyDrawEngine* pDE = MyDrawEngine::GetInstance();
		pDE->DrawAt(getpos(), index_, 2.0f);
		//pDE->FillCircle(Cshape.GetCentre(), Cshape.GetRadius(), pDE->LIGHTGREEN);
	}
}

void EnemyShooter::update(float frametime) {
    shoot(frametime);
	if (getactive()) {
		currentimg = currentimg + 0.1;
        if (getpos().XValue <= -1500) {
            options = 1; 
        }                
        if (getpos().XValue >= 1510) {
            options = 0; 
        }
        if (options == 0) {
            setpos(walkLeft(getpos()));
        }
        if (options == 1) {
            setpos(walkRight(getpos()));
        }
        Cshape.PlaceAt(getpos(), 90);
  
	}

    if (gethealth() <= 0) {
     
        Message m;
        m.Psource = this;
        m.location = this->getpos();
        m.type = EventType::FlyerDead;
        POM->SendMessageW(m);
       
        setactive(false);
    }
}


IShape2D& EnemyShooter::GetShape() {
	return Cshape;
}


void EnemyShooter::CheckCollisions(GameObj& other) {
	if (typeid(other) == typeid(bullet)) {
        bullet* bullet_ptr = dynamic_cast<bullet*>(&other);
        if (bullet_ptr->getbazooka()) {
     
            setdmg(1000);
        }
        
        setdmg(1);

	}
}




#include "EnemyBullet.h"

void EnemyShooter::shoot(float frametime) {
	Vector2D temppos;
	const float turnrate = 5.0f;
    //MySoundEngine* pSE = MySoundEngine::GetInstance();
    //pSE->Play(shootSound);
    // Create a new bullet instance
    if (delay2 < 0) {
        Enemybullet* newBullet = new Enemybullet();


        Vector2D startPos;
        Vector2D startVel;
        temppos = getpos();
        POM->AddObject(newBullet);
        Vector2D direction = player->getpos() - getpos();
        float bulletang = newBullet->genangle();
        float desiredangle = direction.angle();
        float angdiff = bulletang - desiredangle;
        Vector2D acc;
        acc.setBearing(desiredangle, 700.f);
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
        temppos = temppos + Vector2D(3.f, 2.f) + acc.unitVector()*50;

        startPos.set(temppos);
        newBullet->initiliase(startPos, startVel);
        delay2 = SHOOTIME;

 
    }
    delay2 = delay2 - frametime;
}


void EnemyShooter::setMainchar(mainchar* mainplayer) {
    player = mainplayer;
}



void EnemyShooter::HandleMessage(Message msg) {

}