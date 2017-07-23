#pragma once
#include "ObjetoAnimado.h"
#include "Atributo.h"

class Enemigo :public ObjetoAnimado, public Atributo
{
private:
	int zoom;
public:
	Enemigo();
	Enemigo(int _posX, int _posY, int _ancho, int _alto, int _nivel, int _exp, int _dinero, int _tipo, char* _archivoImagen, int _zoom);
	~Enemigo();

	void Mostrar(System::Drawing::Graphics ^gr);
	void SetZoom(int _zoom);
};

