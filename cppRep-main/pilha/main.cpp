#include <iostream>

typedef struct no_
{

  int chave;
  int valor;
} no;

using namespace std;

no pile[10];
int tam = 10;
int top = -1;

int insere(no new_element)
{

  if (top != tam)
  {
    top++;
    pile[top] = new_element;
    return top;
  }
  return -1;
}

no remove()
{
  no retorno;
  if (top != -1)
  {
    retorno = pile[top];
    top--;
  }
  return retorno;
}

int main(int argc, char const *argv[])
{

  no resp;

  cout << "INSERE 1" << endl;
  cin >> resp.chave >> resp.valor;
  insere(resp);

  cout << "INSERE 2" << endl;
  cin >> resp.chave >> resp.valor;
  insere(resp);

  cout << "INSERE 3" << endl;
  cin >> resp.chave >> resp.valor;
  insere(resp);

  remove();
  remove();
  

  return 0;
}
