#include "../include/raylib.h"
#include "../include/draw.hpp"


void drawArray (int v[], int size, int screenHeight, Color color) 
{
    for (int i = 0; i < size; i++) 
    {
        DrawRectangle(2*i, screenHeight - v[i], 2, v[i], color);
    }
}


void drawArrayOrdered (int v[], int size, int screenHeight) 
{
    for (int i = 0; i < size; i++) 
    {
        BeginDrawing();
            ClearBackground(BLACK);
            drawArray(v, size, screenHeight, WHITE);
            drawArray(v, i, screenHeight, GREEN);
        EndDrawing();
    }
}


void drawIteration (int v[], int size, int screenHeight, int i, int j, Color color) 
{
    BeginDrawing();
        ClearBackground(BLACK);
        drawArray(v, size, screenHeight, WHITE);
        DrawRectangle(2 * j, screenHeight - v[j], 2, v[j], color);
        DrawRectangle(2 * i, screenHeight - v[i], 2, v[i], color);
    EndDrawing();
}