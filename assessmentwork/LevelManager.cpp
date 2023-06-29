#include "LevelManager.h"

#include "Vector2D.h"
void LevelManager::StartLevel(ObjectManager* Pom) {
	
	 setactive(true);
	Pom_ = Pom;
	player = new mainchar();

	if (LevelNumber == 1) {
		Message m;
		m.Psource = this;
		m.location = this->getpos();
		m.type = EventType::LEVEL_START;
		Pom_->SendMessageW(m);
		
		mouse = new MousePointer();
		mouse->initiliase();
		Pom_->AddObject(mouse);
		spawnInterval = 2.0f;
		
		
			
		playeralive = true; 
		
	
		pos.set(-1500, -900);
		player->setpos(pos);
		player->setammo(50,10,5,12);
		player->sethealth(100);
		player->initialize(Pom_);
		Pom_->AddObject(player);
		player->setmouse(mouse);
		
		
	


		
		
	
		// create the player
		
	}if (LevelNumber == 2) {

		Message m;
		m.Psource = this;
		m.location = this->getpos();
		m.type = EventType::LEVEL_START;
		Pom_->SendMessageW(m);

		playeralive = true;
		mouse = new MousePointer();
		mouse->initiliase();
		Pom_->AddObject(mouse);
		spawnInterval = 2.0f;
		pos.set(-1500, -900);
		player->setpos(pos);
		player->setammo(50,10,5,2);
		player->sethealth(100);
		player->initialize(Pom_);
		
		Pom_->AddObject(player);
		player->setmouse(mouse);

		
		
		// Platform stuff
			
		Platform* platform = new Platform();
		platform->initialize();
		platform->setpos(Vector2D(-1200, -780));
		Pom_->AddObject(platform);


		Platform* platform2 = new Platform();
		platform2->initialize();
		platform2->setpos(Vector2D(-550, -780));
		Pom_->AddObject(platform2);


		Platform* platform3 = new Platform();
		platform3->initialize();
		platform3->setpos(Vector2D(0, -780));
		Pom_->AddObject(platform3);


		Platform* platform4 = new Platform();
		platform4->initialize();
		platform4->setpos(Vector2D(550, -780));
		Pom_->AddObject(platform4);



		Platform* platform5= new Platform();
		platform5->initialize();
		platform5->setpos(Vector2D(1000, -580));

		Pom_->AddObject(platform5);

	
		Platform* platform6 = new Platform();
		platform6->initialize();
		platform6->setpos(Vector2D(550, -380));
	
		Pom_->AddObject(platform6);
		


		Platform* platform7 = new Platform();
		platform7->initialize();
		platform7->setpos(Vector2D(0, -380));
		
		Pom_->AddObject(platform7);


		Platform* platform8 = new Platform();
		platform8->initialize();
		platform8->setpos(Vector2D(-600, -380));

		Pom_->AddObject(platform8);


		Platform* platform9 = new Platform();
		platform9->initialize();
		platform9->setpos(Vector2D(-850, -180));
	
		Pom_->AddObject(platform9);

		Platform* platform10 = new Platform();
		platform10->initialize();
		platform10->setpos(Vector2D(-650, 0));
	
		Pom_->AddObject(platform10);



		Platform* platform11 = new Platform();
		platform11->initialize();
		platform11->setpos(Vector2D(-450, 200));
	
		Pom_->AddObject(platform11);

		Platform* platform12 = new Platform();
		platform12->initialize();
		platform12->setpos(Vector2D(-50, 200));
		
		Pom_->AddObject(platform12);


		Platform* platform13 = new Platform();
		platform13->initialize();
		platform13->setpos(Vector2D(400, 200));
		
		Pom_->AddObject(platform13);

		Platform* platform14 = new Platform();
		platform14->initialize();
		platform14->setpos(Vector2D(1000, 400));
		
		Pom_->AddObject(platform14);


		Platform* platform15 = new Platform();
		platform15->initialize();
		platform15->setpos(Vector2D(1500, 400));
		
		Pom_->AddObject(platform15);



		Platform* platform16 = new Platform();
		platform16->initialize();
		platform16->setpos(Vector2D(-1500, -950));
		
		Pom_->AddObject(platform16);


		Platform* platform17 = new Platform();
		platform17->initialize();
		platform17->setpos(Vector2D(-1000, -950));

		Pom_->AddObject(platform17);


		Lava* lava = new Lava();
		lava->initialize();
		lava->setpos(Vector2D(-1200, -1000));
		lavapos = lava->getpos();
		Pom_->AddObject(lava);
	



		Lava* lava2 = new Lava();
		lava2->initialize();
		lava2->setpos(Vector2D(-200, -1000));
		lavapos2 = lava2->getpos();
		Pom_->AddObject(lava2);






		Lava* lava3 = new Lava();
		lava3->initialize();
		lava3->setpos(Vector2D(800, -1000));
		lavapos3 = lava3->getpos();
		Pom_->AddObject(lava3);




		Lava* lava4 = new Lava();
		lava4->initialize();
		lava4->setpos(Vector2D(1800, -1000));
		lavapos4 = lava4->getpos();
		Pom_->AddObject(lava4);



	}		
	if (LevelNumber == 3) {
		Message m;
		m.Psource = this;
		m.location = this->getpos();
		m.type = EventType::LEVEL_START;
		Pom_->SendMessageW(m);

		mouse = new MousePointer();
		mouse->initiliase();
		Pom_->AddObject(mouse);
		spawnInterval = 2.0f;



		playeralive = true;


		pos.set(-1500, -900);
		player->setpos(pos);
		player->setammo(50,10,5,20);
		player->sethealth(10);
		player->initialize(Pom_);
		Pom_->AddObject(player);
		player->setmouse(mouse);







	



		MasterHand* masterhand = new MasterHand();
		masterhand->setMainchar(player);
	
		masterhand->setdirection(false);
		masterhand->initialize(Pom_);
		masterhand->setpos(Vector2D(0, 0));
	
		
		Pom_->AddObject(masterhand);
		
		
		
		
		
		MasterHand* masterhand2 = new MasterHand();
		masterhand2->setMainchar(player);

		masterhand2->setdirection(true);
		masterhand2->initialize(Pom_);
		masterhand2->setpos(Vector2D(400, 0));
		
		
		Pom_->AddObject(masterhand2);



	
				


	}
}



void LevelManager::playerDeath(float frametime) {
	playeralive = false;

	if (!playeralive && playerLives > 0) {
		respawnTimer += frametime;
		
	}

	if (respawnTimer >= 5 && LevelNumber == 1) {
		playeralive = true;
		playerLives = playerLives - 1;
		respawnTimer = 0;
		numZombiesSpawned = 0;
		ZombiesDead = 0;
		FlyersSpawned = 0;
		flyersdead = 0;
		spawnInterval = 2.0f;
		timer = 0.0f;
		flyertimer = 0.0f;
		score = 0;
		StartLevel(Pom_);
		
	}




	if (respawnTimer >= 5 && LevelNumber == 2) {
		playeralive = true;
		playerLives = playerLives - 1;
		respawnTimer = 0;
		laserTimer = 0;
		//numZombiesSpawned = 0;
		//ZombiesDead = 0;
		FlyersSpawned2 = 0;
		//flyersdead = 0;
		//spawnInterval = 2.0f;
		//timer = 0.0f;
		flyertimer2 = 0.0f;
		//score = 0;
		lavaSwitch = false;
		StartLevel(Pom_);
		Lasertrig = false;
		score = permaScore;
		lavatimer = 600;

	}



	if (respawnTimer >= 5 && LevelNumber == 3) {
		playeralive = true;
		handsdead = 0;
		respawnTimer = 0;

		playerLives = playerLives - 1;
		StartLevel(Pom_);
		score = permaScore;
		

	}
	

	MyDrawEngine::GetInstance()->WriteInt(Vector2D(500, 900), respawnTimer, MyDrawEngine::WHITE);

	// i could put both death and player death handlers together but this is easier to work with. First one is for variables second one is for object removal
}





void LevelManager::update(float frametime) {
	
	if (player->gethealth() <= 0) {
		playerDeath(frametime);
	}

	AddScore();
	DeathHandler();









	if (handsdead == 2) {
		MasterHead* masterhead = new MasterHead();
		masterhead->setMainchar(player);


		masterhead->initialize(Pom_);
		masterhead->setpos(Vector2D(0, 0));

		player->setammo(50, 10, 5,2);
		Pom_->AddObject(masterhead);

		handsdead++; // soo it dosent creeate infinite bosses
	}

	
	
	if (numZombiesSpawned < 10 && timer <= 0 && LevelNumber == 1 && playeralive) {
		Zombies* zombies = new Zombies();
		
	
		zombies->setpos(Vector2D(1504, -900));
		
		zombies->initialize(Pom_);
		zombies->setplayer(player);
		Pom_->AddObject(zombies);
		
		timer = rand()%5 + 1; // reset the timer
		numZombiesSpawned++;
		//int numZombiesOnScreen = 0;
		
	
	}timer -= frametime;
	
	
	/*int numZombiesOnScreen = 0;

	for (GameObj* obj : Pom_->Getobjs()) {
		if (dynamic_cast<Zombies*>(obj) != nullptr) {
			numZombiesOnScreen = numZombiesOnScreen++;
		}
		ZombiesDead = numZombiesSpawned- numZombiesOnScreen;
	}
	
	
	
	
	Old way of counting enemies, not needed*/
	
	// create enemy again;




	if (FlyersSpawned < 5 && flyertimer <= 0 && LevelNumber == 1 && playeralive) {
		
		EnemyShooter* flyer = new EnemyShooter();
		flyer->setpos(Vector2D(1504, 200));
		
		flyer->initialize(Pom_);
		flyer->setMainchar(player);
		

		
		Pom_->AddObject(flyer);
		flyertimer = rand()%10 + 1; // reset the timer
		FlyersSpawned++;

	}
	/*int flyersonscreen = 0;

	for (GameObj* obj : Pom_->Getobjs()) {
		if (dynamic_cast<EnemyShooter*>(obj) != nullptr) {
			flyersonscreen = flyersonscreen++;
			
		}
		flyersdead = FlyersSpawned- flyersonscreen;
	}
	*/
	flyertimer -= frametime;






		// Start of Level 2
	if (player->getpos().XValue >= 1450 && LevelNumber == 1) {
		permaScore = permaScore + score; // do this for level2 as well :)
		LevelNumber = 2;
		player->setactive(false);
		mouse->setactive(false);
		for (GameObj* obj : Pom_->Getobjs()) {
			if (dynamic_cast<Zombies*>(obj) != nullptr) {
				obj->setactive(false);
				
			
			}
			
		}

		for (GameObj* obj : Pom_->Getobjs()) {
			if (dynamic_cast<EnemyShooter*>(obj) != nullptr) {
				obj->setactive(false);
				
			}
			
		}

		// cant really delete bullets as they are made within the objects idk how to fix that 
		// i fixed it by having the message system send a message for the bullets to deactivate, couldve done that for enenmies as well but too late now
		// plus this method still works fine
		//player->setposition(Vector2D(-1500, -900));
		StartLevel(Pom_);
	}



	// start of level 3







	

	//lava control

	if (lavaSwitch)
	{


		if (lavatimer <= 0 && LevelNumber == 2 && playeralive == true) {
			// Create a new Lava object on top of the current one

			//Lava* newLava = new Lava();

			//Vector2D newPosition(lavapos.XValue, lavapos.YValue + 30); // Set the new position above the current one

			//lavapos = newPosition;

			//newLava->setposition(newPosition); // Set the position of the new Lava object
			//newLava->initialize(Pom_); // Initialize the new Lava object
			//Pom_->AddObject(newLava);
			//// reset timer for it is in milliseconds  due to using frametime probably a way around that but it works, was due to int and not float



			//// lava1 need multiple due to it not fitting on the screen 



			//Lava* newLava2 = new Lava();

			//Vector2D newPosition2(lavapos2.XValue, lavapos2.YValue + 30); // Set the new position above the current one

			//lavapos2 = newPosition2;

			//newLava2->setposition(newPosition2); // Set the position of the new Lava object
			//newLava2->initialize(Pom_); // Initialize the new Lava object
			//Pom_->AddObject(newLava2);






			//Lava* newLava3 = new Lava();

			//Vector2D newPosition3(lavapos3.XValue, lavapos3.YValue + 30); // Set the new position above the current one

			//lavapos3 = newPosition3;

			//newLava3->setposition(newPosition3); // Set the position of the new Lava object
			//newLava3->initialize(Pom_); // Initialize the new Lava object
			//Pom_->AddObject(newLava3);



			//Lava* newLava4 = new Lava();

			//Vector2D newPosition4(lavapos4.XValue, lavapos4.YValue + 30); // Set the new position above the current one

			//lavapos4 = newPosition4;

			//newLava4->setposition(newPosition4); // Set the position of the new Lava object
			//newLava4->initialize(Pom_); // Initialize the new Lava object
			//Pom_->AddObject(newLava4);
			// this works but i need to make 4 of these as the lava just isnt big enough to fill the whole screen Also horrible fps  drop here jesus
			// due to the fps drop, im considering not using frametime for the calculation, its just not very accurate allows the player to cheese this part
			// Old method without engine edit




			for (GameObj* obj : Pom_->Getobjs()) {
				if (dynamic_cast<Lava*>(obj) != nullptr) {
					Lava* plava = dynamic_cast<Lava*>(obj);
					plava->setheight(0.5, 6);
				}

				//new method with engine edit, lava now has some functionaility to set height and stuff
				// weridly enough , this method works on all lava objects, which makes life so much easier than going through each lava blockkand increasing them
				// this is why a new function getobjs() is super helpful, allows me to edit a large amount of duplicate objects with 1 line of code
			}


			if (player->getpos().YValue > -500) {

				for (GameObj* obj : Pom_->Getobjs()) {
					if (dynamic_cast<Lava*>(obj) != nullptr) {
						Lava* plava = dynamic_cast<Lava*>(obj);
						plava->setheight(0.9, 12);
					}

					
				}
			}

			lavatimer = 85;








		}
		lavatimer -= frametime;



	}
	


	// Laser stuff
	
	
	
		if (player->getpos().YValue > 200&& LevelNumber ==2)
		{
			Lasertrig = true;

	
		
		
		}

		if (laserTimer >= 8 && Lasertrig == true) {
			//laserTimer = 0;
			Lasertrig = false;
			for (GameObj* obj : Pom_->Getobjs()) {
				if (dynamic_cast<Laser*>(obj) != nullptr) {
					Laser* plaser = dynamic_cast<Laser*>(obj);
					plaser->setactive(false);
				}
			}


		}
	// cant do it if its = 0 because the game object takes a second to get the position of player, and triggers it instantly 
	// issue fixed, i had 2 positions setters and gettersm causing chaos, removed and adjusted code





		if (Lasertrig) {
 		
			if (laserTimer >= 0 &&  playeralive == true) 
				{
				MyDrawEngine::GetInstance()->DrawLine(Vector2D(-1900, 300), Vector2D(1900, 300), MyDrawEngine::WHITE);
				laserTimer = laserTimer + frametime;
				}
				if (laserTimer >= 2 && playeralive == true)
				{
					MyDrawEngine::GetInstance()->DrawLine(Vector2D(-1900, 300), Vector2D(1900, 300), MyDrawEngine::GREEN);
					laserTimer = laserTimer + frametime;
				}
				if (laserTimer >= 3 &&  playeralive == true)
				{
					MyDrawEngine::GetInstance()->DrawLine(Vector2D(-1900, 300), Vector2D(1900, 300), MyDrawEngine::RED);
				
				// this causes a bit of an fps drop, but i think its because i constantly am drawing a line overlapping, not game breaking but eh
					Laser* laser = new Laser();
					laser->initialize(Pom_);
					laser->setpos(Vector2D(-1900, 300));
					Pom_->AddObject(laser);
				}
			

					
			
		
		
		
		
		
		
		}


























		if (FlyersSpawned2 < 15 && flyertimer2 <= 0 && LevelNumber == 2 && playeralive == true) {

			EnemyShooter* flyer = new EnemyShooter();
			flyer->setpos(Vector2D(1504, 700));

			flyer->initialize(Pom_);
			flyer->setMainchar(player);



			Pom_->AddObject(flyer);
			flyertimer2 = rand() % 10; // reset the timer
			FlyersSpawned2 ++;

		}
		flyertimer2 -= frametime;







	
	
	
	
	

		if (player->getpos().XValue >= 1450 && LevelNumber == 2 && player->getpos().YValue >= 450) {


			player->setactive(false);
			mouse->setactive(false);
			for (GameObj* obj : Pom_->Getobjs()) {
				if (dynamic_cast<EnemyShooter*>(obj) != nullptr) {
					obj->setactive(false);

				}

			}



			for (GameObj* obj : Pom_->Getobjs()) {
				if (dynamic_cast<Platform*>(obj) != nullptr) {
					obj->setactive(false);

				}

			}

			for (GameObj* obj : Pom_->Getobjs()) {
				if (dynamic_cast<Lava*>(obj) != nullptr) {
					obj->setactive(false);
					lavaSwitch = false;
				}

			}


			Pom_->deleteinactive(); // had to place this cuz for 1 frame, the lava kills the player which is kinda sad, forces Obj manager to delete 
									// lava before next level, ensuring the player does not die on level start

			permaScore =  score; 

			
	

				LevelNumber = 3;

				playeralive = true;

				StartLevel(Pom_);
			
		
		

				
		}



		// player limits
		if (player->getpos().XValue <= -1500 && LevelNumber ==1) {
			player->setpos(Vector2D(-1500,player->getpos().YValue));
		}
	
		if (player->getpos().XValue <= -1500 && LevelNumber == 2) {
			player->setpos(Vector2D(-1500, player->getpos().YValue));
		}
		if (player->getpos().XValue <= -1500 && LevelNumber == 3) {
			player->setpos(Vector2D(-1500, player->getpos().YValue));
		}


		if (player->getpos().XValue >= 1500 && LevelNumber == 3) {
			player->setpos(Vector2D(1500, player->getpos().YValue));
		}

	
		// end of player limits
		// its here and not coded in spaceship due to me wanting to only limit <- direction and not -> in other levels except level 3
		// mouse pointer broke with same logic due to Mpos
	// So setting the ground only works if the player jumps at least once. This is due to the ground level being only used when jumping. This is becoming annoying
	// This is due to me trying to be smart and using walk left and right in GameObj, without adding gravity to them. Must be a way around this without changing GameObj
	// this is the last thing i need to focus on tho. Lets focus on finishing the game first fully and get to this part
}



void LevelManager::render()
{
	MyDrawEngine::GetInstance()->WriteText(Vector2D(-1600, 900), L"Level", MyDrawEngine::WHITE);
	MyDrawEngine::GetInstance()->WriteInt(Vector2D(-1500, 900), LevelNumber, MyDrawEngine::WHITE);

	MyDrawEngine::GetInstance()->WriteText(Vector2D(-1200, 900), L"Score", MyDrawEngine::WHITE);
	MyDrawEngine::GetInstance()->WriteInt(Vector2D(-1100, 900), score, MyDrawEngine::WHITE);


	MyDrawEngine::GetInstance()->WriteText(Vector2D(950, 900), L"Health", MyDrawEngine::WHITE);
	MyDrawEngine::GetInstance()->WriteInt(Vector2D(1100, 900), player->gethealth(), MyDrawEngine::WHITE);


	MyDrawEngine::GetInstance()->WriteText(Vector2D(1350, 900), L"Player Lives ", MyDrawEngine::WHITE);
	MyDrawEngine::GetInstance()->WriteInt(Vector2D(1600, 900), playerLives, MyDrawEngine::WHITE);

	




}


IShape2D& LevelManager::GetShape() {
	return Cshape;
}




void LevelManager::AddScore() {
// This isnt really needed because we have a messaging system now.
	
}



void LevelManager::HandleMessage(Message msg) {
	if (msg.type == EventType::EnemyDead && playeralive == true) {
		 
		score = score +100;
		
	}
	if (msg.type == EventType::FlyerDead&& playeralive == true) {

		score = score + 200;

	}



	if (msg.type == EventType::IsOnPlat && playeralive == true) {
		lavaSwitch = true;
	
	
	}



	if (msg.type == EventType::HandDead && playeralive == true) {
		handsdead  ++;
		score = score + 1000;

	}





}


void LevelManager::DeathHandler(){

	// create enemy again;
	// level 1 restart stuff set all actors in screen to be set to false
	if (!playeralive && LevelNumber == 1) {
		for (GameObj* obj : Pom_->Getobjs()) {
			if (dynamic_cast<EnemyShooter*>(obj) != nullptr) {
				obj->setactive(false);

			}

		}
	}


	if (!playeralive && LevelNumber == 1) {
		for (GameObj* obj : Pom_->Getobjs()) {
			if (dynamic_cast<Zombies*>(obj) != nullptr) {
				obj->setactive(false);

			}

		}
	}
	// end of level 1 reset stuff




	// leve2 reset death stuff
	if (!playeralive && LevelNumber == 2) {
		for (GameObj* obj : Pom_->Getobjs()) {
			if (dynamic_cast<Lava*>(obj) != nullptr) {
				obj->setactive(false);

			}

		}
	}




	if (!playeralive && LevelNumber == 2) {
		for (GameObj* obj : Pom_->Getobjs()) {
			if (dynamic_cast<Laser*>(obj) != nullptr) {
				obj->setactive(false);
			
			}

		}
	
		Lasertrig = false;
	}

	if (!playeralive && LevelNumber == 2) {
		for (GameObj* obj : Pom_->Getobjs()) {
			if (dynamic_cast<EnemyShooter*>(obj) != nullptr) {
				obj->setactive(false);

			}

		}
	}

	// end of level 2

	// level 3 stuff


	if (!playeralive && LevelNumber == 3) {
		for (GameObj* obj : Pom_->Getobjs()) {
			if (dynamic_cast<MasterHand*>(obj) != nullptr) {
				obj->setactive(false);

			}

		}
	}


	if (!playeralive && LevelNumber == 3) {
		for (GameObj* obj : Pom_->Getobjs()) {
			if (dynamic_cast<MasterHead*>(obj) != nullptr) {
				obj->setactive(false);

			}

		}
	}


	// always do this as i make a new mousepointer every time you die soo its safe :)
	if (!playeralive) {
		for (GameObj* obj : Pom_->Getobjs()) {
			if (dynamic_cast<MousePointer*>(obj) != nullptr) {
				obj->setactive(false);

			}

		}
	}
}