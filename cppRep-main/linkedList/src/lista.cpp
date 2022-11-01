#include <cstdlib>

#include <iostream>

#include "../src/include/lista.h"

using namespace std;

/**

 * Realiza a alocacao do espaco para que a lista possa comecar

 * a receber nos.

 * @return a lista vazia.

 */

tLista *inicia_lista()
{

  tLista *tmp = new (tLista);

  tmp->tam = 0;

  tmp->lista = NULL;

  cout << "-A lista foi iniciada." << endl;

  return tmp;
}

/**

 * Desaloca o espaco previamente alocado para a lista encadeada.

 * @param ptlista ponteiro para a lista.

 * @return NULL para atualizar o ponteiro da lista.

 */

tLista *encerra_lista(tLista *ptlista)
{

  no *ant = ptlista->lista;

  no *pont = ptlista->lista;

  while (ant != NULL)
  {

    pont = ant->prox;

    delete (ant);

    ant = pont;
  }

  delete (ptlista);

  cout << "-A lista foi removida." << endl;

  return NULL;
}

/**

 * Busca pelo valor de chave passado dentro da lista encadeada.

 * @param chave a ser buscada.

 * @param ant ponteiro anterior a posicao encontrada.

 * @return verdareiro se o elemento foi encontrado.

 */

no *busca(tLista *ptlista, int valor)
{
  for (int i = 0; i < ptlista->tam; i++)
  {
    if (ptlista->lista->valor == valor)
    {
      return ptlista->lista;
    }
  }
  return NULL;
}

/**

 * Realiza a insercao do elemento no início da lista ligada.

 * @param valor a ser inserido.

 */

void insere_inicio(tLista *ptlista, int valor)
{
  no *p = new (no);
  p->valor = valor;
  p->prox = ptlista->lista;
  ptlista->lista = p;
  ptlista->tam++;
}

/**

 * Realiza a insercao do elemento no fim da lista ligada.

 * @param valor a ser inserido.

 */

void insere_fim(tLista *ptlista, int valor)
{
  if (ptlista->lista == NULL)
  {
    insere_inicio(ptlista, valor)
  }
  else
  {

    no *p = new (no);
    p->valor = valor;
    p->prox = NULL;
    ptlista->lista = p;
    ptlista->tam++;
  }
}

/**

 * Realiza a remocao do primeiro elemento da lista encadeada, se houver.

 * @return nulo em caso de lista vazia, senão retorna o nó removido.

 */

no *remove_inicio(tLista *ptlista)
{

  no *ant = ptlista->lista;

  no *pont = ptlista->lista;

  while (ant != NULL)
  {

    pont = ant->prox;

    ant = pont;
  }

  busca(ptlista, );
}

/**

 * Realiza a remocao do último elemento da lista encadeada, se houver.

 * @return nulo em caso de lista vazia, senão retorna o nó removido.

 */

no *remove_fim(tLista *ptlista)
{
}

/**

 * Imprime a lista encadeada.

 */

void imprime(tLista *ptlista)
{
}
