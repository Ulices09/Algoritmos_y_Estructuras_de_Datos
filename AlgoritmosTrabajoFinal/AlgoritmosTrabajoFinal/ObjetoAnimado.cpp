#include "ObjetoAnimado.h"
#include <string.h>
#pragma warning(disable:4996)

ObjetoAnimado::ObjetoAnimado(){
	archivoImagen = new char[100];
}

ObjetoAnimado::~ObjetoAnimado(){
	delete[] archivoImagen;
}

int ObjetoAnimado::GetPosicionX(){
	return posicionX;
}

int ObjetoAnimado::GetPosicionY(){
	return posicionY;
}

int ObjetoAnimado::GetDeltaX(){
	return deltaX;
}

int ObjetoAnimado::GetDeltaY(){
	return deltaY;
}

int ObjetoAnimado::GetAncho(){
	return ancho;
}

int ObjetoAnimado::GetAlto(){
	return alto;
}

int ObjetoAnimado::GetIndiceSpriteX(){
	return indiceSpriteX;
}

int ObjetoAnimado::GetIndiceSpriteY(){
	return indiceSpriteY;
}

int ObjetoAnimado::GetDeltaSpriteX(){
	return deltaSpriteX;
}

int ObjetoAnimado::GetDeltaSpriteY(){
	return deltaSpriteY;
}

int ObjetoAnimado::GetTipo(){
	return tipo;
}

bool ObjetoAnimado::GetVisible(){
	return visible;
}

int ObjetoAnimado::GetNivel(){
	return nivel;
}

int ObjetoAnimado::GetExperiencia(){
	return experiencia;
}

int ObjetoAnimado::GetDinero(){
	return dinero;
}

char* ObjetoAnimado::GetArchivoImagen(){
	return archivoImagen;
}

void ObjetoAnimado::SetPosicionX(int _posicionX){
	posicionX = _posicionX;
}

void ObjetoAnimado::SetPosicionY(int _posicionY){
	posicionY = _posicionY;
}

void ObjetoAnimado::SetAncho(int _ancho){
	ancho = _ancho;
}

void ObjetoAnimado::SetAlto(int _alto){
	alto = _alto;
}

void ObjetoAnimado::SetIndiceSpriteX(int _indiceSpriteX){
	indiceSpriteX = _indiceSpriteX;
}

void ObjetoAnimado::SetIndiceSpriteY(int _indiceSpriteY){
	indiceSpriteY = _indiceSpriteY;
}

void ObjetoAnimado::SetDeltaSpriteX(int _deltaSpriteX){
	deltaSpriteX = _deltaSpriteX;
}

void ObjetoAnimado::SetDeltaSpriteY(int _deltaSpriteY){
	deltaSpriteY = _deltaSpriteY;
}

void ObjetoAnimado::SetTipo(int _tipo){
	tipo = _tipo;
}

void ObjetoAnimado::SetVisible(bool _visible){
	visible = _visible;
}

void ObjetoAnimado::SetNivel(int _nivel){
	nivel = _nivel;
}

void ObjetoAnimado::SetExperiencia(int _experiencia){
	experiencia = _experiencia;
}

void ObjetoAnimado::SetDinero(int _dinero){
	dinero = _dinero;
}

void ObjetoAnimado::SetDeltaX(int _deltaX){
	deltaX = _deltaX;
}

void ObjetoAnimado::SetDeltaY(int _deltaY){
	deltaY = _deltaY;
}

void ObjetoAnimado::SetArchivoImagen(char* _archivo){
	strcpy(archivoImagen, _archivo);
}

void ObjetoAnimado::Mover(){
	posicionX = posicionX + deltaX;
	posicionY = posicionY + deltaY;
}

void ObjetoAnimado::CambiarSprite(){
	indiceSpriteX = indiceSpriteX + deltaSpriteX;
	indiceSpriteY = indiceSpriteY + deltaSpriteY;
}

void ObjetoAnimado::Mostrar(System::Drawing::Graphics ^gr){}
