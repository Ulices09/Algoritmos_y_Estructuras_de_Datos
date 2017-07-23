#include "CLista.h"
#include "CNodo.h"
#include <stdio.h>
#include <string.h>
using namespace System::Windows::Forms;
#pragma warning (disable:4996)

CLista::CLista(){ nodoInicio = NULL; }

CLista::~CLista(){}

int CLista::getSize(){
	return size;
}

void CLista::InsertarInicio(int _x, int _y, char* _dato){
	if (size >= 24) return;
	CNodo* nodoNuevo = new CNodo(_x, _y, _dato);
	if (nodoInicio == NULL){
		nodoInicio = nodoNuevo;
	}
	else
	{
		nodoNuevo->setNext(nodoInicio);
		nodoInicio = nodoNuevo;
	}
	size++;
}

void CLista::insertarFin(int _x, int _y, char* _dato){
	if (size >= 24) return;
	CNodo* nodoNuevo = new CNodo(_x, _y, _dato);
	CNodo* nodoRecorre = nodoInicio;

	if (nodoInicio == NULL){
		nodoInicio = nodoNuevo;
	}
	else
	{
		while (nodoRecorre->getNext() != NULL)
			nodoRecorre = nodoRecorre->getNext();
		nodoRecorre->setNext(nodoNuevo);
	}
	size++;
}

void CLista::insertarEnPosicion(int _x, int _y, char* _dato, int _posicion){
	if (size >= 24) return;
	CNodo* nodoNuevo = new CNodo(_x, _y, _dato);
	CNodo* nodoRecorre = nodoInicio;
	CNodo* nodoAnterior = NULL;

	if (nodoInicio == NULL){
		nodoInicio = nodoNuevo;
		size++;
		return;
	}

	if (nodoInicio->getNext() == NULL){
		if (_posicion == 1){
			nodoNuevo->setNext(nodoInicio);
			nodoInicio = nodoNuevo; size++;
			return;
		}
		else if (_posicion == 2){
			nodoInicio->setNext(nodoNuevo); size++;
			return;
		}
		else{
			MessageBox::Show("Posición ingresada no es válidad"); return;
		}
	}

	while (nodoRecorre != NULL){
		if (nodoRecorre->getPosicion() == _posicion){
			if (_posicion == 1){
				nodoNuevo->setNext(nodoInicio);
				nodoInicio = nodoNuevo; size++;
				return;
			}
			else{
				if (nodoAnterior != NULL)
					nodoAnterior->setNext(nodoNuevo);
				nodoNuevo->setNext(nodoRecorre); size++;
				return;
			}
		}
		else if (_posicion > size){
			while (nodoRecorre->getNext() != NULL)
				nodoRecorre = nodoRecorre->getNext();
			nodoRecorre->setNext(nodoNuevo);
			size++; return;
		}

		nodoAnterior = nodoRecorre;
		nodoRecorre = nodoRecorre->getNext();
	}

	MessageBox::Show("Posición ingresada no es válidad");
}

void CLista::buscar(char* _dato){
	CNodo* nodoRecorre = nodoInicio;
	unsigned int encontro = 0;
	while (nodoRecorre != NULL){
		if (strcmp(nodoRecorre->getDato(), _dato) == 0){
			nodoRecorre->setRelleno(true);
			encontro = 1;
		}			
		nodoRecorre = nodoRecorre->getNext();
	}

	if (encontro == 0){
		MessageBox::Show("Dato no encontrado");
	}
}

void CLista::eliminar(char* _dato){
	CNodo* nodoRecorre = nodoInicio;
	CNodo* anterior = NULL;
	unsigned int encontro = 0;
	while (nodoRecorre != NULL)
	{
		if (strcmp(nodoRecorre->getDato(), _dato) == 0){
			if (nodoRecorre == nodoInicio){
				nodoRecorre->setEliminar(true);
				nodoInicio = nodoRecorre->getNext();
				encontro = 1;
				size--;
			}
			else{
				nodoRecorre->setEliminar(true);
				anterior->setNext(nodoRecorre->getNext());
				encontro = 1;
				size--;
			}
			//return;
		}

		anterior = nodoRecorre;
		nodoRecorre = nodoRecorre->getNext();
	}
	
	if (encontro == 0) MessageBox::Show("Dato no encontrado");
}

bool CLista::quitarRelleno(bool _flag){
	bool flag = _flag;
	if (nodoInicio != NULL && flag == true){
		CNodo* nodoRecorre = nodoInicio;
		while (nodoRecorre != NULL){
			nodoRecorre->setRelleno(false);
			nodoRecorre = nodoRecorre->getNext();
		} flag = false;
	}
	return flag;
}

void CLista::mostrar(Graphics ^gr){
	
	if (nodoInicio != NULL){
		CNodo* nodoRecorre = nodoInicio;
		while (nodoRecorre != NULL){
			nodoRecorre->Mostrar(gr);
			nodoRecorre = nodoRecorre->getNext();
		}
	}
}

void CLista::ordenarNodos(){
	if (nodoInicio != NULL){
		CNodo* nodoRecorre = nodoInicio;
		int t = getSize();
		int pos = 1;
		int x = 70;
		int y = 150;

		while (nodoRecorre != NULL){
			if (pos == 13){
				x = 70;
				y = 250;
			}
			else if (pos < 13 && y == 250){
				x = 70 + (x - 70);
				y = 150;
			}

			nodoRecorre->setX(x);
			nodoRecorre->setY(y);
			nodoRecorre->setPosicion(pos);
			x += 70;			
			pos++;
			nodoRecorre = nodoRecorre->getNext();
		}
	}
}
