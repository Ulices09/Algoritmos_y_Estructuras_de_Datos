#include "Enemigo.h"
#include <string.h>
#pragma warning(disable:4996)

Enemigo::Enemigo(){}

Enemigo::Enemigo(int _posX, int _posY, int _ancho, int _alto, int _nivel, int _exp, int _dinero, int _tipo, char* _archivoImagen, int _zoom){
	posicionX = _posX;
	posicionY = _posY;
	deltaX = 0;
	deltaY = 0;
	indiceSpriteX = 0;
	indiceSpriteY = 0;
	deltaSpriteX = 0;
	deltaSpriteY = 0;
	ancho = _ancho;
	alto = _alto;
	nivel = _nivel;
	visible = true;
	vida = 40 + (nivel - 1) * 13;
	vidaActual = vida;
	fuerza = 15 + (nivel - 1) * 4;
	defensa = 7 + (nivel - 1) * 3;
	experiencia = _exp;
	dinero = _dinero;
	strcpy(archivoImagen, _archivoImagen);
	zoom = _zoom;
	tipo = _tipo;
}

Enemigo::~Enemigo(){ delete[] archivoImagen; }

void Enemigo::Mostrar(System::Drawing::Graphics ^gr){
	if (visible) {
		System::Drawing::Bitmap ^bmp = gcnew System::Drawing::Bitmap(gcnew System::String(archivoImagen));
		bmp->MakeTransparent(bmp->GetPixel(1, 1));

		gr->DrawImage(bmp, posicionX, posicionY, ancho*zoom, alto*zoom);
		//gr->DrawRectangle(System::Drawing::Pens::Red, posicionX, posicionY, ancho*zoom, alto*zoom);
		delete bmp;
	}
}

void Enemigo::SetZoom(int _zoom) {
	zoom = _zoom;
}
