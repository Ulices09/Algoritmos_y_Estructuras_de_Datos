#pragma once

template <class T>
class ArbolRN
{
private:
	struct Nodo
	{
		T* dato;
		int id;
		char color;
		Nodo* izq;
		Nodo* der;
		Nodo* padre;
	};

	Nodo* raiz;
public:
	ArbolRN();
	~ArbolRN();

	void Insercion(int _id, T* _dato);
	void SolucionarRojoRojo(Nodo* _nodo, int h);
	T* Buscar(int _id);
};
