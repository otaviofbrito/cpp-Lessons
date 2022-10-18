#include <iostream>
#include "sort.h"


void imprimevetor(int *v)
{
    for (int *p = v; p < v + 10; p++)
    {
        std::cout << " " << *p;
    }
    std::cout << std::endl;
}



int main(int argc, char const *argv[])
{

    std::cout << std::endl
              << "METODO DE ORDENACAO" << std::endl
              << std::endl;

    int vb0[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    int vb1[10] = {5, 8, 2, 0, 6, 9, 1, 4, 3, 7};
    int vb2[10] = {9, 8, 7, 6, 5, 4, 3, 2, 1, 0};

    /*std::cout << " Bubble Sort, vetor ordenado: " << std::endl;

    imprimevetor(vb1);
    bubblesort(vb1);
    imprimevetor(vb1); */

    std::cout << " Insertion Sort, vetor ordenado: " << std::endl;
    imprimevetor(vb1);
    bubblesort(vb1);
    imprimevetor(vb1);

    return 0;
}
