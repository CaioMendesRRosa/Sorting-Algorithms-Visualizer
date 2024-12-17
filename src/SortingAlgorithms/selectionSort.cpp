#include "../../include/raylib.h"
#include "../../include/draw.hpp"
#include "../../include/sortingAlgorithms.hpp"
#include <algorithm>


int selectionSort (int v[], int size, int screenHeight) 
{
    int lowestIndex;

    for (int i = 0; i < size; i++)
    {
        lowestIndex = i;
        for (int j = i + 1; j < size; j++) 
        {
            if (v[lowestIndex] > v[j]) 
            {
                lowestIndex = j;
            }
            
            if (IsKeyPressed(KEY_ESCAPE)) 
            {
                return -1;
            }

            // Draw comparisons value in Red
            drawIteration (v, size, screenHeight, i, j, RED);
        }
        std::swap(v[i], v[lowestIndex]);

        // Draw swaps values in Green
        drawIteration (v, size, screenHeight, i, lowestIndex, GREEN);
    }

    return 0;
}