#include "spaceship.h"



// ok so i fixed it by writing class mainchar in any object which uses mainchar,this for some reason fixes the issue
//circular dependencies, both of them have each other included causing this bug. Forward declarations solution

void mainchar::setammo(int ammo,int ammo1,int ammo2, int ammo3) {
    ammo_ = ammo;
    ammo_1 = ammo1;
    ammo_2 = ammo2;
    ammo_3 = ammo3;
}

void mainchar::initialize(ObjectManager *Pom_) {
        temp = 0;
        currentimg = 0;
        Pom = Pom_;
        setactive(true);
        MyDrawEngine* pDE = MyDrawEngine::GetInstance();
        index_[0]= pDE->LoadPicture(L"idle.bmp");
        index_[1] = pDE->LoadPicture(L"idle2.bmp");
        index_[2] = pDE->LoadPicture(L"idle3.bmp");
        index_[3] = pDE->LoadPicture(L"idle4.bmp");
        index_[4] = pDE->LoadPicture(L"run.png");
        index_[5] = pDE->LoadPicture(L"run2.png");
        index_[6] = pDE->LoadPicture(L"run3.png");
        index_[7] = pDE->LoadPicture(L"run4.png");
        index_[8] = pDE->LoadPicture(L"Runleft.png");
        index_[9] = pDE->LoadPicture(L"Run2left.png");
        index_[10] = pDE->LoadPicture(L"Run3left.png");
        index_[11] = pDE->LoadPicture(L"Run4left.png");
        delay = SHOOTIME;


        MySoundEngine* pSE = MySoundEngine::GetInstance();
        shootSound = pSE->LoadWav(L"shoot.wav");
}
void mainchar::render() {
   
    MyDrawEngine* pDE = MyDrawEngine::GetInstance();
    if (sta == 1) {
        pDE->DrawAt(getpos(), index_[temp], 4.0f,genangle());
        
    }
    else if (walk_ == 1) {
        pDE->DrawAt(getpos(), index_[tempwalk_], 4.0f,genangle());

    }
    else if (walkleft_ == 1) {
        pDE->DrawAt(getpos(), index_[tempwalkLeft], 4.0f,genangle());

    }
    if (mouseWheel == 0) {
        MyDrawEngine::GetInstance()->WriteInt(Vector2D(900, 900), ammo_, MyDrawEngine::WHITE);
        MyDrawEngine::GetInstance()->WriteText(Vector2D(600, 900), L"PISTOL", MyDrawEngine::GREEN);
    }
    if (mouseWheel == 1) {
        MyDrawEngine::GetInstance()->WriteInt(Vector2D(900, 900), ammo_1, MyDrawEngine::WHITE);
        MyDrawEngine::GetInstance()->WriteText(Vector2D(600, 900), L"MACHINEGUN", MyDrawEngine::GREEN);
    }
    if (mouseWheel == 2) {
        MyDrawEngine::GetInstance()->WriteInt(Vector2D(900, 900), ammo_2, MyDrawEngine::WHITE);
        MyDrawEngine::GetInstance()->WriteText(Vector2D(600, 900), L"Assault Rifle", MyDrawEngine::GREEN);
    }


    if (mouseWheel == 3) {
        MyDrawEngine::GetInstance()->WriteInt(Vector2D(900, 900), ammo_3, MyDrawEngine::WHITE);
        MyDrawEngine::GetInstance()->WriteText(Vector2D(600, 900), L"BAZOOKA", MyDrawEngine::GREEN);
    }

   }
void mainchar::update(float frametime){
     noinput = true;
   


     

     MyInputs* pInputs = MyInputs::GetInstance();
     pInputs->SampleKeyboard();
     if (pInputs->GetMouseDZ() > 0 && mousecooldown <= 0) {
         
         
         
         mouseWheel++;
         mousecooldown = 0.2f; 
     }

     if (pInputs->GetMouseDZ() < 0 && mousecooldown <= 0) {
         
         if (mouseWheel == 0) {
             mouseWheel = 3;
         } // now its  a full circle
         else {
             mouseWheel--;
         }
        
         
         
         mousecooldown = 0.2f; 
     }

     if (mousecooldown > 0) {
         mousecooldown -= frametime; 
         if (mousecooldown < 0) {
             mousecooldown = 0; 
         }
     }
     // i didnt like how the mouse wheel is soo easily altered, therefore delay, makes choosing guns easier 


  

    if (mouseWheel < 0) {
        mouseWheel = 0;
    }
    if (mouseWheel > 3) {
        mouseWheel = 0;
    }


    shoot(frametime);
    if (pInputs->KeyPressed(DIK_A)) {
        setwalk(0);
        setwalkleft(1);
        setstance(0);
        setpos(walkLeft(getpos()));
        noinput = false;
    }

    if (pInputs->KeyPressed(DIK_D)) {
        setwalk(1);
        setwalkleft(0);
        setstance(0);
        setpos(walkRight(getpos()));
        noinput = false;
    }

    if (pInputs->KeyPressed(DIK_SPACE) && !isJumping /*||*/  ) {
        // Start jumping
        isJumping = true;
        jumpVelocity = JUMP_VELOCITY;
        currentHeight = getpos().YValue;
        noinput = false;
    }
    if (isJumping) {
        // Calculate new position based on jump velocity and gravity
        float timeElapsed = 0.01f; // 
        float newHeight = getpos().YValue + jumpVelocity * frametime + 0.5f * GRAVITY * frametime* frametime;

        // Check if player has reached max height
        if (newHeight > GROUND_LEVEL + MAX_HEIGHT ) {
            newHeight = GROUND_LEVEL + MAX_HEIGHT;
            jumpVelocity = -jumpVelocity;
        }

        // Update player position and velocity
        
        
        setpos(Vector2D(getpos().XValue, newHeight));
        
        
        jumpVelocity += GRAVITY * frametime;

        // Check if player has landed
        if (getpos().YValue <= GROUND_LEVEL) {
            setpos(Vector2D(getpos().XValue, GROUND_LEVEL));
            //setposition(position_);
            isJumping = false;
           
            jumpVelocity = 0.0f;
        }
    }


    if (noinput) {
        setwalk(0);
        setwalkleft(0);
        setstance(1);
    }
    if (sta == 1 ) {
       
        currentimg = currentimg + frametime*10;
        if (currentimg > 1) {
            currentimg = 0;
            temp = temp + 1;
            if (temp == 3) {
                temp = 0;
            }
        }
    }
    if (walk_ == 1) {
        
        currentimg = currentimg + frametime*10;
        if (currentimg > 1) {
            
            currentimg = 0;
            tempwalk_ = tempwalk_ + 1;
            if (tempwalk_ == 7) {
                tempwalk_ = 4;
            }
        
           
        }
    }
  

    if (walkleft_ == 1) {

        currentimg = currentimg + frametime*10;
        if (currentimg > 1) {

            currentimg = 0;
            tempwalkLeft = tempwalkLeft+ 1;
            if (tempwalkLeft == 11) {
                tempwalkLeft = 8;
            }


        }
    }
    

    Cshape.PlaceAt(getpos(), 50);



    
    if (gethealth() <= 0) {
        setactive(false);
    }
 
}

   
void mainchar::setwalk(int walk) {
    walk_ = walk;
}



void mainchar::setstance(int stance) {
    sta = stance;

}

void mainchar::setwalkleft(int walkL) {
    walkleft_ = walkL;
}




void mainchar::shoot(float frametime) {
    MySoundEngine* pSE = MySoundEngine::GetInstance();
    MyInputs* pInputs2 = MyInputs::GetInstance();

    // Check if left mouse button is clicked
    Vector2D temppos;
    const float turnrate = 5.0f;
   
    if (ammo_ > 0 && mouseWheel == 0) {
        
        if (pInputs2->IfMouseLeftDown() && delay < 0) {

            
            pSE->Play(shootSound);
            // Create a new bullet instance
            bullet* newBullet = new bullet();


            Vector2D startPos;
            Vector2D startVel;
            temppos = getpos();
            Pom->AddObject(newBullet);
            Vector2D direction = PPM->getpos() - getpos();
            float bulletang = newBullet->genangle();
            float desiredangle = direction.angle();
            float angdiff = bulletang-desiredangle;
            Vector2D acc;
            acc.setBearing(desiredangle, 1500.f);
            newBullet->setangle(desiredangle);
            startVel.set(acc);
            if (angdiff > 3.141f) angdiff - +6.242f;
            if (angdiff < 3.141f) angdiff + 6.242f;

            if (angdiff > 0) {
                bulletang= bulletang- turnrate * frametime;
            }
            else {
                bulletang= bulletang+ turnrate * frametime;
            }
            temppos = temppos + Vector2D(3.f, 2.f) + acc.unitVector() * 50;
            
            startPos.set(temppos);
            newBullet->initiliase(startPos, startVel,PPM );
                
  

            delay = SHOOTIME;

            ammo_ = ammo_ - 1;
        }
    }
    delay = delay - frametime;
    // gun 1




    if (ammo_1 > 0 && mouseWheel == 1) {

        if (pInputs2->IfMouseLeftDown() && delay2 < 0) {

           
            pSE->Play(shootSound);
            // Create a new bullet instance
            bullet* newBullet = new bullet();


            Vector2D startPos;
            Vector2D startVel;
            temppos = getpos();
            Pom->AddObject(newBullet);
            Vector2D direction = PPM->getpos() - getpos();
            float bulletang = newBullet->genangle();
            float desiredangle = direction.angle();
            float angdiff = bulletang - desiredangle;
            Vector2D acc;
            acc.setBearing(desiredangle, 1500.f);
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
            newBullet->initiliase(startPos, startVel, PPM);



            delay2 = SHOOTIMESUB;

            ammo_1 = ammo_1 - 1;
        }
    }
    delay2 = delay2 - frametime;

    // gun 2


    if (ammo_2 > 0 && mouseWheel == 2) {
        if (pInputs2->IfMouseLeftDown() && delay3 < 0) {

          
            pSE->Play(shootSound);

            // Create three new bullet instances
            bullet* newBullet[3];
            for (int i = 0; i < 3; i++) {
                newBullet[i] = new bullet();
            }

            Vector2D startPos[3];
            Vector2D startVel[3];
            Vector2D direction = PPM->getpos() - getpos();
            float desiredangle = direction.angle();
            float offsetangle = 0.785f/3; // 45 degrees in radians/3 soo it feels  nicer

            // Set the angle of the first bullet to be the same as the direction to the target
            startVel[0].setBearing(desiredangle, 1500.f);
            startPos[0].set(getpos());

            // Set the angles of the second and third bullets to be  above and below the first bullet's angle
            startVel[1].setBearing(desiredangle - offsetangle, 1500.f);
            startPos[1].set(getpos());
            startVel[2].setBearing(desiredangle + offsetangle, 1500.f);
            startPos[2].set(getpos());

            // Initialize the bullets with their respective positions and velocities
            for (int i = 0; i < 3; i++) {
                Pom->AddObject(newBullet[i]);
                newBullet[i]->initiliase(startPos[i], startVel[i], PPM);
            }

            delay3 = SHOOTIMEAR;
            ammo_2 = ammo_2 - 1;
        }
     
    }
    delay3 -= frametime;








    // bazooka
    if (ammo_3 > 0 && mouseWheel == 3) {

        if (pInputs2->IfMouseLeftDown() && delay4 < 0) {

           
            pSE->Play(shootSound);
            // Create a new bullet instance
            bullet* newBullet = new bullet();


            Vector2D startPos;
            Vector2D startVel;
            temppos = getpos();
            Pom->AddObject(newBullet);
            Vector2D direction = PPM->getpos() - getpos();
            float bulletang = newBullet->genangle();
            float desiredangle = direction.angle();
            float angdiff = bulletang - desiredangle;
            Vector2D acc;
            acc.setBearing(desiredangle, 1500.f);
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
            newBullet->isbazooka(true);
            newBullet->initiliase(startPos, startVel, PPM);



            delay4 = SHOOTIMEBAZ;

            ammo_3 = ammo_3 - 1;
        }
    }
    delay4 = delay4 - frametime;
    // gun 1


}

void mainchar::setmouse(MousePointer* PPM_) {
    PPM = PPM_;
}
IShape2D& mainchar::GetShape() {
    return Cshape;
}


void mainchar::CheckCollisions(GameObj& other) {
    
    if (typeid(other) == typeid(Laser)) {
        setdmg(20000);

    }
    
    if (typeid(other) == typeid(Enemybullet)) {
        setdmg(2);
        
    }
    if (typeid(other) == typeid(Zombies)) {
        setdmg(1);

    }
    if (typeid(other) == typeid(Lava)) {
        
   
            setdmg(10000);


        


    }
    if (typeid(other) == typeid(MasterHand)) {


        setdmg(10000);





    }



    if (typeid(other) == typeid(FireBall)) {


        setdmg(5);





    }
    


    if (typeid(other) == typeid(bullet)) {
        bullet* bullet_ptr = dynamic_cast<bullet*>(&other);
        if (bullet_ptr->getbazooka() && bullet_ptr->getexplode()) {
            setdmg(1000);
        }







    }

    // This kinda works but i dont like how it works, Hacky as hell, forces both update and collision checks to get user inputs
    if (typeid(other) == typeid(Platform)) {
     
       
        
        Platform* pPlatform = dynamic_cast<Platform*>(&other);
        
        IShape2D& ref = pPlatform->GetShape();
        


        int corners = pPlatform->GetCollisionPos(getpos());

        MyInputs* pInputs = MyInputs::GetInstance();
        pInputs->SampleKeyboard();
        if (corners == 1) {
            
            SetGroundLevel(-1100.f);
            Message m;
            m.Psource = this;
            m.location = this->getpos();
            m.type = EventType::IsOnPlat;
            Pom->SendMessageW(m);
        
            
            
            
            
            setpos(Vector2D(getpos().XValue, other.getpos().YValue + 70));
            
            jumpVelocity = 0;
            if (pInputs->KeyPressed(DIK_SPACE)) {
                jumpVelocity = JUMP_VELOCITY;
            }
            
            
            
            if (pInputs->KeyPressed(DIK_S)) {
                // Start jumping
                
                jumpVelocity = 0.0f;
                setpos(getpos()- Vector2D(0, 150));

            }

            if (corners == 2 || corners == 3 || corners == 4) {
                
                
                if (!pPlatform->GetShape().Intersects(pPlatform->GetShape())) {
                     setpos( getpos()+ Vector2D(5, 0));


                        jumpVelocity = 0.0f;
                        falling();
                        setpos(getpos());
                }

            }

        }



        if (corners == 6 || corners == 7 || corners == 8) {
            if (!pPlatform->GetShape().Intersects(pPlatform->GetShape())) {
                setpos(getpos()- Vector2D(5, 0));


                jumpVelocity = 0.0f;
                falling();
                setpos(getpos());
            }
        }

        if (corners == 5) {

            
            jumpVelocity = 0.0f;
            falling();
            setpos(getpos());

        }
    }
   
}

void mainchar::falling() {
    if (getpos().YValue != GROUND_LEVEL) {

        setpos(Vector2D(getpos().XValue, getpos().YValue - 3));
        setpos(getpos());
        isJumping == false;
    }
}



void mainchar::HandleMessage(Message msg) {

}



void mainchar::SetGroundLevel(float GH) {
    
    
    isJumping == false;
    GROUND_LEVEL = GH;
    // this only works when the player jumps once 
}