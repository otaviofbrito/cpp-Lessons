#include <iostream>
#include "../src/include/arvoreavl.h"
#include "../src/include/lista.h"

using namespace std;

noArvAvl *inicia_arvoreAvl()
{
  return NULL;
}

void encerra_arvoreAvl(noArvAvl *raiz)
{
  if (raiz != NULL)
  {
    encerra_arvoreAvl(raiz->no_esq);
    encerra_arvoreAvl(raiz->no_dir);
    delete (raiz);
    cout << "\n✓ - No da arvore Avl removido com sucesso!" << endl;
  }
  return;
}

noArvAvl *arvAvlNovoNo(no_ *no_lista)
{
  noArvAvl *raiz = new (noArvAvl);
  raiz->nodeList = no_lista;
  raiz->no_esq = NULL;
  raiz->no_dir = NULL;
  raiz->altura = 1;
  return raiz;
}

int alturaAvl(noArvAvl *no_avl)
{
  if (no_avl == NULL)
  {
    return 0;
  }
  return no_avl->altura;
}

int maximo(int a, int b)
{
  return (a > b) ? a : b;
}

noArvAvl *rotacao_direita(noArvAvl *raiz_no)
{
  noArvAvl *nova_raiz = raiz_no->no_esq;
  noArvAvl *sub_arvore2 = nova_raiz->no_dir;

  nova_raiz->no_dir = raiz_no;
  raiz_no->no_esq = sub_arvore2;

  raiz_no->altura = maximo(alturaAvl(raiz_no->no_esq), alturaAvl(raiz_no->no_dir)) + 1;
  nova_raiz->altura = maximo(alturaAvl(nova_raiz->no_esq), alturaAvl(nova_raiz->no_dir)) + 1;

  return nova_raiz;
}

noArvAvl *rotacao_esquerda(noArvAvl *raiz_no)
{
  noArvAvl *nova_raiz = raiz_no->no_dir;
  noArvAvl *sub_arvore2 = nova_raiz->no_esq;
  // rotacao
  nova_raiz->no_esq = raiz_no;
  raiz_no->no_dir = sub_arvore2;
  // atualizar alturas
  raiz_no->altura = maximo(alturaAvl(raiz_no->no_esq), alturaAvl(raiz_no->no_dir)) + 1;
  nova_raiz->altura = maximo(alturaAvl(nova_raiz->no_esq), alturaAvl(nova_raiz->no_dir)) + 1;

  return nova_raiz;
}

int balanceamento(noArvAvl *no_avl)
{
  if (no_avl == NULL)
  {
    return 0;
  }
  return alturaAvl(no_avl->no_esq) - alturaAvl(no_avl->no_dir);
}

noArvAvl *insere_noAvl(noArvAvl *raiz, no_ *no_lista)
{
  if (raiz == NULL)
  {
    return arvAvlNovoNo(no_lista);
  }

  if (no_lista->pt_dcar->placa < raiz->nodeList->pt_dcar->placa)
  {
    raiz->no_esq = insere_noAvl(raiz->no_esq, no_lista);
  }
  else if (no_lista->pt_dcar->placa > raiz->nodeList->pt_dcar->placa)
  {
    raiz->no_dir = insere_noAvl(raiz->no_dir, no_lista);
  }
  else
  {
    return raiz;
  }

  // atualizar altura do no pai;
  raiz->altura = 1 + maximo(alturaAvl(raiz->no_esq), alturaAvl(raiz->no_dir));

  int bal = balanceamento(raiz);

  if (bal > 1 && no_lista->pt_dcar->placa < raiz->no_esq->nodeList->pt_dcar->placa)
  {
    return rotacao_direita(raiz);
  }

  if (bal < -1 && no_lista->pt_dcar->placa > raiz->no_dir->nodeList->pt_dcar->placa)
  {
    return rotacao_esquerda(raiz);
  }

  if (bal > 1 && no_lista->pt_dcar->placa > raiz->no_esq->nodeList->pt_dcar->placa)
  {
    raiz->no_esq = rotacao_esquerda(raiz->no_esq);
    return rotacao_direita(raiz);
  }

  if (bal < -1 && no_lista->pt_dcar->placa < raiz->no_dir->nodeList->pt_dcar->placa)
  {
    raiz->no_dir = rotacao_direita(raiz->no_dir);
    return rotacao_esquerda(raiz);
  }

  return raiz;
}

noArvAvl *no_menor_valor(noArvAvl *raiz)
{
  noArvAvl *atual = raiz;
  while (atual->no_esq != NULL)
  {
    atual = atual->no_esq;
  }
  return atual;
}

noArvAvl *deletar_noAvl(noArvAvl *raiz, no *no_lista)
{
  if (raiz == NULL)
  {
    return raiz;
  }

  if (no_lista->pt_dcar->placa < raiz->nodeList->pt_dcar->placa)
  {
    raiz->no_esq = deletar_noAvl(raiz->no_esq, no_lista);
  }
  else if (no_lista->pt_dcar->placa > raiz->nodeList->pt_dcar->placa)
  {
    raiz->no_dir = deletar_noAvl(raiz->no_dir, no_lista);
  }
  else
  {
    if ((raiz->no_esq == NULL) || (raiz->no_dir == NULL))
    {
      noArvAvl *temp = raiz->no_esq ? raiz->no_esq : raiz->no_dir;
      if (temp == NULL)
      {
        temp = raiz;
        raiz = NULL;
      }
      else
      {
        *raiz = *temp;
      }
      delete (temp);
    }
    else
    {
      noArvAvl *temp = no_menor_valor(raiz->no_dir);
      raiz->nodeList = temp->nodeList;
      raiz->no_dir = deletar_noAvl(raiz->no_dir, temp->nodeList);
    }
  }

  if (raiz == NULL)
  {
    return raiz;
  }

  raiz->altura = 1 + maximo(alturaAvl(raiz->no_esq), alturaAvl(raiz->no_dir));

  int bal = balanceamento(raiz);

  if (bal > 1 && balanceamento(raiz->no_esq) >= 0)
  {
    return rotacao_direita(raiz);
  }

  if (bal > 1 && balanceamento(raiz->no_esq) < 0)
  {
    raiz->no_esq = rotacao_esquerda(raiz->no_esq);
    return rotacao_direita(raiz);
  }

  if (bal < -1 && balanceamento(raiz->no_dir) <= 0)
  {
    return rotacao_esquerda(raiz);
  }

  if (bal < -1 && balanceamento(raiz->no_dir) > 0)
  {
    raiz->no_dir = rotacao_direita(raiz->no_dir);
    return rotacao_esquerda(raiz);
  }
  return raiz;
}

void pre_ordemAvl(noArvAvl *raiz)
{
  if (raiz != NULL)
  {
    cout << raiz->nodeList->pt_dcar->placa << " ";
    pre_ordemAvl(raiz->no_esq);
    pre_ordemAvl(raiz->no_dir);
  }
}