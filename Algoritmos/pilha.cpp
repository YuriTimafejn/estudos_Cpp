#include <iostream>
#include <stack>

void pilha(bool);

int main() {
  // Cria pilha utilizando template stack do próprio C++
  std::stack<int> p;

  // Verifica se a pilha está vazia
  pilha(p.empty()); // empy() retorna true se a pilha estiver vazia

  std::cout << "Adicionando elementos" << std::endl;
  // Incluir elementos a pilha
  p.push(7);  // Adiciona valor 7 a pilha
  p.push(3);  // Adiciona valor 3 a pilha
  p.push(42); // Adiciona valor 42 a pilha
  p.push(25); // Adiciona valor 25 a pilha
  p.push(64); // Adiciona valor 64 a pilha
  p.push(12); // Adiciona valor 12 a pilha

  // Imprimir tamanho da pilha
  std::cout << "Tamanho da pilha:  " << p.size() << std::endl;

  // Remover elemento da pilha
  p.pop();

  // Mostrar elemento do topo da pilha
  std::cout << "Topo da pilha depois de retirar um elemento: " << p.top() << std::endl;

  pilha(p.empty());


  // Limpar a pilha (Apagar todos os elementos)
  std::cout << "Depois de limpar a pilha" << std::endl;
  while(!p.empty()) {
    p.pop();
  }
  std::cout << "Tamanho da pilha:  " << p.size() << std::endl;

  return 0;
}

void pilha(bool verificador)
{
  if (!verificador) {
    std::cout << "A pilha nao esta vazia" << std::endl;
  } else {
    std::cout << "A pilha esta vazia, adicione elementos atraves do metodo push" << std::endl;
  }
}