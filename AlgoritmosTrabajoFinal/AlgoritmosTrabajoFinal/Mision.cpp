#include "Mision.h"
#include <string.h>
#pragma warning(disable:4996)

Mision::Mision(){}

Mision::Mision(char* _descripcion, int _tipoEnemigo, int _cantidadEnemigo, int _experiencia, int _dinero, bool _finalizado, int _id){
	descripcion = new char[100];
	strcpy(descripcion, _descripcion);
	tipoEnemigo = _tipoEnemigo;
	cantidadEnemigos = _cantidadEnemigo;
	cantidadActual = _cantidadEnemigo;
	experiencia = _experiencia;
	dinero = _dinero;
	finalizado = _finalizado;
	id = _id;
}

Mision::~Mision(){}



char* Mision::GetDescripcion(){
	return descripcion;
}

int Mision::GetTipoEnemigo(){
	return tipoEnemigo;
}

int Mision::GetCantidadEnemigos(){
	return cantidadEnemigos;
}

int Mision::GetCantidadActual(){
	return cantidadActual;
}

int Mision::GetExperiencia(){
	return experiencia;
}

int Mision::GetDinero(){
	return dinero;
}

bool Mision::GetFinalizado(){
	return finalizado;
}

int Mision::GetID(){
	return id;
}

void Mision::SetDescripcion(char* _descripcion){
	descripcion = _descripcion;
}

void Mision::SetTipoEnemigo(int _tipoEnemigo){
	tipoEnemigo = _tipoEnemigo;
}

void Mision::SetCantidadEnemigos(int _cantidadEnemigos){
	cantidadEnemigos = _cantidadEnemigos;
}

void Mision::SetCantidadActual(int _cantidadActual){
	cantidadActual = _cantidadActual;
}

void Mision::Finalizado(bool _finalizado){
	finalizado = _finalizado;
}
