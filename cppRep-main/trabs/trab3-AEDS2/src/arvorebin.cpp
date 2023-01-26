#include <iostream>
#include "../src/include/arvorebin.h"
#include "../src/include/lista.h"

using namespace std;

noArv *inicia_arvoreBin()
{
  return NULL;
}

void encerra_arvoreBin(noArv *raiz)
{
  if (raiz != NULL)
  {
    encerra_arvoreBin(raiz->no_esq);
    encerra_arvoreBin(raiz->no_dir);
    delete (raiz);
    cout << "\n✓ - No da arvore binaria removido com sucesso!" << endl;
  }
  return;
}

noArv *arvBinNovoNo(no_ *no_lista)
{
  noArv *raiz = new (noArv);
  raiz->nodeList = no_lista;
  raiz->no_esq = NULL;
  raiz->no_dir = NULL;
  return raiz;
}

noArv *insere_noBin(noArv *raiz, no_ *no_lista)
{
  if (raiz == NULL)
  {
    return arvBinNovoNo(no_lista);
  }

  if (no_lista->pt_dcar->placa < raiz->nodeList->pt_dcar->placa)
  {
    raiz->no_esq = insere_noBin(raiz->no_esq, no_lista);
  }
  else
  {
    raiz->no_dir = insere_noBin(raiz->no_dir, no_lista);
  }
  return raiz;
}

int alturaBin(noArv *raiz)
{
  if (raiz == NULL)
  {
    return 0;
  }
  else
  {
    int esq = alturaBin(raiz->no_esq);
    int dir = alturaBin(raiz->no_dir);
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

void pre_ordemBin(noArv *raiz)
{
  if (raiz != NULL)
  {
    cout << raiz->nodeList->pt_dcar->placa << " ";
    pre_ordemBin(raiz->no_esq);
    pre_ordemBin(raiz->no_dir);
  }
}