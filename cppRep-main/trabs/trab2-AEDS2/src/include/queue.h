#ifndef QUEUE_H
#define QUEUE_H

#include "list.h"

typedef tLista tQueue;

inline tQueue *start_queue(){
  return start_list();
}

inline tQueue *end_queue(tQueue *p){
  return end_list(p);
}

inline void queue_push(tQueue *p, dcar *new_car){
  insere_fim(p, new_car);
}


inline no *queue_pop(tQueue *p){
  return remove_inicio(p);
}


#endif