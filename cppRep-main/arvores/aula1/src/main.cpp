#include <iostream>

#include "../src/include/arvore.h"

using namespace std;

tNode *raiz;

int main(int argc, char const *argv[])
{

  raiz = start_tree();

  raiz = insert(raiz, 50);

  raiz = insert(raiz, 30);
  raiz = insert(raiz, 20);
  raiz = insert(raiz, 40);
  raiz = insert(raiz, 70);
  raiz = insert(raiz, 60);
  raiz = insert(raiz, 80);

  printInOrder(raiz);

  tNode *res = search(raiz, 40);
  cout << "\n BUSCA bfr: " << res->value << endl;

  raiz = removeNode(raiz, 40);

  res = search(raiz, 40);
  cout << "\n BUSCA after: " << endl;

  res = search(raiz, 60);
  cout << "\n BUSCA bfr: "<<  res->value << endl;

  raiz = removeNode(raiz, 60);

  res = search(raiz, 60);
  cout << "\n BUSCA after: " << endl;

  end_tree(raiz);

  return 0;
}
