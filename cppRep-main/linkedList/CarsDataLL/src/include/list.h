#include <string>

#ifndef LISTA_H

#define LISTA_H


typedef struct no_
{

  struct cars_ *cardt; //'carga útil' do nó

  // num cenario real, poderia ser: nome, endereco...

  struct no_ *prox; // ponteiro para o próximo nó da lista encadeada

} no;

typedef struct
{

  int tam; // critério de busca da ordenação

  struct no_ *lista; // ponteiro para o próximo nó da lista encadeada

} tLista;

typedef struct cars_
{
  std::string model;
  std::string brand;
  std::string type;
  std::string year;
  std::string km;
  std::string engine;
  std::string gas;
  std::string gear;
  std::string steering;
  std::string color;
  std::string doors;
  std::string plate;
  double price;
} cd;

tLista *inicia_lista();

tLista *encerra_lista(tLista *ptlista);

no *busca(tLista *ptlista, std::string plate);

void imprime(tLista *ptlista);

void insere_inicio(tLista *ptlista, cars_ *cdata);

no *remove_inicio(tLista *ptlista);

void insere_fim(tLista *ptlista, no *cdata);

no *remove_fim(tLista *ptlista);

#endif /* LISTA_H */