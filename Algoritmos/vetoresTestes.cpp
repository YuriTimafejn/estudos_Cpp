#include "vetoresTestes.hpp"
#include <iostream>

void mostraVetor(int* v, int tam)
{
  for(int i=0; i<tam; i++) {
    std::cout << "Elemento " << i << "\tValor: " << v[i] << std::endl;
  }
}
