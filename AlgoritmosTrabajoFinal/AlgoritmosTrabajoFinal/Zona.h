#pragma once
#include "ObjetoAnimado.h"

class Zona :public ObjetoAnimado
{
public:
	Zona();
	Zona(int _posX, int _posY, int _ancho, int _alto);
	~Zona();

	void Mostrar(System::Drawing::Graphics ^gr);
};

