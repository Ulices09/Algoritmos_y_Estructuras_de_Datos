#include "Arma.h"
#include <string.h>
#pragma warning(disable:4996)

Arma::Arma(){}


Arma::~Arma(){}

Arma::Arma(char* _nombre, int _fuerza, int _id){
	nombre = new char[50];
	strcpy(nombre, _nombre);
	fuerza = _fuerza;
	id = _id;
}

char* Arma::GetNombre(){
	return nombre;
}

int Arma::GetID(){
	return id;
}
