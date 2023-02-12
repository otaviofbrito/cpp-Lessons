#include <iostream>
#include <iomanip> //imprime tabela
#include "../src/include/arvoreavl.h"
#include "../src/include/lista.h"

using namespace std;


/**
 * @brief Inicia a arvore AVL
 * 
 * @return noArvAvl* 
 */
noArvAvl *inicia_arvoreAvl()
{
  cout << "\n✓ - Arvore AVL iniciada com sucesso!" << endl;
  return NULL;
}

/**
 * @brief Encerra a arvore AVL
 * 
 * @param raiz 
 */
void encerra_arvoreAvl(noArvAvl *raiz)
{
  if (raiz != NULL)
  {
    encerra_arvoreAvl(raiz->no_esq);
    encerra_arvoreAvl(raiz->no_dir);
    delete (raiz);
  }
  return;
}


/**
 * @brief Cria um novo nó para a arvore AVL
 * 
 * @param no_lista 
 * @return noArvAvl* 
 */
noArvAvl *arvAvlNovoNo(no_ *no_lista)
{
  noArvAvl *raiz = new (noArvAvl);
  raiz->nodeList = no_lista;
  raiz->no_esq = NULL;
  raiz->no_dir = NULL;
  raiz->altura = 1;
  return raiz;
}

/**
 * @brief Calcula a altura da arvore AVL
 * 
 * @param no_avl 
 * @return int 
 */
int alturaAvl(noArvAvl *no_avl)
{
  if (no_avl == NULL)
  {
    return 0;
  }
  return no_avl->altura;
}

/**
 * @brief Calcula o maximo entre dois inteiros
 * 
 * @param a 
 * @param b 
 * @return int 
 */
int maximo(int a, int b)
{
  return (a > b) ? a : b;
}


/**
 * @brief Realiza a rotacao a direita
 * 
 * @param raiz_no 
 * @return noArvAvl* 
 */
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

/**
 * @brief Realiza a rotacao a esquerda
 * 
 * @param raiz_no 
 * @return noArvAvl* 
 */
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

/**
 * @brief Calcula o fator balanceamento da arvore AVL
 * 
 * @param no_avl 
 * @return int 
 */
int balanceamento(noArvAvl *no_avl)
{
  if (no_avl == NULL)
  {
    return 0;
  }
  return alturaAvl(no_avl->no_esq) - alturaAvl(no_avl->no_dir);
}

/**
 * @brief Insere um no na arvore AVL
 * 
 * @param raiz 
 * @param no_lista 
 * @return noArvAvl* 
 */
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

/**
 * @brief Encontra o no com o maior valor da arvore AVL
 * 
 * @param raiz 
 * @return noArvAvl* 
 */
noArvAvl *no_maior_valor(noArvAvl *raiz)
{
  noArvAvl *atual = raiz;
  while (atual->no_dir != NULL)
  {
    atual = atual->no_dir;
  }
  return atual;
}

/**
 * @brief Deleta um no da arvore AVL
 * 
 * @param raiz 
 * @param no_lista 
 * @return noArvAvl* 
 */
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
      noArvAvl *temp = no_maior_valor(raiz->no_esq);
      raiz->nodeList = temp->nodeList;
      raiz->no_esq = deletar_noAvl(raiz->no_esq, temp->nodeList);
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

/**
 * @brief Percorre a arvore AVL em pre-ordem
 * 
 * @param raiz 
 */
void pre_ordemAvl(noArvAvl *raiz)
{
  if (raiz != NULL)
  {
    cout << raiz->nodeList->pt_dcar->placa << " ";
    pre_ordemAvl(raiz->no_esq);
    pre_ordemAvl(raiz->no_dir);
  }
}

/**
 * @brief Imprime o relatorio da arvore AVL
 * 
 * @param raiz 
 */
void relatorio_preOrdemAvl(noArvAvl *raiz)
{
  if (raiz != NULL)
  {
    cout << left
         << setw(0) << raiz->nodeList->pt_dcar->placa << " - "
         << setw(20) << raiz->nodeList->pt_dcar->marca
         << setw(20) << raiz->nodeList->pt_dcar->modelo
         << setw(10) << raiz->nodeList->pt_dcar->ano
         << setw(20) << raiz->nodeList->pt_dcar->cambio
         << setw(15) << raiz->nodeList->pt_dcar->direcao
         << setw(10) << raiz->nodeList->pt_dcar->potencia
         << setw(10) << raiz->nodeList->pt_dcar->tipo
         << setw(10) << raiz->nodeList->pt_dcar->cor
         << setw(0) << "R$: "
         << setw(10) << raiz->nodeList->pt_dcar->valor;
    cout << "\n";
    relatorio_preOrdemAvl(raiz->no_esq);
    relatorio_preOrdemAvl(raiz->no_dir);
  }
}