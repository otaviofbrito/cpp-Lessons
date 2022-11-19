#ifndef QUEUE_H
#define QUEUE_H

#include "lista.h"

typedef tLista tQueue;

inline tQueue *start_queue(){
  return inicia_lista();
}

inline tQueue *end_queue(tQueue *p){
  return encerra_lista(p);
}

inline void push(tQueue *p, int valor){
  insere_inicio(p, valor);
}


inline no *pop(tQueue *p){
  return remove_fim(p);
}


#endif