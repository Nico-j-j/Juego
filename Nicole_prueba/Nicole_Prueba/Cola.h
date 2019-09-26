#pragma once
#include "Nodo.h"
#include <iostream>

template <class T>
class Cola {
private:
	Nodo<T> *inicio;
	Nodo<T> *fin;
public:
	Cola();
	~Cola();
	void enqueue(T e);
	T dequeue();
	bool vacio();
	T MostrarElemento();
};

template <class T>
Cola<T>::Cola() {
	this->inicio = NULL;
	this->fin = NULL;
}
template <class T>
Cola<T>::~Cola() {}

template <class T>
void Cola<T>::enqueue(T e) {
	Nodo<T>* nodo = new Nodo<T>(e);
	if (vacio()) {
		inicio = nodo;
		fin = nodo;
	}
	else {
		fin->siguiente = nodo;
		fin = nodo;
	}
}

template <class T>
bool Cola<T>::vacio() {
	return inicio == NULL;
}

template <class T>
T Cola<T>::dequeue() {
	T elem = inicio->elemento;
	if (inicio == fin) {
		inicio = NULL;
		fin = NULL;
	}
	else {
		inicio = inicio->siguiente;
	}
	return elem;
}

template<class T>
T Cola<T>::MostrarElemento() {
	return inicio->elemento;
}