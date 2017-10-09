#ifndef ARREGLO_H
#define ARREGLO_H
//Se cargan las librerías necesarias para el programa.
#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>
#define MAX 1000
using namespace std;

//Se declara la clase Arreglo.
class Arreglo{
//Se declaran los parámetros privados.
private:
  //Se declara el arreglo y el tamaño del arreglo.
  int datos[MAX];
  int t;

public:
  /* Se declara la función lecturaTeclado con ningún parámetro.
  Esta función lee los datos enteros que proporciona el usuario.*/
  void lecturaTeclado(){
    /*Se le pregunta al usuario el tamaño del arreglo con un
    límite no mayor a 1000 elementos.*/
    std::cout << "¿De que tamaño quieres tu arreglo? (Máximo 1000)" << '\n';
    std::cin >> t;
    /*Se le pide dato por dato al usuario y en seguida se ensertan
    al arreglo.*/
    for(int i =0;i<t;i++){
      std::cout << "Dame un dato: " << '\n';
      std::cin >> datos[i];
    }
  }
  /* Se declara la función lecturaDatos con un parámetro.
  Esta función lee los datos enteros de un archivo.*/
  void lecturaDatos(string archivo){
    /*Se declara el iterador que operará en el arreglo.
    Se declara el archivo que se va a abrir y leer.*/
    int i=0;
    fstream arch;
    arch.open(archivo);
    //Lee el primer elemento que es el tamaño del arreglo.
    arch>>t;
    while (!arch.eof()) {
      /*Se pasan los datos del archivo a mi arreglo declarado
      anteriormente.*/
      arch>>datos[i];
      //Se aumenta en uno el iterador.
      i++;
    }
  }
  /* Se declara la función busquedaSecuencial con un parámetro.
  Esta función busca secuencialmente en el arreglo un dato llamado k.*/
  int busquedaSecuencial(int k){
    //Se declaran los parámetros índice y respuesta.
    int respuesta, indice;
    /*En este ciclo buscará el valor de k dentro del arreglo
    y si lo encuentra lo regresa en respuesta.*/
    for(indice=0;indice<t;indice++){
      if(k==datos[indice]){
        respuesta = indice;
        return respuesta;
      }
    }
    //Si no encuentra el valor regresará un -1.
    return -1;
  }
  /* Se declara la función busquedaBinaria con tres parámetro.
  Se pasan los siguientes valores: el primero en el arreglo,
  el último y el valor a buscar.
  Esta función busca un dato, partiendo en dos el arreglo.
  El arreglo tiene que estar ordenado.*/
  int busquedaBinaria(int inicio, int fin, int k){
    //Se declara el indice que dará el valor a encontrar.
    int indice;
    /*Si el último elemento del arreglo es mayor que el
    primero, significa que no está, por eso regresa un -1.*/
    if(fin<inicio){
      return -1;
    }
    else{
      /*Si el primer dato no es mayor que el último,
      se encuentra el valor medio sacando el promedio
      del último y primer elemento.*/
      int medio=(inicio+fin)/2;
      /*Si el valor buscado es igual al que está en la posición
      de medio en el arreglo, regresa el valor de medio.*/
      if(k==datos[medio]){
        indice=medio;
      }
      /*Si el valor buscado es menor al que está en la posición
      de medio en el arreglo, se recursa la función, haciendo el
      último valor como el medio -1,esto para solo trabajar
      en la primera mitad del anterior arreglo.*/
      else if(k<datos[medio]){
        indice=busquedaBinaria(inicio,medio-1,k);
      }
      /*Si el valor buscado es mayor al que está en la posición
      de medio en el arreglo, se recursa la función, haciendo el
      primer valor como el medio +1,esto para solo trabajar
      en la segunda mitad del anterior arreglo.*/
      else{
        indice=busquedaBinaria(medio+1,fin,k);
      }
    }
  }

  void selectionSort(){
    int paso, minimo,i,j;
    for(int i=0;i<=(t-2);i++){
      minimo=i;
      for(int j=i+1;j<=(t-1);j++){
        if(datos[j]<datos[minimo]){
          minimo=j;
        }
      }
      paso=datos[i];
      datos[i]=datos[minimo];
      datos[minimo]=paso;
    }
  }
  void bubbleSort(){
    int paso,i,j;
    for(int i=1;i<=(t-1);i++){
      for(int j=0;j<=(t-i-1);j++){
        if(datos[j]>datos[j+1]){
          paso=datos[j];
          datos[j]=datos[j+1];
          datos[j+1]=paso;
        }
      }
    }
  }
  void insertionSort(){
    int paso;
    for(int i=0;i<=(t-1);i++){
      for(int j=i;j>0;j--){
        if(datos[j]<datos[j-1]){
          paso=datos[j-1];
          datos[j-1]=datos[j];
          datos[j]=paso;
        }else
          break;
      }
    }
  }
/*Se declara la función de merge que recibe 3 parámetros, recibe
el elemento más chico, el más grande y el de en medio del arreglo.
Es la función que ayuda a la función de mergeSort().*/
  void merge(int lo,int mid,int hi){
    /*Se declaran las nuevas variables que fungen como apoyo en
    las siguientes operaciones. Se declara un nuevo arreglo en donde
    será copiado para los arreglos ordenados.*/
    int datos2[t];
    int a=lo;
    int b=(mid+1);
    int c=lo;
    /*Se copia el arreglo datos en uno auxiliar llamado datos2.*/
    for(int a=lo;a<=hi;a++){
      datos2[a]=datos[a];
    }
    /*Lo que hace este ciclo es verificar que dato es menor en
    las dos mitades del arreglo para ir ordenando en las dos partes.*/
    while(a<=mid && b<=hi){
      /*Si el número en datos2 en la posición a (que llega hasta la mitad)
      es menor que el número en datos2 en b(que va de la mitad al final)
      se agrega ese dato al arreglo principal datos el dato en la posición a*/
      if(datos2[a]<datos2[b]){
        datos[c]=datos2[a];
        a++;
        c++;
      }
      else{
        /*Si no pasa lo anterior, se agrega, el datos2 en b al arreglo principal*/
        datos[c]=datos2[b];
        c++;
        b++;
      }
    }
    while (a<=mid) {
      /*Si a sigue siendo menor que mid, se pasan los números restantes al
      arreglo original.*/
      datos[c]=datos2[a];
      a++;
      c++;
    }
    while (b <= hi){
      /*Si b sigue siendo menor que el mayor, se pasan los números restantes al
      arreglo original.*/
  		datos[c] = datos2[b];
  		b++;
  		c++;
    }
  }
/*Se declara la función mergeSort con dos parámetros, la función divide en
mitades los arreglos para acomodarlos por pasos.*/
  void mergeSort(int lo, int hi){
    /*Si lo es menor que hi, se llama recursivamente a la función de mergeSort
    para las dos mitades del arreglo. Y se hace merge de los diferentes
    arreglos.*/
    if(lo<hi){
      int mid=lo+(hi-lo)/2;
      mergeSort(lo,mid);
      mergeSort(mid+1,hi);
      merge(lo,mid,hi);
    }else{
      return;
    }
  }
/*Se declara la función partition con dos parámetros. La función verifica un
dato pivote que es el que se ordena.*/
  int particion(int lo,int hi){
    //Se declaran las variables que se utilizarán.
    int paso;
    int i=lo;
    int j=hi;
    int pivote=datos[lo];
//Mientras que i sea menor a j, se seguirá el siguiente proceso.
    while(i<j){
  /*Mientras que el pivote sea mayor a los datos en la posición i, se le
  aumenta a i.*/
      while(pivote>datos[i]){
        i++;
      }
  /*Mientras que el pivote sea menor a los datos en la posición j, se le
  decrementa a j.*/
      while(pivote<datos[j]){
        j--;
      }
  //Si i es menor a j, se intercambian los datos en la posición i y j.
      if(i<j){
          paso=datos[i];
          datos[i]=datos[j];
          datos[j]=paso;
      }
    }
  //El pivote ahora será el dato en j y se regresa esa posición j.
    pivote= datos[j];
    return j;
  }
  /*Se declara la función quickSort con dos parámetros, la función verificar
  dentro del mismo arreglo un pivote que se debe de ordenar por los siguientes
  pasos.*/
  void quickSort(int lo, int hi){
    if(lo<hi){
      //Se declara la partición del arreglo.
      int j= particion(lo,hi);
      //Se ordena la primera mitad del arreglo.
      quickSort(lo,j-1);
      //Se ordena la segunda mitad del arreglo.
      quickSort(j+1,hi);
    }else{
      //Si hi es mayor que lo, se termina la función.
      return;
    }
  }

int pares(int posicion){
  if(posicion==t){
    //std::cout << "entra"<< '\n';
    return 0;
  }
  else if ((datos[posicion]%2)==0){

      return 1+pares(posicion+1);
  }
  else{
    pares(posicion+1);
  }

}

int paresCola(int posicion, int acumulador){

  if(posicion==t){
    return acumulador;
  }else if(datos[posicion]%2==0){

      return paresCola(posicion+1,acumulador+1);
    }
    else{
      paresCola(posicion+1,acumulador);
    }

}

int busquedaSaltandoN(int n, int k){
  int respuesta, indice;

  for(indice=0;indice<t;indice+=n){
    if(k==datos[indice]){
      respuesta = indice;
      return respuesta;
    }
  }
  return -1;

}
int busquedaSecuencialEnRango(int inicio, int fin,int k){
  int respuesta, indice;

  for(inicio=0;inicio<fin;inicio++){
    if(k==datos[inicio]){
      respuesta = inicio;
      return respuesta;
    }
  }

  return -1;
}

  /*Se declara la función imprimeArreglo con ningún parámetro.
  Esta función imprime el Arreglo trabajado anteriormente.*/
  void imprimeArreglo(){
    std::cout << "Datos:[ ";
    /*Este ciclo imprime el dato que se encuentre en la posición
    i del arreglo.*/
    for (int i=0;i<t;i++){
      std::cout << datos[i]<<" ";
    }
    std::cout << "]";
  }
};




#endif
