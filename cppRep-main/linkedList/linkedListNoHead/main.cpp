#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>

typedef struct no_ no;
struct no_
{
  int valor;
  no *prox;
};

no *tlista;

int inserir(int value)
{
  if (tlista == NULL)
  {
    no *tmp = new no;
    tmp->valor = value;
    tmp->prox == NULL;
    tlista = tmp;
    return 1;
  }
  no *ant = tlista;
  no *prox = tlista->prox;
  while (prox != NULL && prox->valor < value)
  {
    ant = prox;
    prox = prox->prox;
  }
  if (prox != NULL && prox->valor == value)
  {
    return 0;
  }
  no *tmp = new no;
  tmp->valor = value;
  ant->prox = tmp;
  tmp->prox = prox;

  return 1;
}

no *remover(int value)
{
  if(tlista == NULL){
    return NULL;
  }
  no *ant = tlista;
  no *prox = tlista->prox;
  while (prox != NULL && prox->valor < value)
  {
    ant = prox;
    prox = prox->prox;
  }
  if (prox != NULL && prox->valor == value)
  {
    ant->prox = prox->prox;
    return prox;
  }
  return NULL;
}

/**
 *
 * @param tlista = endereco do no tlista.
 */
void escrever()
{
  printf("[");
  no *atual = tlista;

  while (atual != NULL)
  {
    printf("%d", atual->valor);
    if (atual->prox != NULL)
      printf(" -> ");

    atual = atual->prox;
  }
  printf("]\n\n");
}

/**
 *
 * @param tlista = endereco do no tlista.
 */
void desaloca_lista()
{
  while (tlista != NULL)
  {
    no *n = tlista;
    tlista = tlista->prox;
    delete (n);
  }
}

/**
 *
 * @return = ponteiro para o no tlista alocado.
 */


int main()
{
  tlista = NULL;
  no *n;

  int valor;
  int ans = 0;

  do
  {
    // Opcoes:
    // 0 -> inserir
    // 1 -> remover
    // 2 -> escrever
    // 3 -> sair
    scanf("%d", &ans);

    switch (ans)
    {
      // inserir
    case 0:
      scanf("%d", &valor);
      inserir(valor);

      break;
      // remover
    case 1:
      scanf("%d", &valor);
      n = remover(valor);
      if (n != NULL)
      {
        delete (n);
      }

      break;
      // escrever
    case 2:
      escrever();

      break;
      // sair
    case 3:
      desaloca_lista();

      break;
    default:

      break;
    }
  } while (ans != 3);

  return (0);
}