#include <iostream>
#include <fstream>
#include <string>

#include <stdlib.h>

#include "./include/list.h"

using namespace std;

tLista *car_list;

int main(int argc, char const *argv[])
{

  car_list = inicia_lista();

  ifstream car_database;
  car_database.open("./cars.txt");
  if (car_database.is_open())
  {
    while (!car_database.eof())
    {

      cd *node = new cd;

      car_database >> node->model;
      car_database >> node->brand;
      car_database >> node->type;
      car_database >> node->year;
      car_database >> node->km;
      car_database >> node->engine;
      car_database >> node->gas;
      car_database >> node->gear;
      car_database >> node->steering;
      car_database >> node->color;
      car_database >> node->doors;
      car_database >> node->plate;
      car_database >> node->price;

      insere_inicio(car_list, node);
    }
  }
  else
  {
    cout << "UNABLE TO OPEN DATABASE" << endl;
  }

  imprime(car_list);

  no *search;
  search = busca(car_list, "JHE1456");
  if(search == NULL){
    cout << "NOT FOUND" << endl;
  }else {
    cout << "BUSCA = " << search->cardt->plate << endl;
  }
  

  car_list = encerra_lista(car_list);
  return 0;
}
