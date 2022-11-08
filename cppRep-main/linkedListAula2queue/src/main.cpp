

#include <iostream>

#include <stdlib.h>

#include "../src/include/lista.h"
#include "../src/include/queue.h"

using namespace std;

tQueue *queue;

/*

 *

 */

int main()
{

  no *p;

  queue = start_queue();

  push(queue, 5);

  cout << "insere 1: ";

  imprime(queue);

  push(queue, 10);

  cout << "insere 2: ";

  imprime(queue);

  push(queue, 15);

  cout << "insere 3: ";

  imprime(queue);

  push(queue, 12);

  cout << "insere 4: ";

  imprime(queue);

  push(queue, 20);

  cout << "insere 5: ";

  imprime(queue);

  p = pop(queue);

  cout << "remove 1: " << p->valor << endl;

  delete (p);

  imprime(queue);

  p = pop(queue);

  cout << "remove 2: " << p->valor << endl;

  delete (p);

  imprime(queue);

  p = pop(queue);

  cout << "remove 3: " << p->valor << endl;

  delete (p);

  imprime(queue);

  p = pop(queue);

  cout << "remove 4: " << p->valor << endl;

  delete (p);

  imprime(queue);

  p = pop(queue);

  cout << "remove 5: " << p->valor << endl;

  delete (p);

  imprime(queue);

  p = pop(queue);

  cout << "remove 6: " << endl;

  delete (p);

  imprime(queue);

  queue = end_queue(queue);

  return (EXIT_SUCCESS);
}
