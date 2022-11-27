#include <iostream>

using namespace std;

typedef struct no_
{
  int chave;
  int valor;
} no;

no queue[5];
int r = -1;
int f = -1;
int tam = 5;

int insere(no new_element)
{
  int retorno = -2;
  int aux = (r + 1) % tam;
  if (aux != f)
  {
    r = aux;
    queue[r] = new_element;
    retorno = r;
    if (f == -1)
    {
      f = 0;
    }
  }
  return retorno;
}

no remove()
{ 
  no retorno;
  if(f != -1){
    retorno = queue[f];
    if(f == r){
      r = -1;
      f = r;
    }else {
      f = (f+1)%tam;
    }
  }

}

int main(int argc, char const *argv[])
{
  no res;

  insere({1, 5});
  insere({2, 10});
  insere({3, 15});
  res = remove();
  insere({4, 20});
  insere({5, 25});
  res = remove();
  insere({6, 30});
  insere({7, 35});
  insere({8, 40});
  res = remove();
  insere({9, 45});
  insere({10, 50});
  insere({11, 55});
  res = remove();
  insere({12, 60});
  res = remove();
  res = remove();
  res = remove();
  res = remove();
  res = remove();
  res = remove();
  return 0;
}
