#include <iostream>
#include "vetoresTestes.hpp"

void bubbleSort(int*, int);
void troca(int*, int*);

int main () {
  int vet[] = {7, 3, 4, 9, 1, 8, 2};

  int tam = sizeof(vet)/sizeof(sizeof(vet[0]));
  std::cout << "Array antes da ordenação" << std::endl;
  mostraVetor(vet, tam);
  bubbleSort(vet, tam);
  std::cout << "Array depois da ordenação" << std::endl;
  mostraVetor(vet, tam);

  return 0;
}

void bubbleSort(int* v, int tam)
{
  for(int i=0; i<tam-1; i++) {  // Itera por todo array
    for(int j=0; j<tam-i-1; j++) {  // Como o final do array fica organizado depois da primeira passagem, limita o número de iterações cortando o final a cada passagem
      if (v[j] > v[j+1]) {
        troca(&v[j], &v[j+1]);
      }
    }
  }
}

void troca(int* a, int* b) // Troca o valor das variáveis
{
  int sup = *a;
  *a = *b;
  *b = sup;
}