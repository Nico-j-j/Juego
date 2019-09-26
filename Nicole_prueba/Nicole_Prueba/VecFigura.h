#pragma once

#include"Circulo.h"
#include<vector>

using namespace std;

//constexpr auto X = 256;
//constexpr auto Y = 320;

class CVecFiguras {
private:
	vector<CFigura*> arrFigura;
	//vector<CFigura> arrFiguraEst;
public:
	CVecFiguras();
	~CVecFiguras();
	//void Agregar(int X, int Y, int Ancho, int Largo, int dX, int dY);
	void Cambio(int Tipo/*int X, int Y, int Ancho, int Largo,*/ /*int dX, int dY*/);
	bool HayColosion(int pX, int pY);
	void Eliminar(int pX, int pY);
	void Mover(int AnchoF, int LargoF);
	void Dibujar(Graphics^ g);
};

CVecFiguras::CVecFiguras() {}
CVecFiguras::~CVecFiguras(){}


//void CVecFiguras::Agregar(int X, int Y, int Ancho, int Largo, int dX, int dY) {
//	arrFigura.push_back(CFigura(X, Y, Ancho, Largo, dX, dY));
//}


void CVecFiguras::Cambio(int Tipo/*int X, int Y, int Ancho, int Largo,*//* int dX, int dY*/){
	//Random^ r = gcnew Random(DateTime::Now.Ticks);
	int X = 256;
	int Y = 320;
	int Ancho = 25;
	int Largo = 25;
	int dX = 5;
	int dY = 5;

	CFigura* objFigura;

	if (Tipo == 1)
		objFigura = new CBubbleRed(X, Y, Ancho, Largo, dX, dY);
	else if (Tipo == 2)
		objFigura = new CBubbleGreen(X, Y, Ancho, Largo, dX, dY);
	else if (Tipo == 3)
		objFigura = new CBubbleBlue(X, Y, Ancho, Largo, dX, dY);

	//arrFigura.push_back(objFigura);
	//arrFiguraEst.push_back(CFigura(X, Y, Ancho, Largo, dX, dY));
	//arrFigura.push_back(CFigura(X, Y, /*Ancho, Largo,*/ dX, dY));
	arrFigura.push_back(objFigura);

}

bool CVecFiguras::HayColosion(int pX, int pY){	
	for (int i = 0; i < arrFigura.size(); i++)
		if (arrFigura.at(i)->HayColision(pX, pY))
			return true;
	return false;
}
void CVecFiguras::Eliminar(int pX, int pY) {
	for (int i = 0; i < arrFigura.size(); i++)
		if (arrFigura.at(i)->HayColision(pX, pY)) {
			arrFigura.erase(arrFigura.begin() + i);
			break;
		}
}
void CVecFiguras::Mover(int AnchoF, int LargoF){
	for (int i = 0; i < arrFigura.size(); i++)
		arrFigura.at(i)->Mover(AnchoF, LargoF);
}
void CVecFiguras::Dibujar(Graphics^ g){
	for (int i = 0; i < arrFigura.size(); i++)
	{
		arrFigura.at(i)->Dibujar(g);
	}
}