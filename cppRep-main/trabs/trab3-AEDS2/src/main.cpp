/*
 * File:   main.cpp
 * Author: otaviofbrito
 *
 * Created on December 2, 2022, 5:29 PM
 *
 * TRABALHO 2 - AEDS II - Gerenciador de Busca de Carros, Vans e Utilitários
 NOMES: OTAVIO FERREIRA DE BRITO SILVEIRA - 2022.1.08.023
        ALICIA GARNIER DUARTE FRANCO - 2022.1.08.001


 A aplicação desenvolvida nesse trabalho, a partir da leitura do banco de dados, constrói uma lista dinâmica principal, na ordem apresentada pelo arquivo. A aplicação disponibibiliza, para o usuário as opções de:
 Realizar a busca por um veículo, com opção de inserção e remoção.
 Ordenação dos veículos presentes nessa lista principal, a partir da construção de uma nova lista, que insere de maneira ordenada os veículos da lista principal para a ordenada.
 Construção de listas dinâmicas estruturadas na forma de fila ou pilha, conforme os resquisitos.
 */

#include <cstdlib>

#include <iostream>
#include <fstream>
#include <string>

#include <climits>   //menu
#include <algorithm> //transform

#include "../src/include/lista.h"
#include "../src/include/arvorebin.h"
#include "../src/include/arvoreavl.h"

using namespace std;

// Cabeçalhos para as listas desenvolvidas.
tLista *ptlista;
noArv *ptArvoreBin = NULL;
noArvAvl *ptArvoreAvl = NULL;

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
    cout << "\n >" << find_car->pt_dcar->marca << " " << find_car->pt_dcar->modelo << " ENCONTRADO!"
         << endl;
    cout << "Você deseja remover esse veículo (s/n)?: ";
    cin >> resposta;
    transform(resposta.begin(), resposta.end(), resposta.begin(), ::tolower);
    while (resposta != "s" && resposta != "n")
    {
      cout << "SELECIONE UMA OPÇÃO VÁLIDA! ";
      cin >> resposta;
      transform(resposta.begin(), resposta.end(), resposta.begin(), ::tolower);
    }
    if (resposta == "s")
    {
      no *car_removed = remove_enc(lista, plate);
      // remover da arvore Avl:
      if (ptArvoreAvl != NULL && car_removed->pt_dcar->cambio == "Manual")
      {
        ptArvoreAvl = deletar_noAvl(ptArvoreAvl, car_removed);
        cout << "\nVeículo removido com sucesso da arvore Avl!\n"
             << "*--------------✓------------*" << endl;
      }

      // remover da arvore Binaria:
      if (ptArvoreBin != NULL && car_removed->pt_dcar->direcao == "Hidraulica")
      {
        ptArvoreBin = removeArvBin(ptArvoreBin, car_removed);
        cout << "\nVeículo removido com sucesso da arvore Binária!\n"
             << "*--------------✓------------*" << endl;
      }

      cout << "\nVeículo removido com sucesso da lista principal!\n"
           << "*--------------✓------------*" << endl;

      delete (car_removed->pt_dcar);
      delete (car_removed);
    }
  }
  else
  {

    cout << "\n\tVEÍCULO NÃO ENCONTRADO!"
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
  cout << "\nInsira a placa do veículo: ";
  cin >> nova_placa;
  transform(nova_placa.begin(), nova_placa.end(), nova_placa.begin(), ::toupper);

  if (busca(ptlista, nova_placa) != NULL)
  {
    cout << "\nVEÍCULO JÁ EXISTENTE!\n"
         << "------------------------" << endl;
    return 0;
  }
  else
  {
    dcar *novo_carro = new dcar;
    novo_carro->placa = nova_placa;
    cout << "Modelo: ";
    cin >> novo_carro->modelo;
    cout << "Marca: ";
    cin >> novo_carro->marca;
    cout << "Tipo: ";
    cin >> novo_carro->tipo;
    cout << "Ano: ";
    cin >> novo_carro->ano;
    cout << "KMs: ";
    cin >> novo_carro->km;
    cout << "Potência: ";
    cin >> novo_carro->potencia;
    cout << "Combustível: ";
    cin >> novo_carro->combustivel;
    cout << "Câmbio: ";
    cin >> novo_carro->cambio;
    cout << "Direção: ";
    cin >> novo_carro->direcao;
    cout << "Cor: ";
    cin >> novo_carro->cor;
    cout << "Portas: ";
    cin >> novo_carro->portas;
    cout << "Preço: ";
    cin >> novo_carro->valor;

    no *no_novo_carro = insere_fim(ptlista, novo_carro);

    cout << "\nVEÍCULO INSERIDO COM SUCESSO NA LISTA PRINCIPAL!\n"
         << "*--------------✓------------*\n";

    // Alocar o carro na arvore binaria de acordo com o tipo de direção:
    if (ptArvoreBin != NULL && novo_carro->direcao == "Hidraulica")
    {
      ptArvoreBin = insere_noBin(ptArvoreBin, no_novo_carro);
    }

    if (ptArvoreAvl != NULL && novo_carro->cambio == "Manual")
    {
      ptArvoreAvl = insere_noAvl(ptArvoreAvl, no_novo_carro);
    }

    return 1;
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
      cout << "\nBANCO DE DADOS ATUALIZADO! (VAZIO)"
           << "\n*--------------✓------------*" << endl;
    }
    else
    {

      no *ptr = ptlista->lista;
      while (ptr->prox != NULL)
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
        car_database << ptr->pt_dcar->valor << endl;
        ptr = ptr->prox;
      }
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
      car_database << ptr->pt_dcar->valor;

      car_database.close();
      cout << "\nBANCO DE DADOS ATUALIZADO!"
           << "\n*--------------✓------------*" << endl;
    }
  }
  else
  {
    cout << "Não foi possível sobrescrever o arquivo!" << endl;
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

  cout << "\n✓ - Os carros foram removidos." << endl;
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
  cout << "1 - Busca pela placa" << endl;
  cout << "2 - Inserir novo veículo" << endl;
  cout << "3 - Arvore binaria - !" << endl;
  cout << "4 - Arvore AVL - !" << endl;
  cout << "5 - Relatorio arvores" << endl;
  cout << "6 - Salvar alterações" << endl;
  cout << "7 - Relatorio" << endl;
  cout << "8 - Sair" << endl;
  cout << "SELECIONE UMA OPÇÃO: ";
  cin >> resposta;

  while (resposta <= 0 || resposta > 8 || cin.fail())
  {
    cin.clear();
    cin.ignore(INT_MAX, '\n');
    cout << "SELECIONE UMA OPÇÃO VÁLIDA: ";
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
    cout << "\n Iniciando lista principal ..." << endl;
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
      ptlista->tam = 0;
    }

    int altura_arvore;
    string placa_busca;
    int opt;

    do
    {
      opt = menu_db();

      switch (opt)
      {
      case 1:
        if (ptlista->lista == NULL)
        {
          cout << "\nBANCO DE DADOS ESTÁ VAZIO!" << endl;
        }
        else
        {
          cout << "Insira a placa do veículo: ";
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
          cout << "\nNAO FOI POSSIVEL CRIAR ARVORE BINARIA: BANCO DE DADOS ESTÁ VAZIO!" << endl;
        }
        else
        {
          if (ptArvoreBin == NULL)
          {
            no *pont = ptlista->lista;
            while (pont != NULL)
            {
              if (pont->pt_dcar->direcao == "Hidraulica")
              {
                ptArvoreBin = insere_noBin(ptArvoreBin, pont);
              }
              pont = pont->prox;
            }

            pre_ordemBin(ptArvoreBin);
            altura_arvore = alturaBin(ptArvoreBin);
            cout << "\nÁrvore binária de altura : " << altura_arvore << " criada!" << endl;
          }
          else
          {
            altura_arvore = alturaBin(ptArvoreBin);
            cout << "\nÁrvore binária de altura : " << altura_arvore << " ja foi criada!" << endl;
            pre_ordemBin(ptArvoreBin);
          }
        }
        break;

      case 4:
        if (ptlista->lista == NULL)
        {
          cout << "\nNAO FOI POSSIVEL CRIAR ARVORE AVL: BANCO DE DADOS ESTÁ VAZIO!" << endl;
        }
        else
        {
          if (ptArvoreAvl == NULL)
          {
            no *pont = ptlista->lista;
            while (pont != NULL)
            {
              if (pont->pt_dcar->cambio == "Manual")
              {
                ptArvoreAvl = insere_noAvl(ptArvoreAvl, pont);
              }
              pont = pont->prox;
            }

            pre_ordemAvl(ptArvoreAvl);
            altura_arvore = alturaAvl(ptArvoreAvl);
            cout << "\nÁrvore AVL de altura : " << altura_arvore << " criada!" << endl;
          }
          else
          {
            altura_arvore = alturaAvl(ptArvoreAvl);
            cout << "\nÁrvore AVL de altura : " << altura_arvore << " ja foi criada!" << endl;
            pre_ordemAvl(ptArvoreAvl);
          }
        }
        break;

      case 5:
        cout << "RELATORIO ARVORES" << endl;
        break;

      case 6:
        saveFile(ptlista);
        break;

      case 7:
        if (ptlista->lista == NULL)
        {
          cout << "\n\tLISTA VAZIA!"
               << "\n--------------X--------------" << endl;
        }
        else
        {
          cout << "\n ------RELATÓRIO LISTA PRINCIPAL:\n"
               << endl;
          imprime(ptlista);
        }
        break;

      case 8:
        cout << "\n Saindo da aplicação...\n"
             << endl;
        cout << "\n Desalocando carros..." << endl;
        deleta_carros(ptlista);
        cout << "\n Desalocando lista principal..." << endl;
        ptlista = encerra_lista(ptlista);

        encerra_arvoreBin(ptArvoreBin);
        cout << "Arvore binaria encerrada" << endl;

        encerra_arvoreAvl(ptArvoreAvl);
        cout << "Arvore Avl encerrada" << endl;

        cout << "\n Aplicação encerrada\n"
             << endl;
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