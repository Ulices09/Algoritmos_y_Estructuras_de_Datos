#include "ArbolRN.h"

template <typename T>
ArbolRN<T>::ArbolRN()
{
	raiz = nullptr;
}

template <typename T>
ArbolRN<T>::~ArbolRN()
{
}

template <typename T>
void ArbolRN<T>::Insercion(int _id, T* _dato){
	int ladohijo;
	Nodo* hijo;
	Nodo* ayudante;
	int bandera;
	if (!raiz){
		raiz = new Nodo();
		raiz->id = _id;
		raiz->dato = _dato;
		raiz->padre = nullptr;
		raiz->izq = nullptr;
		raiz->der = nullptr;
		raiz->color = 'n';
	}
	else{
		hijo = new Nodo();
		hijo->id = _id;
		hijo->dato = _dato;
		hijo->padre = nullptr;
		hijo->izq = nullptr;
		hijo->der = nullptr;
		hijo->color = 'r';
		ayudante = raiz;
		do{
			hijo->padre = ayudante, bandera = 1;
			if (_id < ayudante->id){
				if (ayudante->izq) ayudante = ayudante->izq;
				else ayudante->izq = hijo, bandera = 0, ladohijo = 1;
			}
			else{
				if (ayudante->der) ayudante = ayudante->der;
				else ayudante->der = hijo, bandera = 0, ladohijo = 2;
			}
		} while (bandera == 1);
		if (ayudante->color == 'r') SolucionarRojoRojo(ayudante, ladohijo);
	}
}

template <typename T>
void ArbolRN<T>::SolucionarRojoRojo(Nodo* _nodo, int h){
	int ladohijo;
	Nodo* abuelo;
	Nodo* tio;
	Nodo* ayudante;
	abuelo = _nodo->padre;
	if (abuelo->izq && abuelo->der){
		if (_nodo == abuelo->izq) tio = abuelo->der;
		else tio = abuelo->izq;
		if (tio->color == 'r'){
			tio->color = 'n'; _nodo->color = 'n';
			if (abuelo != raiz) abuelo->color = 'r';
			if (abuelo->padre){
				ayudante = abuelo->padre;
				if (ayudante->izq == abuelo) ladohijo = 1;
				else ladohijo = 2;
				if (ayudante->color == 'r') SolucionarRojoRojo(ayudante, ladohijo);
			}
			return;
		}
	}
	if (h == 1 && abuelo->izq == _nodo){
		_nodo->color = 'n', abuelo->color = 'r';
		ayudante = _nodo->der, _nodo->der = abuelo, _nodo->padre = abuelo->padre;
		abuelo->padre = _nodo, abuelo->izq = ayudante;
		if (ayudante) ayudante->padre = abuelo;
		if (_nodo->padre){
			ayudante = _nodo->padre;
			if (ayudante->izq == _nodo->der) ayudante->izq = _nodo;
			else ayudante->der = _nodo;
		}
		else raiz = _nodo;
	}
	else if (h == 2 && abuelo->der == _nodo){
		_nodo->color = 'n', abuelo->color = 'r';
		ayudante = _nodo->izq, _nodo->izq = abuelo, _nodo->padre = abuelo->padre;
		abuelo->padre = _nodo, abuelo->der = ayudante;
		if (ayudante) ayudante->padre = abuelo;
		if (_nodo->padre){
			ayudante = _nodo->padre;
			if (ayudante->izq == _nodo->izq) ayudante->izq = _nodo;
			else ayudante->der = _nodo;
		}
		else raiz = _nodo;
	}
	else if (h == 2 && abuelo->izq == _nodo){
		tio = _nodo->der, ayudante = tio->izq, abuelo->izq = tio;
		tio->padre = abuelo, tio->izq = _nodo, _nodo->padre = tio;
		_nodo->der = ayudante;
		if (ayudante) ayudante->padre = _nodo;
		SolucionarRojoRojo(tio, 1);
	}
	else if (h == 1 && abuelo->der == _nodo){
		tio = _nodo->izq, ayudante = tio->der, abuelo->der = tio;
		tio->padre = abuelo, tio->der = _nodo, _nodo->padre = tio;
		_nodo->izq = ayudante;
		if (ayudante) ayudante->padre = _nodo;
		SolucionarRojoRojo(tio, 2);
	}
}

template <typename T>
T* ArbolRN<T>::Buscar(int _id){
	Nodo* ayudante;
	ayudante = raiz;
	if (!ayudante) return nullptr;
	do{
		if (_id == ayudante->id) return ayudante->dato;
		else if (_id < ayudante->id) ayudante = ayudante->izq;
		else if (_id > ayudante->id) ayudante = ayudante->der;
	} while (ayudante);
	return nullptr;
}
