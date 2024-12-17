#include "../../include/raylib.h"
#include "../../include/draw.hpp"
#include "../../include/sortingAlgorithms.hpp"
#include <algorithm>
#include <iostream>


int countingSort (int v[], int size, int screenHeight)
{
    int *vAux, greatestValue = 0, indexV = 0;


    for (int i = 0; i < size; i++)
    {
        if (greatestValue < v[i])
        {
            greatestValue = v[i];
        }

        if (IsKeyPressed(KEY_ESCAPE)) 
        {
            return -1;
        }

        drawIteration (v, size, screenHeight, i, i, RED);
    }

    vAux = (int*)calloc((greatestValue + 1), sizeof(int));

    if (!vAux)
    {
        return -1;
    }

    for (int i = 0; i < size; i++)
    {
        vAux[v[i]]++;

        if (IsKeyPressed(KEY_ESCAPE)) 
        {
            return -1;
        }

        drawIteration (v, size, screenHeight, i, i, RED);
    }


    for (int i = 0; i <= greatestValue; i++)
    {
        while (vAux[i] != 0)
        {
            v[indexV++] = i;

            vAux[i]--;
        }

        if (IsKeyPressed(KEY_ESCAPE)) 
        {
            return -1;
        }

        drawIteration (v, size, screenHeight, i, i, RED);
    }

    free(vAux);

    return 0;
}