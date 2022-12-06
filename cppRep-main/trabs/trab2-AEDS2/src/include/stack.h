#ifndef STACK_H
#define STACK_H

#include "list.h"

typedef tLista tStack;

inline tStack *start_stack(){
  return start_list();
}

inline tStack *end_stack(tStack *p){
  return end_list(p);
}

inline void stack_push(tStack *p, dcar *new_car){
  insere_inicio(p, new_car);
}


inline no *stack_pop(tStack *p){
  return remove_inicio(p);
}


#endif