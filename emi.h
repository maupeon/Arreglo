//Por Emiliano Abascal Gurria
//API por Victor de la Cueva
#ifndef ARREGLO1_HPP
#define ARREGLO1_HPP

#include <iostream>
#include <string>
#include <fstream>  
#include <cstdlib>
using namespace std;
int tamanio;

class Arreglo{
	private:
		int *array;//Arreglo predefinido de numeros enteros.
		int t;
	public:
		Arreglo();
		// Lee los datos de una archivo cuyo nombre recibe como parámetro
		void lecturaDatos(string archivo);
		// busca el elemento K en el arreglo, usando el algoritmo SECUENCIAL. Si lo // encuentra devuelve su posición y en caso contrario regresa un ‐1.
		int busquedaSecuencial(int K);
		// busca el elemento K en el arreglo, usando el algoritmo BINARIO. Si lo // encuentra devuelve su posición y en caso contrario regresa un ‐1.
		int busquedaBinaria(int, int, int);
		void selectionSort();
		void bubbleSort();
		void insertionSort();
		void merge(int, int, int);
		void mergeSort(int , int);
		void quickSort(int lo, int hi);
		int particion(int lo, int hi);
		void swapArr(int a, int b);
		void print();
};

Arreglo:: Arreglo(){
	
}//Constructor sin parametros

void Arreglo:: swapArr(int a, int b){
	int auxiliar = array[a];
	
	array[a] = array[b];
	array[b] = auxiliar;
}

void Arreglo::lecturaDatos(string file){//Funcionalidad del metodo lecturaDatos.
	int i = 0;//Variable iteradora.
	fstream archivo;//Se instancia el archivo.
	archivo.open(file);//Es una funcion que abre el archivo con el nombre del parametro de la funcion.
	string line;//String que hace referencia al valor de cada renglon del archivo.
	getline(archivo, line);//Se le da el valor del primer renglon a la variable line.
	tamanio = stoi(line);//Se convierte el valor de tipo string de line a int, se le asigna a la variable tamanio.
	array = new int[tamanio];//Se asigna espacio en la memoria para el arreglo que se va a usar, con el tamano de la variable tamanio.
	while(!archivo.eof()){//Mientras no se llegue al ultimo renglon.
		archivo.ignore(0, '\n');
		getline(archivo, line, '\n');
		array[i] = atoi(line.c_str());//asigna el valor del renglon actual al arreglo en la posicion i.
		i++;//Se aumenta el valor de i.
	}
	t = tamanio;
}

int Arreglo:: busquedaSecuencial(int k){//Funcionalidad del metodo busquedaSecuencial.
	int x;
	if(array[0] == k || tamanio == 1){//Caso base que dice que si el valor del primer elemento es igual al numero que se paso por parametro de la funcion o el tamaño del arreglo es igual a 1, entonces se regresa 0.
		x = 0;
	}
	for (int i = 0; i <= tamanio; i++){//Ciclo que itera por cada valor del arreglo hasta que i sea menor o igual al tamaño del arreglo.
		if(array[i] == k){//Si el elemento en la posicion i del arreglo es igual al numero que se paso por parametro de la funcion entonces se regresa el valor de i.
			x = i;
			break;//Rompe el ciclo si la condicion se cumple.
		}
		if(array[i] != k && i == tamanio){//Si el elemento en la posicion i del arreglo es diferente al numero que se paso por parametro de la funcion y la variable i es igual al tamaño del arreglo, entonces se regresa -1.
			x = -1;
		}
	}
	return x;
}
int Arreglo:: busquedaBinaria(int inicio, int fin, int K){//Funcionalidad del metodo busquedaBinaria.
	if(fin < inicio){//Si el valor del ultimo valor del indice donde se va a buscar es menor que el valor del primer valor del indice donde se va a buscar, entonces regresa -1.
		return  -1;
	}else{
		int medio = (inicio + fin)/2;//Se divide la suma de la variable inicio y la variable fin, entre dos, para obtener el valor de la variable medio.
		if(K == array[medio]){//Si el elemento que quieres encontrar es igual al elemento en la posicion medio del arreglo, entonces se regresa medio.
			return medio;
		}else if(K < array[medio]){//Si el elemento que quieres encontrar es menor que el elemento en la posicion medio del arreglo, entonces se regresa la llamada de la misma funcion pero con el parametro "fin" cambiado por medio-1 haciendo que se recurse.
			return busquedaBinaria(inicio, medio-1, K);
		}else{//Si no, entonces se regresa la llamada de la misma funcion pero con el parametro "inicio" cambiado por medio+1 haciendo que se recurse.
			return busquedaBinaria(medio + 1, fin, K);
		}
	}
}
void Arreglo:: selectionSort(){
	int posmin;
	int temp;
	for (int i = 0; i < t-1; i++){
		posmin = i;
		for(int j = i + 1; j < t; j++){
			if(array[j] < array[posmin]){
				posmin = j;
				print();
			}
		}
		if (posmin != i){
			temp = array[i];
			array[i] = array[posmin];
			array[posmin] = temp;
		}
	}
}

void Arreglo:: bubbleSort() {
	bool s = true;
	int j = 0;
	int tmp;
	while(s){
		s = false;
		j++;
		for (int i = 0; i < t - j; i++) {
			if (array[i] > array[i + 1]) {
				tmp = array[i];
				array[i] = array[i + 1];
				array[i + 1] = tmp;
				s = true;
				
			}
			print();
		}
	}
}
void Arreglo:: insertionSort(){
	int j; 
	int temp;
	for (int i = 0; i < t; i++){
		j = i;
		while (j > 0 && array[j] < array[j-1]){
			temp = array[j];
			array[j] = array[j-1];
			array[j-1] = temp;
			j--;
			  }
		}
}

void Arreglo:: merge(int ab,int mid, int ar){
	int x = ab;
	int y = mid + 1;
	int z = ab;
	int arrb[t];
	for(int x = ab; x <= ar; x++){//Se copia el valor del arreglo original en el arreglo arrb.	
		arrb[x] = array[x];
	}	
	while (x <= mid && y <= ar){
		if (arrb[x] < arrb[y]){// Si el valor del arreglo arrb en la posicion y es menor al valor del arreglo arrb en la posicion izquierda o (x), entonces el valor del arreglo array en la posicion z tendra el valor del arreglo arrb en la posicion y.
			array[z] = arrb[x];
			z++;
			x++;
		}else{
			array[z] = arrb[y];//Si lo anterior no se cumple, el valor del arreglo array en la posición z guardará el valor del arreglo arrb en la posicion x.
			z++;
			y++;
		}
	}
	while (x <= mid){//	Mientras el tamaño de x sea menor o igual al valor de la mitad del tamaño del arreglo, el valor del areglo array en la posición z guardará el valor de el arreglo arrb en la posicion x.
		array[z] = arrb[x];
		z++;
		x++;
	}
	while (y <= ar){//mientras el tamaño de y sea menor o igual al valor de la ultima posicion del arreglo array, el areglo array en la posición z guardará el valor de arrb contenido en y.
		array[z] = arrb[y];
		z++;
		y++;
	}
}


void Arreglo:: mergeSort(int ab,int ar){
	if(ab < ar){
		int mid = ab + (ar - ab)/2;//Se saca la mitad de la dimension del arreglo.
		mergeSort(mid + 1,ar);// Se ordena la mitad derecha, llamando su misma funcion.
		mergeSort(ab, mid);//Se ordena mitad izquierda, llamando su misma funcion.
		merge(ab, mid, ar);// Se hace "Merge Sort" de las dos mitades, llamando la funcion merge.
		
	}
	
}

void Arreglo:: quickSort(int lo, int hi){
	if (hi <= lo){//Si hi es menor o igual a lo entonces se regresa valor vacio.
		return;
		
	}else{//sino
	cout<<"lol";
		int j = particion(lo, hi); //Se declara la variable j que va a tener como valor el resultado de la funcion "particion".
		quickSort(lo, j-1);//Se llama recursivamente la funcion quickSort con argumentos, lo y j-1.
		quickSort(j+1, hi);//Se llama recursivamente la funcion quickSort con argumentos, j+1 y hi.
	}
}

int Arreglo:: particion(int lo, int hi){
	int i = lo;//Declaracion de la variable i que es igual a lo.
	int j = hi;//Declaracion de la variable j que es igual a hi.
	int v = lo;//Declaracion de la variable v que es igual a lo.
	
	while (i < j){// Mientras el valor de i sea menor que el valor de j.
			while (array[j] > array[v]){//Mientras el arreglo en la posicion j sea mayor al arreglo en la posicion del pivote entonces se reducira el valor de j en 1, moviendolo de derecha a izquierda.
				j--;
			}
			while (i <= hi && array[i] < array[v]){//Mientras i sea menor o igual a hi, y el valor del arreglo en la posicion i sea menor que el arreglo en la posicion del pivote, se aumentara el valor de i en uno, moviendo i de izquierda a derecha.
				i++;
			}
			if (i < j){//Si el valor de i es mayor al valor de j, entonces se intercambian i por j.
				swapArr(i,j);
			}
		}
		swapArr(v,j);//Se intercambian el pivote por j.
		return j;//Se regresa el valor de j
}

void Arreglo:: print(){
	int index;
	if (t > 0){
		for(index = 0; index < t; index++){
			cout << endl << array[index];
		}
		cout << endl;
	}
	else{
		cout << "\n No Hay Elementos" << endl;
	}		
}
#endif
