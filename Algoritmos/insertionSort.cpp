#include <iostream>
#include "vetoresTestes.hpp"

void insertionSort(int*, int);

int main () {
  int vet[] = {7, 3, 4, 9, 1, 8, 2};
  int tam = sizeof(vet)/ sizeof(vet[0]);

  std::cout << "Array antes da ordenação" << std::endl;
  mostraVetor(vet, tam);
  insertionSort(vet, tam);
  std::cout << "Array depois da ordenação" << std::endl;
  mostraVetor(vet, tam);
}

void insertionSort(int* v, int tam)
{
  for(int i=1;i<tam;i++) { // Itera do 2° elemento do array até o ultimo
  int sup = v[i]; // A variável que serve para fazer as comparações
    int j = i - 1;  // Começa valendo 0 (primeiro elemento do array)

    while(j >= 0 && v[j] > sup) { // Enquanto o elemento na posição j for maior que o valor da variável suporte
      v[j+1] = v[j];  // O  próximo elemento recebe o valor do elemento na posição j
      j--;  // Volta comparando
    }

    v[j+1] = sup; // O próximo elemento recebe o valor da variável suportes
  }
}


