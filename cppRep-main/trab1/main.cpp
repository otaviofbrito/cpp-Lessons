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
  float price;
};
int removeCar(struct car *dcar[], int index, int tam)
{
  delete (dcar[index]);
  int i;
  for (i = index; i < tam; i++)
  {
    if (tam != 50)
    {

      dcar[i] = dcar[i + 1];
    }
    else
    {
      dcar[i] = NULL;
    }
  }
  return tam--;
}

int insertCar(struct car *dcar[], int tam)
{
  if (tam < 50)
  {
    dcar[tam + 1] = new car;
    cout << "Model: ";
    cin >> dcar[tam + 1]->model;

    cout << "Brand: ";
    cin >> dcar[tam + 1]->brand;

    cout << "Type: ";
    cin >> dcar[tam + 1]->type;

    cout << "Year: ";
    cin >> dcar[tam + 1]->year;

    cout << "KMs: ";
    cin >> dcar[tam + 1]->km;

    cout << "Engine: ";
    cin >> dcar[tam + 1]->engine;

    cout << "Gas type: ";
    cin >> dcar[tam + 1]->gas;

    cout << "Gear: ";
    cin >> dcar[tam + 1]->gear;

    cout << "Steering: ";
    cin >> dcar[tam + 1]->steering;

    cout << "Color: ";
    cin >> dcar[tam + 1]->color;

    cout << "Doors: ";
    cin >> dcar[tam + 1]->doors;

    cout << "plate: ";
    cin >> dcar[tam + 1]->plate;

    cout << "price: ";
    cin >> dcar[tam + 1]->price;
    tam++;
  }
  else
  {
    cout << "Database is Full" << endl;
  }
  return tam;
}

int carSearch(int tam, struct car *dcar[], string plate)
{
  for (int c = 0; c < tam; c++)
  {
    if (plate == dcar[c]->plate)
    {
      string ans;
      cout << "Car Found!" << endl;
      cout << "Do you want to remove this car(y/n)? ";
      cin >> ans;
      while (ans != "y" && ans != "n")
      {
        cout << "Enter valid values!" << endl;
        cin >> ans;
      }
      if (ans == "y")
      {
        tam = removeCar(dcar, c, tam);
      }
      else
      {
      }
      return c;
    }
  }
  cout << "Car not found!" << endl;
  return NULL;
}

int menuDB()
{
  int opt;
  cout << "----MENU----" << endl;
  cout << "SELECT AN ACTION" << endl;
  cout << "1 - SEARCH CAR BY LICENSE PLATE" << endl;
  cout << "2 - SEARCH CAR BY PRICE" << endl;
  cout << "3 - INSERT CAR" << endl;
  cout << "4 - SORT DATABASE" << endl;
  cout << "5 - QUIT" << endl;
  cin >> opt;
  while (opt <= 0 || opt > 5)
  {
    cout << "SELECT AN AVAILABLE OPTION!" << endl;
    cin >> opt;
  }
  return opt;
}

int main(int argc, char const *argv[])
{

  struct car *bd[50];

  int i = 0;
  ifstream myfile;
  myfile.open("./cars.txt");
  if (myfile.is_open())
  {
    while (!myfile.eof())
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
      myfile >> bd[i]->price;
      i++;
    }
    myfile.close();

    int k = i;
    while (k < 50)
    {
      bd[k] = NULL;
      k++;
    }

    string rPlate;
    int slct;

    int q = 0;
    while (q >= 0)
    {
      slct = menuDB();
      if (slct == 1)
      {
        int search_res;
        cout << "Enter vehicle license plate: ";
        cin >> rPlate;
        search_res = carSearch(i, bd, rPlate);
       }else if( slct == 3) {
        i = insertCar(bd, i);
      }
       else if (slct == 5){
        q = -1;
      } 
    }

    for (int k = 0; k < i; k++)
    {
      delete (bd[k]);
    }
  }
  else
  {
    cout << "Unable to open file";
  }

  return 0;
}