#pragma once

class ObjetoAnimado
{
protected:
	int posicionX;
	int posicionY;
	int deltaX;
	int deltaY;
	int ancho;
	int alto;
	int indiceSpriteX;
	int indiceSpriteY;
	int deltaSpriteX;
	int deltaSpriteY;
	int tipo;
	bool visible;
	int nivel;
	int experiencia;
	int dinero;
	char* archivoImagen;

public:
	ObjetoAnimado();
	~ObjetoAnimado();

	int GetPosicionX();
	int GetPosicionY();
	int GetDeltaX();
	int GetDeltaY();
	int GetAncho();
	int GetAlto();
	int GetIndiceSpriteX();
	int GetIndiceSpriteY();
	int GetDeltaSpriteX();
	int GetDeltaSpriteY();
	int GetTipo();
	bool GetVisible();
	int GetNivel();
	int GetExperiencia();
	int GetDinero();
	char* GetArchivoImagen();

	void SetPosicionX(int _posicionX);
	void SetPosicionY(int _posicionY);
	void SetAncho(int _ancho);
	void SetAlto(int _alto);
	void SetIndiceSpriteX(int _indiceSpriteX);
	void SetIndiceSpriteY(int _indiceSpriteY);
	void SetDeltaSpriteX(int _deltaSpriteX);
	void SetDeltaSpriteY(int _deltaSpriteY);
	void SetTipo(int _tipo);
	void SetVisible(bool _visible);
	void SetNivel(int _nivel);
	void SetExperiencia(int _experiencia);
	void SetDinero(int _dinero);
	void SetDeltaX(int _deltaX);
	void SetDeltaY(int _deltaY);
	void SetArchivoImagen(char* _archivo);

	void Mover();
	void CambiarSprite();
	virtual void Mostrar(System::Drawing::Graphics ^gr);
};
