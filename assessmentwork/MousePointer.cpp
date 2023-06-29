#include "MousePointer.h"

void MousePointer::initiliase(){
	setactive(true);
	Mpos.set(0, 0);
	
	MyDrawEngine* pDE = MyDrawEngine::GetInstance();
	img = pDE->LoadPicture(L"crosshairw.bmp");
}


void MousePointer::update(float frametime) {
	MyDrawEngine* pDE = MyDrawEngine::GetInstance();
	MyInputs* pinputs = MyInputs::GetInstance();
	pinputs->SampleMouse();

	Mpos.XValue = Mpos.XValue + pinputs->GetMouseDX();
	Mpos.YValue = Mpos.YValue - pinputs->GetMouseDY();



	
	// mouse limits using width and height soo it workss on all resolutions not sure if that was an issue but better safe than sorry
	if (Mpos.XValue<= -(pDE->GetScreenWidth()-200)) {
		Mpos.set(Vector2D(-(pDE->GetScreenWidth()-200), Mpos.YValue));
	}

	if (Mpos.XValue >= (pDE->GetScreenWidth()-200)) {
		Mpos.set(Vector2D((pDE->GetScreenWidth() -200), Mpos.YValue));
	}

	if (Mpos.YValue <= -(pDE->GetScreenHeight()-100)) {
		Mpos.set(Vector2D(Mpos.XValue, -(pDE->GetScreenHeight() - 100)));
	}
	if (Mpos.YValue >= +(pDE->GetScreenHeight() -100)) {
		Mpos.set(Vector2D(Mpos.XValue, (pDE->GetScreenHeight() -100)));
	}



	setpos(Mpos);
	if (pinputs->IfMouseLeftDown()) {
		click();
	}
}
void MousePointer::render() {
	MyDrawEngine* pDE = MyDrawEngine::GetInstance();
	pDE->DrawAt(getpos(), img, 0.01f);
}


void MousePointer::click() {
	MyInputs* pinputs = MyInputs::GetInstance();
	pinputs->SampleMouse();
	
}



IShape2D& MousePointer::GetShape() {
	return m_shape;
}

void MousePointer::HandleMessage(Message msg) {

}