#include <stdio.h>
#include <stdlib.h>

typedef struct noArv_
{

  int data;
  struct noArv_ *no_esq;
  struct noArv_ *no_dir;
} noArv;

noArv *insere_no(noArv *raiz, noArv *novo_no)
{

  if (raiz == NULL)
  {
    return novo_no;
  }

  if (raiz->data > novo_no->data)
  {
    raiz->no_esq = insere_no(raiz->no_esq, novo_no);
  }
  else if (raiz->data < novo_no->data)
  {
    raiz->no_dir = insere_no(raiz->no_dir, novo_no);
  }
  else
  {
    printf("\nNo existente!!!!!!\n");
    return raiz;
  }
  return raiz;
}

noArv *cria_no(int valor){
  noArv *temp = malloc(sizeof(noArv));
  temp->data = valor;
  temp->no_esq = NULL;
  temp->no_dir = NULL;
  return temp;
}


noArv *busca_no(noArv *raiz, int valor){
  if(raiz == NULL || raiz->data == valor){
    return raiz;
  }

  if(raiz->data > valor){
    return busca_no(raiz->no_esq, valor);
  } else {
    return busca_no(raiz->no_dir, valor);
  }
}

void em_ordem(noArv *raiz){
  if(raiz != NULL){
    em_ordem(raiz->no_esq);
    printf("%d ", raiz->data);
    em_ordem(raiz->no_dir);
  }
}


noArv *max_node(noArv * raiz){
  noArv *atual = raiz;
  while(atual && atual->no_dir != NULL){
    atual = atual->no_dir;
  }
  return atual;
}

noArv *remove_no(noArv *raiz, int valor){
  if(raiz == NULL){
    return raiz;
  }

  if(raiz->data > valor){
    raiz->no_esq = remove_no(raiz->no_esq, valor);
  }else if(raiz->data < valor){
    raiz->no_dir = remove_no(raiz->no_dir, valor);
  }else {
    if(raiz->no_esq == NULL){
      noArv *temp = raiz->no_dir;
      free(raiz);
      return temp;
    }else if(raiz->no_dir == NULL){
      noArv *temp = raiz->no_esq;
      free(raiz);
      return temp;
    }

    noArv *temp = max_node(raiz->no_esq);
    raiz->data = temp->data;
    raiz->no_esq = remove_no(raiz->no_esq, temp->data);
  }
  return raiz;
}


int main(int argc, char const *argv[])
{
  noArv *ArvoreBin = NULL;
  noArv *novo1;
  novo1 = cria_no(50);
  ArvoreBin = insere_no(ArvoreBin, novo1);
  novo1 = cria_no(10);
  ArvoreBin = insere_no(ArvoreBin, novo1);
  novo1 = cria_no(30);
  ArvoreBin = insere_no(ArvoreBin, novo1);
  novo1 = cria_no(40);
  ArvoreBin = insere_no(ArvoreBin, novo1);
  novo1 = cria_no(70);
  ArvoreBin = insere_no(ArvoreBin, novo1);
  ArvoreBin = insere_no(ArvoreBin, novo1);

  em_ordem(ArvoreBin);

  noArv *busca;
  busca = busca_no(ArvoreBin, 20);
  printf("\n%d\n", busca->data);


  ArvoreBin = remove_no(ArvoreBin, 50);

  busca = busca_no(ArvoreBin, 50);
  if (busca == NULL)
  {
    printf("\nno removido\n");
  };


  em_ordem(ArvoreBin);

  return 0;
}
