#pragma once
#include "ObjetoAnimado.h"
#include "Atributo.h"
#include "Arma.h"
#include "Mision.h"

class Jugador :public ObjetoAnimado, public Atributo
{
private:
	int expNecesaria;
	double zoom;
	Arma* arma;
	Mision* mision;
public:
	Jugador();
	Jugador(int _posX, int _posY, char* _archivoImagen, double _zoom);
	~Jugador();

	void Mostrar(System::Drawing::Graphics ^gr);
	int GetExpNecesaria();
	void SetZoom(double _zoom);
	Arma* GetArma();
	void SetArma(Arma* _arma, bool _primeraVez);
	Mision* GetMision();
	void SetMision(Mision* _mision);
	void SubirNivel(int _nivel);
};

