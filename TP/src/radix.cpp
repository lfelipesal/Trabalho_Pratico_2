#include "../include/radix.hpp"

template <typename T, typename Comparar>
void radixSort(T *arr, int tamanho, Comparar comp)
{
    T maior = arr[0];
    for (int i = 1; i < tamanho; ++i)
    {
        if (comp(arr[i], maior))
        {
            maior = arr[i];
        }
    }

    for (int exp = 1; maior / exp > 0; exp *= 10)
    {
        countingSort(arr, tamanho, exp, comp);
    }
}

template <typename T, typename Comparar>
void countingSort(T *arr, int tamanho, int exp, Comparar comp)
{
    const int BASE = 10;
    int contagem[BASE] = {0};
    T *resultado = new T[tamanho];

    for (int i = 0; i < tamanho; ++i)
    {
        contagem[(arr[i] / exp) % BASE]++;
    }

    for (int i = 1; i < BASE; ++i)
    {
        contagem[i] += contagem[i - 1];
    }

    for (int i = tamanho - 1; i >= 0; --i)
    {
        resultado[contagem[(arr[i] / exp) % BASE] - 1] = arr[i];
        contagem[(arr[i] / exp) % BASE]--;
    }

    for (int i = 0; i < tamanho; ++i)
    {
        arr[i] = resultado[i];
    }

    delete[] resultado;
}