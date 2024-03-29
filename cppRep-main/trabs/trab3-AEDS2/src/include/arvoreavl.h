
#ifndef ARVOREAVL_H

#define ARVOREAVL_H

#include <string>
#include "lista.h"

typedef struct noArvAvl_
{
  struct no_ *nodeList;
  struct noArvAvl_ *no_esq;
  struct noArvAvl_ *no_dir;
  int altura;
} noArvAvl;

noArvAvl *inicia_arvoreAvl();

void encerra_arvoreAvl(noArvAvl *raiz);

noArvAvl *arvAvlNovoNo(no_ *no_lista);

noArvAvl *insere_noAvl(noArvAvl *raiz, no_ *no_lista);

noArvAvl *deletar_noAvl(noArvAvl *raiz, no_ *no_lista);

int alturaAvl(noArvAvl *raiz);

void pre_ordemAvl(noArvAvl *raiz);

noArvAvl *no_maior_valor(noArvAvl *raiz);

int balanceamento(noArvAvl *raiz);

noArvAvl *rotacao_direita(noArvAvl *raiz);

noArvAvl *rotacao_esquerda(noArvAvl *raiz);

int maximo(int a, int b);

void relatorio_preOrdemAvl(noArvAvl *raiz);

#endif /* ARVOREAVL_H */
