#pragma once
#include "ObjetoAnimado.h"
class Personaje :public ObjetoAnimado
{
private:
	double zoom;
public:
	Personaje();
	Personaje(int _posX, int _posY, int _ancho, int _alto, char* _archivoImagen, double _zoom);
	~Personaje();

	void Mostrar(System::Drawing::Graphics ^gr);
};

