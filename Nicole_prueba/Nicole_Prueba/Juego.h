#pragma once
#include "Cola.h"
#include "Circulo.h"
#include "VecFigura.h"

using namespace std;

class Juego {
private:
	Cola<CFigura*>* cola;
	CFigura* burbuja;
	vector<CFigura*> arrFigura;
public:
	Juego();
	~Juego();
	void AgregarCirculo();
	void dibujar(Graphics^ g);
	void disparar();
	void mover(int anchof, int largof);
	bool colision(int pX, int pY);
	void eliminar(int pX, int pY);
	void fondo(Graphics ^ g);
};

Juego::Juego() {
	cola = new Cola<CFigura*>();
	burbuja = NULL;
	AgregarCirculo();
}

Juego::~Juego() {}

void Juego::AgregarCirculo() {
	Random^ r = gcnew Random(DateTime::Now.Ticks);
	int tipo = r->Next(3);
	if (tipo == 0)
		cola->enqueue(new CBubbleRed(256, 350, 25, 25, 5, -5));
	if (tipo == 1)
		cola->enqueue(new CBubbleBlue(256, 350, 25, 25, 5, -5));
	if (tipo == 2)
		cola->enqueue(new CBubbleGreen(256, 350, 25, 25, 5, -5));
}

void Juego::dibujar(Graphics^ g) {
	cola->MostrarElemento()->Dibujar(g);
	if (burbuja != NULL)
		burbuja->Dibujar(g);
}

void Juego::disparar() {
	burbuja = cola->dequeue();
	AgregarCirculo();
}

void Juego::mover(int anchof, int largof) {
	burbuja->Mover(anchof, largof);
}

bool Juego::colision(int pX, int pY) {
	for (int i = 0; i < arrFigura.size(); i++)
		if (arrFigura.at(i)->HayColision(pX, pY))
			return true;
	return false;
}

void Juego::eliminar(int pX, int pY) {
	for (int i = 0; i < arrFigura.size(); i++)
		if (arrFigura.at(i)->HayColision(pX, pY)) {
			arrFigura.erase(arrFigura.begin() + i);
			break;
		}
}

void Juego::fondo(Graphics^ g) {
	Bitmap ^bmp = gcnew Bitmap("imagen.png");
	g->DrawImage(bmp, 0, 0, 900, 510);
	delete bmp;
}