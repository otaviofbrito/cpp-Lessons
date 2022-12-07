#include <iostream>

#include "../src/include/arvore.h"

tNode *start_tree()
{
  return NULL;
}

void end_tree(tNode *raiz)
{
  if (raiz == NULL)
  {
    return;
  }
  end_tree(raiz->left_node);
  end_tree(raiz->right_node);
  delete (raiz);
  std::cout << "\nA raiz foi desalocada" << std::endl;
}

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
  }
  else
  {
    raiz->right_node = insert(raiz->right_node, value);
  }
  return raiz;
}

void printInOrder(tNode *raiz)
{
  if (raiz == NULL)
  {
    return;
  }

  printInOrder(raiz->left_node);
  std::cout << raiz->value << " ";
  printInOrder(raiz->right_node);
}