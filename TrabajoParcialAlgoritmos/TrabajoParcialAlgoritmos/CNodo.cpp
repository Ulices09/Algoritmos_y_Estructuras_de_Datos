#include "CNodo.h"
#include <stdio.h>
#include <string.h>
using namespace System::Windows::Forms;
#pragma warning (disable:4996)

CNodo::CNodo(){}

CNodo::~CNodo(){}

CNodo::CNodo(int _x, int _y, char* _dato){
	cuadrado.X = _x;
	cuadrado.Y = _y;
	strcpy(cuadrado.dato, _dato);
	cuadrado.lado = 60;
	next = NULL;

	System::Random ^r = gcnew System::Random;
	cuadrado.color = r->Next();

	cuadrado.relleno = false;
	cuadrado.eliminar = false;

	posicion = 0;
}

void CNodo::Mostrar(Graphics ^gr){
	if (!cuadrado.eliminar){
		if (cuadrado.relleno)
		{
			System::Random ^r = gcnew System::Random;
			Color clr = ColorTranslator::FromWin32(r->Next());
			gr->FillRectangle(gcnew SolidBrush(clr), cuadrado.X, cuadrado.Y, cuadrado.lado, cuadrado.lado);			
			gr->DrawString(gcnew System::String(getDato()), gcnew Font("Arial", 8), gcnew SolidBrush(Color::Azure), cuadrado.X + cuadrado.lado / 2 - 5, cuadrado.Y + cuadrado.lado / 2 - 5);
			gr->DrawString(posicion.ToString(), gcnew Font("Arial", 8), gcnew SolidBrush(Color::Red), cuadrado.X + cuadrado.lado / 2 - 5, cuadrado.Y + cuadrado.lado + 10);
		}
		else
		{
			Color clr = ColorTranslator::FromWin32(cuadrado.color);
			gr->DrawRectangle(gcnew Pen(clr, 4), cuadrado.X, cuadrado.Y, cuadrado.lado, cuadrado.lado);
			gr->DrawString(gcnew System::String(cuadrado.dato), gcnew Font("Arial", 8), gcnew SolidBrush(clr), cuadrado.X + cuadrado.lado / 2 - 5, cuadrado.Y + cuadrado.lado / 2 - 5);
			gr->DrawString(posicion.ToString(), gcnew Font("Arial", 8), gcnew SolidBrush(Color::Red), cuadrado.X + cuadrado.lado / 2 - 5, cuadrado.Y + cuadrado.lado + 10);
		}
	}
}

CNodo* CNodo::getNext(){
	return next;
}
void CNodo::setNext(CNodo* _next){
	next = _next;
}

void CNodo::setPosicion(int pos){
	posicion = pos;
}

void CNodo::setX(int x){
	cuadrado.X = x;
}

int CNodo::getPosicion(){
	return posicion;
}

char* CNodo::getDato(){
	return cuadrado.dato;
}

void CNodo::setRelleno(bool _flag){
	cuadrado.relleno = _flag;
}

void CNodo::setEliminar(bool flag){
	cuadrado.eliminar = flag;
}

void CNodo::setY(int y){
	cuadrado.Y = y;
}