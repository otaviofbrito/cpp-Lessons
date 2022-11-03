
#ifndef LISTA_H

#define LISTA_H

typedef struct no_
{

  int valor; //'carga útil' do nó

  // num cenario real, poderia ser: nome, endereco...

  struct no_ *prox; // ponteiro para o próximo nó da lista encadeada

} no;

typedef struct
{

  int tam; // critério de busca da ordenação

  struct no_ *lista; // ponteiro para o próximo nó da lista encadeada

} tLista;

tLista *inicia_lista();

tLista *encerra_lista(tLista *ptlista);

no *busca(tLista *ptlista, int valor);

void imprime(tLista *ptlista);

void insere_inicio(tLista *ptlista, int valor);

no *remove_inicio(tLista *ptlista);

void insere_fim(tLista *ptlista, int valor);

no *remove_fim(tLista *ptlista);

#endif /* LISTA_H */