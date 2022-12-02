#ifndef FILA_H
#define FILA_H

#include "lista.h"

typedef tLista tFila;

inline tFila *inicia_fila(){
  return inicia_lista();
}

inline tFila *encerra_fila(tFila *p){
  return encerra_lista(p);
}

inline void fila_push(tFila *p, dcar *new_car){
  insere_fim(p, new_car);
}


inline no *fila_pop(tFila *p){
  return remove_inicio(p);
}


#endif