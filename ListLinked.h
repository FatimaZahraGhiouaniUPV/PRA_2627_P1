#ifndef LIST_LINKED_H
#define LIST_LINKED_H

#include <ostream>
#include <stdexcept>
#include <iostream>
#include "List.h"
#include "Node.h"
using namespace std;

template <typename T>
class ListLinked : public List<T> {

    private:
	    Node<T>* first;
	    int n;


    public:
	    ListLinked(){
	    	n=0;
		first=nullptr;

	    }

	    ~ListLinked(){
		   	while (first!=nullptr){
		    	Node<T>* aux= first->next;
		    	delete first;
		    	first=aux;
		    }
	    }

	    T operator[] (int pos){
		    if (pos<0 || pos>= n){
		    	throw out_of_range("Error: posición fuera de rango");
		    }
		    int i=0;
		    Node<T>* aux=first;
		    while(i<pos && aux!=nullptr){
		    	aux=aux->next;
			i++;
		    }
		    return aux->data;
	    
	    }

	    friend ostream& operator<<(ostream &out, ListLinked &list){
		    out <<"[ ";
		    Node<T>* aux=list.first;
		    while(aux!=nullptr){
		    	out << aux->data;
			if (aux->next!=nullptr){
			 out << ", ";
			}
			aux=aux->next;
		    }
		    out << "]";
		    return out;
	    }

	    //Métodos heredados de List.h
	    void insert (int pos, T e){
	    	if (pos < 0 || pos > n){
			throw out_of_range("Error: posición fuera de rango");

		}
		if (pos==0){
			Node<T>* a = new Node<T>(e, first);
			first = a;
		}
		else{
			Node<T>* aux = first;
			for (int i=0;i<pos-1;i++){
				aux=aux->next;
			}
			Node<T>* a = new Node<T>(e, aux->next);
			aux->next=a;
		
		}
		n++;
	    }

	    void append(T e){
	    	insert(n,e);
	    }

	    void prepend(T e){
	    	insert(0, e);
	    }

	    T remove(int pos){
	    	if (pos<0 || pos>=n){
			throw out_of_range("Error: posición fuera de rango");
		}
		T element;

		if (pos==0){
			Node<T>* aux = first;
			element=aux->data;
			first=first->next;
			delete aux;
		}
		else{
			Node<T>* prev=nullptr;
			Node<T>* aux=first;
			for (int i=0;i<pos;i++){
				prev=aux;
				aux=aux->next;
			}

			prev->next=aux->next;
			element=aux->data;
			delete aux;
		}
		n--;
		return element;
	    }

	    T get (int pos) {
	    	if (pos<0 || pos>=n){
			throw out_of_range("Error: posición fuera de rango");
		}
		Node<T>* aux= first;
		for (int i=0;i<pos;i++){
			aux=aux->next;
		}
		return aux->data;

	    }

	    int search(T e){
	    	Node<T>* aux=first;
		int i=0;
		while (aux!=nullptr){
			aux=aux->next;
			i++;
		}
		if (aux==nullptr) return -1;
		else return i;
	    }

	    bool empty(){
	    	return n==0;
	    }

	    int size(){
	    	return n;
	    }



};

#endif
