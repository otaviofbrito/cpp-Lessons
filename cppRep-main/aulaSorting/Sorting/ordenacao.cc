#include <iostream>

void imprimevetor(int *v)
{
    for (int *p = v; p < v + 10; p++)
    {
        std::cout << " " << *p;
    }
    std::cout << std::endl;
}

void bubblesort(int *vet)
{
    int aux;
    for (int *p = vet + 9; p > vet; p--)
    {
        for (int *q = vet; q < p; q++)
        {
            if (*q > *(q + 1))
            {
                aux = *q;
                *q = *(q + 1);
                *(q + 1) = aux;
            }
        }
    }
}

void insertionsort(int *vet)
{
    int aux;
    int *q;
    for (int *p = vet + 1; p < vet + 10; p++)
    {
        aux = *p;
        q = (p - 1);
        while (q >= vet && *q > aux)
        {
            *(q + 1) = *q;
            q--;
        }
        *(q + 1) = aux;
    }
}

void selectionsort(int *vet)
{
    int aux, *q, *min;
    for (int *p = vet; p < vet + 10; p++)
    {
        min = p;
        aux = *p;
        for (q = p + 1; q < vet + 10; q++)
        {
            if (*q < aux)
            {
                aux = *q;
                min = q;
            }
        }
        *min = *p;
        *p = aux;
    }
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
    selectionsort(vb1);
    imprimevetor(vb1);

    return 0;
}
