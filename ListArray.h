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
			return out;
		
		}



};
