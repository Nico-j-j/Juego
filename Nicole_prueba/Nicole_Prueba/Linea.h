#pragma once

#define xInicial 256
#define yInicial 362

using namespace System;
using namespace System::Drawing;
using namespace std;

class CLinea {
private:
	int x;
	int y;
	double distancia;
public:
	CLinea(){
		x = 256;
		y = 362;
	}	
	~CLinea(){}
	void dibujar(Graphics ^g) {
		g->DrawLine(gcnew Pen(Color::Black), xInicial + (25 / 2), yInicial + (25 / 2), x, y);
	}

	//double getDistancia() {
	//	double distancia = sqrt(pow(xInicial - this->x, 2) + pow(yInicial - this->y, 2));
	//	return distancia;
	//}

	void setX(int x) { this->x = x; }
	void setY(int y) { this->y = y; }

	int getX() { return x; }
	int getY() { return y; }
};