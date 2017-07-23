#include "Zona.h"

Zona::Zona(){}

Zona::Zona(int _posX, int _posY, int _ancho, int _alto){
	posicionX = _posX;
	posicionY = _posY;
	ancho = _ancho;
	alto = _alto;
	deltaX = 0;
	deltaY = 0;
	visible = true;
}

Zona::~Zona(){}

void Zona::Mostrar(System::Drawing::Graphics ^gr){
	if (visible) 
		gr->DrawRectangle(gcnew System::Drawing::Pen(System::Drawing::Color::Red), posicionX, posicionY, ancho, alto);
}