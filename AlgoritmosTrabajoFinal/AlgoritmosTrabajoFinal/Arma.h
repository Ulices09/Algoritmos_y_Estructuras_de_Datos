#pragma once
#include "Atributo.h"
class Arma :public Atributo
{
private:
	char* nombre;
	int id;
public:
	Arma();
	Arma(char* _nombre, int _fuerza, int _id);
	~Arma();

	char* GetNombre();
	int GetID();
};

