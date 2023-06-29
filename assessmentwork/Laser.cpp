#include "Laser.h"


IShape2D& Laser::GetShape() {
    return Cshape;
}

void Laser::CheckCollisions(GameObj& other) {




}



void Laser::initialize(ObjectManager* Pom_) {
    Pom = Pom_;
    setactive(true);
}




void Laser::render() {

    //MyDrawEngine* pDE = MyDrawEngine::GetInstance();
   // pDE->FillRect( Cshape, pDE->LIGHTGREEN);
}


void Laser::setheight(float PublicHeight, float PublicColHeight) {
    height = height + PublicHeight;
    ColHeight = ColHeight + PublicColHeight;
}


void Laser::update(float frametime) {



    Cshape.PlaceAt(getpos().YValue + ColHeight, getpos().XValue + 3550, getpos().YValue - 35, getpos().XValue - 550);
    //    ColHeight = ColHeight + 1.2;
      //  height = height + 0.1;
}




void Laser::HandleMessage(Message msg) {

}










float Laser::getHeight() {
    return height;
}



float Laser::getColheight() {
    return ColHeight;
}