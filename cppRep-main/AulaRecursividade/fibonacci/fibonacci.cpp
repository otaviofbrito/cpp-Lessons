#include <iostream>

using namespace std;

void fibonacci(int n, int ult, int penult){
  cout << ult << " ";
  if (ult + penult < n){
    fibonacci(n, ult+penult, ult);
  }
}
int main(int argc, char const *argv[])
{
  int n, ft;
  cout << "Fibonacci . . ." << endl;
  cout << " Type n value: ";
  cin >> n;
  cout << " Sequencia: ";
  fibonacci(n, 1, 0);
  cout << endl;
  return 0;
}