#ifndef ARVORE_H
#define ARVORE_H


typedef struct tNode_{

  int value;
  struct tNode_ *left_node;
  struct tNode_ *right_node;

}tNode;


typedef struct cab_ { 
int tam; 
struct tNode_ *raiz; 
} cab; 



cab *start_tree();

tNode *insert(tNode *raiz , int value);








#endif