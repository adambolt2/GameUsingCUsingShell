#pragma once
#include "vector2D.h"
#include "mydrawengine.h"
#include "mysoundengine.h"
#include "Gameobject.h"
#include "MousePointer.h"
#include "ObjectManager.h"
#include "shapes.h"
#include "Platform.h"
#include "Lava.h"
#include "Laser.h"
#include "myinputs.h"
#include "Zombies.h"
#include "MasterHand.h"
#include "Bullet.h"

#include "FireBall.h"
#include "EnemyBullet.h"


// Author: W20000343
// This is the main character of the game, header is called spaceship but the class is mainchar
class mainchar: public  GameObj{


private:
    int health_;
  // Vector2D position_;
    ObjectManager* Pom;
    MousePointer* PPM;
    int ammo_;
    int ammo_1;
    int ammo_2;
    int ammo_3;
    int mouseWheel;
    float velocityY_;
    float currentimg;
    int temp = 0;
    int sta;
     float GROUND_LEVEL = -900.0f;
    int walk_ ;
    int walkleft_;
    int tempwalk_ = 4;
    int tempwalkLeft = 8;
    float delay;              
    float delay2;              
    float delay3;              
    float delay4;              
    float const SHOOTIME = 0.5;
    float const SHOOTIMESUB = 0.1;
    float const SHOOTIMEAR = 1.f;
    float const SHOOTIMEBAZ = 2.f;
    
    Circle2D Cshape;
    
     bool isJumping = false;
     bool isColliding = false;
     float jumpVelocity = 0.0f;
     float JUMP_VELOCITY = 700.0f;
     bool Level3 ;
     bool isPlat;
     float mousecooldown;

     bool noinput = true;
     PictureIndex index_[12];
     SoundIndex shootSound;

     protected:
     const float GRAVITY = -981.0f; // acceleration due to gravity in pixels/second^2
   // initial velocity when jumping in pixels/second
      float MAX_HEIGHT = 2000.0f; // maximum jump height in pixels
      // level of the ground in pixels

      float currentHeight = GROUND_LEVEL;
   
public:
    
    void SetGroundLevel(float GH);
 
    void setammo(int ammo, int ammo1,int ammo2, int ammo3);
    void setstance(int stance);
    void setwalk(int walk);
    void setwalkleft(int walkL);

    void render();
            
   void shoot(float frametime);
    void update(float frametime);
    
    void initialize(ObjectManager *Pom_);
    IShape2D& GetShape();
    void setmouse(MousePointer* PPM_);
    void CheckCollisions(GameObj& other);
    void falling();
    void HandleMessage(Message msg);
    virtual ~mainchar() {}
};

