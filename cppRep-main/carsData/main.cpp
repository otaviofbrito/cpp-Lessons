
#include <fstream>
#include <iomanip>
#include <iostream>
#include <string>
#include <algorithm>
#include <climits>

using namespace std;

struct car
{
  string model;
  string brand;
  string type;
  string year;
  string km;
  string engine;
  string gas;
  string gear;
  string steering;
  string color;
  string doors;
  string plate;
  double price;
};

void removeCar(int index, int tam, car *dcar[])
{
  delete (dcar[index]);
  for (int i = index; i < tam; i++)
  {
    if (index == tam - 1)
    {
      dcar[index] = NULL; // ponteiro nulo
    }
    else
    {
      dcar[i] = dcar[i + 1];
    }
  }
}

int insertCar(struct car *dcar[], int tam)
{
  if (tam < 50) // não está cheia
  {
    string v_plate;
    cout << "\nEnter vehicle license plate: ";
    cin >> v_plate;
    transform(v_plate.begin(), v_plate.end(), v_plate.begin(), ::toupper);
    for (int i = 0; i < tam; i++)
    {
      if (dcar[i]->plate == v_plate)
      {
        cout << "\nCAR ALREADY IN DATABASE!\n"
             << "------------------------" << endl;
        return tam;
      }
    }
    if (dcar[0]->plate == "")
    {
      dcar[0]->plate = v_plate;
      cout << "Model: ";
      cin >> dcar[0]->model;
      cout << "Brand: ";
      cin >> dcar[0]->brand;
      cout << "Type: ";
      cin >> dcar[0]->type;
      cout << "Year: ";
      cin >> dcar[0]->year;
      cout << "KMs: ";
      cin >> dcar[0]->km;
      cout << "Engine: ";
      cin >> dcar[0]->engine;
      cout << "Gas type: ";
      cin >> dcar[0]->gas;
      cout << "Gear: ";
      cin >> dcar[0]->gear;
      cout << "Steering: ";
      cin >> dcar[0]->steering;
      cout << "Color: ";
      cin >> dcar[0]->color;
      cout << "Doors: ";
      cin >> dcar[0]->doors;
      cout << "price: ";
      cin >> dcar[0]->price;

      cout << "\nCAR STORED SUCCESSFULLY!\n"
           << "*--------------✓------------*\n";
      return tam;
    }
    else
    {
      dcar[tam] = new car;
      dcar[tam]->plate = v_plate;
      cout << "Model: ";
      cin >> dcar[tam]->model;
      cout << "Brand: ";
      cin >> dcar[tam]->brand;
      cout << "Type: ";
      cin >> dcar[tam]->type;
      cout << "Year: ";
      cin >> dcar[tam]->year;
      cout << "KMs: ";
      cin >> dcar[tam]->km;
      cout << "Engine: ";
      cin >> dcar[tam]->engine;
      cout << "Gas type: ";
      cin >> dcar[tam]->gas;
      cout << "Gear: ";
      cin >> dcar[tam]->gear;
      cout << "Steering: ";
      cin >> dcar[tam]->steering;
      cout << "Color: ";
      cin >> dcar[tam]->color;
      cout << "Doors: ";
      cin >> dcar[tam]->doors;
      cout << "price: ";
      cin >> dcar[tam]->price;

      cout << "\nCAR STORED SUCCESSFULLY!\n"
           << "*--------------✓------------*\n";
      return tam + 1;
    }
  }
  else
  {
    cout << "Database is Full"
         << "\n--------------X--------------" << endl;
  }
  return tam;
}

int buscaCarro(int tam, car *dcar[], string plate)
{

  for (int i = 0; i < tam; i++)
  {
    if (plate == dcar[i]->plate)
    {
      string resposta;
      cout << "\n >" << dcar[i]->brand << " " << dcar[i]->model << " FOUND!"
           << endl;
      cout << "Do you want remove this car(y/n)?: ";
      cin >> resposta;
      transform(resposta.begin(), resposta.end(), resposta.begin(), ::tolower);
      while (resposta != "y" && resposta != "n")
      {
        cout << "SELECT AN AVAILABLE OPTION! ";
        cin >> resposta;
        transform(resposta.begin(), resposta.end(), resposta.begin(), ::tolower);
      }
      if (resposta == "y")
      {
        removeCar(i, tam, dcar);
        tam--;
        cout << "\nCAR WAS REMOVED SUCCESSFULLY!\n"
             << "*--------------✓------------*" << endl;
      }
      return tam;
    }
  }

  cout << "\n\tCAR NOT FOUND!"
       << "\n--------------X--------------" << endl;
  return tam;
}

void ordenaCarro(int tam, car *dcar[], car *ordenado[])
{
  if (dcar[0]->plate == "")
  {
    cout << "\nDATABASE IS EMPTY!\n"
         << "--------------X--------------" << endl;
  }
  else
  {
    int i, j;
    car *aux;
    for (i = 0; i < tam; i++)
    {
      ordenado[i] = new car;
      ordenado[i] = dcar[i];
    }

    for (i = tam; i >= 1; i--)
    {
      for (j = 0; j < i - 1; j++)
      {
        if (ordenado[j]->plate > ordenado[j + 1]->plate)
        {
          aux = ordenado[j];
          ordenado[j] = ordenado[j + 1];
          ordenado[j + 1] = aux;
        }
      }
    }

    ofstream sortPlate;
    sortPlate.open("ordenado.txt");
    if (sortPlate.is_open())
    {
      int w;
      for (w = 0; w < tam - 1; w++)
      {
        sortPlate << ordenado[w]->model << " ";
        sortPlate << ordenado[w]->brand << " ";
        sortPlate << ordenado[w]->type << " ";
        sortPlate << ordenado[w]->year << " ";
        sortPlate << ordenado[w]->km << " ";
        sortPlate << ordenado[w]->engine << " ";
        sortPlate << ordenado[w]->gas << " ";
        sortPlate << ordenado[w]->gear << " ";
        sortPlate << ordenado[w]->steering << " ";
        sortPlate << ordenado[w]->color << " ";
        sortPlate << ordenado[w]->doors << " ";
        sortPlate << ordenado[w]->plate << " ";
        sortPlate << ordenado[w]->price << endl;
      }
      sortPlate << ordenado[w]->model << " ";
      sortPlate << ordenado[w]->brand << " ";
      sortPlate << ordenado[w]->type << " ";
      sortPlate << ordenado[w]->year << " ";
      sortPlate << ordenado[w]->km << " ";
      sortPlate << ordenado[w]->engine << " ";
      sortPlate << ordenado[w]->gas << " ";
      sortPlate << ordenado[w]->gear << " ";
      sortPlate << ordenado[w]->steering << " ";
      sortPlate << ordenado[w]->color << " ";
      sortPlate << ordenado[w]->doors << " ";
      sortPlate << ordenado[w]->plate << " ";
      sortPlate << ordenado[w]->price;

      sortPlate.close();

      cout << "\n"
           << "----------A-Z:" << endl;
      for (w = 0; w < tam; w++)
      {
        cout << w + 1 << " - " << ordenado[w]->plate << " - ";
        cout << ordenado[w]->model << " ";
        cout << ordenado[w]->brand << " ";
        cout << ordenado[w]->type << " ";
        cout << ordenado[w]->year << " ";
        cout << ordenado[w]->km << " KMs ";
        cout << ordenado[w]->engine << " ";
        cout << ordenado[w]->gas << " ";
        cout << ordenado[w]->gear << " ";
        cout << ordenado[w]->steering << " ";
        cout << ordenado[w]->color << " ";
        cout << ordenado[w]->doors << " Portas ";
        cout << "R$:" << ordenado[w]->price << endl;
      }
    }
    else
    {
      cout << "UNABLE TO OPEN FILE DURING SORTING" << endl;
    }
  }
}

void sortPrice(int tam, car *dcar[], car *sort_price[])
{
  int i, j;
  car *aux;
  for (i = 0; i < tam; i++)
  {
    sort_price[i] = new car;
    sort_price[i] = dcar[i];
  }

  for (i = tam; i >= 1; i--)
  {
    for (j = 0; j < i - 1; j++)
    {
      if (sort_price[j]->price > sort_price[j + 1]->price)
      {
        aux = sort_price[j];
        sort_price[j] = sort_price[j + 1];
        sort_price[j + 1] = aux;
      }
    }
  }
}

int binarySearch(car *dcar[], int tam, float target)
{
  int min = 0;
  int max = tam - 1;

  while (min <= max)
  {
    int mid = min + (max - min) / 2;
    if (dcar[mid]->price < target)
    {
      min = mid + 1;
    }
    else if (dcar[mid]->price > target)
    {
      max = mid - 1;
    }
    else
    {
      return mid;
    }
  }
  return min;
}

void findElementsByPrice(car *dcar[], int target, int v, int tam)
{
  int i = binarySearch(dcar, tam, target);

  int esq = i - 1;
  int dir = i;
  if (tam <= 10)
  {
    v = tam;
  }
  while (v-- > 0)
  {

    if (esq < 0 || (dir < tam && abs(dcar[esq]->price - target) >
                                     abs(dcar[dir]->price - target)))
    {
      dir++;
    }
    else
    {
      esq--;
    }
  }

  esq++;
  cout << "\nRESULTS:\n"
       << endl;
  while (esq < dir)
  {
    cout << left
         << setw(0) << "R$ "
         << setw(10) << dcar[esq]->price << " - "
         << setw(20) << dcar[esq]->brand
         << setw(20) << dcar[esq]->model
         << setw(10) << dcar[esq]->year
         << setw(10) << dcar[esq]->engine
         << setw(10) << dcar[esq]->type
         << setw(10) << dcar[esq]->color
         << setw(10) << dcar[esq]->plate << endl;

    esq++;
  }
}

void saveFile(int tam, car *dcar[])
{
  if (dcar[0]->plate == "")
  {
    cout << "\nFAILED TO SAVE FILE(DATABASE IS EMPTY!)\n";
  }
  else
  {
    ofstream car_database;
    car_database.open("./cars.txt");
    if (car_database.is_open())
    {
      int c;
      for (c = 0; c < tam - 1; c++)
      {
        car_database << dcar[c]->model << " ";
        car_database << dcar[c]->brand << " ";
        car_database << dcar[c]->type << " ";
        car_database << dcar[c]->year << " ";
        car_database << dcar[c]->km << " ";
        car_database << dcar[c]->engine << " ";
        car_database << dcar[c]->gas << " ";
        car_database << dcar[c]->gear << " ";
        car_database << dcar[c]->steering << " ";
        car_database << dcar[c]->color << " ";
        car_database << dcar[c]->doors << " ";
        car_database << dcar[c]->plate << " ";
        car_database << dcar[c]->price << endl;
      }
      car_database << dcar[c]->model << " ";
      car_database << dcar[c]->brand << " ";
      car_database << dcar[c]->type << " ";
      car_database << dcar[c]->year << " ";
      car_database << dcar[c]->km << " ";
      car_database << dcar[c]->engine << " ";
      car_database << dcar[c]->gas << " ";
      car_database << dcar[c]->gear << " ";
      car_database << dcar[c]->steering << " ";
      car_database << dcar[c]->color << " ";
      car_database << dcar[c]->doors << " ";
      car_database << dcar[c]->plate << " ";
      car_database << dcar[c]->price;

      car_database.close();
      cout << "\nDATABASE UPDATED!"
           << "\n*--------------✓------------*" << endl;
    }
    else
    {
      cout << "UNABLE TO OVERWRITE FILE" << endl;
    }
  }
}

int menu_db()
{
  int resposta;
  string in_placa;

  cout << "\n*----------MENU----------*" << endl;
  cout << "1 - Busca pela placa" << endl;
  cout << "2 - Filtrar valores proximos" << endl;
  cout << "3 - Incluir um novo veículo" << endl;
  cout << "4 - Ordenar veículos " << endl;
  cout << "5 - Salvar alterações" << endl;
  cout << "6 - Sair" << endl;
  cout << "SELECT AN OPTION: ";
  cin >> resposta;

  while (resposta <= 0 || resposta > 6 || cin.fail())
  {
    cin.clear();
    cin.ignore(INT_MAX, '\n');
    cout << "SELECT AN AVAILABLE OPTION!: ";
    cin >> resposta;
  }
  return resposta;
}

int main(int argc, char const *argv[])
{

  struct car *bd[50];
  struct car *sort[50];
  struct car *sort_by_price[50];

  ifstream car_database;
  car_database.open("./cars.txt");
  int i = 0;
  if (car_database.is_open())
  {
    while (!car_database.eof())
    {
      bd[i] = new car;
      car_database >> bd[i]->model;
      car_database >> bd[i]->brand;
      car_database >> bd[i]->type;
      car_database >> bd[i]->year;
      car_database >> bd[i]->km;
      car_database >> bd[i]->engine;
      car_database >> bd[i]->gas;
      car_database >> bd[i]->gear;
      car_database >> bd[i]->steering;
      car_database >> bd[i]->color;
      car_database >> bd[i]->doors;
      car_database >> bd[i]->plate;
      car_database >> bd[i]->price;
      i++;
    }

    car_database.close();

    int k = i;
    while (k < 50)
    {
      bd[k] = NULL;
      k++;
    }

    for (int c = 0; c < 50; c++)
    {
      sort[c] = NULL;
      sort_by_price[c] = NULL;
    }

    string rPlate;
    int slct;
    int q = 0;

    while (q >= 0)
    {
      slct = menu_db();
      if (slct == 1)
      {
        cout << "Enter vehicle license plate: ";
        cin >> rPlate;
        transform(rPlate.begin(), rPlate.end(), rPlate.begin(), ::toupper);
        i = buscaCarro(i, bd, rPlate);
      }
      else if (slct == 2)
      {
        float r_price;
        cout << "Enter price range: ";
        cin >> r_price;
        sortPrice(i, bd, sort_by_price);
        findElementsByPrice(sort_by_price, r_price, 10, i);
      }
      else if (slct == 3)
      {
        i = insertCar(bd, i);
      }
      else if (slct == 4)
      {
        ordenaCarro(i, bd, sort);
      }
      else if (slct == 5)
      {
        saveFile(i, bd);
      }
      else if (slct == 6)
      {
        q = -1;
        cout << "\nLEAVING APPLICATION... " << endl;
      }
    }

    for (int k = 0; k < i; k++)
    {
      delete (bd[k]);
    }
  }
  else
  {
    cout << "UNABLE TO ACCESS DATA FILE" << endl;
  }
}