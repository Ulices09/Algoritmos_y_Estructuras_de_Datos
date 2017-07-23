#include "CFondo.h"

CFondo::CFondo(void){}
CFondo::~CFondo(void){}

void CFondo::Mostrar(Graphics ^gr, Bitmap ^bmp)
{
	/*Rectangle porcion = Rectangle(X, Y, gr->VisibleClipBounds.Width, gr->VisibleClipBounds.Height);
	Rectangle zoom = Rectangle(X, Y, gr->VisibleClipBounds.Width, gr->VisibleClipBounds.Height);

	gr->DrawImage(bmp, zoom, porcion, GraphicsUnit::Pixel);*/

	gr->DrawImage(bmp, 0, 0, 1000, 580);
}