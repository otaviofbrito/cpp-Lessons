#include <cctype>
#include <fstream>
#include <iostream>
#include <string>

using namespace std;

struct car
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

void removeCarro(int index, int tam, car *dcar[])
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
  if (tam < 50) // não está cheia.
  {
    string v_plate;
    cout << "Enter vehicle license plate: ";
    cin >> v_plate;
    for (int i = 0; i < tam; i++)
    {
      if (dcar[i]->plate == v_plate)
      {
        cout << "Car already in database" << endl;
        return tam;
      }
    }

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

    // cout << "plate: ";
    // cin >> dcar[tam]->plate;

    cout << "price: ";
    cin >> dcar[tam]->price;
  }
  else
  {
    cout << "Database is Full" << endl;
  }
  return tam + 1;
}

int buscaCarro(int tam, car *dcar[], string plate)
{

  for (int i = 0; i < tam; i++)
  {
    if (plate == dcar[i]->plate)
    {
      string resposta;
      cout << "\n >" << dcar[i]->brand << " " << dcar[i]->model << " FOUND!" << endl;
      cout << "Do you want remove this car(y/n)?: ";
      cin >> resposta;
      while (resposta != "y" && resposta != "n")
      {
        cout << "SELECT AN AVAILABLE OPTION!" << endl;
        cin >> resposta;
      }
      if (resposta == "y")
      {
        removeCarro(i, tam, dcar);
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
  int low = 0;
  int high = tam - 1;

  while (low <= high)
  {
    int mid = low + (high - low) / 2;
    if (dcar[mid]->price < target)
    {
      low = mid + 1;
    }
    else if (dcar[mid]->price > target)
    {
      high = mid - 1;
    }
    else
    {
      return mid;
    }
  }
  return low;
}

void findKClosestElements(car *dcar[], int target, int k, int tam)
{
  int i = binarySearch(dcar, tam, target);

  int left = i - 1;
  int right = i;

  while (k-- > 0)
  {

    if (left < 0 || (right < tam && abs(dcar[left]->price - target) > abs(dcar[right]->price - target)))
    {
      right++;
    }
    else
    {
      left--;
    }
  }

  left++;
  while (left < right)
  {
    printf("%f ", dcar[left]->price);
    left++;
  }
}

int menu_db()
{
  int resposta;
  string in_placa;

  cout << "\n*----------MENU----------*" << endl;
  cout << "1 - Busca pela placa." << endl;
  cout << "2 - Busca pelor valor" << endl;
  cout << "3 - Inclusão de um novo veículo" << endl;
  cout << "4 - Ordenação dos veículos " << endl;
  cout << "5 - Quit" << endl;
  cout << "SELECT AN OPTION: ";

  cin >> resposta;

  while (resposta <= 0 || resposta > 5)
  {
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
        i = buscaCarro(i, bd, rPlate);
      }
      else if (slct == 2)
      {
        float r_price;
        cout << "Enter price range: ";
        cin >> r_price;
        sortPrice(i, bd, sort_by_price);
        findKClosestElements(sort_by_price, r_price, 10, i);
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
    cout << "não foi possível abrir o arquivo" << endl;
  }
}