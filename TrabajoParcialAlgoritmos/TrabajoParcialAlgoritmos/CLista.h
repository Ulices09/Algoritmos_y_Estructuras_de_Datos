#pragma once
#include "CNodo.h"

class CLista
{
private:
	CNodo* nodoInicio;
	int size = 0;
public:
	CLista();
	~CLista();

	int getSize();
	void InsertarInicio(int _x, int _y, char* _dato);
	void insertarFin(int _x, int _y, char* _dato);
	void insertarEnPosicion(int _x, int _y, char* _dato, int _posicion);
	void buscar(char* _dato);
	void eliminar(char* _dato);
	bool quitarRelleno(bool _flag);
	void mostrar(Graphics ^gr);
	void ordenarNodos();
	
};

