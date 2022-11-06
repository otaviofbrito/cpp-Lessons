#include <iostream>

typedef struct no_
{
  int chave;
  int valor;
  no_ *prox;
} no;

no *head;

no *start_list()
{
  no *tmp = new (no);
  tmp->chave = 0;
  tmp->valor = 0;
  tmp->prox = NULL;

  return tmp;
}

void end_list()
{
  no *ant = head->prox;
  no *pont = ant->prox;
  while (pont != NULL)
  {
    delete (ant);
    ant = pont;
    pont = pont->prox;
  }
  delete (ant);
  delete (head);
}

void busca_enc(int key, no **ant, no **pont)
{
  *pont = NULL;
  *ant = head;
  no *ptr = head->prox;
  while (ptr != NULL)
  {
    if (ptr->chave < key)
    {
      *ant = ptr;
      ptr = ptr->prox;
    }
    else
    {
      if (ptr->chave == key)
      {
        *pont = ptr;
      }
      ptr = NULL;
    }
  }
}

int insere_enc(int key, int value)
{
  int retorno = -1;
  no *ant;
  no *pont;
  busca_enc(key, &ant, &pont);
  if (pont == NULL)
  {
    no *tmp = new (no);
    tmp->chave = key;
    tmp->valor = value;
    tmp->prox = ant->prox;
    ant->prox = tmp;
    retorno = 0;
  }

  return retorno;
}

no *remove_enc(int key)
{
  no *ant;
  no *pont;
  busca_enc(key, &ant, &pont);
  if (pont != NULL)
  {
    ant->prox = pont->prox;
    return pont;
  }
  return NULL;
}

void imprime()
{
  no *ptr = head->prox;
  while (ptr != NULL)
  {
    printf("chave %d\n", ptr->chave);
    printf("valor: %d\n", ptr->valor);
    ptr = ptr->prox;
  }
}

int main(int argc, char const *argv[])
{

  head = start_list();

  printf("VALOR = %d\n ", insere_enc(1, 5));
  imprime();
  printf("--------------");

  printf("VALOR = %d\n ", insere_enc(2, 10));
  imprime();
  printf("--------------");

  printf("VALOR = %d\n ", insere_enc(3, 5));
  imprime();
  printf("--------------");

  printf("VALOR = %d\n ", remove_enc(1));
  imprime();
  printf("--------------");

  printf("VALOR = %d\n ", insere_enc(4, 15));
  imprime();
  printf("--------------");

  printf("VALOR = %d\n ", insere_enc(5, 20));
  imprime();
  printf("--------------");

  printf("VALOR = %d\n ", remove_enc(2));
  imprime();
  printf("--------------");

  end_list();
  return 0;
}
