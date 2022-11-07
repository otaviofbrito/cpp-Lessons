#include <iostream>

typedef struct no_
{
  int chave;
  int valor;

  no_ *prox;

} no;

no *top = NULL;

void end_list()
{
  while (top != NULL)
  {
    no *del = top;
    top = top->prox;
    delete (del);
  }
}

void insert(int key, int value)
{
  no *node = new (no);
  node->chave = key;
  node->valor = value;
  node->prox = top;
  top = node;
}

no *remove()
{
  no *retorno;
  if (top != NULL)
  {
    retorno = top;
    no *del = top;
    top = top->prox;
    delete (del);
    return retorno;
  }
  return NULL;
}

void imprime()
{
  no *ptr = top;
  while (ptr != NULL)
  {
    printf("chave %d\n", ptr->chave);
    printf("valor: %d\n", ptr->valor);
    ptr = ptr->prox;
  }
}

int main(int argc, char const *argv[])
{
  insert(1, 5);
  imprime();

  printf("\n=======\n");

  insert(2, 10);
  imprime();

  printf("\n=======\n");

  insert(3, 51);
  imprime();

  printf("\n=======\n");

  insert(4, 52);
  imprime();

  printf("\n=======\n");

  insert(5, 53);
  imprime();

  printf("\n=======\n");

  remove();
  remove();
  remove();
  remove();

  imprime();

  end_list();
  return 0;
}
