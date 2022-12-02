#include <cstdlib>

#include <iostream>

#include "../src/include/lista.h"

using namespace std;

tLista *inicia_lista()
{

  tLista *tmp = new (tLista);

  tmp->tam = 0;
  tmp->lista = NULL;

  cout << "-A lista foi iniciada." << endl;

  return tmp;
}

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

no *busca(tLista *ptlista, string placa)
{

  no *pont = NULL;
  no *ptr = ptlista->lista;

  while (ptr != NULL)
  {
    if (ptr->pt_dcar->placa == placa)
    {
      pont = ptr;
      return pont;
    }
    ptr = ptr->prox;
  }
  return pont;
}

void busca_ordenada(tLista *ordenado, string placa, no **ant, no **pont)
{
  *ant = ordenado->lista;    // precisam ser ponteiros.
  no *ptr = ordenado->lista; // primeiro elemento da lista.
  *pont = NULL;

  while (ptr != NULL)
  {
    if (ptr->pt_dcar->placa < placa)
    {
      *ant = ptr;
      ptr = ptr->prox;
    }
    else
    {
      if (ptr->pt_dcar->placa == placa)
      {
        *pont = ptr;
      }
      ptr = NULL; // sair da repetição
    }
  }
}

void insere_inicio(tLista *ptlista, dcar *new_car)
{
  no *novo_no = new (no);
  novo_no->pt_dcar = new_car;
  novo_no->prox = ptlista->lista;
  ptlista->lista = novo_no;
  ptlista->tam++;
}

void insere_fim(tLista *ptlista, dcar *new_car)
{

  no *ant; // lista aponta para o nó
  no *pont = ptlista->lista;

  if (pont == NULL)
  {
    no *novo_no = new no;
    novo_no->pt_dcar = new_car;
    novo_no->prox = ptlista->lista; // recebe o valor NULL, para manter esse null.
    ptlista->lista = novo_no;       // agora ptlista->lista aponta para o primeiro nó.
    ptlista->tam++;
  }
  else
  {
    while (pont != NULL)
    { // aponta para algum nó do tipo carros.
      ant = pont;
      pont = pont->prox;
    }
    no *novo_no = new no;
    novo_no->pt_dcar = new_car;
    novo_no->prox = ant->prox;
    ant->prox = novo_no;
    ptlista->tam++;
  }
}

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

no *remove_enc(tLista *ptlista, string placa)
{
  no *retorno = NULL;
  if (ptlista->lista != NULL)
  {
    no *ant = ptlista->lista;
    no *ptr = ptlista->lista;
    no *pt_car = busca(ptlista, placa);
    while (ptr != pt_car)
    {
      ant = ptr;
      ptr = ptr->prox;
    }
    if (ptr == ptlista->lista)
    {
      retorno = pt_car;
      ptlista->lista = ptr->prox;
      ptlista->tam--;
      return retorno;
    }
    retorno = pt_car;
    ant->prox = ptr->prox;
    ptlista->tam--;
    return retorno;
  }
  return retorno;
}

void imprime(tLista *ptlista)
{
  no *p = ptlista->lista;
  while (p != NULL)
  {
    cout << p->pt_dcar->placa << " \n";
    p = p->prox;
  }
  cout << "\n";
}

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
    if (pont->prox == NULL)
    {
      retorno = pont;
      ptlista->lista = NULL;
      ptlista->tam--;
      return retorno;
    }
    else
    {
      while (pont->prox != NULL)
      {
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
}
*/

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