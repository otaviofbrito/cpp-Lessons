#include <string>
#ifndef LIST_H

#define LIST_H

typedef struct no_
{
  struct no_ *prox;
  struct dcar_ *pt_dcar;

} no;

typedef struct
{
  int tam;
  struct no_ *lista;

} tLista;

typedef struct dcar_
{
  std::string modelo;
  std::string marca;
  std::string tipo;
  std::string ano;
  std::string km;
  std::string potencia;
  std::string combustivel;
  std::string cambio;
  std::string direcao;
  std::string cor;
  std::string portas;
  std::string placa;
  double valor;

} dcar;

tLista *start_list();

tLista *end_list(tLista *ptlista);

no *busca(tLista *ptlista, std::string placa);

void search_sorted(tLista *ptlista, std::string placa, no **ant, no **pont);

void imprime(tLista *ptlista);

void insere_inicio(tLista *ptlista, dcar *new_car);

no *remove_inicio(tLista *ptlista);

void insere_fim(tLista *ptlista, dcar *new_car);

no *remove_fim(tLista *ptlista);

no *remove_enc(tLista *ptlista, std::string placa);

#endif /* LIST_H */