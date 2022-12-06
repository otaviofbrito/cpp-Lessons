#include <cstdlib>
#include <iomanip> //tabela imprime
#include <iostream>

#include "../src/include/list.h"

using namespace std;

/**
 * @brief Inicializa uma lista com a criação de um cabeçalho.
 *
 * @return tLista* retorna o endereço desse cabeçalho criado
 */
tLista *start_list()
{

  tLista *tmp = new (tLista);

  tmp->tam = 0;
  tmp->lista = NULL;

  cout << "\n✓ - Struct started successfully!" << endl;

  return tmp;
}

/**
 * @brief Desaloca toda uma lista.
 *
 * @param ptlista endereco do cabeçalho.
 * @return tLista* retornal ponteiro do no cabeca;
 */
tLista *end_list(tLista *ptlista)
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

  cout << "\n✓ - Struct removed successfully!" << endl;

  return NULL;
}

/**
 * @brief Realiza uma busca pela placa fornecida como parâmetro.
 *
 * @param ptlista endereco do cabeçalho.
 * @param placa placa a ser encontrada na lista.
 * @return no* retorna o endereço do elemento encontrado.
 */
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

/**
 * @brief Realiza uma busca de acordo placa fornecida da função insere_ordenado, levando em consideração uma lista ordenada, dessa forma fornece a posição a qual devo reorganizar os elementos de forma ordenada.

 *
 * @param ordenado endereco do cabeçalho.
 * @param placa placa a ser inserida na lista.
 * @param ant endereço de uma variável ponteiro. Fornece a posição adequada.
 * @param pont endereço de uma variável ponteiro. Sinaliza se o elemento já existe ou não.
 */
void search_sorted(tLista *ordenado, string placa, no **ant, no **pont)
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

/**
 * @brief Insere no inicio de uma lista.
 *
 * @param ptlista endereco do cabeçalho.
 * @param new_car endereço de uma struct dcar.
 */
void insere_inicio(tLista *ptlista, dcar *new_car)
{
  no *novo_no = new (no);
  novo_no->pt_dcar = new_car;
  novo_no->prox = ptlista->lista;
  ptlista->lista = novo_no;
  ptlista->tam++;
}

/**
 * @brief Percorre toda a lista para inserir no fim dessa.
 *
 * @param ptlista endereco do cabeçalho.
 * @param new_car endereço de uma struct dcar.
 */
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

/**
 * @brief Remove o primeiro elemento de uma lista.
 *
 * @param ptlista endereco do cabeçalho.
 * @return no* retorna o endereço do elemento removido.
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
 * @brief Remove um elemento específico, com auxílio da função de busca.
 *
 * @param ptlista endereco do cabeçalho.
 * @param placa placa do veículo a ser removido.
 * @return no* retorna o endereço do elemento removido.
 */
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

/**
 * @brief Imprime toda uma lista a partir do seu cabeçalho.
 *
 * @param ptlista endereco do cabeçalho.
 */
void imprime(tLista *ptlista)
{
  no *p = ptlista->lista;
  int i = 1;
  cout << "\n ----------------------------->RESULTS-->\n"
       << endl;
  while (p != NULL)
  {

    cout << left
         << setw(0) << i << " - "
         << setw(10) << p->pt_dcar->placa << " - "
         << setw(20) << p->pt_dcar->marca
         << setw(20) << p->pt_dcar->modelo
         << setw(10) << p->pt_dcar->ano
         << setw(20) << p->pt_dcar->cambio
         << setw(15) << p->pt_dcar->direcao
         << setw(10) << p->pt_dcar->potencia
         << setw(10) << p->pt_dcar->tipo
         << setw(10) << p->pt_dcar->cor
         << setw(0) << "R$: "
         << setw(10) << p->pt_dcar->valor;
    p = p->prox;
    i++;

    cout << "\n";
  }
  cout << "\n <--END<-----------------------------\n"
       << endl;
}