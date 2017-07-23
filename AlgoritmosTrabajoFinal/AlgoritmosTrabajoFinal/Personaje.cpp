#include "Personaje.h"
#include <string.h>
#pragma warning(disable:4996)

Personaje::Personaje(){}

Personaje::Personaje(int _posX, int _posY, int _ancho, int _alto, char* _archivoImagen, double _zoom){
	posicionX = _posX;
	posicionY = _posY;
	ancho = _ancho;
	alto = _alto;
	strcpy(archivoImagen, _archivoImagen);
	zoom = _zoom;
	visible = true;
}

Personaje::~Personaje(){}

void Personaje::Mostrar(System::Drawing::Graphics ^gr){
	if (visible){
		System::Drawing::Bitmap ^bmp = gcnew System::Drawing::Bitmap(gcnew System::String(archivoImagen));
		bmp->MakeTransparent(bmp->GetPixel(1, 1));
		gr->DrawImage(bmp, posicionX, posicionY, ancho*zoom, alto*zoom);
		//gr->DrawRectangle(System::Drawing::Pens::Red, posicionX, posicionY, ancho*zoom, alto*zoom);
		delete bmp;
	}
}
