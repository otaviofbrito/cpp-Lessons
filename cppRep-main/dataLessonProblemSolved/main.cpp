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
void removeCar(struct car *dcar[], int index, int tam)
{
  int i = 0;
  dcar[index] = NULL;
  for (i = index; i < tam; i++)
  {
    dcar[i] = dcar[i + 1];
    dcar[i + 1] = NULL;
  }
}

void insertCar(struct car *dcar[], int tam)
{
  if (tam < 50)
  {
    ofstream myfile("cars.txt", ios_base::app | ios_base::out);
    if (myfile.is_open())
    {
      dcar[tam + 1] = new car;
      cout << "Model: ";
      cin >> dcar[tam + 1]->model;
      myfile << "\n"
             << dcar[tam + 1]->model << " ";

      cout << "Brand: ";
      cin >> dcar[tam + 1]->brand;
      myfile << dcar[tam + 1]->brand << " ";

      cout << "Type: ";
      cin >> dcar[tam + 1]->type;
      myfile << dcar[tam + 1]->type << " ";

      cout << "Year: ";
      cin >> dcar[tam + 1]->year;
      myfile << dcar[tam + 1]->year << " ";

      cout << "KMs: ";
      cin >> dcar[tam + 1]->km;
      myfile << dcar[tam + 1]->km << " ";

      cout << "Engine: ";
      cin >> dcar[tam + 1]->engine;
      myfile << dcar[tam + 1]->engine << " ";

      cout << "Gas type: ";
      cin >> dcar[tam + 1]->gas;
      myfile << dcar[tam + 1]->gas << " ";

      cout << "Gear: ";
      cin >> dcar[tam + 1]->gear;
      myfile << dcar[tam + 1]->gear << " ";

      cout << "Steering: ";
      cin >> dcar[tam + 1]->steering;
      myfile << dcar[tam + 1]->steering << " ";

      cout << "Color: ";
      cin >> dcar[tam + 1]->color;
      myfile << dcar[tam + 1]->color << " ";

      cout << "Doors: ";
      cin >> dcar[tam + 1]->doors;
      myfile << dcar[tam + 1]->doors << " ";

      cout << "plate: ";
      cin >> dcar[tam + 1]->plate;
      myfile << dcar[tam + 1]->plate << endl;
      exit(0);
    }
    else
    {
      cout << "Unable to open file during insertion" << endl;
    }
  }
  else
  {
    cout << "Database is Full" << endl;
  }
  exit(0);
}

car *carSearch(int tam, struct car *dcar[], string plate)
{
  string ans;
  for (int c = 0; c < tam; c++)
  {
    if (plate == dcar[c]->plate)
    {
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
        removeCar(dcar, c, tam);
        ofstream myfile;
        myfile.open("cars.txt");
        if (myfile.is_open())
        {
          int j = 0;
          for (j; j < tam - 2; j++)
          {
            myfile << dcar[j]->model << " ";
            myfile << dcar[j]->brand << " ";
            myfile << dcar[j]->type << " ";
            myfile << dcar[j]->year << " ";
            myfile << dcar[j]->km << " ";
            myfile << dcar[j]->engine << " ";
            myfile << dcar[j]->gas << " ";
            myfile << dcar[j]->gear << " ";
            myfile << dcar[j]->steering << " ";
            myfile << dcar[j]->color << " ";
            myfile << dcar[j]->doors << " ";
            myfile << dcar[j]->plate << "\n";
          } 
          myfile << dcar[j]->model << " ";
            myfile << dcar[j]->brand << " ";
            myfile << dcar[j]->type << " ";
            myfile << dcar[j]->year << " ";
            myfile << dcar[j]->km << " ";
            myfile << dcar[j]->engine << " ";
            myfile << dcar[j]->gas << " ";
            myfile << dcar[j]->gear << " ";
            myfile << dcar[j]->steering << " ";
            myfile << dcar[j]->color << " ";
            myfile << dcar[j]->doors << " ";
            myfile << dcar[j]->plate;
          myfile.close();
          exit(0);
        }
        else
        {
          cout << "Unable to open file during removal";
        }
      }
      else
      {
        exit(0);
      }
      return dcar[c];
    }
  }
  cout << "Car not found!" << endl;
  cout << "Do you want to add this car(y/n)? ";
  cin >> ans;
  while (ans != "y" && ans != "n")
  {
    cout << "Enter valid values!" << endl;
    cin >> ans;
  }
  if (ans == "y")
  {
    insertCar(dcar, tam);
  }
  else
  {
    exit(0);
  }
  return NULL;
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
    cout << "Enter vehicle license plate: ";
    cin >> rPlate;
    carSearch(i, bd, rPlate);

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