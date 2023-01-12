#include <iostream>

#include "../src/include/arvore.h"

tNode *start_tree()
{
  return NULL;
}

void end_tree(tNode *raiz) // percorrer em pos-ordem
{
  if (raiz == NULL)
  {
    return;
  }
  end_tree(raiz->left_node);
  end_tree(raiz->right_node);
  delete (raiz);
  std::cout << "\nO no foi desalocado" << std::endl;
}

tNode *getNewNode(int value)
{
  tNode *new_node = new tNode;
  new_node->value = value;
  new_node->left_node = NULL;
  new_node->right_node = NULL;
  return new_node;
}

tNode *insert(tNode *raiz, int value)
{

  if (raiz == NULL)
  {
    return getNewNode(value);
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

tNode *search(tNode *raiz, int value)
{
  if (raiz == NULL || raiz->value == value)
  {
    return raiz;
  }
  if (raiz->value > value)
  {
    return search(raiz->left_node, value);
  }
  else
  {
    return search(raiz->right_node, value);
  }
}

tNode *minValueNode(tNode *node)
{
  tNode *current = node;
  while (current && current->left_node != NULL)
  {
    current = current->left_node;
  }
  return current;
}

tNode *removeNode(tNode *raiz, int value)
{
  if (raiz == NULL)
  {
    return raiz;
  }
  if (value < raiz->value)
  {
    raiz->left_node = removeNode(raiz->left_node, value);
  }
  else if (value > raiz->value)
  {
    raiz->right_node = removeNode(raiz->right_node, value);
  }
  else
  {
    if (raiz->left_node == NULL)
    {
      tNode *temp = raiz->right_node;
      delete (raiz);
      return temp;
    }
    else if (raiz->right_node == NULL)
    {
      tNode *temp = raiz->left_node;
      delete (raiz);
      return temp;
    }
    tNode *temp = minValueNode(raiz->right_node);
    raiz->value = temp->value;
    raiz->right_node = removeNode(raiz->right_node, temp->value);
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