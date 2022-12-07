#include <iostream>

#include "../src/include/arvore.h"

using namespace std;

tNode *raiz; // ponteiro pro cabeçalho da árvore

int main(int argc, char const *argv[])
{

  raiz = start_tree(); // inicializando o cabeçalho
  // cabeçalho->raiz ==  NULL se a árvore está vazia.
  // ou simplesmente raiz == null que eu acho mais fácil.

  raiz = insert(raiz, 10);

  raiz = insert(raiz, 30);

  raiz = insert(raiz, 20);

  printInOrder(raiz);

  end_tree(raiz);
  

  return 0;
}
