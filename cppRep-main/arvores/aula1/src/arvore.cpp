#include <iostream>

#include "../src/include/arvore.h"

cab *start_tree()
{

  cab *tmp = new cab; 
  tmp->raiz = NULL; 

  return tmp;
}

/*tNode *end_tree(tNode *raiz)
{


}*/

tNode *insert(tNode *raiz, int value) // ai pra passar aq eh fácil só passar o cabeçalho->raiz q vo ta sempre passando a raiz 
{

  if (raiz == NULL)
  {
    tNode *new_node = new tNode;
    new_node->value = value;
    new_node->left_node = NULL;
    new_node->right_node = NULL;
    return new_node;
  }

  if (raiz->value > value)
  {
    raiz->left_node = insert(raiz->left_node, value);
  } else {
    raiz->right_node = insert(raiz->right_node, value);
  }
  std::cout << "test";
  return raiz;

}