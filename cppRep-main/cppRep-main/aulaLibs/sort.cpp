#include <iostream>
#include "sort.h"

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
    int aux, *q;
    for (int *p = vet + 1; p < vet + 10; p++)
    {
        aux = *p;
        q = p - 1;
        while (q >= vet && *q > aux)
        {
            *(q + 1) = *q;
            q--;
        }
        *(q+1) = aux;
    }
}