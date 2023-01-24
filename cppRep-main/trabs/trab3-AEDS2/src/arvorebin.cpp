#include <iostream>
#include "../src/include/arvore.h"
#include "../src/include/lista.h"

using namespace std;




noArv *inicia_arvore()
{
  noArv *tmp = new (noArv);
  tmp->nodeList = NULL;
  tmp->no_esq = NULL;
  tmp->no_dir = NULL;
  return tmp;
}

void encerra_arvore(noArv *raiz)
{
  if (raiz != NULL)
  {
    encerra_arvore(raiz->no_esq);
    encerra_arvore(raiz->no_dir);
    delete (raiz);
    cout << "\n✓ - Arvore binaria removida com sucesso!" << endl;
  }
  return;
}

noArv *insere_no(noArv *raiz, no_ *no_lista)
{
  if (raiz == NULL)
  {
    raiz = new (noArv);
    raiz->nodeList = no_lista;
    raiz->no_esq = NULL;
    raiz->no_dir = NULL;
  }
  else if (no_lista->pt_dcar->placa < raiz->nodeList->pt_dcar->placa)
  {
    raiz->no_esq = insere_no(raiz->no_esq, no_lista);
  }
  else
  {
    raiz->no_dir = insere_no(raiz->no_dir, no_lista);
  }
  return raiz;
}

int altura(noArv *raiz)
{
  if (raiz == NULL)
  {
    return 0;
  }
  else
  {
    int esq = altura(raiz->no_esq);
    int dir = altura(raiz->no_dir);
    if (esq > dir)
    {
      return esq + 1;
    }
    else
    {
      return dir + 1;
    }
  }
}

void pre_ordem(noArv *raiz)
{
  if (raiz != NULL)
  {
    cout << raiz->nodeList->pt_dcar->placa << " ";
    pre_ordem(raiz->no_esq);
    pre_ordem(raiz->no_dir);
  }
}