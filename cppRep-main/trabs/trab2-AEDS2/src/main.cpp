#include <iostream>
#include <fstream>
#include <string>
#include <climits>   //menu
#include <algorithm> //transform

#include "../src/include/list.h"
#include "../src/include/queue.h"
#include "../src/include/stack.h"

using namespace std;

// Cabeçalhos para as listas desenvolvidas.
tLista *ptlista;
tLista *ord_lista;

tQueue *ptfila;

tStack *ptpilha;

/**
 * @brief Realiza a função de busca na lista principal, caso seja requisitado pelo usuário, remove um veículo encontrado.
 *
 * @param lista  endereco do cabeçalho da lista principal.
 * @param plate placa fornecida pelo usuário.
 */
void buscaCarro(tLista *lista, string plate)
{
  no *find_car = busca(lista, plate);
  if (find_car != NULL)
  {
    string resposta;
    cout << "\n >" << find_car->pt_dcar->marca << " " << find_car->pt_dcar->modelo << " FOUND!"
         << endl;
    cout << "Do you want to remove this car?(y/n)?: ";
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
      cout << "\nVehicle removed successfully!\n"
           << "*--------------✓------------*" << endl;

      delete (car_removed->pt_dcar);
      delete (car_removed);
    }
  }
  else
  {

    cout << "\n\tVEHICLE NOT FOUND!"
         << "\n--------------X--------------" << endl;
  }
}

/**
 * @brief Realiza a leitura dos dados fornecidos pelo usuário, fornecendo o endereço da nova struct alocada, para a função insere_fim.
 *
 * @param ptlista endereco do cabeçalho da lista principal.
 * @return int retorna 1 se for possivel inserir e 0 caso contrario.
 */
int insertCar(tLista *ptlista)
{
  string nova_placa;
  cout << "\n Insert vehicle license plate: ";
  cin >> nova_placa;
  transform(nova_placa.begin(), nova_placa.end(), nova_placa.begin(), ::toupper);

  if (busca(ptlista, nova_placa) != NULL)
  {
    cout << "\nVEHICLE ALREADY IN DATABASE!\n"
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
    cout << "Gas: ";
    cin >> novo_carro->combustivel;
    cout << "Transmission: ";
    cin >> novo_carro->cambio;
    cout << "Steering: ";
    cin >> novo_carro->direcao;
    cout << "Color: ";
    cin >> novo_carro->cor;
    cout << "Doors: ";
    cin >> novo_carro->portas;
    cout << "Price: ";
    cin >> novo_carro->valor;

    insere_fim(ptlista, novo_carro);

    cout << "\nVEHICLE STORED SUCCESSFULLY!\n"
         << "*--------------✓------------*\n";

    return 1;
  }
  return 0;
}

/**
 * @brief Insere de forma ordenada os elementos da lista principal, em uma nova lista, com auxílio de uma busca de forma ordenada.
 *
 * @param ptlista endereco do cabeçalho. Nesse caso da lista principal.
 * @param ordenado endereço do cabeçalho. Nesse caso, da lista ordenada.
 */
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
    search_sorted(ordenado, placa, &ant, &pont);
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

/**
 * @brief Reescreve no arquivo (banco de dados), as alterações(se realizadas) na lista principal durante a execução do programa.
 *
 * @param ptlista endereco do cabeçalho. Nesse caso da lista principal.
 */
void saveFile(tLista *ptlista)
{
  ofstream car_database;
  car_database.open("./cars.txt");
  if (car_database.is_open())
  {
    if (ptlista->lista == NULL)
    {
      car_database << "";
      cout << "\nDATABASE UPDATED!"
           << "\n*--------------✓------------*" << endl;
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
    cout << "COULD NOT BE ABLE TO OVERWRITE DATA!" << endl;
  }
}

/**
 * @brief Construção de uma stack com base na lista principal, por meio de uma busca realizada na mesma. Caso um veículo possua direção hidráulica, este é inserido no topo da queue. Nessa stack, utiliza-se o método de inserir no começo.
 *
 * @param ptlista endereco do cabeçalho. Nesse caso da lista principal.
 * @param ptpilha endereço de um cabeçalho. Nesse caso da stack a ser construída.
 */
void constroi_pilha(tLista *ptlista, tStack *ptpilha)
{
  no *ptr = ptlista->lista;
  while (ptr != NULL)
  {
    if (ptr->pt_dcar->direcao == "Hidráulica")
    {
      stack_push(ptpilha, ptr->pt_dcar);
    }
    ptr = ptr->prox;
  }
}

/**
 * @brief Construção de uma queue com base na lista princpal, por meio de uma busca realizada na mesma. Caso um veículo possua câmbio automático, este é inserido no final da queue. Nessa queue, utiliza-se o método de inserir no fim e as remoções ocorrem no inicio.
 *
 * @param ptlista endereco do cabeçalho. Nesse caso da lista principal.
 * @param ptfila endereço de um cabeçalho. Nesse caso da stack a ser construída.
 */
void constroi_fila(tLista *ptlista, tQueue *ptfila)
{
  no *ptr = ptlista->lista;
  while (ptr != NULL)
  {
    if (ptr->pt_dcar->cambio == "Automático")
    {
      queue_push(ptfila, ptr->pt_dcar);
    }
    ptr = ptr->prox;
  }
}

/**
 * @brief Desaloca as struct dos carros.
 *
 * @param ptlista endereco do cabeçalho.
 */
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

  cout << "\n✓ - All vehicles were removed!" << endl;
}

/**
 * @brief Função que realiza uma interface com o usuário.
 *
 * @return int retorna a opcao selecionada.
 */
int menu_db()
{
  int resposta;
  string in_placa;

  cout << "\n*----------MENU----------*" << endl;
  cout << "1 - Search by license plate" << endl;
  cout << "2 - Insert new car" << endl;
  cout << "3 - Sort vehicles by license plate" << endl;
  cout << "4 - Stack of vehicles with hydraulic steering" << endl;
  cout << "5 - Queue of vehicles with automatic transmission" << endl;
  cout << "6 - Save changes" << endl;
  cout << "7 - Main list log" << endl;
  cout << "8 - Quit" << endl;
  cout << "SELECT AN OPTION: ";
  cin >> resposta;

  while (resposta <= 0 || resposta > 8 || cin.fail())
  {
    cin.clear();
    cin.ignore(INT_MAX, '\n');
    cout << "SELECT AN AVAILABLE OPTION: ";
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
    cout << "\n Starting main list ..." << endl;
    ptlista = start_list();

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
      ptlista->tam = 0;
    }

    string placa_busca;
    int opt;

    cout << "\n Starting sorted list..." << endl;
    ord_lista = start_list();
    cout << "\n Starting stack ..." << endl;
    ptpilha = start_stack();
    cout << "\n Starting queue ..." << endl;
    ptfila = start_queue();

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
          cout << "INSERT VEHICLE LICENSE PLATE: ";
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
          cout << "\n\tEMPTY LIST!"
               << "\n--------------X--------------" << endl;
        }
        else
        {
          insere_ordenado(ptlista, ord_lista);
          cout << "\n ------SORTED LIST:\n"
               << endl;
          imprime(ord_lista);
        }
        break;
      case 4:
        constroi_pilha(ptlista, ptpilha);
        if (ptpilha->lista == NULL)
        {
          cout << "\n\tEMPTY STACK!"
               << "\n--------------X--------------" << endl;
        }
        else
        {
          cout << "\n ------STACK OF HYDRAULIC STEERING VEHICLES: \n"
               << endl;
          imprime(ptpilha);
        }
        break;

      case 5:
        constroi_fila(ptlista, ptfila);
        if (ptfila->lista == NULL)
        {
          cout << "\n\tEMPTY QUEUE!"
               << "\n--------------X--------------" << endl;
        }
        else
        {
          cout << "\n ------QUEUE OF AUTOMATIC TRANSMISSION VEHICLES:\n"
               << endl;
          imprime(ptfila);
        }
        break;

      case 6:
        saveFile(ptlista);
        break;

      case 7:
        if (ptlista->lista == NULL)
        {
          cout << "\n\tEMPTY LIST!"
               << "\n--------------X--------------" << endl;
        }
        else
        {
          cout << "\n ------MAIN LIST LOG:\n"
               << endl;
          imprime(ptlista);
        }
        break;

      case 8:
        cout << "\n Leaving application...\n"
             << endl;
        cout << "\n Deallocating vehicles..." << endl;
        deleta_carros(ptlista);
        cout << "\n Deallocating main list..." << endl;
        ptlista = end_list(ptlista);
        cout << "\n Deallocating sorted list..." << endl;
        ord_lista = end_list(ord_lista);

        cout << "\n Deallocating stack..." << endl;
        ptpilha = end_stack(ptpilha);

        cout << "\n Deallocating queue..." << endl;
        ptfila = end_queue(ptfila);
        cout << "\n Application finished\n"
             << endl;
        break;

      default:
        break;
      }

    } while (opt != 8);
  }
  else
  {
    cout << "Could not be able to open data file!" << endl;
  }

  return 0;
}
