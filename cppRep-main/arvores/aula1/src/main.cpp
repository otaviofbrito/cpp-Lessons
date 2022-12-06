#include <iostream>

#include "../src/include/arvore.h"

using namespace std;

cab *cabecalho; // ponteiro pro cabeçalho da árvore

int main(int argc, char const *argv[])
{

  cabecalho = start_tree(); // inicializando o cabeçalho
  // cabeçalho->raiz ==  NULL se a árvore está vazia.
  // ou simplesmente raiz == null que eu acho mais fácil. 

  tNode *arv = cabecalho->raiz; 

  tNode *test = insert(arv, 10);
  cout << test->value << endl;
  test = insert(arv, 20);
  cout << test->value << endl;

  test = insert(arv, 30);
  cout << test->value << endl;

  return 0;
}
