#pragma once
#include "ObjetoAnimado.h"

class Imagen :public ObjetoAnimado
{
private:
	double zoomX;
	double zoomY;
	bool transparente;
public:
	Imagen();
	Imagen(int _posX, int _posY, int _ancho, int _alto, double _zoomX, double _zoomY, char* _archivoImagen, bool _transparente, bool _visible);
	~Imagen();
	void Mostrar(System::Drawing::Graphics ^gr);
};

