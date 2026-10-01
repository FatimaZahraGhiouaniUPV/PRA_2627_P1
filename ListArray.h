#include <iostream>
#include <ostream>
#include <stdexcept>
#include "List.h"
using namespace std;
template <typename T> 

class ListArray : public List<T> {
	private:
		T* arr; //Puntero al inicio del array
		int max; //Tamaño del array
		int n; //Número de elementos de la lista
		static const int MINSIZE=2; //tamaño mínimo del array
		
		void resize(int new_size){
			T* newArr=new T[new_size];
			for (int i=0;i<n;i++){
				newArr[i]=arr[i];
			}
			delete[] arr;
			arr=newArr;
			max=new_size;
		
		}

	public:
		//Métodos de List.h
		void insert (int pos, T e){
			if (pos<0 || pos>n){
				throw out_of_range("Error: posición fuera de rango");
			}
			for (int i=n;i>pos;i--){
				arr[i]=arr[i-1];		
			}
			arr[pos]=e;
			n++;
		}
		void append(T e){
			insert(n,e);
		
		}
		
		void prepend(T e){
			insert(0,e);
		
		}

		T remove(int pos){
			if (pos<0 || pos>n){
				throw out_of_range ("Error: posición fuera de rango");
			
			}
			T removido = arr[pos];
			for (int i=pos; i<n; i++){
				arr[i]=arr[i+1];
			}
			n--;
			return removido;

		
		}

		T get(int pos){
			if (pos<0 || pos > n){
				throw out_of_range ("Error: posición fuera de rango");
			}
			return arr[pos];
		
		}

		int search (T e){
			for (int i=0;i<n;i++){
				if (arr[i]==e){
					return i;
				}
			
			}
			return -1;
		
		}

		bool empty(){
			if (n==0) return true;
			return false;
		
		}

		int size(){
			return n;
		}

		//Métodos de ListArray.h

		ListArray(){
			 arr=new T[MINSIZE];
			 max=MINSIZE;
			 n=0;
		}

		~ListArray(){
			delete[] arr;
		
		}

		T operator[](int pos){
			if (pos<0 || pos>n-1){
				throw out_of_range("Error: fuera de rango");
			
			}
			
			return arr[pos];
		}
		friend ostream& operator<<(ostream &out, const ListArray<T> &list){
			out << "[ ";
			for (int i=0;i<list.n;i++){
				out << list.arr[i];
				if (list.n-1>i){
					out << ", ";
				
				}
			
			}
			out << "]";
			return out;
		
		}



};
