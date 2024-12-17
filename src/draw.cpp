#include "../include/raylib.h"
#include "../include/draw.hpp"


void drawArray (int v[], int size, int screenHeight, Color color) 
{
    for (int i = 0; i <= size; i++) 
    {
        DrawRectangle(widthPlot * i, screenHeight - v[i], widthPlot, v[i], color);
    }
}


void drawArrayOrdered (int v[], int size, int screenHeight) 
{
    for (int i = 0; i <= size; i++) 
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
        DrawRectangle(widthPlot * j, screenHeight - v[j], widthPlot, v[j], color);
        DrawRectangle(widthPlot * i, screenHeight - v[i], widthPlot, v[i], color);

        if (j > 0)
        {
            DrawRectangle(widthPlot * (j - 1), screenHeight - v[j - 1], widthPlot, v[j - 1], color);
        }
        if (j < size)
        {
            DrawRectangle(widthPlot * (j + 1), screenHeight - v[j + 1], widthPlot, v[j + 1], color);
        }

        if (i > 0)
        {
            DrawRectangle(widthPlot * (i - 1), screenHeight - v[i - 1], widthPlot, v[i - 1], color);
        }
        if (i < size)
        {
            DrawRectangle(widthPlot * (i + 1), screenHeight - v[i + 1], widthPlot, v[i + 1], color);
        }
    EndDrawing();
}