
#ifndef ARVORE_H

#define ARVORE_H

#include <string>
#include "lista.h"

typedef struct noArv_
{
  struct no_ *nodeList;
  
  struct noArv_ *no_esq;
  struct noArv_ *no_dir;
} noArv;



noArv *inicia_arvore();

void encerra_arvore(noArv *ptArvore);

noArv *insere_no(noArv *raiz, no_ *no_lista);

int altura(noArv *raiz);

void pre_ordem(noArv *raiz);

noArv *arvNovoNo(no_ *no_lista);

#endif /* AROVRE_H */
