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
  string gear;
  string steering;
  string color;
  string doors;
  string plate;
};

void printCar(int i,struct car *dcar[50])
{
  cout << "model: " << dcar[i]->model << endl;
  cout << "brand: " << dcar[i]->brand << endl;
  cout << "type: " << dcar[i]->type << endl;
  cout << "year: " << dcar[i]->year << endl;
  cout << "KMs: " << dcar[i]->km << endl;
  cout << "engine: " << dcar[i]->engine << endl;
  cout << "gas: " << dcar[i]->gas << endl;
  cout << "gear: " << dcar[i]->gear << endl;
  cout << "steering: " << dcar[i]->steering << endl;
  cout << "color: " << dcar[i]->color << endl;
  cout << "doors: " << dcar[i]->doors << endl;
  cout << "plate: " << dcar[i]->plate << endl;
}

int main(int argc, char const *argv[])
{

  struct car *bd[50];

  int i = 1;
  ifstream myfile;
  myfile.open("cars.txt");
  if (myfile.is_open())
  {
    while (!myfile.eof() && i < 50)
    {
      bd[i] = new car;
      myfile >> bd[i]->model;
      myfile >> bd[i]->brand;
      myfile >> bd[i]->type;
      myfile >> bd[i]->year;
      myfile >> bd[i]->km;
      myfile >> bd[i]->engine;
      myfile >> bd[i]->gas;
      myfile >> bd[i]->gear;
      myfile >> bd[i]->steering;
      myfile >> bd[i]->color;
      myfile >> bd[i]->doors;
      myfile >> bd[i]->plate;
      i++;
    }
    printCar(3, bd);
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
