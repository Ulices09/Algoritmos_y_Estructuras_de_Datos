#include "Atributo.h"


Atributo::Atributo(){}


Atributo::~Atributo(){}

int Atributo::GetVida(){
	return vida;
}

int Atributo::GetFuerza(){
	return fuerza;
}

int Atributo::GetDefensa(){
	return defensa;
}

int Atributo::GetVidaActual(){
	return vidaActual;
}


void Atributo::SetVida(int _vida){
	vida = _vida;
}

void Atributo::SetFuerza(int _fuerza){
	fuerza = _fuerza;
}

void Atributo::SetDefensa(int _defensa){
	defensa = _defensa;
}

void Atributo::SetVidaActual(int _vidaActual){
	vidaActual = _vidaActual;
}