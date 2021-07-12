#include <iostream>
#include <list>

int main() {
  // Cria lista utilizando template queue do próprio C++
  std::list<int> l;

  // Criar um iterator para poder caminhar pelos elementos da lista
  std::list<int>::iterator ite;

  // Incluir elementos na lista
  short int tam = 10;
  for(int i=0; i<tam; i++) {
    l.push_front(i);
  }

  // Coloca o iterator na marca de começo da lista
  ite = l.begin();
  advance(ite, 4); // avança o marcador do iterator para posição 4

  // Insere na posição do iterator um valor
  l.insert(ite, 42);

  // Mostrar tamanho da lista
  std::cout << "A lista tem " << l.size() << " elementos" << std::endl;

  // Mostrar o elemento que a frente da lista
  std::cout << "Primeiro: " << l.front() << std::endl;
  // Remover elemento a frente da lista
  short int aux = l.front();
  l.pop_front();

  // Mostrar o elemento que atras da lista
  std::cout << "Ultimo: " << l.back() << std::endl;
  // Inserir o elemento da variavel auxiliar no final
  l.push_back(aux);
  std::cout << "Novo primeiro: " << l.front() << std::endl;
  std::cout << "Novo ultimo: " << l.back() << std::endl;

  l.sort(); // Ordena a lista

  // Cria uma segunda lista
  std::list<int> l2;
  for(int i=10; i<(tam*17); i+=17) {
      l2.push_back(i);
  }

  // Mescla as duas listas e esvazia a lista 2
  l.merge(l2);
  

  l.reverse(); // Inverte a ordem
  // Mostrar tamanho da lista
  std::cout << "A lista agora tem " << l.size() << " elementos" << std::endl;
  std::cout << "A lista 2 agora tem " << l2.size() << " elementos" << std::endl;
  std::cout << "Novo primeiro: " << l.front() << std::endl;
  std::cout << "Novo ultimo: " << l.back() << std::endl;


  // Limpa a lista
  l.clear();

  return 0;
}