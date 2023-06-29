#include "Lava.h"


IShape2D& Lava::GetShape() {
    return Cshape;
}

void Lava::CheckCollisions(GameObj& other) {




}



void Lava::initialize() {
    
    setactive(true);
    MyDrawEngine* pDE = MyDrawEngine::GetInstance();
    index_ = pDE->LoadPicture(L"Lava.bmp");
    
}




void Lava::render() {

    MyDrawEngine* pDE = MyDrawEngine::GetInstance();
    pDE->DrawAt(getpos(), index_, 0.5f, height,genangle(),0);
    

//pDE->FillRect( Cshape, pDE->LIGHTGREEN);
}


void Lava::setheight(float PublicHeight, float PublicColHeight) {
    height = height +PublicHeight;
    ColHeight = ColHeight+ PublicColHeight;
}


void Lava::update(float frametime) {
   

   
    Cshape.PlaceAt(getpos().YValue + ColHeight, getpos().XValue + 550, getpos().YValue - 35, getpos().XValue - 550);
//    ColHeight = ColHeight + 1.2;
  //  height = height + 0.1;
}





void Lava::HandleMessage(Message msg) {

}







float Lava::getHeight(){
    return height;
}



float Lava::getColheight() {
    return ColHeight;
}