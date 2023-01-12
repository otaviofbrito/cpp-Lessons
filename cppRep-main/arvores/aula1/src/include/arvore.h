#ifndef ARVORE_H
#define ARVORE_H


typedef struct tNode_{

  int value;
  struct tNode_ *left_node;
  struct tNode_ *right_node;

}tNode;


tNode *start_tree();

void end_tree(tNode *raiz);

tNode *insert(tNode *raiz,  int value);

tNode *search(tNode *raiz, int value);

void printInOrder(tNode *raiz);

tNode *getNewNode(int value);

tNode *minValueNode(tNode *node);

tNode *removeNode(tNode *raiz, int value);




#endif