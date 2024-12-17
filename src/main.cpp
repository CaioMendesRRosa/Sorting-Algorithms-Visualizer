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
    int screenWidth = 1920, size = screenWidth / 2, screenHeight = 1080, option, shouldExit = 0, firstIteration = 1;
    int *v = (int*)malloc(sizeof(int) * size);
    auto urng = std::default_random_engine {};

    if (!v) 
    {
        exit(1);
    }

    for (int i = 0; i < size; i++)
    {
        v[i] = i + 1;
    }

    std::cout << "This is a program that allows you to visualize the process of ordering of the most popular sorting algorithms\n\n";
    std::cout << "When in the window visualization, press ESC to exit the program\n\n";

    std::this_thread::sleep_for(std::chrono::milliseconds(1000));

    while (!shouldExit)
    {
        std::cout << "Choose one of the following algorithms\n0 - Exit\n1 - Selection Sort\n2 - Merge Sort\n3 - Quick Sort\n4 - Bubble Sort\n";

        std::cin >> option;

        if (option == 0)
        {
            break;
        }

        if (option < 0 || option > 4)
        {
            std::cout << "Invalid option\n";
            break;
        }

        std::shuffle (v, v + size, urng);

        InitWindow(screenWidth, screenHeight, "Sorting Algorithms Visualizer");

        if (firstIteration)
        {
            // If ToggleFullscreen is used after the first iteration, it will exit out of fullscreen
            ToggleFullscreen();
            firstIteration = 0;
        }

        BeginDrawing();
            ClearBackground(BLACK);
            drawArray(v, size, screenHeight, WHITE);
        EndDrawing();

        std::this_thread::sleep_for(std::chrono::milliseconds(700));

        switch (option)
        {
        case 1:
            SetTargetFPS(30000);
            shouldExit = selectionSort(v, size, screenHeight);
            break;  
        
        case 2:
            SetTargetFPS(300);
            shouldExit = mergeSort(v, 0, size - 1, size, screenHeight);
            break;
        
        case 3:
            SetTargetFPS(300);
            shouldExit = quickSort(v, 0, size - 1, size, screenHeight);
            break;

        case 4:
            SetTargetFPS(30000);
            shouldExit = bubbleSort(v, size, screenHeight);
            break;

        default:
            break;
        }

        if (!shouldExit && option != 0)
        {
            drawArrayOrdered(v, size, screenHeight);
            std::this_thread::sleep_for(std::chrono::milliseconds(700));
        }

        CloseWindow();
    }

    return 0;
}