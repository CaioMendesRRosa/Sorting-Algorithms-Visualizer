#include "../../include/raylib.h"
#include "../../include/draw.hpp"
#include "../../include/sortingAlgorithms.hpp"
#include <algorithm>


int heapify (int v[], int index, int size, int screenHeight, int maxSize)
{
    int leftChild = (index + 1) * 2 - 1;
    int rightChild = (index + 1) * 2;
    int max = index;

    if (size > rightChild)
    {
        if (v[max] < v[leftChild] && v[leftChild] > v[rightChild])
        {
            max = leftChild;
        }
        else if (v[max] < v[rightChild] && v[leftChild] <= v[rightChild])
        {
            max = rightChild;
        }
    }
    else if (size > leftChild && v[leftChild] > v[max])
    {
        max = leftChild;
    }

    if (IsKeyPressed(KEY_ESCAPE)) 
    {
        return -1;
    }

    drawIteration (v, maxSize, screenHeight, index, max, RED);

    if (max != index)
    {
        std::swap(v[index], v[max]);
        heapify(v, max, size, screenHeight, maxSize);
    }

    return 1;
}


int buildMaxHeap (int v[], int size, int screenHeight)
{
    for (int i = size / 2; i >= 0; i--)
    {
        if (heapify(v, i, size, screenHeight, size) == -1)
        {
            return -1;
        }
    }

    return 1;
}


int heapSort (int v[], int size, int screenHeight)
{
    if (buildMaxHeap(v, size, screenHeight) == -1)
    {
        return -1;
    }

    for (int i = 0; i < size; i++)
    {
        std::swap(v[0], v[size - 1 - i]);

        drawIteration (v, size, screenHeight, 0, size - 1 - i, RED);

        if (heapify(v, 0, size - 1 - i, screenHeight, size) == -1)
        {
            return -1;
        }
    }

    return 0;
}


