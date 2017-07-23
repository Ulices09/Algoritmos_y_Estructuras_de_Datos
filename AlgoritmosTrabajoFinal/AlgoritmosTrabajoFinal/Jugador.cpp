#include "Jugador.h"
#include <string.h>
#pragma warning(disable:4996)

Jugador::Jugador(){}

Jugador::Jugador(int _posX, int _posY, char* _archivoImagen, double _zoom){
	posicionX = _posX;
	posicionY = _posY;
	deltaX = 0;
	deltaY = 0;
	ancho = 45;
	alto = 73;
	indiceSpriteX = 0;
	indiceSpriteY = 0;
	deltaSpriteX = 0;
	deltaSpriteY = 0;
	tipo = 1;
	visible = true;
	experiencia = 0;
	dinero = 0;
	archivoImagen = new char[100];
	strcpy(archivoImagen, _archivoImagen);	
	nivel = 1;
	vida = 50 + (nivel - 1) * 15;
	vidaActual = vida;
	fuerza = 20 + (nivel - 1) * 5;
	defensa = 10 + (nivel - 1) * 3;
	expNecesaria = nivel * 100;
	zoom = _zoom;
	arma = nullptr;
	mision = nullptr;
}

Jugador::~Jugador(){ delete[] archivoImagen; }

void Jugador::Mostrar(System::Drawing::Graphics ^gr){
	if (visible){
		System::Drawing::Bitmap ^bmp = gcnew System::Drawing::Bitmap(gcnew System::String(archivoImagen));
		System::Drawing::Rectangle porcion = System::Drawing::Rectangle(ancho*indiceSpriteX, alto*indiceSpriteY, ancho, alto);
		System::Drawing::Rectangle destino = System::Drawing::Rectangle(posicionX, posicionY, ancho*zoom, alto*zoom);
		bmp->MakeTransparent(bmp->GetPixel(1, 1));

		gr->DrawImage(bmp, destino, porcion, System::Drawing::GraphicsUnit::Pixel);
		//gr->DrawRectangle(System::Drawing::Pens::Red, posicionX, posicionY, ancho*zoom, alto*zoom);
		delete bmp;
	}
}

int Jugador::GetExpNecesaria(){
	return expNecesaria;
}
void Jugador::SetZoom(double _zoom){
	zoom = _zoom;
}

Arma* Jugador::GetArma(){
	return arma;
}

void Jugador::SetArma(Arma* _arma, bool _primeraVez){

	if (_primeraVez == false)
		fuerza -= arma->GetFuerza();

	arma = _arma;
	fuerza += arma->GetFuerza();
}

Mision* Jugador::GetMision(){
	return mision;
}

void Jugador::SetMision(Mision* _mision){
	mision = _mision;
}

void Jugador::SubirNivel(int _nivel)
{
	if (_nivel < nivel){
		expNecesaria = _nivel * 100;
		experiencia = expNecesaria*0.9;
	}
	else{
		expNecesaria = _nivel * 100;
		experiencia = 0;
	}

	nivel = _nivel;
	vida = 50 + (nivel - 1) * 15;
	vidaActual = vida;
	fuerza = 15 + (nivel - 1) * 5 + arma->GetFuerza();
	defensa = 10 + (nivel - 1) * 3;
	
}

