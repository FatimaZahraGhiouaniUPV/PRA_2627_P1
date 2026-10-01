#ifndef LIST_H
#define LIST_H
#include <iostream>
using namespace std;

// Clase abstracta pura y genérica, que definirá los métodos de la interfaz de una EDL de tipo lista, para almacenar secuencias de objetos de tipo genérico T.

template <typename T>
class List{
	public:
		void insert(int pos, T e);
		void append(T e);
		void prepend(T e);
		T remove(int pos);
		T get(int pos);
		int search(T e);
		bool empty();
		int size();
		~List(){};


};

#endif
