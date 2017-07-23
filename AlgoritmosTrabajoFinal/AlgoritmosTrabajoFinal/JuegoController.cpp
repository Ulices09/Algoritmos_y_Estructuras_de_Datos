#include "JuegoController.h"
#include <fstream>
#include <string>

using namespace std;

JuegoController::JuegoController()
{
	//Misiones
	AgregarMisiones();

	//Armas
	AgregarArnas();

	//Juagador
	jugador = new Jugador(350, 250, "jugador.png", 0.75);
	jugador->SetArma(arbolArmas.Buscar(0), true);
	jugador->SetMision(arbolMisiones.Buscar(0));

	//NPCs
	campesino = new Personaje(270, 75, 30, 40, "campesino.png", 1);

	//Imagenes
	menuInicio = new Imagen(0, 0, 960, 640, 0.85, 0.9, "menu_inicio.jpg", false, true);
	seleccion = new Imagen(220, 355, 50, 50, 1, 1, "seleccion.jpg", true, true);
	fin = new Imagen(0, 0, 790, 580, 1, 1, "fin.png", false, true);
	guardar = new Imagen(0, 0, 790, 580, 1, 1, "guardar.png", false, true);

	//Mapas
	continente = new Mapa(0, 0, 0.5, 558, 564, 2157, 2057, 1, true, "mapa_continente.png", 0, 0, 0, 0);
	dungeon1 = new Mapa(0, 0, 0.5, 792, 436, 1298, 1182, 2, true, "dungeon1.png", 0, 0, 0, 0);
	dungeon2 = new Mapa(0, 0, 0.5, 68, 408, 1361, 781, 3, true, "dungeon2.png", 0, 0, 0, 0);
	dungeon3 = new Mapa(0, 0, 0.5, 728, 98, 1298, 1182, 4, true, "dungeon3.png", 0, 0, 0, 0);
	dungeon4 = new Mapa(0, 0, 0.5, 156, 875, 1298, 1182, 5, true, "dungeon4.png", 0, 0, 0, 0);
	dungeon5 = new Mapa(0, 0, 0.5, -16, 23, 1298, 1182, 6, true, "dungeon5.png", 0, 0, 0, 0);
	dungeon6 = new Mapa(0, 0, 0.5, 62, 212, 1298, 1182, 7, true, "dungeon6.gif", 0, 0, 0, 0);
	dungeon7 = new Mapa(0, 0, 0.5, 54, 564, 1298, 1182, 8, true, "dungeon7.gif", 0, 0, 0, 0);
	ciudad = new Mapa(0, 0, 0.5, 216, 210, 1298, 1182, 9, true, "ciudad.gif", 0, 0, 0, 0);//55

	//MapaBatalla
	batallContinente = new Mapa(0, 0, 0.5, 0, 0, 800, 600, 1, true, "batalla_continente.png", 0, 0, 0, 0);

	//Zonas restringidas
	AgregarZonasRestringidasContinente();
	AgregarZonasRestringidasdun1();
	AgregarZonasRestringidasdun2();
	AgregarZonasRestringidasdun3();
	AgregarZonasRestringidasdun4();
	AgregarZonasRestringidasdun5();
	AgregarZonasRestringidasdun6();
	AgregarZonasRestringidasdun7();
	AgregarZonasRestringidasciudad();

	//Enemigos
	AgregarEnemigos(50, rand() % 1300 + 10, rand() % 1300 + 10, lstZonasRestringidasContinente, 1);
	mostrarEnemigo = true;AgregarEnemigos(100, (rand() % (500 - (-820))) + (-820), (rand() % (900 - (-270))) + (-270), lstZonasRestringidasdun1, 2);
	mostrarEnemigo = true;AgregarEnemigos(100, (rand() % (1800 - 400)) + 400, (rand() % (200 - (-400))) + (-400), lstZonasRestringidasdun2, 3);
	mostrarEnemigo = true;AgregarEnemigos(20, (rand() % (400 - (-800))) + (-800), (rand() % (360 - 100)) + 100, lstZonasRestringidasdun3, 4);
	mostrarEnemigo = true;AgregarEnemigos(100, (rand() % (450 - 200)) + 200, (rand() % (300 - (-1200))) + (-1200), lstZonasRestringidasdun4, 5);
	mostrarEnemigo = true;AgregarEnemigos(100, (rand() % (1300 - 400)) + 400, (rand() % (900 - 200)) + 200, lstZonasRestringidasdun5, 6);
	mostrarEnemigo = true;AgregarEnemigos(100, (rand() % (1800 - 300)) + 300, (rand() % (1100 - (-40))) + (-40), lstZonasRestringidasdun6, 7);
	mostrarEnemigo = true;AgregarEnemigos(100, (rand() % (620 - 155)) + 155, (rand() % ((-390) - (-750))) + (-750), lstZonasRestringidasdun7, 8);

	//Bosses
	boss1 = new Enemigo(-1150, 200, 40, 40, 10, 200, 300, 100, "boss1.png", 1);
	boss2 = new Enemigo(350, -1260, 60, 40, 20, 300, 300, 200, "boss5.png", 1);
	boss3 = new Enemigo(1970, 2750, 40, 40, 30, 400, 300, 300, "boss3.png", 1);
	boss4 = new Enemigo(360, -640, 40, 40, 40, 500, 300, 400, "boss4.png", 1);

	
	estado = 0;
	seleccion_menu = 1;

	//Batalla
	enemigoActual = nullptr;
	faseBatalla = 1;
	seleccionFaseBatalla = 1;
	damage = 0;
	ganador = 0;
	expGanada = 0;
	oroGanado = 0;
	anteriorEstado = 0;

	//Guardar
	seleccionGuardar = 1;
}


JuegoController::~JuegoController() {}
void JuegoController::Mostrar(System::Drawing::Graphics ^gr) {
	if (estado == 0) {//Menu de Inicio
		menuInicio->Mostrar(gr);
		seleccion->Mostrar(gr);
	}
	else if (estado == 1) {//Mapa del continente		
		continente->Mostrar(gr);		
		jugador->Mostrar(gr);
		boss3->Mostrar(gr);
		for (int i = 0; i < lstEnemigosContinente.size(); i++)lstEnemigosContinente.at(i)->Mostrar(gr);
		for (int i = 0; i < lstZonasRestringidasContinente.size(); i++)lstZonasRestringidasContinente.at(i)->Mostrar(gr);
		MostrarInfoPersonaje(gr, continente);

	}
	else if (estado == 2) {//Dungeon 1
		dungeon1->Mostrar(gr);
		jugador->Mostrar(gr);

		for (int i = 0; i < lstEnemigosdun1.size(); i++)lstEnemigosdun1.at(i)->Mostrar(gr);
		//	for (int i = 0; i < lstZonasRestringidasdun1.size(); i++)lstZonasRestringidasdun1.at(i)->Mostrar(gr);
		MostrarInfoPersonaje(gr, dungeon1);
	}
	else if (estado == 3) {//Dungeon 2
		dungeon2->Mostrar(gr);
		jugador->Mostrar(gr);

		for (int i = 0; i < lstEnemigosdun2.size(); i++)lstEnemigosdun2.at(i)->Mostrar(gr);
		//for (int i = 0; i < lstZonasRestringidasdun2.size(); i++)lstZonasRestringidasdun2.at(i)->Mostrar(gr);
		MostrarInfoPersonaje(gr, dungeon2);
	}
	else if (estado == 4) {//Dungeon 3
		dungeon3->Mostrar(gr);
		jugador->Mostrar(gr);
		boss1->Mostrar(gr);
		for (int i = 0; i < lstEnemigosdun3.size(); i++)lstEnemigosdun3.at(i)->Mostrar(gr);
		//for (int i = 0; i < lstZonasRestringidasdun3.size(); i++)lstZonasRestringidasdun3.at(i)->Mostrar(gr);
		MostrarInfoPersonaje(gr, dungeon3);
	}
	else if (estado == 5) {//Dungeon 4
		dungeon4->Mostrar(gr);
		jugador->Mostrar(gr);
		boss2->Mostrar(gr);
		for (int i = 0; i < lstEnemigosdun4.size(); i++)lstEnemigosdun4.at(i)->Mostrar(gr);
		//for (int i = 0; i < lstZonasRestringidasdun4.size(); i++)lstZonasRestringidasdun4.at(i)->Mostrar(gr);
		MostrarInfoPersonaje(gr, dungeon4);
	}
	else if (estado == 6) {//Dungeon 5
		dungeon5->Mostrar(gr);
		jugador->Mostrar(gr);

		for (int i = 0; i < lstEnemigosdun5.size(); i++)lstEnemigosdun5.at(i)->Mostrar(gr);
		//for (int i = 0; i < lstZonasRestringidasdun5.size(); i++)lstZonasRestringidasdun5.at(i)->Mostrar(gr);
		MostrarInfoPersonaje(gr, dungeon5);
	}
	else if (estado == 7) {//Dungeon 6
		dungeon6->Mostrar(gr);
		jugador->Mostrar(gr);

		for (int i = 0; i < lstEnemigosdun6.size(); i++)lstEnemigosdun6.at(i)->Mostrar(gr);
		//for (int i = 0; i < lstZonasRestringidasdun6.size(); i++)lstZonasRestringidasdun6.at(i)->Mostrar(gr);
		MostrarInfoPersonaje(gr, dungeon6);
	}
	else if (estado == 8) {//Dungeon 7
		dungeon7->Mostrar(gr);
		jugador->Mostrar(gr);
		boss4->Mostrar(gr);
		for (int i = 0; i < lstEnemigosdun7.size(); i++)lstEnemigosdun7.at(i)->Mostrar(gr);
		//	for (int i = 0; i < lstZonasRestringidasdun7.size(); i++)lstZonasRestringidasdun7.at(i)->Mostrar(gr);
		MostrarInfoPersonaje(gr, dungeon7);
	}
	else if (estado == 9) {//Ciudad
		ciudad->Mostrar(gr);
		campesino->Mostrar(gr);
		jugador->Mostrar(gr);

		//		for (int i = 0; i < lstEnemigosciudad.size(); i++)lstEnemigosdun3.at(i)->Mostrar(gr); PERSONITAS
		for (int i = 0; i < lstZonasRestringidasciudad.size(); i++)lstZonasRestringidasciudad.at(i)->Mostrar(gr);
		MostrarInfoPersonaje(gr, ciudad);
	}
	else if (estado == 20){
		fin->Mostrar(gr);
	}
	else if (estado == 69) {//Batalla
		batallContinente->Mostrar(gr);
		jugador->Mostrar(gr);
		enemigoActual->Mostrar(gr);
		MostrarInfoPersonaje(gr, batallContinente);
		MostrarAtaques(gr);
	}
	else if (estado == 15){
		MostrarPantallaGuardado(gr);
	}
}
void JuegoController::Mover(System::Windows::Forms::Keys _tecla)
{
	if ((estado != 69 && estado != 0) && _tecla == System::Windows::Forms::Keys::Escape){
		anteriorEstado = estado;
		seleccionGuardar = 1;
		estado = 15;
	}


	if (estado == 0)
	{//Menu de inicio
		if (_tecla == System::Windows::Forms::Keys::Down && seleccion_menu == 1) { seleccion->SetPosicionY(425); seleccion_menu = 2; }
		else if (_tecla == System::Windows::Forms::Keys::Up && seleccion_menu == 2) { seleccion->SetPosicionY(355); seleccion_menu = 1; }
		else if (_tecla == System::Windows::Forms::Keys::Enter)
		{
			if (seleccion_menu == 1) estado = 9;
			else {
				AbrirArchivo();
				estado = 9;
			}
		}
	}
#pragma region  Estado==1 //Continente
	else if (estado == 1) {//Mapa del continente

		if (continente->GetPosicionX() == 406 && continente->GetPosicionY() == 820 && _tecla == System::Windows::Forms::Keys::Enter)
			estado = 2;
		else if (continente->GetPosicionX() == 790 && continente->GetPosicionY() == 1020 && _tecla == System::Windows::Forms::Keys::Enter)
			estado = 3;
		else if (continente->GetPosicionX() == 222 && continente->GetPosicionY() == 1076 && _tecla == System::Windows::Forms::Keys::Enter)
			estado = 4;
		else if (continente->GetPosicionX() == 1334 && continente->GetPosicionY() == 516 && _tecla == System::Windows::Forms::Keys::Enter)
			estado = 5;
		else if (continente->GetPosicionX() == 1374 && continente->GetPosicionY() == 1012 && _tecla == System::Windows::Forms::Keys::Enter)
			estado = 6;
		else if (continente->GetPosicionX() == 1902 && continente->GetPosicionY() == 1580 && _tecla == System::Windows::Forms::Keys::Enter)
			estado = 7;
		else if (continente->GetPosicionX() == 558 && continente->GetPosicionY() == 564 && _tecla == System::Windows::Forms::Keys::Enter)
			estado = 9;
		bool movimiento = false;

		if (_tecla == System::Windows::Forms::Keys::Right) {
			continente->SetDeltaX(8);
			continente->SetDeltaY(0);

			campesino->SetDeltaX(-16);
			campesino->SetDeltaY(0);

			SetDeltaEnemigos(-16, 0);
			SetDeltaZonasRestringidas(-16, 0);

			boss3->SetDeltaX(-16);
			boss3->SetDeltaY(0);

			jugador->SetIndiceSpriteY(2);

			movimiento = true;
		}
		else if (_tecla == System::Windows::Forms::Keys::Left) {
			continente->SetDeltaX(-8);
			continente->SetDeltaY(0);

			campesino->SetDeltaX(16);
			campesino->SetDeltaY(0);

			SetDeltaEnemigos(16, 0);
			SetDeltaZonasRestringidas(16, 0);

			boss3->SetDeltaX(16);
			boss3->SetDeltaY(0);

			jugador->SetIndiceSpriteY(1);

			movimiento = true;
		}
		else if (_tecla == System::Windows::Forms::Keys::Up) {
			continente->SetDeltaX(0);
			continente->SetDeltaY(-8);

			campesino->SetDeltaX(0);
			campesino->SetDeltaY(16);

			SetDeltaEnemigos(0, 16);
			SetDeltaZonasRestringidas(0, 16);

			boss3->SetDeltaX(0);
			boss3->SetDeltaY(16);

			jugador->SetIndiceSpriteY(3);

			movimiento = true;
		}
		else if (_tecla == System::Windows::Forms::Keys::Down) {
			continente->SetDeltaX(0);
			continente->SetDeltaY(8);

			campesino->SetDeltaX(0);
			campesino->SetDeltaY(-16);

			SetDeltaEnemigos(0, -16);
			SetDeltaZonasRestringidas(0, -16);

			boss3->SetDeltaX(0);
			boss3->SetDeltaY(-16);

			jugador->SetIndiceSpriteY(0);

			movimiento = true;
		}

		bool noPasar = false;
		for (int i = 0; i < lstZonasRestringidasContinente.size(); i++)if (HabraColision(jugador, lstZonasRestringidasContinente.at(i))) noPasar = true;

		if (!noPasar && movimiento) {
			continente->Mover();
			campesino->Mover();
			MoverZonasRestringidas();
			MoverEnemigos();
			boss3->Mover();
		}

		if (HayColision(jugador, boss3) && boss3->GetVisible() == true && _tecla == System::Windows::Forms::Keys::Enter){
			anteriorEstado = estado;
			batallContinente->SetArchivoImagen("batalla_continente.png");
			estado = 69;
			enemigoActual = nullptr;
			enemigoActual = boss3;
			SetPosicionesBatalla();
		}

		for (vector<Enemigo*>::iterator i = lstEnemigosContinente.begin(); i != lstEnemigosContinente.end(); ++i)
			if (HayColision(jugador, *i) && (*i)->GetVisible() == true)
			{
				anteriorEstado = estado;
				batallContinente->SetArchivoImagen("batalla_continente.png");
				estado = 69;
				enemigoActual = nullptr;
				enemigoActual = *i;
				SetPosicionesBatalla();
			}

		jugador->SetDeltaSpriteX(1);
		if (jugador->GetIndiceSpriteX() == 1) jugador->SetIndiceSpriteX(0);
		else jugador->CambiarSprite();
	}
#pragma endregion
#pragma region Estado==2 //Dungeon1
	else if (estado == 2) {
		if (dungeon1->GetPosicionX() == 792 && dungeon1->GetPosicionY() == 436 && _tecla == System::Windows::Forms::Keys::Enter)//salida
			estado = 1;

		bool movimiento = false;

		if (_tecla == System::Windows::Forms::Keys::Right) {
			dungeon1->SetDeltaX(8);
			dungeon1->SetDeltaY(0);

			SetDeltaEnemigos(-16, 0);
			SetDeltaZonasRestringidas(-16, 0);
			jugador->SetIndiceSpriteY(2);

			movimiento = true;
		}
		else if (_tecla == System::Windows::Forms::Keys::Left) {
			dungeon1->SetDeltaX(-8);
			dungeon1->SetDeltaY(0);

			SetDeltaEnemigos(16, 0);
			SetDeltaZonasRestringidas(16, 0);
			jugador->SetIndiceSpriteY(1);

			movimiento = true;
		}
		else if (_tecla == System::Windows::Forms::Keys::Up) {
			dungeon1->SetDeltaX(0);
			dungeon1->SetDeltaY(-8);

			SetDeltaEnemigos(0, 16);
			SetDeltaZonasRestringidas(0, 16);
			jugador->SetIndiceSpriteY(3);

			movimiento = true;
		}
		else if (_tecla == System::Windows::Forms::Keys::Down) {
			dungeon1->SetDeltaX(0);
			dungeon1->SetDeltaY(8);

			SetDeltaEnemigos(0, -16);
			SetDeltaZonasRestringidas(0, -16);
			jugador->SetIndiceSpriteY(0);

			movimiento = true;
		}

		bool noPasar = false;
		for (int i = 0; i < lstZonasRestringidasdun1.size(); i++)if (HabraColision(jugador, lstZonasRestringidasdun1.at(i))) noPasar = true;

		if (!noPasar && movimiento) {
			dungeon1->Mover();
			MoverZonasRestringidas();
			MoverEnemigos();
		}
		for (vector<Enemigo*>::iterator i = lstEnemigosdun1.begin(); i != lstEnemigosdun1.end(); ++i)
			if (HayColision(jugador, *i) && (*i)->GetVisible() == true)
			{
				anteriorEstado = estado;
				batallContinente->SetArchivoImagen("batalla1.png");
				estado = 69;
				enemigoActual = nullptr;
				enemigoActual = *i;
				SetPosicionesBatalla();
			}

		jugador->SetDeltaSpriteX(1);
		if (jugador->GetIndiceSpriteX() == 1) jugador->SetIndiceSpriteX(0);
		else jugador->CambiarSprite();
	}
#pragma endregion
#pragma region Estado==3 //Dungeon2
	else if (estado == 3) {

		if (dungeon2->GetPosicionX() == 68 && dungeon2->GetPosicionY() == 408 && _tecla == System::Windows::Forms::Keys::Enter)//salida
			estado = 1;

		bool movimiento = false;

		if (_tecla == System::Windows::Forms::Keys::Right) {
			dungeon2->SetDeltaX(8);
			dungeon2->SetDeltaY(0);

			SetDeltaEnemigos(-16, 0);
			SetDeltaZonasRestringidas(-16, 0);

			jugador->SetIndiceSpriteY(2);

			movimiento = true;
		}
		else if (_tecla == System::Windows::Forms::Keys::Left) {
			dungeon2->SetDeltaX(-8);
			dungeon2->SetDeltaY(0);

			SetDeltaEnemigos(16, 0);
			SetDeltaZonasRestringidas(16, 0);
			jugador->SetIndiceSpriteY(1);

			movimiento = true;
		}
		else if (_tecla == System::Windows::Forms::Keys::Up) {
			dungeon2->SetDeltaX(0);
			dungeon2->SetDeltaY(-8);

			SetDeltaEnemigos(0, 16);
			SetDeltaZonasRestringidas(0, 16);
			jugador->SetIndiceSpriteY(3);

			movimiento = true;
		}
		else if (_tecla == System::Windows::Forms::Keys::Down) {
			dungeon2->SetDeltaX(0);
			dungeon2->SetDeltaY(8);

			SetDeltaEnemigos(0, -16);
			SetDeltaZonasRestringidas(0, -16);
			jugador->SetIndiceSpriteY(0);

			movimiento = true;
		}

		bool noPasar = false;
		for (int i = 0; i < lstZonasRestringidasdun2.size(); i++)if (HabraColision(jugador, lstZonasRestringidasdun2.at(i))) noPasar = true;

		if (!noPasar && movimiento) {
			dungeon2->Mover();
			MoverZonasRestringidas();
			MoverEnemigos();			
		}

		for (vector<Enemigo*>::iterator i = lstEnemigosdun2.begin(); i != lstEnemigosdun2.end(); ++i)
			if (HayColision(jugador, *i) && (*i)->GetVisible() == true)
			{ 
				anteriorEstado = estado;
				batallContinente->SetArchivoImagen("batalla2.png");
				estado = 69;
				enemigoActual = nullptr;
				enemigoActual = *i;
				SetPosicionesBatalla();
			}

		jugador->SetDeltaSpriteX(1);
		if (jugador->GetIndiceSpriteX() == 1) jugador->SetIndiceSpriteX(0);
		else jugador->CambiarSprite();
	}
#pragma endregion
#pragma region Estado==4 //Dungeon3
	else if (estado == 4) {

		if (dungeon3->GetPosicionX() == 728 && dungeon3->GetPosicionY() == 98 && _tecla == System::Windows::Forms::Keys::Enter)//salida
			estado = 1;

		bool movimiento = false;

		if (_tecla == System::Windows::Forms::Keys::Right) {
			dungeon3->SetDeltaX(8);
			dungeon3->SetDeltaY(0);

			SetDeltaEnemigos(-16, 0);
			SetDeltaZonasRestringidas(-16, 0);

			boss1->SetDeltaX(-16);
			boss1->SetDeltaY(0);

			jugador->SetIndiceSpriteY(2);

			movimiento = true;
		}
		else if (_tecla == System::Windows::Forms::Keys::Left) {
			dungeon3->SetDeltaX(-8);
			dungeon3->SetDeltaY(0);

			SetDeltaEnemigos(16, 0);
			SetDeltaZonasRestringidas(16, 0);

			boss1->SetDeltaX(16);
			boss1->SetDeltaY(0);

			jugador->SetIndiceSpriteY(1);

			movimiento = true;
		}
		else if (_tecla == System::Windows::Forms::Keys::Up) {
			dungeon3->SetDeltaX(0);
			dungeon3->SetDeltaY(-8);

			SetDeltaEnemigos(0, 16);
			SetDeltaZonasRestringidas(0, 16);

			boss1->SetDeltaX(0);
			boss1->SetDeltaY(16);

			jugador->SetIndiceSpriteY(3);

			movimiento = true;
		}
		else if (_tecla == System::Windows::Forms::Keys::Down) {
			dungeon3->SetDeltaX(0);
			dungeon3->SetDeltaY(8);

			SetDeltaEnemigos(0, -16);
			SetDeltaZonasRestringidas(0, -16);

			boss1->SetDeltaX(0);
			boss1->SetDeltaY(-16);

			jugador->SetIndiceSpriteY(0);

			movimiento = true;
		}

		bool noPasar = false;
		for (int i = 0; i < lstZonasRestringidasdun3.size(); i++)if (HabraColision(jugador, lstZonasRestringidasdun3.at(i))) noPasar = true;

		if (!noPasar && movimiento) {
			dungeon3->Mover();
			MoverZonasRestringidas();
			MoverEnemigos();
			boss1->Mover();
		}


		if (HayColision(jugador, boss1) && boss1->GetVisible() == true && _tecla == System::Windows::Forms::Keys::Enter){
			anteriorEstado = estado;
			batallContinente->SetArchivoImagen("batalla3.png");
			estado = 69;
			enemigoActual = nullptr;
			enemigoActual = boss1;
			SetPosicionesBatalla();
		}

		for (vector<Enemigo*>::iterator i = lstEnemigosdun3.begin(); i != lstEnemigosdun3.end(); ++i)
			if (HayColision(jugador, *i) && (*i)->GetVisible() == true)
			{
				anteriorEstado = estado;
				batallContinente->SetArchivoImagen("batalla3.png");
				estado = 69;
				enemigoActual = nullptr;
				enemigoActual = *i;
				SetPosicionesBatalla();
			}

		jugador->SetDeltaSpriteX(1);
		if (jugador->GetIndiceSpriteX() == 1) jugador->SetIndiceSpriteX(0);
		else jugador->CambiarSprite();
	}
#pragma endregion
#pragma region Estado==5 //Dungeon4
	else if (estado == 5) {

		if (dungeon4->GetPosicionX() == 156 && dungeon4->GetPosicionY() == 875 && _tecla == System::Windows::Forms::Keys::Enter)//salida
			estado = 1;

		bool movimiento = false;

		if (_tecla == System::Windows::Forms::Keys::Right) {
			dungeon4->SetDeltaX(8);
			dungeon4->SetDeltaY(0);

			SetDeltaEnemigos(-16, 0);
			SetDeltaZonasRestringidas(-16, 0);

			boss2->SetDeltaX(-16);
			boss2->SetDeltaY(0);

			jugador->SetIndiceSpriteY(2);

			movimiento = true;
		}
		else if (_tecla == System::Windows::Forms::Keys::Left) {
			dungeon4->SetDeltaX(-8);
			dungeon4->SetDeltaY(0);

			SetDeltaEnemigos(16, 0);
			SetDeltaZonasRestringidas(16, 0);

			boss2->SetDeltaX(16);
			boss2->SetDeltaY(0);

			jugador->SetIndiceSpriteY(1);

			movimiento = true;
		}
		else if (_tecla == System::Windows::Forms::Keys::Up) {
			dungeon4->SetDeltaX(0);
			dungeon4->SetDeltaY(-8);

			SetDeltaEnemigos(0, 16);
			SetDeltaZonasRestringidas(0, 16);

			boss2->SetDeltaX(0);
			boss2->SetDeltaY(16);

			jugador->SetIndiceSpriteY(3);

			movimiento = true;
		}
		else if (_tecla == System::Windows::Forms::Keys::Down) {
			dungeon4->SetDeltaX(0);
			dungeon4->SetDeltaY(8);

			SetDeltaEnemigos(0, -16);
			SetDeltaZonasRestringidas(0, -16);

			boss2->SetDeltaX(0);
			boss2->SetDeltaY(-16);

			jugador->SetIndiceSpriteY(0);

			movimiento = true;
		}

		bool noPasar = false;
		for (int i = 0; i < lstZonasRestringidasdun4.size(); i++)if (HabraColision(jugador, lstZonasRestringidasdun4.at(i))) noPasar = true;

		if (!noPasar && movimiento) {
			dungeon4->Mover();
			MoverZonasRestringidas();
			MoverEnemigos();
			boss2->Mover();
		}

		if (HayColision(jugador, boss2) && boss2->GetVisible() == true && _tecla == System::Windows::Forms::Keys::Enter){
			anteriorEstado = estado;
			batallContinente->SetArchivoImagen("batalla4.png");
			estado = 69;
			enemigoActual = nullptr;
			enemigoActual = boss2;
			SetPosicionesBatalla();
		}

		for (vector<Enemigo*>::iterator i = lstEnemigosdun4.begin(); i != lstEnemigosdun4.end(); ++i)
		if (HayColision(jugador, *i) && (*i)->GetVisible() == true && _tecla == System::Windows::Forms::Keys::Enter)
			{
				anteriorEstado = estado;
				batallContinente->SetArchivoImagen("batalla4.png");
				estado = 69;
				enemigoActual = nullptr;
				enemigoActual = *i;
				SetPosicionesBatalla();
			}

		jugador->SetDeltaSpriteX(1);
		if (jugador->GetIndiceSpriteX() == 1) jugador->SetIndiceSpriteX(0);
		else jugador->CambiarSprite();
	}
#pragma endregion
#pragma region Estado==6 //Dungeon5
	else if (estado == 6) {

		if (dungeon5->GetPosicionX() == -16 && dungeon5->GetPosicionY() == 23 && _tecla == System::Windows::Forms::Keys::Enter)//salida
			estado = 1;

		bool movimiento = false;

		if (_tecla == System::Windows::Forms::Keys::Right) {
			dungeon5->SetDeltaX(8);
			dungeon5->SetDeltaY(0);

			SetDeltaEnemigos(-16, 0);
			SetDeltaZonasRestringidas(-16, 0);
			jugador->SetIndiceSpriteY(2);

			movimiento = true;
		}
		else if (_tecla == System::Windows::Forms::Keys::Left) {
			dungeon5->SetDeltaX(-8);
			dungeon5->SetDeltaY(0);

			SetDeltaEnemigos(16, 0);
			SetDeltaZonasRestringidas(16, 0);
			jugador->SetIndiceSpriteY(1);

			movimiento = true;
		}
		else if (_tecla == System::Windows::Forms::Keys::Up) {
			dungeon5->SetDeltaX(0);
			dungeon5->SetDeltaY(-8);

			SetDeltaEnemigos(0, 16);
			SetDeltaZonasRestringidas(0, 16);
			jugador->SetIndiceSpriteY(3);

			movimiento = true;
		}
		else if (_tecla == System::Windows::Forms::Keys::Down) {
			dungeon5->SetDeltaX(0);
			dungeon5->SetDeltaY(8);

			SetDeltaEnemigos(0, -16);
			SetDeltaZonasRestringidas(0, -16);
			jugador->SetIndiceSpriteY(0);

			movimiento = true;
		}

		bool noPasar = false;
		for (int i = 0; i < lstZonasRestringidasdun5.size(); i++)if (HabraColision(jugador, lstZonasRestringidasdun5.at(i))) noPasar = true;

		if (!noPasar && movimiento) {
			dungeon5->Mover();
			MoverZonasRestringidas();
			MoverEnemigos();
		}

		for (vector<Enemigo*>::iterator i = lstEnemigosdun5.begin(); i != lstEnemigosdun5.end(); ++i)
			if (HayColision(jugador, *i) && (*i)->GetVisible() == true)
			{
				anteriorEstado = estado;
				batallContinente->SetArchivoImagen("batalla5.png");
				estado = 69;
				enemigoActual = nullptr;
				enemigoActual = *i;
				SetPosicionesBatalla();
			}

		jugador->SetDeltaSpriteX(1);
		if (jugador->GetIndiceSpriteX() == 1) jugador->SetIndiceSpriteX(0);
		else jugador->CambiarSprite();
	}
#pragma endregion
#pragma region Estado==7 //Dungeon6
	else if (estado == 7) {

		if (dungeon6->GetPosicionX() == 62 && dungeon6->GetPosicionY() == 212 && _tecla == System::Windows::Forms::Keys::Enter)//salida
			estado = 1;
		else if (dungeon6->GetPosicionX() == 990 && dungeon6->GetPosicionY() == -12 && _tecla == System::Windows::Forms::Keys::Enter)
			estado = 8;

		bool movimiento = false;

		if (_tecla == System::Windows::Forms::Keys::Right) {
			dungeon6->SetDeltaX(8);
			dungeon6->SetDeltaY(0);

			SetDeltaEnemigos(-16, 0);
			SetDeltaZonasRestringidas(-16, 0);
			jugador->SetIndiceSpriteY(2);

			movimiento = true;
		}
		else if (_tecla == System::Windows::Forms::Keys::Left) {
			dungeon6->SetDeltaX(-8);
			dungeon6->SetDeltaY(0);

			SetDeltaEnemigos(16, 0);
			SetDeltaZonasRestringidas(16, 0);
			jugador->SetIndiceSpriteY(1);

			movimiento = true;
		}
		else if (_tecla == System::Windows::Forms::Keys::Up) {
			dungeon6->SetDeltaX(0);
			dungeon6->SetDeltaY(-8);

			SetDeltaEnemigos(0, 16);
			SetDeltaZonasRestringidas(0, 16);
			jugador->SetIndiceSpriteY(3);

			movimiento = true;
		}
		else if (_tecla == System::Windows::Forms::Keys::Down) {
			dungeon6->SetDeltaX(0);
			dungeon6->SetDeltaY(8);

			SetDeltaEnemigos(0, -16);
			SetDeltaZonasRestringidas(0, -16);
			jugador->SetIndiceSpriteY(0);

			movimiento = true;
		}

		bool noPasar = false;
		for (int i = 0; i < lstZonasRestringidasdun6.size(); i++)if (HabraColision(jugador, lstZonasRestringidasdun6.at(i))) noPasar = true;

		if (!noPasar && movimiento) {
			dungeon6->Mover();
			MoverZonasRestringidas();
			MoverEnemigos();
		}

		for (vector<Enemigo*>::iterator i = lstEnemigosdun6.begin(); i != lstEnemigosdun6.end(); ++i)
			if (HayColision(jugador, *i) && (*i)->GetVisible() == true)
			{
				anteriorEstado = estado;
				batallContinente->SetArchivoImagen("batalla6.png");
				estado = 69;
				enemigoActual = nullptr;
				enemigoActual = *i;
				SetPosicionesBatalla();
			}

		jugador->SetDeltaSpriteX(1);
		if (jugador->GetIndiceSpriteX() == 1) jugador->SetIndiceSpriteX(0);
		else jugador->CambiarSprite();
	}
#pragma endregion
#pragma region Estado==8 //Dungeon7
	else if (estado == 8) {

		if (dungeon7->GetPosicionX() == 54 && dungeon7->GetPosicionY() == 564 && _tecla == System::Windows::Forms::Keys::Enter)//salida
			estado = 7;

		bool movimiento = false;

		if (_tecla == System::Windows::Forms::Keys::Right) {
			dungeon7->SetDeltaX(8);
			dungeon7->SetDeltaY(0);

			SetDeltaEnemigos(-16, 0);
			SetDeltaZonasRestringidas(-16, 0);

			boss4->SetDeltaX(-16);
			boss4->SetDeltaY(0);

			jugador->SetIndiceSpriteY(2);

			movimiento = true;
		}
		else if (_tecla == System::Windows::Forms::Keys::Left) {
			dungeon7->SetDeltaX(-8);
			dungeon7->SetDeltaY(0);

			SetDeltaEnemigos(16, 0);
			SetDeltaZonasRestringidas(16, 0);

			boss4->SetDeltaX(16);
			boss4->SetDeltaY(0);

			jugador->SetIndiceSpriteY(1);

			movimiento = true;
		}
		else if (_tecla == System::Windows::Forms::Keys::Up) {
			dungeon7->SetDeltaX(0);
			dungeon7->SetDeltaY(-8);

			SetDeltaEnemigos(0, 16);
			SetDeltaZonasRestringidas(0, 16);

			boss4->SetDeltaX(0);
			boss4->SetDeltaY(16);

			jugador->SetIndiceSpriteY(3);

			movimiento = true;
		}
		else if (_tecla == System::Windows::Forms::Keys::Down) {
			dungeon7->SetDeltaX(0);
			dungeon7->SetDeltaY(8);

			SetDeltaEnemigos(0, -16);
			SetDeltaZonasRestringidas(0, -16);

			boss4->SetDeltaX(0);
			boss4->SetDeltaY(-16);

			jugador->SetIndiceSpriteY(0);

			movimiento = true;
		}

		bool noPasar = false;

		for (int i = 0; i < lstZonasRestringidasdun7.size(); i++)if (HabraColision(jugador, lstZonasRestringidasdun7.at(i))) noPasar = true;

		if (!noPasar && movimiento) {
			dungeon7->Mover();
			MoverZonasRestringidas();
			MoverEnemigos();
			boss4->Mover();
		}

		if (HayColision(jugador, boss4) && boss4->GetVisible() == true && _tecla == System::Windows::Forms::Keys::Enter){
			anteriorEstado = estado;
			batallContinente->SetArchivoImagen("batalla6.png");
			estado = 69;
			enemigoActual = nullptr;
			enemigoActual = boss4;
			SetPosicionesBatalla();
		}

		jugador->SetDeltaSpriteX(1);
		if (jugador->GetIndiceSpriteX() == 1) jugador->SetIndiceSpriteX(0);
		else jugador->CambiarSprite();
	}
#pragma endregion
#pragma region Estado==7 //Ciudad
	else if (estado == 9) {

		if (ciudad->GetPosicionX() == 544 && ciudad->GetPosicionY() == 258 && _tecla == System::Windows::Forms::Keys::Enter)//salida
			estado = 1;

		bool movimiento = false;

		if (_tecla == System::Windows::Forms::Keys::Right) {
			ciudad->SetDeltaX(8);
			ciudad->SetDeltaY(0);

			SetDeltaEnemigos(-16, 0);
			SetDeltaZonasRestringidas(-16, 0);
			jugador->SetIndiceSpriteY(2);

			movimiento = true;
		}
		else if (_tecla == System::Windows::Forms::Keys::Left) {
			ciudad->SetDeltaX(-8);
			ciudad->SetDeltaY(0);

			SetDeltaEnemigos(16, 0);
			SetDeltaZonasRestringidas(16, 0);
			jugador->SetIndiceSpriteY(1);

			movimiento = true;
		}
		else if (_tecla == System::Windows::Forms::Keys::Up) {
			ciudad->SetDeltaX(0);
			ciudad->SetDeltaY(-8);

			SetDeltaEnemigos(0, 16);
			SetDeltaZonasRestringidas(0, 16);
			jugador->SetIndiceSpriteY(3);

			movimiento = true;
		}
		else if (_tecla == System::Windows::Forms::Keys::Down) {
			ciudad->SetDeltaX(0);
			ciudad->SetDeltaY(8);

			SetDeltaEnemigos(0, -16);
			SetDeltaZonasRestringidas(0, -16);
			jugador->SetIndiceSpriteY(0);

			movimiento = true;
		}

		bool noPasar = false;

		for (int i = 0; i < lstZonasRestringidasciudad.size(); i++)if (HabraColision(jugador, lstZonasRestringidasciudad.at(i))) noPasar = true;

		if (!noPasar && movimiento) {
			ciudad->Mover();
			MoverZonasRestringidas();
			MoverEnemigos();
		}

		jugador->SetDeltaSpriteX(1);
		if (jugador->GetIndiceSpriteX() == 1) jugador->SetIndiceSpriteX(0);
		else jugador->CambiarSprite();
	}
#pragma endregion
#pragma region Estado==69 //Batalla
	else if (estado == 69) {//Batalla
		if (faseBatalla == 1) {
			if (_tecla == System::Windows::Forms::Keys::Down && seleccionFaseBatalla == 1) seleccionFaseBatalla = 2;
			else if (_tecla == System::Windows::Forms::Keys::Up && seleccionFaseBatalla == 2) seleccionFaseBatalla = 1;
			else if (_tecla == System::Windows::Forms::Keys::Enter)
			{
				if (seleccionFaseBatalla == 1) {
					System::Random ^r = gcnew System::Random;
					int max = jugador->GetFuerza() * 0.2;
					damage = jugador->GetFuerza() - enemigoActual->GetDefensa() + r->Next(0, max);
					if (damage <= 0) damage = 0;
					int vidaEnemigo = enemigoActual->GetVidaActual() - damage;
					enemigoActual->SetVidaActual(vidaEnemigo);
				}

				faseBatalla = 2;

				ComprobarGanador();
			}
		}
		else if (faseBatalla == 2) {
			if (_tecla == System::Windows::Forms::Keys::Enter)
			{
				int defAdicional = 0;
				if (seleccionFaseBatalla == 2) {
					defAdicional = 0.4 * jugador->GetDefensa();
				}

				System::Random ^r = gcnew System::Random;
				int max = enemigoActual->GetFuerza() * 0.2;
				damage = enemigoActual->GetFuerza() - (jugador->GetDefensa() + defAdicional) + r->Next(0, max);
				if (damage <= 0) damage = 0;
				int vidaJugador = jugador->GetVidaActual() - damage;
				jugador->SetVidaActual(vidaJugador);

				faseBatalla = 3;
			}
		}
		else if (faseBatalla == 3) {
			if (_tecla == System::Windows::Forms::Keys::Enter)
			{
				faseBatalla = 1;
				seleccionFaseBatalla = 1;
				ComprobarGanador();
			}
		}
		else if (faseBatalla == 0) {
			if (_tecla == System::Windows::Forms::Keys::Enter) {
				jugador->SetPosicionX(350);
				jugador->SetPosicionY(250);
				jugador->SetZoom(0.75);
				ganador = 0;
				faseBatalla = 1;
				estado = anteriorEstado;
			}
		}
	}
	else if (estado == 15){
		if (_tecla == System::Windows::Forms::Keys::Enter){
			if (seleccionGuardar == 1){
				GuardarArchivo();
				estado = anteriorEstado;
			}
			else{
				estado = anteriorEstado;
			}
		}
		else if (_tecla == System::Windows::Forms::Keys::Down && seleccionGuardar == 1){
			seleccionGuardar = 0;
		}
		else if (_tecla == System::Windows::Forms::Keys::Up && seleccionGuardar == 0){
			seleccionGuardar = 1;
		}
	}
}
#pragma endregion

void JuegoController::AgregarEnemigos(short n, short v1, short v2, vector<Zona*>lstZonasRestringidas, short est)
{
	Enemigo* enemigo = new Enemigo();
	if (n == 0)return;
	else
	{
		for each (Zona* var in lstZonasRestringidas)
		{
			if ((est == 1 && v1 > var->GetPosicionX() && v1<var->GetAncho() + var->GetPosicionX()) && (v2>var->GetPosicionY() && v2 < var->GetAlto() + var->GetPosicionY())) {
				AgregarEnemigos(n, rand() % 1300 + 10, rand() % 1300 + 10, lstZonasRestringidas, est); mostrarEnemigo = false;
			}
			else if ((est == 2 && v1 > var->GetPosicionX() && v1<var->GetAncho() + var->GetPosicionX()) && (v2>var->GetPosicionY() && v2 < var->GetAlto() + var->GetPosicionY())) {
				AgregarEnemigos(n - 1, (rand() % (500 - (-820))) + (-820), (rand() % (900 - (-270))) + (-270), lstZonasRestringidas, est); mostrarEnemigo = false;
			}
			else if ((est == 3 && v1 > var->GetPosicionX() && v1<var->GetAncho() + var->GetPosicionX()) && (v2>var->GetPosicionY() && v2 < var->GetAlto() + var->GetPosicionY())) {
				AgregarEnemigos(n - 1, (rand() % (1800 - 400)) + 400, (rand() % (200 - (-400))) + (-400), lstZonasRestringidas, est);mostrarEnemigo = false;
			}
			else if ((est == 4 && v1 > var->GetPosicionX() && v1<var->GetAncho() + var->GetPosicionX()) && (v2>var->GetPosicionY() && v2 < var->GetAlto() + var->GetPosicionY())) {
				AgregarEnemigos(n - 1, (rand() % (400 - (-800))) + (-800), (rand() % (360 - 100)) + 100, lstZonasRestringidas, est);mostrarEnemigo = false;
			}
			else if ((est == 5 && v1 > var->GetPosicionX() && v1<var->GetAncho() + var->GetPosicionX()) && (v2>var->GetPosicionY() && v2 < var->GetAlto() + var->GetPosicionY())) {
				AgregarEnemigos(n - 1, (rand() % (450 - 200)) + 200, (rand() % (300 - (-1200))) + (-1200), lstZonasRestringidas, est);mostrarEnemigo = false;
			}
			else if ((est == 6 && v1 > var->GetPosicionX() && v1<var->GetAncho() + var->GetPosicionX()) && (v2>var->GetPosicionY() && v2 < var->GetAlto() + var->GetPosicionY())) {
				AgregarEnemigos(n - 1, (rand() % (1300 - 400)) + 400, (rand() % (900 - 200)) + 200, lstZonasRestringidas, est);mostrarEnemigo = false;
			}
			else if ((est == 7 && v1 > var->GetPosicionX() && v1<var->GetAncho() + var->GetPosicionX()) && (v2>var->GetPosicionY() && v2 < var->GetAlto() + var->GetPosicionY())) {
				AgregarEnemigos(n - 1, (rand() % (1800 - 300)) + 300, (rand() % (1100 - (-40))) + (-40), lstZonasRestringidas, est);mostrarEnemigo = false;
			}
			else if ((est == 8 && v1 > var->GetPosicionX() && v1<var->GetAncho() + var->GetPosicionX()) && (v2>var->GetPosicionY() && v2 < var->GetAlto() + var->GetPosicionY())) {
				AgregarEnemigos(n - 1, (rand() % (620 - 155)) + 155, (rand() % ((-390) - (-750))) + (-750), lstZonasRestringidas, est);mostrarEnemigo = false;
			}
		}
		if (mostrarEnemigo == true)
		{
			short v5 = rand() % 2;
			if (est == 1) {
				if (v5 == 0)enemigo = new Enemigo(v1, v2, 30, 30, 1, 15, 8, 1, "mob4.png", 1);
				//		else enemigo = new Enemigo(v1, v2, 30, 30, 2, 25, 10, 2, "enemigo_planta.png", 1);
				lstEnemigosContinente.push_back(enemigo);
				AgregarEnemigos(n - 1, rand() % 1300 + 10, rand() % 1300 + 10, lstZonasRestringidas, est);
			}
			else if (est == 2) {
				if (v5 == 0)enemigo = new Enemigo(v1, v2, 30, 30, 2, 28, 15, 2, "mob1.png", 1);
				//else enemigo = new Enemigo(v1, v2, 30, 30, 2, 25, 10, 2, "enemigo_planta.png", 1);
				lstEnemigosdun1.push_back(enemigo);
				AgregarEnemigos(n - 1, (rand() % (500 - (-820))) + (-820), (rand() % (900 - (-270))) + (-270), lstZonasRestringidas, est);
			}
			else if (est == 3) {
				if (v5 == 0)enemigo = new Enemigo(v1, v2, 30, 30, 3, 35, 27, 3, "mob2.png", 1);
				//	else enemigo = new Enemigo(v1, v2, 30, 30, 2, 25, 10, 2, "enemigo_planta.png", 1);
				lstEnemigosdun2.push_back(enemigo);
				AgregarEnemigos(n - 1, (rand() % (1800 - 400)) + 400, (rand() % (200 - (-400))) + (-400), lstZonasRestringidas, est);
			}
			else if (est == 4) {
				if (v5 == 0)enemigo = new Enemigo(v1, v2, 30, 30, 4, 70, 38, 4, "mob3.png", 1);
				lstEnemigosdun3.push_back(enemigo);
				AgregarEnemigos(n - 1, (rand() % (400 - (-800))) + (-800), (rand() % (360 - 100)) + 100, lstZonasRestringidas, est);
			}
			else if (est == 5) {
				if (v5 == 0)enemigo = new Enemigo(v1, v2, 30, 30, 6, 150, 95, 5, "mobd4.png", 1);
				//	else enemigo = new Enemigo(v1, v2, 30, 30, 2, 25, 10, 2, "enemigo_planta.png", 1);
				lstEnemigosdun4.push_back(enemigo);
				AgregarEnemigos(n - 1, (rand() % (450 - 200)) + 200, (rand() % (300 - (-1200))) + (-1200), lstZonasRestringidas, est);
			}
			else if (est == 6) {
				if (v5 == 0)enemigo = new Enemigo(v1, v2, 30, 50, 7, 250, 170, 6, "mob5.png", 1);
				//	else enemigo = new Enemigo(v1, v2, 30, 30, 2, 25, 10, 2, "enemigo_planta.png", 1);
				lstEnemigosdun5.push_back(enemigo);
				AgregarEnemigos(n - 1, (rand() % (1300 - 400)) + 400, (rand() % (900 - 200)) + 200, lstZonasRestringidas, est);
			}
			else if (est == 7) {
				if (v5 == 0)enemigo = new Enemigo(v1, v2, 70, 50, 10, 15, 10, 7, "mob6.png", 1);
				//	else enemigo = new Enemigo(v1, v2, 30, 30, 2, 25, 10, 2, "enemigo_planta.png", 1);
				lstEnemigosdun6.push_back(enemigo);
				AgregarEnemigos(n - 1, (rand() % (1800 - 300)) + 300, (rand() % (1100 - (-40))) + (-40), lstZonasRestringidas, est);
			}
		}
	}
}

void JuegoController::AgregarMisiones(){
	arbolMisiones.Insercion(0, new Mision("Mata al Demonio en la mazmorra de lava", 1, 1, 100, 100, false, 0));
	arbolMisiones.Insercion(1,new Mision("Mata al jefe en la mazmorra noreste", 1, 1, 100, 100, false, 1));
	arbolMisiones.Insercion(2, new Mision("Mata al Elegido Corrompido", 1, 1, 100, 100, false, 3));
	arbolMisiones.Insercion(3, new Mision("Mata al Dios del Caos en el Castillo Celestial", 1, 1, 100, 100, false, 4));
}

void JuegoController::AgregarArnas()
{
	arbolArmas.Insercion(0, new Arma("Espada Básica", 5, 0));//Arma al comenzar
	arbolArmas.Insercion(1, new Arma("Espada de Fuego", 20, 1)); //Al matar al primer boss
	arbolArmas.Insercion(2, new Arma("Espada de la Bestia", 65, 3));//Al matar al segundo boss
	arbolArmas.Insercion(3, new Arma("Espada Maestra", 100, 4));//Al matar al tercer boss
}
#pragma region No Concurrente
void JuegoController::MostrarInfoPersonaje(Graphics ^gr, Mapa* _mapa)
{
	gr->FillRectangle(Brushes::Black, 0, 0, 790, 70);
	gr->DrawRectangle(gcnew System::Drawing::Pen(System::Drawing::Color::Red, 3), 0, 2, 783, 65);
	Font ^font = gcnew Font("Arial", 10);
	SolidBrush ^brocha = gcnew SolidBrush(Color::White);
	gr->DrawString("Nivel: " + jugador->GetNivel().ToString(), font, brocha, 5, 8);
	gr->DrawString("Exp: " + jugador->GetExperiencia().ToString() + "/" + jugador->GetExpNecesaria(), font, brocha, 5, 28);
	gr->DrawString("Oro: " + jugador->GetDinero().ToString(), font, brocha, 5, 48);
	gr->DrawString("Vida: " + jugador->GetVidaActual().ToString() + "/" + jugador->GetVida(), font, brocha, 130, 8);
	gr->DrawString("Fuerza: " + jugador->GetFuerza().ToString(), font, brocha, 130, 28);
	gr->DrawString("Defensa: " + jugador->GetDefensa().ToString(), font, brocha, 130, 48);
	gr->DrawString("Arma: " + gcnew System::String(jugador->GetArma()->GetNombre()), font, brocha, 250, 8);
	gr->DrawString("Misión actual: " + gcnew System::String(jugador->GetMision()->GetDescripcion()), font, brocha, 250, 30);
	gr->DrawString(_mapa->GetPosicionX().ToString() + " " + _mapa->GetPosicionY(), font, brocha, 715, 8);
}
void JuegoController::MostrarAtaques(System::Drawing::Graphics ^gr) {
	if (faseBatalla == 1)
	{
		Font ^font = gcnew Font("Arial", 12);
		SolidBrush ^brocha = gcnew SolidBrush(Color::White);
		gr->FillRectangle(Brushes::Black, 50, 150, 100, 30);
		gr->FillRectangle(Brushes::Black, 50, 190, 100, 30);
		if (seleccionFaseBatalla == 1) gr->DrawRectangle(gcnew System::Drawing::Pen(System::Drawing::Color::Red, 4), 50, 150, 100, 30);
		else if (seleccionFaseBatalla == 2) gr->DrawRectangle(gcnew System::Drawing::Pen(System::Drawing::Color::Red, 4), 50, 190, 100, 30);
		gr->DrawString("Atacar", font, brocha, 70, 155);
		gr->DrawString("Defenderse", font, brocha, 55, 195);
	}
	else if (faseBatalla == 2)
	{
		Font ^font = gcnew Font("Arial", 15);
		SolidBrush ^brocha = gcnew SolidBrush(Color::White);
		gr->FillRectangle(Brushes::Black, 200, 450, 390, 70);
		gr->DrawRectangle(gcnew System::Drawing::Pen(System::Drawing::Color::Red, 3), 200, 450, 390, 70);
		if (seleccionFaseBatalla == 1) {

			gr->DrawString("Causaste " + damage.ToString() + " de daño al enemigo", font, brocha, 230, 470);
		}
		else if (seleccionFaseBatalla == 2) {
			gr->DrawString("Te pusisite en posición defensiva", font, brocha, 230, 470);
		}
	}
	else if (faseBatalla == 3) {
		Font ^font = gcnew Font("Arial", 15);
		SolidBrush ^brocha = gcnew SolidBrush(Color::White);
		gr->FillRectangle(Brushes::Black, 200, 450, 390, 70);
		gr->DrawRectangle(gcnew System::Drawing::Pen(System::Drawing::Color::Red, 3), 200, 450, 390, 70);
		gr->DrawString("Recibiste " + damage.ToString() + " de daño", font, brocha, 230, 470);
	}
	else if (faseBatalla == 0) {
		Font ^font = gcnew Font("Arial", 10);
		SolidBrush ^brocha = gcnew SolidBrush(Color::White);
		gr->FillRectangle(Brushes::Black, 200, 450, 390, 70);
		gr->DrawRectangle(gcnew System::Drawing::Pen(System::Drawing::Color::Red, 3), 200, 450, 390, 70);

		if (ganador == 1) {
			gr->DrawString("¡Ganaste la batalla!", font, brocha, 260, 460);
			gr->DrawString("» Oro ganado: " + oroGanado.ToString(), font, brocha, 230, 480);
			gr->DrawString("» Experiencia ganada: " + expGanada.ToString(), font, brocha, 230, 500);
		}
		else if (ganador == 2) {
			gr->DrawString("¡Perdiste la batalla!", font, brocha, 260, 460);
			gr->DrawString("» Experiencia perdida: " + expGanada.ToString(), font, brocha, 230, 490);
		}
	}

	if (faseBatalla != 0) {
		gr->FillRectangle(Brushes::Black, 650, 150, 90, 20);
		gr->DrawRectangle(gcnew System::Drawing::Pen(System::Drawing::Color::Red, 1), 650, 150, 90, 20);
		gr->DrawString("Vida: " + enemigoActual->GetVidaActual().ToString() + "/" + enemigoActual->GetVida().ToString(), gcnew Font("Arial", 10), gcnew SolidBrush(Color::White), 653, 152);
	}
}
void JuegoController::SetPosicionesBatalla() {
	jugador->SetPosicionX(200);
	jugador->SetPosicionY(250);
	jugador->SetZoom(1.5);
	jugador->SetIndiceSpriteX(0);
	jugador->SetIndiceSpriteY(2);
	jugador->CambiarSprite();
	
	if (enemigoActual->GetTipo() == 100){//Boss1
		enemigoActual->SetPosicionX(450);
		enemigoActual->SetPosicionY(160);
		enemigoActual->SetZoom(6);
	}
	else if (enemigoActual->GetTipo() == 200){//Boss2
		enemigoActual->SetPosicionX(400);
		enemigoActual->SetPosicionY(160);
		enemigoActual->SetZoom(6);
	}
	else if (enemigoActual->GetTipo() == 300){//Boss3
		enemigoActual->SetPosicionX(400);
		enemigoActual->SetPosicionY(160);
		enemigoActual->SetZoom(6);
	}
	else if (enemigoActual->GetTipo() == 400){//Boss4
		enemigoActual->SetPosicionX(350);
		enemigoActual->SetPosicionY(120);
		enemigoActual->SetZoom(10);
		jugador->SetZoom(1);
		jugador->SetPosicionY(430);
	}
	else if (enemigoActual->GetTipo() == 1){//Enemigo Continente
		enemigoActual->SetPosicionX(450);
		enemigoActual->SetPosicionY(300);
		enemigoActual->SetZoom(2);
	}
	else if (enemigoActual->GetTipo() == 2){//Enemigo dungeon1
		enemigoActual->SetPosicionX(450);
		enemigoActual->SetPosicionY(260);
		enemigoActual->SetZoom(3);
	}
	else if (enemigoActual->GetTipo() == 3){//Enemigo dungeon2
		enemigoActual->SetPosicionX(450);
		enemigoActual->SetPosicionY(260);
		enemigoActual->SetZoom(3);
	}
	else if (enemigoActual->GetTipo() == 4){//Enemigo dungeon3
		enemigoActual->SetPosicionX(450);
		enemigoActual->SetPosicionY(200);
		enemigoActual->SetZoom(5);
	}
	else if (enemigoActual->GetTipo() == 5){//enemigo dungeon4
		enemigoActual->SetPosicionX(450);
		enemigoActual->SetPosicionY(260);
		enemigoActual->SetZoom(4);
	}
	else if (enemigoActual->GetTipo() == 6){//enemigo dungeon5
		enemigoActual->SetPosicionX(450);
		enemigoActual->SetPosicionY(210);
		enemigoActual->SetZoom(3);
	}
	else if (enemigoActual->GetTipo() == 7){//enemigo dungeon6
		enemigoActual->SetPosicionX(430);
		enemigoActual->SetPosicionY(300);
		enemigoActual->SetZoom(5);
		jugador->SetZoom(2);
		jugador->SetPosicionY(400);
	}
}
void JuegoController::ComprobarGanador() {
	if (enemigoActual->GetVidaActual() <= 0) {
		ganador = 1;

		if (enemigoActual->GetTipo() == 100){//Boss1 
			jugador->SetMision(arbolMisiones.Buscar(1));
			jugador->SetArma(arbolArmas.Buscar(1), false);
		}
		else if (enemigoActual->GetTipo() == 200){//Boss2
			jugador->SetMision(arbolMisiones.Buscar(3));
			jugador->SetArma(arbolArmas.Buscar(3), false);
		}
		else if (enemigoActual->GetTipo() == 300){//Boss3
			jugador->SetMision(arbolMisiones.Buscar(4));
			jugador->SetArma(arbolArmas.Buscar(4), false);
		}

		oroGanado = enemigoActual->GetDinero();
		int oroTotal = oroGanado + jugador->GetDinero();
		jugador->SetDinero(oroTotal);

		expGanada = enemigoActual->GetExperiencia();
		int expTotal = expGanada + jugador->GetExperiencia();
		jugador->SetExperiencia(expTotal);

		jugador->SetVidaActual(jugador->GetVida());
		enemigoActual->SetVisible(false);

		if (jugador->GetExperiencia() > jugador->GetExpNecesaria()) {
			int nivel = jugador->GetNivel() + 1;
			jugador->SubirNivel(nivel);
		}

		faseBatalla = 0;

		if (enemigoActual->GetTipo() == 400) estado = 20;//Boss4
	}
	else if (jugador->GetVidaActual() <= 0) {
		ganador = 2;

		oroGanado = 0;
		expGanada = jugador->GetExpNecesaria()*(0.05);
		int exp = jugador->GetExperiencia() - expGanada;
		jugador->SetExperiencia(exp);

		jugador->SetVidaActual(jugador->GetVida());

		if (enemigoActual->GetTipo() < 100)
			enemigoActual->SetVisible(false);

		if (jugador->GetExperiencia() < 0) {
			if (jugador->GetNivel() == 1)
				jugador->SetExperiencia(0);
			else {
				int nivel = jugador->GetNivel() - 1;
				jugador->SubirNivel(nivel);
			}
		}
		faseBatalla = 0;
	}
}
bool JuegoController::HabraColision(ObjetoAnimado* _objeto1, ObjetoAnimado* _objeto2)
{
	System::Drawing::Rectangle obj1 = System::Drawing::Rectangle(_objeto1->GetPosicionX() + _objeto1->GetDeltaX(), _objeto1->GetPosicionY() + _objeto1->GetDeltaY(), _objeto1->GetAncho(), _objeto1->GetAlto());
	System::Drawing::Rectangle obj2 = System::Drawing::Rectangle(_objeto2->GetPosicionX() + _objeto2->GetDeltaX(), _objeto2->GetPosicionY() + _objeto2->GetDeltaY(), _objeto2->GetAncho(), _objeto2->GetAlto());
	return obj1.IntersectsWith(obj2);
}
bool JuegoController::HayColision(ObjetoAnimado* _objeto1, ObjetoAnimado* _objeto2)
{
	System::Drawing::Rectangle obj1 = System::Drawing::Rectangle(_objeto1->GetPosicionX(), _objeto1->GetPosicionY(), _objeto1->GetAncho(), _objeto1->GetAlto());
	System::Drawing::Rectangle obj2 = System::Drawing::Rectangle(_objeto2->GetPosicionX(), _objeto2->GetPosicionY(), _objeto2->GetAncho(), _objeto2->GetAlto());
	return obj1.IntersectsWith(obj2);
}
void JuegoController::MoverZonasRestringidas()
{
	if (estado == 1) for (int i = 0; i < lstZonasRestringidasContinente.size(); i++)lstZonasRestringidasContinente.at(i)->Mover();
	else if (estado == 2) for (int i = 0; i < lstZonasRestringidasdun1.size(); i++)lstZonasRestringidasdun1.at(i)->Mover();
	else if (estado == 3) for (int i = 0; i < lstZonasRestringidasdun2.size(); i++)lstZonasRestringidasdun2.at(i)->Mover();
	else if (estado == 4) for (int i = 0; i < lstZonasRestringidasdun3.size(); i++)lstZonasRestringidasdun3.at(i)->Mover();
	else if (estado == 5) for (int i = 0; i < lstZonasRestringidasdun4.size(); i++)lstZonasRestringidasdun4.at(i)->Mover();
	else if (estado == 6) for (int i = 0; i < lstZonasRestringidasdun5.size(); i++)lstZonasRestringidasdun5.at(i)->Mover();
	else if (estado == 7) for (int i = 0; i < lstZonasRestringidasdun6.size(); i++)lstZonasRestringidasdun6.at(i)->Mover();
	else if (estado == 8) for (int i = 0; i < lstZonasRestringidasdun7.size(); i++)lstZonasRestringidasdun7.at(i)->Mover();
	else if (estado == 9) for (int i = 0; i < lstZonasRestringidasciudad.size(); i++)lstZonasRestringidasciudad.at(i)->Mover();
}
void JuegoController::MoverEnemigos()
{
	if (estado == 1) for (int i = 0; i < lstEnemigosContinente.size(); i++)lstEnemigosContinente.at(i)->Mover();
	else if (estado == 2) for (int i = 0; i < lstEnemigosdun1.size(); i++)lstEnemigosdun1.at(i)->Mover();
	else if (estado == 3) for (int i = 0; i < lstEnemigosdun2.size(); i++)lstEnemigosdun2.at(i)->Mover();
	else if (estado == 4) for (int i = 0; i < lstEnemigosdun3.size(); i++)lstEnemigosdun3.at(i)->Mover();
	else if (estado == 5) for (int i = 0; i < lstEnemigosdun4.size(); i++)lstEnemigosdun4.at(i)->Mover();
	else if (estado == 6) for (int i = 0; i < lstEnemigosdun5.size(); i++)lstEnemigosdun5.at(i)->Mover();
	else if (estado == 7) for (int i = 0; i < lstEnemigosdun6.size(); i++)lstEnemigosdun6.at(i)->Mover();
	else if (estado == 8) for (int i = 0; i < lstEnemigosdun7.size(); i++)lstEnemigosdun7.at(i)->Mover();
	//PERSONAS XQ ES CIUDAD	else if (estado == 9) for (int i = 0; i < lstEnemigosdun8.size(); i++)lstEnemigosdun1.at(i)->Mover();
}
void JuegoController::SetDeltaZonasRestringidas(int _x, int _y)
{
	if (estado == 1)
		for (int i = 0; i < lstZonasRestringidasContinente.size(); i++)
		{
			lstZonasRestringidasContinente.at(i)->SetDeltaX(_x);
			lstZonasRestringidasContinente.at(i)->SetDeltaY(_y);
		}
	else if (estado == 2)
		for (int i = 0; i < lstZonasRestringidasdun1.size(); i++)
		{
			lstZonasRestringidasdun1.at(i)->SetDeltaX(_x);
			lstZonasRestringidasdun1.at(i)->SetDeltaY(_y);
		}
	else if (estado == 3)
		for (int i = 0; i < lstZonasRestringidasdun2.size(); i++)
		{
			lstZonasRestringidasdun2.at(i)->SetDeltaX(_x);
			lstZonasRestringidasdun2.at(i)->SetDeltaY(_y);
		}
	else if (estado == 4)
		for (int i = 0; i < lstZonasRestringidasdun3.size(); i++)
		{
			lstZonasRestringidasdun3.at(i)->SetDeltaX(_x);
			lstZonasRestringidasdun3.at(i)->SetDeltaY(_y);
		}
	else if (estado == 5)
		for (int i = 0; i < lstZonasRestringidasdun4.size(); i++)
		{
			lstZonasRestringidasdun4.at(i)->SetDeltaX(_x);
			lstZonasRestringidasdun4.at(i)->SetDeltaY(_y);
		}
	else if (estado == 6)
		for (int i = 0; i < lstZonasRestringidasdun5.size(); i++)
		{
			lstZonasRestringidasdun5.at(i)->SetDeltaX(_x);
			lstZonasRestringidasdun5.at(i)->SetDeltaY(_y);
		}
	else if (estado == 7)
		for (int i = 0; i < lstZonasRestringidasdun6.size(); i++)
		{
			lstZonasRestringidasdun6.at(i)->SetDeltaX(_x);
			lstZonasRestringidasdun6.at(i)->SetDeltaY(_y);
		}
	else if (estado == 8)
		for (int i = 0; i < lstZonasRestringidasdun7.size(); i++)
		{
			lstZonasRestringidasdun7.at(i)->SetDeltaX(_x);
			lstZonasRestringidasdun7.at(i)->SetDeltaY(_y);
		}
	else if (estado == 9)
		for (int i = 0; i < lstZonasRestringidasciudad.size(); i++)
		{
			lstZonasRestringidasciudad.at(i)->SetDeltaX(_x);
			lstZonasRestringidasciudad.at(i)->SetDeltaY(_y);
		}
}
void JuegoController::SetDeltaEnemigos(int _x, int _y)
{
	if (estado == 1)
		for (int i = 0; i < lstEnemigosContinente.size(); i++)
		{
			lstEnemigosContinente.at(i)->SetDeltaX(_x);
			lstEnemigosContinente.at(i)->SetDeltaY(_y);
		}
	else if (estado == 2)
		for (int i = 0; i < lstEnemigosdun1.size(); i++)
		{
			lstEnemigosdun1.at(i)->SetDeltaX(_x);
			lstEnemigosdun1.at(i)->SetDeltaY(_y);
		}
	else if (estado == 3)
		for (int i = 0; i < lstEnemigosdun2.size(); i++)
		{
			lstEnemigosdun2.at(i)->SetDeltaX(_x);
			lstEnemigosdun2.at(i)->SetDeltaY(_y);
		}
	else if (estado == 4)
		for (int i = 0; i < lstEnemigosdun3.size(); i++)
		{
			lstEnemigosdun3.at(i)->SetDeltaX(_x);
			lstEnemigosdun3.at(i)->SetDeltaY(_y);
		}
	else if (estado == 5)
		for (int i = 0; i < lstEnemigosdun4.size(); i++)
		{
			lstEnemigosdun4.at(i)->SetDeltaX(_x);
			lstEnemigosdun4.at(i)->SetDeltaY(_y);
		}
	else if (estado == 6)
		for (int i = 0; i < lstEnemigosdun5.size(); i++)
		{
			lstEnemigosdun5.at(i)->SetDeltaX(_x);
			lstEnemigosdun5.at(i)->SetDeltaY(_y);
		}
	else if (estado == 7)
		for (int i = 0; i < lstEnemigosdun6.size(); i++)
		{
			lstEnemigosdun6.at(i)->SetDeltaX(_x);
			lstEnemigosdun6.at(i)->SetDeltaY(_y);
		}
	else if (estado == 8)
		for (int i = 0; i < lstEnemigosdun7.size(); i++)
		{
			lstEnemigosdun7.at(i)->SetDeltaX(_x);
			lstEnemigosdun7.at(i)->SetDeltaY(_y);
		}
}
#pragma region ZonasNoPaso
void JuegoController::AgregarZonasRestringidasContinente() {
	lstZonasRestringidasContinente.push_back(new Zona(270, 410, 110, 170));//1
	lstZonasRestringidasContinente.push_back(new Zona(370, 120, 120, 20));//2
	lstZonasRestringidasContinente.push_back(new Zona(420, 160, 120, 20));//3
	lstZonasRestringidasContinente.push_back(new Zona(472, 190, 120, 20));//4
	lstZonasRestringidasContinente.push_back(new Zona(520, 230, 120, 20));//5
	lstZonasRestringidasContinente.push_back(new Zona(600, 260, 60, 20));//6
	lstZonasRestringidasContinente.push_back(new Zona(300, 680, 120, 70));//7
	lstZonasRestringidasContinente.push_back(new Zona(420, 660, 50, 20));//8
	lstZonasRestringidasContinente.push_back(new Zona(-320, 720, 465, 40));//9
	lstZonasRestringidasContinente.push_back(new Zona(-350, 770, 390, 10));//10
	lstZonasRestringidasContinente.push_back(new Zona(-250, 820, 220, 80));//11
	lstZonasRestringidasContinente.push_back(new Zona(-410, 910, 340, 40));//12
	lstZonasRestringidasContinente.push_back(new Zona(-350, 970, 100, 85));//13
	lstZonasRestringidasContinente.push_back(new Zona(-390, 960, 250, 20));//14
	lstZonasRestringidasContinente.push_back(new Zona(-350, 1190, 100, 80));//15
	lstZonasRestringidasContinente.push_back(new Zona(-180, 1130, 45, 20));//16
	lstZonasRestringidasContinente.push_back(new Zona(-220, 1160, 40, 60));//17
	lstZonasRestringidasContinente.push_back(new Zona(430, 1170, 85, 80));//18
	lstZonasRestringidasContinente.push_back(new Zona(345, 1230, 50, 5));//19
	lstZonasRestringidasContinente.push_back(new Zona(530, 1260, 90, 1));//20
	lstZonasRestringidasContinente.push_back(new Zona(620, 1290, 90, 1));//21
	lstZonasRestringidasContinente.push_back(new Zona(740, 1320, 150, 20));//22
	lstZonasRestringidasContinente.push_back(new Zona(900, 1390, 110, 1));//23
	lstZonasRestringidasContinente.push_back(new Zona(1030, 1455, 20, 35));//24
	lstZonasRestringidasContinente.push_back(new Zona(650, 1050, 250, 110));//25
	lstZonasRestringidasContinente.push_back(new Zona(825, 990, 80, 40));//26
	lstZonasRestringidasContinente.push_back(new Zona(900, 920, 40, 10));//27
	lstZonasRestringidasContinente.push_back(new Zona(970, 860, 15, 40));//28
	lstZonasRestringidasContinente.push_back(new Zona(920, 1180, 35, 40));//29
	lstZonasRestringidasContinente.push_back(new Zona(270, 260, 70, 35));//Ciudad
	lstZonasRestringidasContinente.push_back(new Zona(1600, -200, 200, 35));//31
	lstZonasRestringidasContinente.push_back(new Zona(1560, -300, 30, 100));//32
	lstZonasRestringidasContinente.push_back(new Zona(1800, -250, 30, 50));//33
	lstZonasRestringidasContinente.push_back(new Zona(-150, 20, 1250, 10));//34
	lstZonasRestringidasContinente.push_back(new Zona(-150, 20, 10, 700));//35
	lstZonasRestringidasContinente.push_back(new Zona(-550, 700, 10, 780));//36
	lstZonasRestringidasContinente.push_back(new Zona(-550, 700, 400, 10));//37
	lstZonasRestringidasContinente.push_back(new Zona(-550, 1400, 1200, 10));//38
	lstZonasRestringidasContinente.push_back(new Zona(650, 1400, 10, 300));//39
	lstZonasRestringidasContinente.push_back(new Zona(650, 1700, 500, 10));//40
	lstZonasRestringidasContinente.push_back(new Zona(1150, 430, 10, 1400));//41
	lstZonasRestringidasContinente.push_back(new Zona(1160, 430, 500, 1000));//42
	lstZonasRestringidasContinente.push_back(new Zona(1480, 100, 300, 300));//43
	lstZonasRestringidasContinente.push_back(new Zona(1100, -600, 1200, 10));//44
	lstZonasRestringidasContinente.push_back(new Zona(1100, -600, 10, 600));//45
	lstZonasRestringidasContinente.push_back(new Zona(2300, -700, 10, 100));//46
	lstZonasRestringidasContinente.push_back(new Zona(2300, -700, 400, 10));//47
	lstZonasRestringidasContinente.push_back(new Zona(2700, -700, 10, 1000));//48
	lstZonasRestringidasContinente.push_back(new Zona(2700, -700, 10, 500));//49
	lstZonasRestringidasContinente.push_back(new Zona(2200, 300, 500, 500));//49
	lstZonasRestringidasContinente.push_back(new Zona(2500, 800, 10, 700));//50
	lstZonasRestringidasContinente.push_back(new Zona(2500, 1500, 1150, 10));//51
	lstZonasRestringidasContinente.push_back(new Zona(3650, 1500, 10, 1400));//52
	lstZonasRestringidasContinente.push_back(new Zona(1300, 2900, 2500, 10));//53
	lstZonasRestringidasContinente.push_back(new Zona(1300, 1400, 10, 1500));//54
	lstZonasRestringidasContinente.push_back(new Zona(1850, 50, 100, 100));//55
}
void JuegoController::AgregarZonasRestringidasdun1() {
	lstZonasRestringidasdun1.push_back(new Zona(300, 332, 120, 5));
	lstZonasRestringidasdun1.push_back(new Zona(-190, 400, 514, 5));
	lstZonasRestringidasdun1.push_back(new Zona(-269, 140, 76, 70));
	lstZonasRestringidasdun1.push_back(new Zona(-555, 230, 376, 100));
	lstZonasRestringidasdun1.push_back(new Zona(-235, 400, 50, 80));
	lstZonasRestringidasdun1.push_back(new Zona(-430, 557, 170, 440));
	lstZonasRestringidasdun1.push_back(new Zona(-860, 999, 410, 1));
	lstZonasRestringidasdun1.push_back(new Zona(-620, 488, 50, 420));
	lstZonasRestringidasdun1.push_back(new Zona(-857, 444, 1, 500));
	lstZonasRestringidasdun1.push_back(new Zona(-870, 430, 115, 43));
	lstZonasRestringidasdun1.push_back(new Zona(-1070, 355, 150, 43));
	lstZonasRestringidasdun1.push_back(new Zona(-1109, 255, 1, 50));
	lstZonasRestringidasdun1.push_back(new Zona(-1108, 246, 395, 1));
	lstZonasRestringidasdun1.push_back(new Zona(-695, -190, 1, 435));
	lstZonasRestringidasdun1.push_back(new Zona(-695, -270, 270, 1));
	lstZonasRestringidasdun1.push_back(new Zona(447, 50, 1, 250));
	lstZonasRestringidasdun1.push_back(new Zona(200, 35, 244, 1));
	lstZonasRestringidasdun1.push_back(new Zona(-70, -10, 242, 190));
	lstZonasRestringidasdun1.push_back(new Zona(210, -270, 1, 190));
	lstZonasRestringidasdun1.push_back(new Zona(-50, -330, 250, 1));
	lstZonasRestringidasdun1.push_back(new Zona(-430, -280, 367, 167));
	lstZonasRestringidasdun1.push_back(new Zona(-430, -70, 250, 80));
	lstZonasRestringidasdun1.push_back(new Zona(-585, 10, 200, 110));
}
void JuegoController::AgregarZonasRestringidasdun2() {
	lstZonasRestringidasdun2.push_back(new Zona(300, -120, 1, 450));
	lstZonasRestringidasdun2.push_back(new Zona(300, -130, 216, 1));
	lstZonasRestringidasdun2.push_back(new Zona(550, -155, 70, 1));
	lstZonasRestringidasdun2.push_back(new Zona(630, -185, 85, 1));
	lstZonasRestringidasdun2.push_back(new Zona(710, -215, 100, 1));
	lstZonasRestringidasdun2.push_back(new Zona(815, -245, 86, 1));
	lstZonasRestringidasdun2.push_back(new Zona(920, -275, 10, 1));
	lstZonasRestringidasdun2.push_back(new Zona(960, -500, 1, 200));
	lstZonasRestringidasdun2.push_back(new Zona(960, -550, 578, 45));
	lstZonasRestringidasdun2.push_back(new Zona(1560, -599, 400, 1));
	lstZonasRestringidasdun2.push_back(new Zona(1969, -540, 1, 888));
	lstZonasRestringidasdun2.push_back(new Zona(300, 390, 1699, 1));

	lstZonasRestringidasdun2.push_back(new Zona(450, 25, 1, 205));
	lstZonasRestringidasdun2.push_back(new Zona(550, 25, 1, 205));
	lstZonasRestringidasdun2.push_back(new Zona(460, 25, 50, 1));
	lstZonasRestringidasdun2.push_back(new Zona(835, 25, 1, 205));
	lstZonasRestringidasdun2.push_back(new Zona(935, 25, 1, 205));
	lstZonasRestringidasdun2.push_back(new Zona(845, 25, 50, 1));
	lstZonasRestringidasdun2.push_back(new Zona(1220, 25, 1, 205));
	lstZonasRestringidasdun2.push_back(new Zona(1320, 25, 1, 205));
	lstZonasRestringidasdun2.push_back(new Zona(1230, 25, 50, 1));
	lstZonasRestringidasdun2.push_back(new Zona(1605, 25, 1, 205));
	lstZonasRestringidasdun2.push_back(new Zona(1880, 25, 1, 205));
	lstZonasRestringidasdun2.push_back(new Zona(1615, 25, 230, 1));
	lstZonasRestringidasdun2.push_back(new Zona(1730, 250, 40, 1));
}
void JuegoController::AgregarZonasRestringidasdun3() {
	lstZonasRestringidasdun3.push_back(new Zona(443, 89, 1, 250));
	lstZonasRestringidasdun3.push_back(new Zona(-1170, 80, 1570, 1));
	lstZonasRestringidasdun3.push_back(new Zona(-56, 372, 480, 1));
	lstZonasRestringidasdun3.push_back(new Zona(-260, 312, 20, 140));
	lstZonasRestringidasdun3.push_back(new Zona(-195, 90, 90, 125));
	lstZonasRestringidasdun3.push_back(new Zona(-210, 440, 100, 1));
	lstZonasRestringidasdun3.push_back(new Zona(-380, 90, 22, 188));
	lstZonasRestringidasdun3.push_back(new Zona(-580, 90, 22, 60));
	lstZonasRestringidasdun3.push_back(new Zona(-900, 90, 95, 120));
	lstZonasRestringidasdun3.push_back(new Zona(-1189, 122, 1, 220));
	lstZonasRestringidasdun3.push_back(new Zona(-1170, 380, 740, 1));
	lstZonasRestringidasdun3.push_back(new Zona(-400, 444, 100, 1));
	lstZonasRestringidasdun3.push_back(new Zona(-640, 244, 80, 100));
}
void JuegoController::AgregarZonasRestringidasdun4() {
	lstZonasRestringidasdun4.push_back(new Zona(180, -1250, 1, 1150));
	lstZonasRestringidasdun4.push_back(new Zona(189, -1290, 340, 1));
	lstZonasRestringidasdun4.push_back(new Zona(570, -1250, 1, 1150));
	lstZonasRestringidasdun4.push_back(new Zona(180, -20, 13, 20));
	lstZonasRestringidasdun4.push_back(new Zona(216, 60, 13, 90));
	lstZonasRestringidasdun4.push_back(new Zona(250, 200, 13, 120));
	lstZonasRestringidasdun4.push_back(new Zona(290, 400, 140, 1));
	lstZonasRestringidasdun4.push_back(new Zona(530, -20, 13, 20));
	lstZonasRestringidasdun4.push_back(new Zona(494, 60, 13, 90));
	lstZonasRestringidasdun4.push_back(new Zona(460, 200, 13, 120));

}
void JuegoController::AgregarZonasRestringidasdun5() {
	lstZonasRestringidasdun5.push_back(new Zona(344, 155, 1, 180));
	lstZonasRestringidasdun5.push_back(new Zona(350, 140, 977, 1));
	lstZonasRestringidasdun5.push_back(new Zona(1380, 155, 1, 430));
	lstZonasRestringidasdun5.push_back(new Zona(358, 358, 50, 1));
	lstZonasRestringidasdun5.push_back(new Zona(398, 370, 1, 200));
	lstZonasRestringidasdun5.push_back(new Zona(363, 592, 200, 130));
	lstZonasRestringidasdun5.push_back(new Zona(510, 310, 170, 180));
	lstZonasRestringidasdun5.push_back(new Zona(670, 592, 720, 1));
	lstZonasRestringidasdun5.push_back(new Zona(660, 592, 414, 130));
	lstZonasRestringidasdun5.push_back(new Zona(340, 750, 1, 370));
	lstZonasRestringidasdun5.push_back(new Zona(350, 1180, 1111, 1));
	lstZonasRestringidasdun5.push_back(new Zona(1470, 1150, 95, 20));
	lstZonasRestringidasdun5.push_back(new Zona(1600, 900, 1, 200));
	lstZonasRestringidasdun5.push_back(new Zona(1460, 980, 1, 70));
	lstZonasRestringidasdun5.push_back(new Zona(1526, 980, 1, 70));
	lstZonasRestringidasdun5.push_back(new Zona(1460, 970, 50, 1));
	lstZonasRestringidasdun5.push_back(new Zona(791, 722, 124, 150));
	lstZonasRestringidasdun5.push_back(new Zona(1010, 822, 130, 190));
	lstZonasRestringidasdun5.push_back(new Zona(1160, 822, 40, 110));
	lstZonasRestringidasdun5.push_back(new Zona(1170, 630, 88, 90));
	lstZonasRestringidasdun5.push_back(new Zona(1389, 880, 177, 1));
	lstZonasRestringidasdun5.push_back(new Zona(1300, 780, 80, 160));

}
void JuegoController::AgregarZonasRestringidasdun6() {
	lstZonasRestringidasdun6.push_back(new Zona(250, -170, 1, 1420));
	lstZonasRestringidasdun6.push_back(new Zona(260, 1320, 1970, 1));
	lstZonasRestringidasdun6.push_back(new Zona(2280, -170, 1, 1420));
	lstZonasRestringidasdun6.push_back(new Zona(269, -199, 1970, 1));
	lstZonasRestringidasdun6.push_back(new Zona(350, -56, 257, 225));
	lstZonasRestringidasdun6.push_back(new Zona(860, -56, 257, 225));
	lstZonasRestringidasdun6.push_back(new Zona(1374, -56, 257, 225));
	lstZonasRestringidasdun6.push_back(new Zona(1888, -56, 257, 225));
	lstZonasRestringidasdun6.push_back(new Zona(350, 456, 257, 225));
	lstZonasRestringidasdun6.push_back(new Zona(860, 456, 257, 225));
	lstZonasRestringidasdun6.push_back(new Zona(1374, 456, 257, 225));
	lstZonasRestringidasdun6.push_back(new Zona(1888, 456, 257, 225));
	lstZonasRestringidasdun6.push_back(new Zona(350, 968, 257, 225));
	lstZonasRestringidasdun6.push_back(new Zona(860, 968, 257, 225));
	lstZonasRestringidasdun6.push_back(new Zona(1374, 968, 257, 225));
	lstZonasRestringidasdun6.push_back(new Zona(1888, 968, 257, 225));

}
void JuegoController::AgregarZonasRestringidasdun7() {
	lstZonasRestringidasdun7.push_back(new Zona(320, 260, 1, 24));
	lstZonasRestringidasdun7.push_back(new Zona(325, 250, 10, 1));
	lstZonasRestringidasdun7.push_back(new Zona(425, 250, 10, 1));
	lstZonasRestringidasdun7.push_back(new Zona(438, 260, 1, 24));
	lstZonasRestringidasdun7.push_back(new Zona(340, 350, 80, 1));
	lstZonasRestringidasdun7.push_back(new Zona(340, -550, 1, 780));
	lstZonasRestringidasdun7.push_back(new Zona(420, -550, 1, 780));
	lstZonasRestringidasdun7.push_back(new Zona(140, -770, 1, 380));
	lstZonasRestringidasdun7.push_back(new Zona(150, -788, 450, 1));
	lstZonasRestringidasdun7.push_back(new Zona(150, -377, 180, 1));
	lstZonasRestringidasdun7.push_back(new Zona(630, -770, 1, 380));
	lstZonasRestringidasdun7.push_back(new Zona(450, -377, 180, 1));

}
void JuegoController::AgregarZonasRestringidasciudad() {
	lstZonasRestringidasciudad.push_back(new Zona(30, -15, 600, 1));
	lstZonasRestringidasciudad.push_back(new Zona(30, 10, 103, 100));
	lstZonasRestringidasciudad.push_back(new Zona(370, 15, 100, 1));
	lstZonasRestringidasciudad.push_back(new Zona(550, 15, 350, 100));
	lstZonasRestringidasciudad.push_back(new Zona(910, 15, 50, 30));
	lstZonasRestringidasciudad.push_back(new Zona(-10, 110, 1, 450));
	lstZonasRestringidasciudad.push_back(new Zona(1000, 90, 1, 250));
	lstZonasRestringidasciudad.push_back(new Zona(1000, 450, 1, 120));
	lstZonasRestringidasciudad.push_back(new Zona(130, 280, 95, 30));
	lstZonasRestringidasciudad.push_back(new Zona(830, 280, 70, 30));
	lstZonasRestringidasciudad.push_back(new Zona(510, 395, 1, 1));
	lstZonasRestringidasciudad.push_back(new Zona(30, 600, 950, 1));
	lstZonasRestringidasciudad.push_back(new Zona(1060, 380, 1, 50));
	lstZonasRestringidasciudad.push_back(new Zona(1000, 330, 50, 1));
	lstZonasRestringidasciudad.push_back(new Zona(1000, 450, 50, 1));
}

void JuegoController::GuardarArchivo(){
	ofstream fdata("archivo.csv");
	if (!fdata.is_open()) System::Windows::Forms::MessageBox::Show("No se pudo abrir el archivo", "Error", System::Windows::Forms::MessageBoxButtons::OK, System::Windows::Forms::MessageBoxIcon::Error);
	else{					
		fdata << jugador->GetNivel() << ';' << jugador->GetDinero() << ';' << jugador->GetExperiencia() << ';';
		fdata << jugador->GetArma()->GetID() << ';';
		fdata << jugador->GetMision()->GetID() << ';';
		fdata << boss1->GetVisible() << ';' << boss2->GetVisible() << ';' << boss3->GetVisible() << ';' << boss4->GetVisible();
	}
	fdata.close();
	System::Windows::Forms::MessageBox::Show("Partida Guardada!", " ", System::Windows::Forms::MessageBoxButtons::OK, System::Windows::Forms::MessageBoxIcon::Information);
}

void JuegoController::AbrirArchivo(){
	ifstream fdata("archivo.csv");
	if (!fdata.is_open()) System::Windows::Forms::MessageBox::Show("No se pudo abrir el archivo", "Error", System::Windows::Forms::MessageBoxButtons::OK, System::Windows::Forms::MessageBoxIcon::Error);
	else{
		string aux;
		while (!fdata.eof()){
			getline(fdata, aux, ';');
			jugador->SubirNivel(atoi(aux.c_str()));
			getline(fdata, aux, ';');
			jugador->SetDinero(atoi(aux.c_str()));
			getline(fdata, aux, ';');
			jugador->SetExperiencia(atoi(aux.c_str()));
			getline(fdata, aux, ';');
			jugador->SetArma(arbolArmas.Buscar(atoi(aux.c_str())), false);
			getline(fdata, aux, ';');
			jugador->SetMision(arbolMisiones.Buscar(atoi(aux.c_str())));
			getline(fdata, aux, ';');
			boss1->SetVisible(atoi(aux.c_str()));
			getline(fdata, aux, ';');
			boss2->SetVisible(atoi(aux.c_str()));
			getline(fdata, aux, ';');
			boss3->SetVisible(atoi(aux.c_str()));
			getline(fdata, aux, ';');
			boss4->SetVisible(atoi(aux.c_str()));
		}
	}
}

void JuegoController::MostrarPantallaGuardado(System::Drawing::Graphics ^gr){
	guardar->Mostrar(gr);

	if (seleccionGuardar == 1) gr->DrawRectangle(gcnew System::Drawing::Pen(System::Drawing::Color::Red, 4), 270, 185, 180, 50);
	else if (seleccionGuardar == 0) gr->DrawRectangle(gcnew System::Drawing::Pen(System::Drawing::Color::Red, 4), 270, 265, 180, 50);
}

#pragma endregion
#pragma endregion