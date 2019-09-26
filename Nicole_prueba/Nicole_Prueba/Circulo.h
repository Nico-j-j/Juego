#pragma once

using namespace System;
using namespace System::Drawing;

//constexpr int Ancho = 25;
//constexpr int Largo = 25;

class CFigura {
	protected:
		int X;
		int Y;
		int Ancho, Largo;
		double dX, dY;

	public:
		CFigura(int X, int Y,int Ancho, int Largo, double dX, double dY);
		~CFigura();
		virtual void Dibujar(Graphics^g) {};
		void Mover(int AnchoF, int LargoF);
		bool HayColision(double pX, double pY);
};

CFigura::CFigura(int X, int Y, int Ancho, int Largo, double dX, double dY) {
	this->X = X;
	this->Y = Y;
	this->Ancho = Ancho;
	this->Largo = Largo;
	this->dX = dX;
	this->dY = dY;
}
CFigura::~CFigura() {}
void CFigura::Mover(int AnchoF, int LargoF) {
	if (X + dX <0 || X + dX + Ancho > AnchoF)
		dX *= -1;
	if (Y + dY < 0 || Y + dY + Largo > LargoF)
		dY *= -1;

	X += dX;
	Y += dY;
}
bool CFigura::HayColision(double pX, double pY) {
	// De acuerdo a las coordenadas "x" e "y" (punto)
	return pX >= X && pX <= X + Ancho &&
		pY >= Y && pY <= Y + Largo;
}


//BUBBLE ROJOS
class CBubbleRed : public CFigura
{
public:
	CBubbleRed(int X, int Y, int Ancho, int Largo, double dX, double dY);
	~CBubbleRed();
	void Dibujar(Graphics^g);

private:

};

CBubbleRed::CBubbleRed(int X, int Y, int Ancho, int Largo, double dX, double dY) :CFigura(X, Y, Ancho, Largo, dX, dY) {}
CBubbleRed::~CBubbleRed(){}
void CBubbleRed::Dibujar(Graphics^g){
	SolidBrush^ objSolidBrush = gcnew SolidBrush(Color::Red);
	g->FillEllipse(objSolidBrush, X, Y, Ancho, Largo);
}


//BUBBLE VERDES
class CBubbleGreen : public CFigura
{
public:
	CBubbleGreen(int X, int Y, int Ancho, int Largo, double dX, double dY);
	~CBubbleGreen();
	void Dibujar(Graphics^g);

private:

};

CBubbleGreen::CBubbleGreen(int X, int Y, int Ancho, int Largo, double dX, double dY) :CFigura(X, Y, Ancho, Largo, dX, dY) {}
CBubbleGreen::~CBubbleGreen() {}
void CBubbleGreen::Dibujar(Graphics^g) {
	SolidBrush^ objSolidBrush = gcnew SolidBrush(Color::Green);
	g->FillEllipse(objSolidBrush, X, Y, Ancho, Largo);
}



//BUBBLE AZULES
class CBubbleBlue : public CFigura
{
public:
	CBubbleBlue(int X, int Y, int Ancho, int Largo, double dX, double dY);
	~CBubbleBlue();
	void Dibujar(Graphics^g);

private:

};

CBubbleBlue::CBubbleBlue(int X, int Y, int Ancho, int Largo, double dX, double dY) :CFigura(X, Y,Ancho, Largo, dX, dY) {}
CBubbleBlue::~CBubbleBlue() {}
void CBubbleBlue::Dibujar(Graphics^g) {
	SolidBrush^ objSolidBrush = gcnew SolidBrush(Color::Blue);
	g->FillEllipse(objSolidBrush, X, Y, Ancho, Largo);
}
