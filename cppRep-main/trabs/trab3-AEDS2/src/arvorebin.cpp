#include <iostream>
#include <iomanip> //imprime tabela
#include "../src/include/arvorebin.h"
#include "../src/include/lista.h"

using namespace std;

/**
 * @brief Inicia a arvore binaria
 * 
 * @return noArv* 
 */
noArv *inicia_arvoreBin()
{
  cout << "\n✓ - Arvore binaria iniciada com sucesso!" << endl;
  return NULL;
}

/**
 * @brief Encerra a arvore binaria
 * 
 * @param raiz 
 */
void encerra_arvoreBin(noArv *raiz)
{
  if (raiz != NULL)
  {
    encerra_arvoreBin(raiz->no_esq);
    encerra_arvoreBin(raiz->no_dir);
    delete (raiz);
 
  }
  return;
}

/**
 * @brief Cria um novo nó para a arvore binaria
 * 
 * @param no_lista 
 * @return noArv* 
 */
noArv *arvBinNovoNo(no_ *no_lista)
{
  noArv *raiz = new (noArv);
  raiz->nodeList = no_lista;
  raiz->no_esq = NULL;
  raiz->no_dir = NULL;
  return raiz;
}

/**
 * @brief Insere um novo nó na arvore binaria
 * 
 * @param raiz 
 * @param no_lista 
 * @return noArv* 
 */
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

/**
 * @brief Calcula a altura da arvore binaria
 * 
 * @param raiz 
 * @return int 
 */
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

/**
 * @brief Encontra o maior valor da arvore /subarvore
 * 
 * @param raiz 
 * @return noArv* 
 */
noArv *valorMax(noArv *raiz)
{
  noArv *aux = raiz; // nó que eu irei encontrar o menor dos maiores
  while (aux && aux->no_dir != NULL)
  {
    aux = aux->no_dir;
  }
  return aux;
}

/**
 * @brief Remove um nó da arvore binaria
 * 
 * @param raiz 
 * @param no_lista 
 * @return noArv* 
 */
noArv *removeArvBin(noArv *raiz, no_ *no_lista)
{

  if (raiz == NULL)
  {
    return raiz;
  }

  if (no_lista->pt_dcar->placa < raiz->nodeList->pt_dcar->placa)
  {
    raiz->no_esq = removeArvBin(raiz->no_esq, no_lista);
  }
  else if (no_lista->pt_dcar->placa > raiz->nodeList->pt_dcar->placa)
  {
    raiz->no_dir = removeArvBin(raiz->no_dir, no_lista);
  }
  else
  {
    if (raiz->no_esq == NULL)
    {
      noArv *tmp = raiz->no_dir;
      delete (raiz);
      return tmp;
    }
    else if (raiz->no_dir == NULL)
    {
      noArv *tmp = raiz->no_esq;
      delete (raiz);
      return tmp;
    }

    noArv *min = valorMax(raiz->no_esq);
    raiz->nodeList = min->nodeList;
    raiz->no_esq = removeArvBin(raiz->no_esq, min->nodeList);
  }

  return raiz;
}

/**
 * @brief Imprime a arvore binaria em pre-ordem
 * 
 * @param raiz 
 */
void pre_ordemBin(noArv *raiz)
{
  if (raiz != NULL)
  {
    cout << raiz->nodeList->pt_dcar->placa << " ";
    pre_ordemBin(raiz->no_esq);
    pre_ordemBin(raiz->no_dir);
  }
}

/**
 * @brief Imprime o relatorio da arvore binaria em pre-ordem
 * 
 * @param raiz 
 */
void relatorio_preOrdemBin(noArv *raiz)
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
    relatorio_preOrdemBin(raiz->no_esq);
    relatorio_preOrdemBin(raiz->no_dir);
  }
}