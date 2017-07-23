#include "Mapa.h"
#include <string.h>
#pragma warning(disable:4996)

Mapa::Mapa()
{
}

Mapa::Mapa(int _zoomX, int _zoomY, double _zoom, int _posX, int _posY, int _ancho, int _alto, int _tipo, bool _visible, char* _archivoImagen, int _indiceSpriteX, int _indiceSpriteY, int _deltaSpriteX, int _deltaSpriteY){
	zoomX = _zoomX;
	zoomY = _zoomY;
	zoom = _zoom;
	posicionX = _posX;
	posicionY = _posY;
	deltaX = 0;
	deltaY = 0;
	ancho = _ancho;
	alto = _alto;
	tipo = _tipo;
	visible = _visible;
	strcpy(archivoImagen, _archivoImagen);
	indiceSpriteX = _indiceSpriteX;
	indiceSpriteY = _indiceSpriteY;
	deltaSpriteX = _deltaSpriteX;
	deltaSpriteY = _deltaSpriteY;
}

Mapa::~Mapa()
{
	delete[] archivoImagen;
}

void Mapa::Mostrar(System::Drawing::Graphics ^gr){
	if(visible) {
		System::Drawing::Bitmap ^bmp = gcnew System::Drawing::Bitmap(gcnew System::String(archivoImagen));
		System::Drawing::Rectangle destino = System::Drawing::Rectangle(0, 0, ancho + zoomX, alto + zoomY);
		System::Drawing::Rectangle porcion = System::Drawing::Rectangle(posicionX, posicionY, ancho*zoom, alto*zoom);
		gr->DrawImage(bmp, destino, porcion, System::Drawing::GraphicsUnit::Pixel);
		System::Drawing::Font ^font = gcnew System::Drawing::Font("Lucida Sans", 10);
		gr->DrawString(System::Convert::ToString(posicionX) + " " + System::Convert::ToString(posicionY), font, System::Drawing::Brushes::Black, 20, 20);
		delete bmp;
	}
}