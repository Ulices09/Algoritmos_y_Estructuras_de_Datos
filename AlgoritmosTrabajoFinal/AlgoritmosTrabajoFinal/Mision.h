#pragma once
class Mision
{
private:
	char* descripcion;
	int tipoEnemigo;
	int cantidadEnemigos;
	int cantidadActual;
	int experiencia;
	int dinero;
	bool finalizado;
	int id;
public:
	Mision();
	Mision(char* _descripcion, int _tipoEnemigo, int _cantidadEnemigo, int _experiencia, int _dinero, bool _finalizado, int _id);
	~Mision();

	char* GetDescripcion();
	int GetTipoEnemigo();
	int GetCantidadEnemigos();
	int GetCantidadActual();
	int GetExperiencia();
	int GetDinero();
	bool GetFinalizado();
	int GetID();

	void SetDescripcion(char* _descripcion);
	void SetTipoEnemigo(int _tipoEnemigo);
	void SetCantidadEnemigos(int _cantidadEnemigos);
	void SetCantidadActual(int _cantidadActual);
	void Finalizado(bool _finalizado);
};

