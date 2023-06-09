#pragma once
#include <iostream>
#include <string>
#include <cstring>

class Point
{
public:
    int x, y;

    //  a comparação é feita primeiro na coordenada y e depois na coordenada x
    bool operator<(Point b)
    {
        if (y != b.y)
            return y < b.y;
        return x < b.x;
    }
};
