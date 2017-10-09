#include "Arreglo.h"


int main() {

  Arreglo a;

  a.lecturaDatos("Numeros.txt");

  //a.busquedaSecuencial(3);
  //a.lecturaTeclado();
  //a.selectionSort();
  //a.bubbleSort();
  a.quickSort(0,10);
  a.imprimeArreglo();
  std::cout <<  '\n';
  //std::cout << a.busquedaSaltandoN(1,-4) << '\n';
  //std::cout <<a.paresCola(0,0) << '\n';

  return 0;
}
