#pragma once
#include "ObjetoAnimado.h"

class Mapa : public ObjetoAnimado
{
private:
	double zoom;
	int zoomX;
	int zoomY;
public:
	Mapa();
	Mapa(int _zoomX, int _zoomY, double _zoom, int _posX, int _posY, int _ancho, int _alto, int _tipo, bool _visible, char* _archivoImagen, int _indiceSpriteX, int _indiceSpriteY, int _deltaSpriteX, int _deltaSpriteY);
	~Mapa();

	void Mostrar(System::Drawing::Graphics ^gr);
};

