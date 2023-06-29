#include "Platform.h"


IShape2D& Platform::GetShape() {
    return Cshape;
}

void Platform::CheckCollisions(GameObj& other) {
    if (typeid(other) == typeid(Lava)) {
        setactive(false);

    }

}



void Platform::initialize() {
  
    setactive(true);
    MyDrawEngine* pDE = MyDrawEngine::GetInstance();
    index_ = pDE->LoadPicture(L"GrassBlock.bmp");
}




void Platform::render() {

    MyDrawEngine* pDE = MyDrawEngine::GetInstance();
    pDE->DrawAt(getpos(), index_, 0.5f, genangle());
    //pDE->FillRect( Cshape, pDE->LIGHTGREEN);
}


void Platform::update(float frametime) {
    
    Cshape.PlaceAt(getpos().YValue+25,getpos().XValue+255,getpos().YValue-25,getpos().XValue-255);
}



Vector2D Platform::Getcorner() {
    Corner =     Cshape.GetCorner1();
    return Corner;
}


void Platform::HandleMessage(Message msg) {

}



int Platform::GetCollisionPos(Vector2D targetPos) {
    float Top = Cshape.GetTopLeft().YValue;
    float Left = Cshape.GetTopLeft().XValue;
   
    
    float Bottom = Cshape.GetBottomRight().YValue;
    float Right = Cshape.GetBottomRight().XValue;
    if (targetPos.YValue > Top) {
        if (targetPos.XValue < Left) {
            return 8;
            
        }
    
    
        else if(targetPos.XValue > Right)
        {
            return 2;
        }
        else
        {


            return 1;
        }
    
    
    
    }

    else if(targetPos.YValue < Bottom)
    {
        

        if (targetPos.XValue < Left) {
            return 6;
        }


        else if (targetPos.XValue > Right)
        {
            return 4;
        }
        else
        {
            return 5;
        }



    



    }
    else
    {
        if (targetPos.XValue < Left) {
            return 7;
        }
        else if(targetPos.XValue > Right){
            return 3;
        }
        else {
            return 0;
        }

    }
    return 0;

}