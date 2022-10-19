#include <iostream>
#include <fstream>

using namespace std;

typedef struct car
{
  string model;
  string brand;
  string type;
  int year;
  int km;
  string engine;
  string gas;
  string cambio;
  string steering;
  string color;
  string doors;
  string plate;
};

int main(int argc, char const *argv[])
{

  car *bd[50];

  ofstream myfile;
  myfile.open("cars.txt");
  if (myfile.is_open())
  {
    while (!myfile.eof())
    {
      for (int i = 0; i < 50; i++)
      {
        bd[i] = new car;
        bd[i]->model;
        bd[i]->brand;
        bd[i]->type;
        bd[i]->year;
        bd[i]->km;
        bd[i]->engine;
        bd[i]->gas;
        bd[i]->cambio;
        bd[i]->steering;
        bd[i]->color;
        bd[i]->doors;
        bd[i]->plate;
      }
    }
    myfile.close();
  }
  else
  {
    cout << "Unable to open file";
  }

  /*abrir arquivoo
  alocar a lsita de ponteiros
  p cada arquivo aloca ruma struc e inserir os valroes
  imprimir os valroes*/

  /*
  ofstream myfile;

  myfile.open("data.txt");
  if (myfile.is_open())
  {
    myfile << "AAAAA aa aAAA";

    myfile.close();
  }
  else
  {
    cout << "Unable to open file";
  }

  string line;
  ifstream myfile("data.txt");
  if (myfile.is_open())
  {
    while (!myfile.eof())
    {
      myfile >> line;
      cout << "string: " << line << endl;
    }
    myfile.close();
  }
  else
  {
    cout << "UNABLE TO OPEN FILE";
  }
*/
  return 0;
}
