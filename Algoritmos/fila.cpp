#include <iostream>
#include <queue>

void fila(bool);


int main() {
  // Cria fila utilizando template queue do próprio C++
  std::queue<int> f;

  // Verifica se a fila está vazia
  fila(f.empty()); // empy() retorna true se a fila estiver vazia

  std::cout << "Adicionando elementos" << std::endl;
  // Incluir elementos a fila
  f.push(7);  // Adiciona valor 7 a fila
  f.push(3);  // Adiciona valor 3 a fila
  f.push(42); // Adiciona valor 42 a fila
  f.push(25); // Adiciona valor 25 a fila
  f.push(64); // Adiciona valor 64 a fila
  f.push(12); // Adiciona valor 12 a fila

  // Imprimir tamanho da fila
  std::cout << "Tamanho da fila:  " << f.size() << std::endl;

  // Remover elemento a frente da fila - esperado remoção do 7
  f.pop();

  // Imprime o elemento a frente da fila - esperado mostrar o valor 3
  std::cout << "Elemento a frente da fila depois de retirar um elemento:  " << f.front() << std::endl;

  fila(f.empty());

  // Limpando a fila
  while(f.empty()) {
    std::cout << "Removendo o valor: " << f.front() << " da fila" << std::endl;
    f.pop();
  }
  std::cout << "A lista esta limpa e nao possui mais elementos." << std::endl;

  return 0;
}

void fila(bool verificador)
{
  if (!verificador) {
    std::cout << "A fila nao esta vazia" << std::endl;
  } else {
    std::cout << "A fila esta vazia, adicione elementos atraves do metodo push" << std::endl;
  }
}