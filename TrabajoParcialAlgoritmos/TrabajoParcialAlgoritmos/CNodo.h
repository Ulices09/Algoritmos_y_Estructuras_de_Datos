#pragma once
using namespace System::Drawing;

struct Cuadrado{
	int X;
	int Y;

	int lado;
	int color;
	char dato[1];

	bool relleno;
	bool eliminar;
};

class CNodo
{
private:
	Cuadrado cuadrado;
	int posicion;
	CNodo* next;
public:
	CNodo();
	CNodo(int _x, int _y, char* _dato);
	~CNodo();

	void Mostrar(Graphics ^gr);
	CNodo* getNext();
	void setNext(CNodo* _next);
	void setPosicion(int pos);
	int getPosicion();
	char* getDato();
	void setRelleno(bool _flag);
	void setX(int x);
	void setY(int y);
	void setEliminar(bool flag);
};

