#include <iostream>
#include <stdlib.h>
#include <math.h>

using namespace std;

typedef struct no_
{
  int valor;
  int chave;

} no;

no list[5];
int tam = 5;
int qtd = 0;

int busca(int key)
{
  int retorno = -1;
  for (int i = 0; i < qtd; i++)
  {
    if (list[i].chave == key)
    {
      retorno = i;
      i = qtd + 1;
    }
  }
  return retorno;
}

int busca2(int key)
{
  int retorno = -3;
  list[qtd + 1].chave = key;
  int i = 0;
  while (list[i].chave != key)
  {
    i++;
  }
  if (i != qtd + 1)
  {
    retorno = i;
  }
  else
  {
    retorno = -1;
  }
  return retorno;
}

int busca_ord(int key)
{
  int retorno = -3;
  list[qtd + 1].chave = key;
  int i = 0;
  while (list[i].chave < key)
  {
    i++;
  }
  if (i = qtd + 1 || list[i].chave != key)
  {
    retorno = -1;
  }
  else
  {
    retorno = i;
  }
  return retorno;
}

int busca_bin(int key)
{
  int inf = 0;
  int sup = qtd;
  int retorno = -1;
  while (inf <= sup)
  {
    int meio = floor(inf + sup / 2);
    if (list[meio].chave == key)
    {
      retorno = meio;
      inf = sup + 1;
    }
    else if (list[meio].chave < key)
    {
      inf = meio + 1;
    }
    else
    {
      sup = meio - 1;
    }
  }
  return retorno;
}

int insere(no novo_el)
{
int retorno = -3;
  if (qtd < tam)
  {
    if (busca2(novo_el.chave) == -1)
    {
      list[qtd] = novo_el;
      qtd++;
      retorno = qtd;
    }
    else
    {
      retorno = -1;
    }
  }
  else
  {
    retorno = -2;
  }
  return retorno;
}

no remove(int key)
{
  no retorno;
  if (qtd != 0)
  {
    int index = busca2(key);
    if (index != -1)
    {
      retorno = list[index];
      for (int i = index; i < qtd; i++)
      {
        list[i] = list[i + 1];
      }
      qtd--;
    }
  }
  return retorno;
}

int main(int argc, char const *argv[])
{

  no novo;
  int result;
  cout << "INSERE 1: ";
  cin >> novo.chave;
  cin >> novo.valor;
  result = insere(novo);
  cout << "\n"
       << result;

  cout << "INSERE 2: ";
  cin >> novo.chave;
  cin >> novo.valor;
  result = insere(novo);
  cout << "\n"
       << result;

  cout << "INSERE 3: ";
  cin >> novo.chave;
  cin >> novo.valor;
  result = insere(novo);
  cout << "\n"
       << result;

  cout << "INSERE 4: ";
  cin >> novo.chave;
  cin >> novo.valor;
  result = insere(novo);
  cout << "\n"
       << result;

  cout << "INSERE 5: ";
  cin >> novo.chave;
  cin >> novo.valor;
  result = insere(novo);
  cout << "\n"
       << result;

  cout << "INSERE 6: ";
  cin >> novo.chave;
  cin >> novo.valor;
  result = insere(novo);
  cout << "\n"
       << result;

  cout << "INSERE 7: ";
  cin >> novo.chave;
  cin >> novo.valor;
  result = insere(novo);
  cout << "\n"
       << result;

  cout << "BUSCAR KEY 1: ";
  result = busca(1);
  cout << "\n"
       << result;

  cout << "BUSCAR KEY 5: ";
  result = busca(5);
  cout << "\n"
       << result;

  cout << "BUSCAR KEY 1: ";
  result = busca2(1);
  cout << "\n"
       << result;

  cout << "BUSCAR KEY 5: ";
  result = busca2(5);
  cout << "\n"
       << result;

  no res_remv;

  cout << "REMOVER KEY 1: ";
  res_remv = remove(1);
  cout << "\n"
       << result;

  cout << "REMOVER KEY 5: ";
  res_remv = remove(5);
  cout << "\n"
       << result;

  return 0;
}
