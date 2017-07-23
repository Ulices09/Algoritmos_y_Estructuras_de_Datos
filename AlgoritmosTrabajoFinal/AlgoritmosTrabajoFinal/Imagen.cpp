#include "Imagen.h"
#include <string.h>
#pragma warning(disable:4996)

Imagen::Imagen(){}


Imagen::~Imagen(){}

Imagen::Imagen(int _posX, int _posY, int _ancho, int _alto, double _zoomX, double _zoomY, char* _archivoImagen, bool _transparente, bool _visible){
	posicionX = _posX;
	posicionY = _posY;
	ancho = _ancho;
	alto = _alto;
	zoomX = _zoomX;
	zoomY = _zoomY;
	strcpy(archivoImagen, _archivoImagen);
	transparente = _transparente;
	visible = _visible;
}

void Imagen::Mostrar(System::Drawing::Graphics ^gr){
	if (visible) {
		System::Drawing::Bitmap ^bmp = gcnew System::Drawing::Bitmap(gcnew System::String(archivoImagen));
		if (transparente) bmp->MakeTransparent(bmp->GetPixel(1, 1));

		gr->DrawImage(bmp, posicionX, posicionY, ancho*zoomX, alto*zoomY);
		//gr->DrawRectangle(System::Drawing::Pens::Red, posicionX, posicionY, ancho*zoom, alto*zoom);
		delete bmp;
	}
}
