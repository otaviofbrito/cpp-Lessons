#include <cstdlib>

#include <iostream>

#include "./include/list.h"

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

no *busca(tLista *ptlista, string plate)
{
  no *ant;
  no *pont = ptlista->lista;
  if( pont == NULL){
    return NULL;
  }
  while (pont != NULL) 
  {
    if(pont->cardt->plate != plate){
      ant = pont;
      pont = pont->prox;
    } else {
      return pont;
    }
  }
  cout << "PLACA NAO ENCONTRADA" << endl;
  return NULL;
}

/**

 * Realiza a insercao do elemento no início da lista ligada.

 * @param valor a ser inserido.

 */

void insere_inicio(tLista *ptlista, cars_ *cd)
{
  no *p = new no;
  p->cardt = cd;
  p->prox = ptlista->lista;
  ptlista->lista = p;
  ptlista->tam++;
}

/**

 * Realiza a insercao do elemento no fim da lista ligada.

 * @param valor a ser inserido.

 */

/*void insere_fim(tLista *ptlista, int valor)
{
  no *ant = ptlista->lista;
  no *pont = ptlista->lista;

  if(ant == NULL){
    no *p = new(no);
    p->valor = valor;
    p->prox = NULL;
    ptlista->lista = p; 
    ptlista->tam++;
  }

  while (ant != NULL)
  {
    pont = ant->prox;
    if (pont == NULL)
    {
      no *p = new (no);
      p->valor = valor;
      p->prox = NULL;
      ant->prox = p;
      ptlista->tam++;
    }
    ant = pont;
  }
}
*/
/**

 * Realiza a remocao do primeiro elemento da lista encadeada, se houver.

 * @return nulo em caso de lista vazia, senão retorna o nó removido.

 */

no *remove_inicio(tLista *ptlista)
{
  if (ptlista->lista == NULL)
  {
    return NULL;
  }
  else
  {
    no *p = ptlista->lista;
    ptlista->lista = p->prox;
    ptlista->tam--;
    return p;
  }
}

/**

 * Realiza a remocao do último elemento da lista encadeada, se houver.

 * @return nulo em caso de lista vazia, senão retorna o nó removido.

 */

/*no *remove_fim(tLista *ptlista)
{
  no *ant;
  no *pont = ptlista->lista;
  no *retorno;
  if (pont == NULL)
  {
    return NULL;
  }
  else
  {
    if(pont->prox == NULL){
      retorno = pont;
      ptlista->lista = NULL;
      ptlista->tam--;
      return retorno;
    } else {
      while(pont->prox != NULL){
        ant = pont;
        pont = pont->prox;
      }
      retorno = pont;
      ant->prox = NULL;
      ptlista->tam--;
      return retorno;
    }
  }
  return NULL;
}*/

/**

 * Imprime a lista encadeada.

 */

void imprime(tLista *ptlista)
{
  no *p = ptlista->lista;
  while (p != NULL)
  {
    cout << p->cardt->plate << " ";
    p = p->prox;
  }
  cout << "\n";
}

/*
while (ant != NULL)
    {
      pont = ant->prox;
      if (ant->prox == NULL)
      {
        retorno = ant;
        ptlista->lista = NULL;
        ptlista->tam--;
        return retorno;
      }
      else
      {

        if (pont->prox == NULL)
        {
          retorno = pont;
          ant->prox = NULL;
          ptlista->tam--;
          return retorno;
        }
        ant = pont;
      }
    }*/