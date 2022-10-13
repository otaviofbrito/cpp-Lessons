#include <iostream>

using namespace std;

int fatorial(int n)
{
  if (n < 2)
  {
    return 1;
  }
  else
  {
    return n * fatorial(n - 1);
  }
}

int inst = 0;

int fatorial2(int n)
{
  int fat = 1;
  if (n < 1)
  {
    return -1;
  }
  while (n > 1)
  {
    fat = fat * n;
    n--;
  }
  return fat;
}

int main(int argc, char const *argv[])
{
  int n, ft;
  cout << "Factorial calc . . ." << endl;
  cout << " Type n value ->";
  cin >> n;
  ft = fatorial2(n);
  cout << " N Factorial  " << n << "is equal to: " << ft << endl;
  return 0;
}