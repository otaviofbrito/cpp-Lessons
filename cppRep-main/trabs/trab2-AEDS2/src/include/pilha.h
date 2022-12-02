#ifndef PILHA_H
#define PILHA_H

#include "lista.h"

typedef tLista tPilha;

inline tPilha *inicia_pilha(){
  return inicia_lista();
}

inline tPilha *encerra_pilha(tPilha *p){
  return encerra_lista(p);
}

inline void pilha_push(tPilha *p, dcar *new_car){
  insere_inicio(p, new_car);
}


inline no *pilha_pop(tPilha *p){
  return remove_inicio(p);
}


#endif