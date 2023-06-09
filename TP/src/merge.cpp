#include "../include/merge.hpp"

template <typename T, typename Comparar>
void mergeSort(T *arr, int tamanho, Comparar comp)
{
    if (tamanho <= 1)
        return;

    int meio = tamanho / 2;

    mergeSort(arr, meio, comp);
    mergeSort(arr + meio, tamanho - meio, comp);

    merge(arr, 0, meio, tamanho - 1, comp);
}

template <typename T, typename Comparar>
void merge(T *arr, int esquerda, int meio, int direita, Comparar comp)
{
    int tamanho = direita - esquerda + 1;
    T *temp = new T[tamanho];

    int i = esquerda;
    int j = meio + 1;
    int k = 0;

    while (i <= meio && j <= direita)
    {
        if (comp(arr[i], arr[j]))
        {
            temp[k++] = arr[i++];
        }
        else
        {
            temp[k++] = arr[j++];
        }
    }

    while (i <= meio)
    {
        temp[k++] = arr[i++];
    }

    while (j <= direita)
    {
        temp[k++] = arr[j++];
    }

    for (int indice = 0; indice < tamanho; ++indice)
    {
        arr[esquerda + indice] = temp[indice];
    }

    delete[] temp;
}