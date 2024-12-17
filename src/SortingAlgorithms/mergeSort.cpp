#include "../../include/raylib.h"
#include "../../include/draw.hpp"
#include "../../include/sortingAlgorithms.hpp"
#include <algorithm>
#include <thread>
#include <chrono>

int merge (int v[], int begin, int end, int size, int screenHeight)
{
    int middle = (begin + end) / 2,  i = begin, j = middle + 1, indexNewArray;

    int *newArray = (int*)malloc(sizeof(int) * (end - begin + 1));

    if (!newArray)
    {
        return -1;
    }

    indexNewArray = 0;

    while (j <= end && i <= middle)
    {
        if (v[i] > v[j]) 
        {
            newArray[indexNewArray++] = v[j++];
        } 
        else 
        {
            newArray[indexNewArray++] = v[i++];
        }

        if (IsKeyPressed(KEY_ESCAPE)) 
        {
            return -1;
        }

        drawIteration (v, size, screenHeight, i, j, RED);
    }

    while (i <= middle) 
    {
        newArray[indexNewArray++] = v[i++];

        if (IsKeyPressed(KEY_ESCAPE)) 
        {
            return -1;
        }

        drawIteration (v, size, screenHeight, i, j, RED);
    }

    while (j <= end) 
    {
        newArray[indexNewArray++] = v[j++];

        if (IsKeyPressed(KEY_ESCAPE)) 
        {
            return -1;
        }

        drawIteration (v, size, screenHeight, i, j, RED);
    }

    indexNewArray = 0;

    for (int ind = begin; ind <= end; ind++) 
    {
        v[ind] = newArray[indexNewArray++];
    }

    free(newArray);

    return 0;
}


int mergeSort (int v[], int begin, int end, int size, int screenHeight)
{
    if (begin < end)
    {
        int middle = (begin + end) / 2;

        if (mergeSort(v, begin, middle, size, screenHeight) == -1)
        {
            return -1;
        }

        if (mergeSort(v, middle + 1, end, size, screenHeight) == -1)
        {
            return -1;
        }

        if (merge(v, begin, end, size, screenHeight) == -1)
        {
            return -1;
        }
    }

    return 0;
}