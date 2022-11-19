#ifndef STACK_H
#define STACK_H

#include "lista.h"

typedef tLista tStack;

inline tStack *start_stack(){
  return inicia_lista();
}

inline tStack *end_stack(tStack *p){
  return encerra_lista(p);
}

inline void push(tStack *p, int valor){
  insere_inicio(p, valor);
}


inline no *pop(tStack *p){
  return remove_inicio(p);
}


#endif