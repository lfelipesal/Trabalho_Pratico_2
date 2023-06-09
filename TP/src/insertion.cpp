#include "../include/insertion.hpp"

template <typename T, typename Comparar>
void insertionSort(T *arr, int tamanho, Comparar comp)
{
    for (int i = 1; i < tamanho; ++i)
    {
        T chave = arr[i];
        int j = i - 1;

        while (j >= 0 && comp(chave, arr[j]))
        {
            arr[j + 1] = arr[j];
            j--;
        }

        arr[j + 1] = chave;
    }
}