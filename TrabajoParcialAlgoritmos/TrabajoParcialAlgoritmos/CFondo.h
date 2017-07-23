#pragma once
using namespace System::Drawing;

class CFondo
{

public:
	CFondo(void);
	~CFondo(void);

	void Mostrar(Graphics ^gr, Bitmap ^bmp);
};