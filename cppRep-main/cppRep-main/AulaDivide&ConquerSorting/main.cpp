/*
 * File:   main.cpp
 * Author: paulo
 *
 * Created on August 27, 2019, 2:50 PM
 */

#include <cstdlib>
#include <iostream>
#include <stdlib.h>

using namespace std;

int inst = 0, tamanho = 10;
int *z;

void debug(int p, int r, int v[])
{
  inst++;
  cout << endl
       << "  " << inst << "ª instância p = " << p << " r = " << r << " -> ";
  for (int *z = v; z < v + tamanho; z++)
    cout << *z << " ";
}

int *inicializa(int tam)
{
  int *v = (int *)malloc(tam * sizeof(int));
  int *p;
  srand(time(NULL));
  for (p = v; p < v + tam; p++)
  {
    *p = rand() % 100;
  }
  return v;
}

void intercala1(int p, int q, int r, int v[])
{
  int *w;
  w = (int *)malloc((r - p) * sizeof(int));
  int i = p, j = q;
  int k = 0;
  while (i < q && j < r)
  {
    if (v[i] <= v[j])
      w[k++] = v[i++];
    else
      w[k++] = v[j++];
  }
  while (i < q)
    w[k++] = v[i++];
  while (j < r)
    w[k++] = v[j++];
  for (i = p; i < r; ++i)
    v[i] = w[i - p];
  free(w);
}

void intercala2(int p, int q, int r, int v[])
{
  int i, j, *w;
  w = (int *)malloc((r - p) * sizeof(int));

  for (i = p; i < q; ++i)
    w[i - p] = v[i];
  for (j = q; j < r; ++j)
    w[r - p + q - j - 1] = v[j];
  i = 0;
  j = r - p - 1;
  for (int k = p; k < r; ++k)
    if (w[i] <= w[j])
      v[k] = w[i++];
    else
      v[k] = w[j--];
  free(w);
}

void MergeSort(int p, int r, int v[])
{
  if (p < r - 1)
  {
    int q = (p + r) / 2;
    MergeSort(p, q, v);
    MergeSort(q, r, v);
    intercala1(p, q, r, v);
  }
}

int separa(int v[], int p, int r)
{
  int c = v[r]; // pivô
  int temp, j = p;
  for (int k = p; k < r; ++k)
    if (v[k] <= c)
    {
      temp = v[j];
      v[j] = v[k];
      v[k] = temp;
      ++j;
    }
  v[r] = v[j];
  v[j] = c;
  return j;
}

void QuickSort(int v[], int p, int r)
{
  if (p < r)
  {
    int j = separa(v, p, r);
    QuickSort(v, p, j - 1);
    QuickSort(v, j + 1, r);
  }
}

void constroiHeap(int m, int v[])
{
  int aux;
  for (int k = 1; k < m; ++k)
  {
    int f = k + 1;
    while (f > 1 && v[f / 2 - 1] < v[f - 1])
    {
      aux = v[f / 2 - 1];
      v[f / 2 - 1] = v[f - 1];
      v[f - 1] = aux;
      f /= 2;
    }
  }
}

void peneira(int m, int v[])
{
  int f = 2, aux;
  while (f <= m)
  {
    if (f < m && v[f - 1] < v[f])
      ++f;
    if (v[f / 2 - 1] >= v[f - 1])
      break;
    aux = v[f / 2 - 1];
    v[f / 2 - 1] = v[f - 1];
    v[f - 1] = aux;
    f *= 2;
  }
}

void HeapSort(int n, int v[])
{
  int aux;
  constroiHeap(n, v);
  for (int m = n; m >= 2; --m)
  {
    aux = v[0];
    v[0] = v[m - 1];
    v[m - 1] = aux;
    peneira(m - 1, v);
  }
}

/*
 *
 */
int main(int argc, char **argv)
{
  int *v;

  v = inicializa(10);

  cout << "Estado Inicial" << endl;
  for (int *p = v; p < v + 10; p++)
  {
    cout << "   " << *p;
  }

  MergeSort(0, 10, v);
  // QuickSort(v, 0, 9);
  // HeapSort(10, v);

  cout << endl
       << "Estado Final" << endl;
  for (int *p = v; p < v + 10; p++)
  {
    cout << "   " << *p;
  }
  cout << endl;
  free(v);

  return 0;
}