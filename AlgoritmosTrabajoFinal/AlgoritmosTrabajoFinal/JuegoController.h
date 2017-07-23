#pragma once
#include <vector>

using namespace std;
using namespace System::Drawing;

#include "ObjetoAnimado.h"
#include "Jugador.h"
#include "Personaje.h"
#include "Mapa.h"
#include "Imagen.h"
#include "Enemigo.h"
#include "Zona.h"
#include "Mision.h"
#include "Arma.h"
#include "ArbolRN.h"
#include "ArbolRN.cpp"

class JuegoController
{
private:
	Jugador* jugador;

	//Imagenes
	Imagen* menuInicio;
	Imagen* seleccion;
	Imagen* fin;
	Imagen* guardar;

	//Mapas
	Mapa* continente;
	Mapa* dungeon1;
	Mapa* dungeon2;
	Mapa* dungeon3;
	Mapa* dungeon4;
	Mapa* dungeon5;
	Mapa* dungeon6;
	Mapa* dungeon7;
	Mapa* ciudad;
	Mapa* batallContinente;

	//Zonas restringidas
	vector<Zona*> lstZonasRestringidasContinente;
	vector<Zona*> lstZonasRestringidasdun1;
	vector<Zona*> lstZonasRestringidasdun2;
	vector<Zona*> lstZonasRestringidasdun3;
	vector<Zona*> lstZonasRestringidasdun4;
	vector<Zona*> lstZonasRestringidasdun5;
	vector<Zona*> lstZonasRestringidasdun6;
	vector<Zona*> lstZonasRestringidasdun7;
	vector<Zona*> lstZonasRestringidasciudad;

	//Enemigos
	vector<Enemigo*> lstEnemigosContinente;
	vector<Enemigo*> lstEnemigosdun1;
	vector<Enemigo*> lstEnemigosdun2;
	vector<Enemigo*> lstEnemigosdun3;
	vector<Enemigo*> lstEnemigosdun4;
	vector<Enemigo*> lstEnemigosdun5;
	vector<Enemigo*> lstEnemigosdun6;
	vector<Enemigo*> lstEnemigosdun7;

	//Bosses
	Enemigo* boss1;
	Enemigo* boss2;
	Enemigo* boss3;
	Enemigo* boss4;
	
	//Personajes
	Personaje* campesino;

	//Misiones
	ArbolRN<Mision> arbolMisiones;

	//Armas
	ArbolRN<Arma> arbolArmas;

	int estado;
	int seleccion_menu;
	bool mostrarEnemigo = true;
	//Batallas
	Enemigo* enemigoActual;
	int faseBatalla;//1.-Turno jugador   2.-Se muestra el daño del juegador 3.- Se muestra el daño del enemigo 0.- Fin batalla
	int seleccionFaseBatalla; //1.- Atcar  2.- Defender
	int damage;
	int ganador; //0.-Aun no hay ganador   1.-Gana jugador    2.-Gana enemigo
	int expGanada;
	int oroGanado;
	int anteriorEstado; //Guarda el mapa anterior

	//Guardar
	int seleccionGuardar; //1.- Guardar 0.- Cancelar
public:
	JuegoController();
	~JuegoController();

	void Mostrar(System::Drawing::Graphics ^gr);
	void Mover(System::Windows::Forms::Keys _tecla);
	void MostrarInfoPersonaje(System::Drawing::Graphics ^gr, Mapa* _mapa);
	bool HabraColision(ObjetoAnimado* _objeto1, ObjetoAnimado* _objeto2);
	bool HayColision(ObjetoAnimado* _objeto1, ObjetoAnimado* _objeto2);

	//Zonas restringidas
	void AgregarZonasRestringidasContinente();
	void AgregarZonasRestringidasdun1();
	void AgregarZonasRestringidasdun2();
	void AgregarZonasRestringidasdun3();
	void AgregarZonasRestringidasdun4();
	void AgregarZonasRestringidasdun5();
	void AgregarZonasRestringidasdun6();
	void AgregarZonasRestringidasdun7();
	void AgregarZonasRestringidasciudad();
	void SetDeltaZonasRestringidas(int _x, int _y);
	void MoverZonasRestringidas();

	//Enemigos
	void AgregarEnemigos(short n, short v1, short v2, vector<Zona*>lstZonasRestringidas,short est);
	void SetDeltaEnemigos(int _x, int _y);	
	void MoverEnemigos();

	//Misiones
	void AgregarMisiones();

	//Armas
	void AgregarArnas();

	//Batalla
	void SetPosicionesBatalla();
	void MostrarAtaques(System::Drawing::Graphics ^gr);
	void ComprobarGanador();

	//Archivos
	void GuardarArchivo();
	void AbrirArchivo();
	void MostrarPantallaGuardado(System::Drawing::Graphics ^gr);
};

