#include "../include/Ponto.hpp"
#include "../include/Pilha.hpp"
#include "../include/merge.hpp"
#include "../include/insertion.hpp"
#include "../include/radix.hpp"

Point pivot;
// retorna -1 se a -> b -> c forma uma volta no sentido anti-horário,
// +1 para um giro no sentido horário, 0 se forem colineares
int ccw(Point a, Point b, Point c)
{
    int area = (b.x - a.x) * (c.y - a.y) - (b.y - a.y) * (c.x - a.x);
    if (area > 0)
        return -1;
    else if (area < 0)
        return 1;
    return 0;
}

// retorna o quadrado da distância euclidiana entre dois pontos
int sqrDist(Point a, Point b)
{
    int dx = a.x - b.x, dy = a.y - b.y;
    return dx * dx + dy * dy;
}

// usado para classificar pontos de acordo com a ordem polar w.r.t o pivô
bool POLAR_ORDER(Point a, Point b)
{
    int order = ccw(pivot, a, b);
    if (order == 0)
        return sqrDist(pivot, a) < sqrDist(pivot, b);
    return (order == -1);
}

Pilha<Point> grahamScan(Point *points, int N, int tipo)
{
    Pilha<Point> hull;

    if (N < 3)
        return hull;

    // encontra o ponto com a menor coordenada y (pivot),
    // empates são quebrados em favor da coordenada x inferior
    int leastY = 0;
    for (int i = 1; i < N; i++)
        if (points[i] < points[leastY])
            leastY = i;

    // troque o pivô com o primeiro ponto
    Point temp = points[0];
    points[0] = points[leastY];
    points[leastY] = temp;

    // classificar o ponto restante de acordo com a ordem polar sobre o pivô
    pivot = points[0];
    // tipo 1 utiliza o mergesort, tipo 2 utiliza o insertion sort e o tipo 3 o Radix
    if (tipo == 1)
    {
        mergeSort(points, N, POLAR_ORDER);
    }
    else if (tipo == 2)
    {
        insertionSort(points, N, POLAR_ORDER);
    }
    else if (tipo == 3)
    {
        radixSort(points, N, POLAR_ORDER);
    }
    else
        std::cout << "Algoritmo de ordenação não foi classificado para esse indice." << std::endl;

    hull.empilhar(points[0]);
    hull.empilhar(points[1]);
    hull.empilhar(points[2]);

    for (int i = 3; i < N; i++)
    {
        Point top = hull.topo();
        hull.desempilhar();
        while (ccw(hull.topo(), top, points[i]) != -1)
        {
            top = hull.topo();
            hull.desempilhar();
        }
        hull.empilhar(top);
        hull.empilhar(points[i]);
    }
    return hull;
}
