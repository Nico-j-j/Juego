#pragma once

template <class T>
class Nodo {
public:
	T elemento;
	Nodo<T> *siguiente;
	Nodo(T e, Nodo<T> *sig = NULL) {
		elemento = e;
		siguiente = sig;
	}
};