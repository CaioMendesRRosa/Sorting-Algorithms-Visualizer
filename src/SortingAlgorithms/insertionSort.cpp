#include "../../include/raylib.h"
#include "../../include/draw.hpp"
#include "../../include/sortingAlgorithms.hpp"
#include <algorithm>
#include <iostream>


int insertionSort (int v[], int size, int screenHeight)
{
    int aux, j;

    for (int i = 1; i < size; i++)
    {
        aux = v[i];
        j = i - 1;

        while (j >= 0 && aux < v[j])
        {
            v[j + 1] = v[j];

            if (IsKeyPressed(KEY_ESCAPE)) 
            {
                return -1;
            }

            drawIteration (v, size, screenHeight, j, j + 1, RED);
            
            j--;
        }

        v[j + 1] = aux;

        drawIteration (v, size, screenHeight, j + 1, i, RED);
    }
    
    return 0;
}