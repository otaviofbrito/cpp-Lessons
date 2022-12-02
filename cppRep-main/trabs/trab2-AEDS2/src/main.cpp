#include <iostream>
#include <fstream>
#include <string>
#include <climits>   //menu
#include <algorithm> //transform

#include "../src/include/lista.h"
#include "../src/include/fila.h"
#include "../src/include/pilha.h"

using namespace std;

tLista *ptlista;
tLista *ord_lista;

tFila *ptfila;

tPilha *ptpilha;

void buscaCarro(tLista *lista, string plate)
{
  no *find_car = busca(lista, plate);
  if (find_car != NULL)
  {
    string resposta;
    cout << "\n >" << find_car->pt_dcar->marca << " " << find_car->pt_dcar->modelo << " FOUND!"
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
      no *car_removed = remove_enc(lista, plate);
      cout << "\nCAR WAS REMOVED SUCCESSFULLY!\n"
           << "*--------------✓------------*" << endl;

      delete (car_removed->pt_dcar);
      delete (car_removed);
    }
  }
  else
  {

    cout << "\n\tCAR NOT FOUND!"
         << "\n--------------X--------------" << endl;
  }
}

int insertCar(tLista *ptlista)
{
  string nova_placa;
  cout << "\nEnter vehicle license plate: ";
  cin >> nova_placa;
  transform(nova_placa.begin(), nova_placa.end(), nova_placa.begin(), ::toupper);

  if (busca(ptlista, nova_placa) != NULL)
  {
    cout << "\nCAR ALREADY IN DATABASE!\n"
         << "------------------------" << endl;
    return 0;
  }
  else
  {
    dcar *novo_carro = new dcar;
    novo_carro->placa = nova_placa;
    cout << "Model: ";
    cin >> novo_carro->modelo;
    cout << "Brand: ";
    cin >> novo_carro->marca;
    cout << "Type: ";
    cin >> novo_carro->tipo;
    cout << "Year: ";
    cin >> novo_carro->ano;
    cout << "KMs: ";
    cin >> novo_carro->km;
    cout << "Engine: ";
    cin >> novo_carro->potencia;
    cout << "Gas type: ";
    cin >> novo_carro->combustivel;
    cout << "Gear: ";
    cin >> novo_carro->cambio;
    cout << "Steering: ";
    cin >> novo_carro->direcao;
    cout << "Color: ";
    cin >> novo_carro->cor;
    cout << "Doors: ";
    cin >> novo_carro->portas;
    cout << "price: ";
    cin >> novo_carro->valor;

    insere_fim(ptlista, novo_carro);

    cout << "\nCAR STORED SUCCESSFULLY!\n"
         << "*--------------✓------------*\n";

    return 1;
  }
  return 0;
}

void insere_ordenado(tLista *ptlista, tLista *ordenado)
{
  no *ant = ordenado->lista;
  no *lista_principal = ptlista->lista;
  no *pont;
  string placa;

  for (int i = 1; i <= ptlista->tam; i++)
  {
    no *novo_ord = new no;
    novo_ord->pt_dcar = lista_principal->pt_dcar;
    placa = lista_principal->pt_dcar->placa;
    busca_ordenada(ordenado, placa, &ant, &pont);
    if (pont == NULL)
    { // não estou inserindo o mesmo.
      if (ant == NULL)
      { // primeira inserção.
        novo_ord->prox = ant;
        ordenado->lista = novo_ord;
      }
      else if (ant == ordenado->lista && ant->pt_dcar->placa > placa)
      { // ele é o menor de todos.
        novo_ord->prox = ordenado->lista;
        ordenado->lista = novo_ord;
      }
      else
      {
        novo_ord->prox = ant->prox;
        ant->prox = novo_ord;
      }
    }
    lista_principal = lista_principal->prox;
  }
}

void saveFile(tLista *ptlista)
{
  ofstream car_database;
  car_database.open("./cars.txt");
  if (car_database.is_open())
  {
    if (ptlista->lista == NULL)
    {
      car_database << "";
    }
    else
    {

      no *ptr = ptlista->lista;
      while (ptr != NULL)
      {
        car_database << ptr->pt_dcar->modelo << " ";
        car_database << ptr->pt_dcar->marca << " ";
        car_database << ptr->pt_dcar->tipo << " ";
        car_database << ptr->pt_dcar->ano << " ";
        car_database << ptr->pt_dcar->km << " ";
        car_database << ptr->pt_dcar->potencia << " ";
        car_database << ptr->pt_dcar->combustivel << " ";
        car_database << ptr->pt_dcar->cambio << " ";
        car_database << ptr->pt_dcar->direcao << " ";
        car_database << ptr->pt_dcar->cor << " ";
        car_database << ptr->pt_dcar->portas << " ";
        car_database << ptr->pt_dcar->placa << " ";
        if (ptr->prox == NULL)
        {

          car_database << ptr->pt_dcar->valor;
        }
        else
        {
          car_database << ptr->pt_dcar->valor << endl;
        }

        ptr = ptr->prox;
      }

      car_database.close();
      cout << "\nDATABASE UPDATED!"
           << "\n*--------------✓------------*" << endl;
    }
  }
  else
  {
    cout << "UNABLE TO OVERWRITE FILE" << endl;
  }
}

void constroi_pilha(tLista *ptlista, tPilha *ptpilha)
{
  no *ptr = ptlista->lista;
  while (ptr != NULL)
  {
    if (ptr->pt_dcar->direcao == "Hidráulica")
    {
      pilha_push(ptpilha, ptr->pt_dcar);
    }
    ptr = ptr->prox;
  }
}

void constroi_fila(tLista *ptlista, tFila *ptfila)
{
  no *ptr = ptlista->lista;
  while (ptr != NULL)
  {
    if (ptr->pt_dcar->cambio == "Automático")
    {
      fila_push(ptfila, ptr->pt_dcar);
    }
    ptr = ptr->prox;
  }
}

void deleta_carros(tLista *ptlista)
{

  no *ant = ptlista->lista;
  no *pont = ptlista->lista;

  while (ant != NULL)
  {
    pont = ant->prox;
    delete (ant->pt_dcar);
    ant = pont;
  }

  cout << "-Os carros foram removidos." << endl;
}

int menu_db()
{
  int resposta;
  string in_placa;

  cout << "\n*----------MENU----------*" << endl;
  cout << "1 - Busca pela placa" << endl;
  cout << "2 - Inserir novo veículo" << endl;
  cout << "3 - Ordenar veículos" << endl;
  cout << "4 - Pilha de veículos com direção hidráulica" << endl;
  cout << "5 - Lista de veículos com câmbio automático" << endl;
  cout << "6 - Salvar alterações" << endl;
  cout << "7 - Relatorio" << endl;
  cout << "8 - Sair" << endl;
  cout << "SELECT AN OPTION: ";
  cin >> resposta;

  while (resposta <= 0 || resposta > 8 || cin.fail())
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

  ifstream bd_carros;
  bd_carros.open("cars.txt");
  if (bd_carros.is_open())
  {

    ptlista = inicia_lista();

    while (!bd_carros.eof())
    {

      dcar *novocarro = new dcar;

      bd_carros >> novocarro->modelo;
      bd_carros >> novocarro->marca;
      bd_carros >> novocarro->tipo;
      bd_carros >> novocarro->ano;
      bd_carros >> novocarro->km;
      bd_carros >> novocarro->potencia;
      bd_carros >> novocarro->combustivel;
      bd_carros >> novocarro->cambio;
      bd_carros >> novocarro->direcao;
      bd_carros >> novocarro->cor;
      bd_carros >> novocarro->portas;
      bd_carros >> novocarro->placa;
      bd_carros >> novocarro->valor;

      insere_fim(ptlista, novocarro);
    }
    bd_carros.close();

    if (ptlista->lista->pt_dcar->placa == "")
    {
      delete (ptlista->lista->pt_dcar);
      delete (ptlista->lista);
      ptlista->lista = NULL;
    }

    string placa_busca;
    int opt;
    ord_lista = inicia_lista();
    ptpilha = inicia_pilha();
    ptfila = inicia_fila();

    do
    {
      opt = menu_db();

      switch (opt)
      {
      case 1:
        if (ptlista->lista == NULL)
        {
          cout << "\nDATABASE IS EMPTY!" << endl;
        }
        else
        {
          cout << "Enter vehicle license plate: ";
          cin >> placa_busca;
          transform(placa_busca.begin(), placa_busca.end(), placa_busca.begin(), ::toupper);
          buscaCarro(ptlista, placa_busca);
        }

        break;

      case 2:
        insertCar(ptlista);
        break;

      case 3:
        if (ptlista->lista == NULL)
        {
          cout << "\n"
               << "Lista vazia!" << endl;
        }
        else
        {
          insere_ordenado(ptlista, ord_lista);
          imprime(ord_lista);
        }
        break;
      case 4:
        constroi_pilha(ptlista, ptpilha);
        if (ptpilha->lista == NULL)
        {
          cout << "Pilha vazia!" << endl;
        }
        else
        {
          imprime(ptpilha);
        }
        break;

      case 5:
        constroi_fila(ptlista, ptfila);
        if (ptfila->lista == NULL)
        {
          cout << "Fila vazia!" << endl;
        }
        else
        {
          imprime(ptfila);
        }
        break;

      case 6:
        saveFile(ptlista);
        break;

      case 7:
        if(ptlista->lista == NULL){
          cout << "\n Lista vazia!" << endl;
        } else {
          imprime(ptlista);
        }
        break;

      case 8:
        deleta_carros(ptlista);
        ptlista = encerra_lista(ptlista);
        ord_lista = encerra_lista(ord_lista);

        ptpilha = encerra_pilha(ptpilha);
        ptfila = encerra_fila(ptfila);
        break;

      default:
        break;
      }

    } while (opt != 8);
  }
  else
  {
    cout << "Não foi possível abrir o arquivo" << endl;
  }

  return 0;
}
