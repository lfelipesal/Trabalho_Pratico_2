#pragma once
#include <iostream>

template <typename T, typename Comparar>
void mergeSort(T *arr, int tamanho, Comparar comp);

template <typename T, typename Comparar>
void merge(T *arr, int esquerda, int meio, int direita, Comparar comp);