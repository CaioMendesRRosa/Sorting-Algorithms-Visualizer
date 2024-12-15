#include "../include/raylib.h"
#include "../include/sortingAlgorithms.hpp"
#include "../include/draw.hpp"
#include <stdlib.h>
#include <algorithm>
#include <iostream>
#include <thread>
#include <chrono>
#include <random>

int main(void)
{
    int screenWidth = 1920, size = screenWidth / 2, screenHeight = 1080;
    int *v = (int*)malloc(sizeof(int) * size);
    auto urng = std::default_random_engine {};

    if (!v) 
    {
        exit(1);
    }

    for (int i = 0; i < size; i++)
    {
        v[i] = i+1;
    }


    std::shuffle (v, v + size, urng);

    InitWindow(screenWidth, 1080, "Sorting Algorithms Visualizer");
    ToggleFullscreen();
    SetTargetFPS(10000);

    while (!WindowShouldClose())
    {
        BeginDrawing();
            ClearBackground(BLACK);
            drawArray(v, size, screenHeight, WHITE);
        EndDrawing();

        std::this_thread::sleep_for(std::chrono::milliseconds(1000));

        if (selectionSort(v, size, screenHeight) == -1)
        {
            break;
        }

        drawArrayOrdered(v, size, screenHeight);

        std::this_thread::sleep_for(std::chrono::milliseconds(1500));
    }

    CloseWindow();

    return 0;
}