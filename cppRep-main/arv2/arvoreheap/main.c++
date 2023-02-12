// A C++ program to demonstrate common Binary Heap Operations
#include <iostream>
#include <climits>
using namespace std;

// Prototype of a utility function to swap two integers
void swap(int *x, int *y);

// A class for Min Heap
class MinHeap
{
  int *vet;       // pointer to array of elements in heap
  int capacidade; // maximum possible size of min heap
  int tam_vet;    // Current number of elements in min heap
public:
  // Constructor
  MinHeap(int capacidade);

  // to heapify a subtree with the root at given index
  void MinHeapify(int);

  int pai(int i) { return (i - 1) / 2; }

  // to get index of esquerda child of node at index i
  int esquerda(int i) { return (2 * i + 1); }

  // to get index of direita child of node at index i
  int direita(int i) { return (2 * i + 2); }

  // to extract the root which is the minimum element
  int extractMin();

  // Returns the minimum key (key at root) from min heap
  int getMin() { return vet[0]; }

  // Inserts a new key 'k'
  void insertKey(int k);
};

// Constructor: Builds a heap from a given array a[] of given size
MinHeap::MinHeap(int cap)
{
  tam_vet = 0;
  capacidade = cap;
  vet = new int[cap];
}

// Inserts a new key 'k'
void MinHeap::insertKey(int k)
{
  if (tam_vet == capacidade)
  {
    cout << "\nMAX capacidade!\n";
    return;
  }

  tam_vet++;
  int i = tam_vet - 1;
  vet[i] = k;

  while (i != 0 && vet[pai(i)] > vet[i])
  {
    swap(&vet[i], &vet[pai(i)]);
    i = pai(i);
  }
}


// Method to remove minimum element (or root) from min heap

int MinHeap::extractMin()
{
  if(tam_vet <= 0){
    return INT_MAX;
  }
  if(tam_vet == 1){
    tam_vet--;
    return vet[0];
  }


  int raiz = vet[0];
  vet[0] = vet[tam_vet -1];
  tam_vet--;
  MinHeapify(0);
  return raiz;

}

// A recursive method to heapify a subtree with the root at given index
// This method assumes that the subtrees are already heapified
void MinHeap::MinHeapify(int i)
{
  int esq = esquerda(i);
  int dir = direita(i);
  int menor = i;
  if(esq < tam_vet && vet[esq] < vet[i]){
    menor = esq;
  }
  if(dir < tam_vet && vet[dir] < vet[menor]){
    menor = dir;
  }
  if(menor != i){
    swap(&vet[i], &vet[menor]);
    MinHeapify(menor);
  }
}

// A utility function to swap two elements
void swap(int *x, int *y)
{
  int temp = *x;
  *x = *y;
  *y = temp;
}

// Driver program to test above functions
int main()
{
  MinHeap h(11);
  h.insertKey(3);
  h.insertKey(2);
  h.insertKey(15);
  h.insertKey(5);
  h.insertKey(4);
  h.insertKey(45);
  cout << h.extractMin() << " ";
  cout << h.getMin() << " ";
  cout << h.extractMin() << " ";
  cout << h.getMin();
  return 0;
}