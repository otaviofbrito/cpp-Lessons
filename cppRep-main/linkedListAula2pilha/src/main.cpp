

#include <iostream>

#include <stdlib.h>

#include "../src/include/lista.h"
#include "../src/include/stack.h"

using namespace std;

tStack *stack;

/*

 *

 */

int main()
{

  no *p;

  stack = start_stack();

  push(stack, 5);

  cout << "insere 1: ";

  imprime(stack);

  push(stack, 10);

  cout << "insere 2: ";

  imprime(stack);

  push(stack, 15);

  cout << "insere 3: ";

  imprime(stack);

  push(stack, 12);

  cout << "insere 4: ";

  imprime(stack);

  push(stack, 20);

  cout << "insere 5: ";

  imprime(stack);

  p = pop(stack);

  cout << "remove 1: " << p->valor << endl;

  delete (p);

  imprime(stack);

  p = pop(stack);

  cout << "remove 2: " << p->valor << endl;

  delete (p);

  imprime(stack);

  p = pop(stack);

  cout << "remove 3: " << p->valor << endl;

  delete (p);

  imprime(stack);

  p = pop(stack);

  cout << "remove 4: " << p->valor << endl;

  delete (p);

  imprime(stack);

  p = pop(stack);

  cout << "remove 5: " << p->valor << endl;

  delete (p);

  imprime(stack);

  p = pop(stack);

  cout << "remove 6: " << endl;

  delete (p);

  imprime(stack);

  stack = end_stack(stack);

  return (EXIT_SUCCESS);
}
