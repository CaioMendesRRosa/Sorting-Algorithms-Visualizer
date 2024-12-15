#include "../../include/raylib.h"
#include "../../include/draw.hpp"
#include "../../include/sortingAlgorithms.hpp"
#include <algorithm>
#include <thread>
#include <chrono>


int partition(int v[], int begin, int end, int size, int screenHeight) 
{
    int pivot, pos = begin + ( rand() % (end - begin + 1) );
 
    std::swap(v[begin], v[pos]);

    pos = begin;
    pivot = v[begin];

    for (int i = begin + 1; i <= end; i++) 
    {
        if (v[i] < pivot) 
        {
            pos = pos + 1;

            if (i != pos) 
            {
                std::swap(v[i], v[pos]);
            }
        }

        if (IsKeyPressed(KEY_ESCAPE)) 
        {
                return -1;
        }

        // Draw comparisons value in Red
        drawIteration (v, size, screenHeight, begin, i, RED);

    }

    std::swap(v[begin], v[pos]);

    drawIteration (v, size, screenHeight, begin, pos, GREEN);

    std::this_thread::sleep_for(std::chrono::milliseconds(1));

    return pos;
}


int quickSort(int v[], int begin, int end, int size, int screenHeight) 
{
    if (begin < end) 
    {
        int pivot = partition(v, begin, end, size, screenHeight);

        if (pivot == -1)
        {
            return -1;
        }

        if (quickSort(v, begin, pivot - 1, size, screenHeight) == -1)
        {
            return -1;
        }

        if (quickSort(v, pivot + 1, end, size, screenHeight) == -1)
        {
            return -1;
        }
    }

    return 1;
}