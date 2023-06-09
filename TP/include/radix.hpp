#pragma once
#include <iostream>

template <typename T, typename Comparar>
void countingSort(T *arr, int tamanho, int exp, Comparar comp);

template <typename T, typename Comparar>
void radixSort(T *arr, int tamanho, Comparar comp);