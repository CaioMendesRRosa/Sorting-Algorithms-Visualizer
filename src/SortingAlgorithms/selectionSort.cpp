#include "../../include/raylib.h"
#include "../../include/draw.hpp"
#include "../../include/sortingAlgorithms.hpp"
#include <algorithm>
#include <thread>
#include <chrono>


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
            
            if (IsKeyPressed(KEY_ESCAPE)) {
                return -1;
            }

            // Draw comparisons value in Red
            BeginDrawing();
                ClearBackground(BLACK);
                drawArray(v, size, screenHeight, WHITE);
                DrawRectangle(2 * i, screenHeight - v[i], 2, v[i], RED);
                DrawRectangle(2 * j, screenHeight - v[j], 2, v[j], RED);
            EndDrawing();
        }
        std::swap(v[i], v[lowestIndex]);

        // Draw swaps values in Green
        BeginDrawing();
            ClearBackground(BLACK);
            drawArray(v, size, screenHeight, WHITE);
            DrawRectangle(2 * i, 0, 2, screenHeight, BLACK);
            DrawRectangle(2 * lowestIndex, 0, 2, screenHeight, BLACK);
            DrawRectangle(2 * i, screenHeight - v[lowestIndex], 2, v[lowestIndex], GREEN);
            DrawRectangle(2 * lowestIndex, screenHeight - v[i], 2, v[i], GREEN);
        EndDrawing();
    }

    return 1;
}