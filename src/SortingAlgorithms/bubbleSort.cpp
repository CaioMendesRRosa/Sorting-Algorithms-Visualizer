#include "../../include/raylib.h"
#include "../../include/draw.hpp"
#include "../../include/sortingAlgorithms.hpp"
#include <algorithm>


int bubbleSort (int v[], int size, int screenHeight)
{
    for (int i = 0; i < size; i++)
    {
        for (int j = 1; j < size - i; j++)
        {
            if (v[j] < v[j - 1])
            {   
                std::swap(v[j - 1], v[j]);
            }

            if (IsKeyPressed(KEY_ESCAPE)) 
            {
                return -1;
            }

            drawIteration (v, size, screenHeight, j - 1, j, RED);
        }
    }
    
    return 0;
}