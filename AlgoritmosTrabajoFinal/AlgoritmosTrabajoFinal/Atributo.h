#pragma once
class Atributo
{
protected:
	int vida;
	int vidaActual;
	int fuerza;
	int defensa;
public:
	Atributo();
	~Atributo();

	int GetVida();
	int GetFuerza();
	int GetDefensa();
	int GetVidaActual();

	void SetVida(int _vida);
	void SetFuerza(int _fuerza);
	void SetDefensa(int _defensa);
	void SetVidaActual(int _vidaActual);
};

