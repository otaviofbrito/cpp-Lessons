#ifndef ARVOREBIN_H

#define ARVOREBIN_H

#include <string>
#include "lista.h"

typedef struct noArv_
{
  struct no_ *nodeList;
  
  struct noArv_ *no_esq;
  struct noArv_ *no_dir;
} noArv;



noArv *inicia_arvoreBin();

void encerra_arvoreBin(noArv *ptArvore);

noArv *insere_noBin(noArv *raiz, no_ *no_lista);

int alturaBin(noArv *raiz);

void pre_ordemBin(noArv *raiz);

noArv *arvBinNovoNo(no_ *no_lista);

noArv *removeArvBin(noArv *raiz, no_ *no_lista);

#endif /* AROVREBIN_H */
