#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>

typedef struct no_ no;
struct no_
{
  int valor;
  no *prox;
  no *ant;
};

int inserir(no *cabeca, int value)
{
  no *ptr = cabeca;
  while (ptr->prox != NULL && ptr->prox->valor < value)
  {
    ptr = ptr->prox;
  }
  if (ptr->prox != NULL && ptr->prox->valor == value)
  {
    return 0;
  }
  if (ptr->prox == NULL)
  {
    no *tmp = new no;
    tmp->valor = value;
    tmp->prox = NULL;
    tmp->ant = ptr;
    ptr->prox = tmp;
    return 1;
  }
  no *tmp = new no;
  tmp->valor = value;
  tmp->prox = ptr->prox;
  tmp->ant = ptr;
  ptr->prox->ant = tmp;
  ptr->prox = tmp;
  return 1;
}

no *remover(no *cabeca, int value)
{
  no *ptr = cabeca->prox;
  no *retorno;
  while (ptr != NULL && ptr->valor < value)
  {
    ptr = ptr->prox;
  }
  if (ptr != NULL && ptr->valor == value)
  {
    if (ptr->prox == NULL)
    {
      retorno = ptr;
      ptr->ant->prox = NULL;
      return retorno;
    }
    retorno = ptr;
    ptr->ant->prox = ptr->prox;
    ptr->prox->ant = ptr->ant;
    return retorno;
  }
  return NULL;
}

/**
 *
 * @param cabeca = endereco do no cabeca.
 */
void escrever(no *cabeca)
{
  printf("[");
  no *atual = cabeca->prox;

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
 * @param cabeca = endereco do no cabeca.
 */
void desaloca_lista(no *cabeca)
{
  while (cabeca != NULL)
  {
    no *n = cabeca;
    cabeca = cabeca->prox;
    delete (n);
  }
}

/**
 *
 * @return = ponteiro para o no cabeca alocado.
 */
no *aloca_no_cabeca()
{
  no *cabeca = new no;
  cabeca->prox = NULL;
  cabeca->ant = NULL;
  return cabeca;
}

int main()
{
  no *cabeca = aloca_no_cabeca();
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
      inserir(cabeca, valor);

      break;
      // remover
    case 1:
      scanf("%d", &valor);
      n = remover(cabeca, valor);
      if (n != NULL)
      {
        delete (n);
      }

      break;
      // escrever
    case 2:
      escrever(cabeca);

      break;
      // sair
    case 3:
      desaloca_lista(cabeca);

      break;
    default:

      break;
    }
  } while (ans != 3);

  return (0);
}