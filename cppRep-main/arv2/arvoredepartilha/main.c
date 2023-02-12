#include <stdio.h>
#include <stdlib.h>


//copilot help me with the structs
typedef struct noArv_
{
  struct noArv_ *esq;
  struct noArv_ *dir;
  int real;
  int partilha;
} noArv;



typedef struct arr_
{
  int tam;
  int *arr;
} arr;


noArv *busca_no(int chave, noArv *raiz)
{
  if (raiz == NULL)
  {
    return NULL;
  }
  else if (chave == raiz->real)
  {
    return raiz;
  }
  else
  {
    if (chave <= raiz->partilha)
    {
      busca_no(chave, raiz->esq);
    }
    else
    {
      busca_no(chave, raiz->dir);
    }
  }
}

void cria_arvore(int chaves[], int frequencias[])
{
  if (chaves->tam > 0)
    {
      raiz->real = maior_frequencia(chaves);
      remove_chave_frequencia(chaves, frequencias);
      raiz->partilha = valor_mediano(chaves);
      cria_arvore(primeira_metade(chaves), primeira_metade(frequencias));
      cria_arvore(segunda_metade(chaves), segunda_metade(frequencias));
    }
}

int main(int argc, char const *argv[])
{
  /* code */
  return 0;
}
