#pragma once
#define PONGHEIGHT 100
#define PONGWIDTH 20
#include <stdlib.h>
#include "include/raylib.h"
#include "pongs.cpp"
class Ball
{
private:
    int direction = rand() % 4 + 1;
    const int veclocity = 5;
    const float radius = 8.0f;
    int xWhenCollided = 500, yWhenCollided = 300;
    int x = 500, y = 300;
    int time = 0;
    bool hasEverCollided = false;

public:
    Vector2 cercleVector{(float)x, (float)y};
    char scoreHandling()
    {
        if (x == 0)
        {   
            x = 500;
            y = 300;
            direction = rand() % 4 + 1;
            return 'l';
        }
        if (x == 1000)
        {
            x = 500;
            y = 300;
            direction = rand() % 4 + 1;
            return 'r';
        }
        return 'n';
    }
    void collisionHandling(int yPongA, int yPongB)
    {
        if (y == 0)
        {
            if (x > xWhenCollided)
            {
                direction = 4;
                xWhenCollided = x;
                yWhenCollided = y;
            }
            else
            {
                direction = 3;
                xWhenCollided = x;
                yWhenCollided = y;
            }
        }
        if (y == 600)
        {
            if (x > xWhenCollided)
            {
                direction = 2;
                xWhenCollided = x;
                yWhenCollided = y;
            }
            else
            {
                direction = 1;
                xWhenCollided = x;
                yWhenCollided = y;
            }
        }
        if (x == 120 && y >= yPongA && y <= yPongA + PONGHEIGHT)
        {
            if (y > yWhenCollided)
            {
                direction = 4;
                yWhenCollided = y;
                xWhenCollided = x;
            }
            else
            {
                direction = 2;
                yWhenCollided = y;
                xWhenCollided = x;
            }
        }
        if (x == 880 && y >= yPongB && y <= yPongB + PONGHEIGHT)
        {
            if (y > yWhenCollided)
            {
                direction = 3;
                yWhenCollided = y;
                xWhenCollided = x;
            }
            else
            {
                direction = 1;
                yWhenCollided = y;
                xWhenCollided = x;
            }
        }
    }
    void update()
    {
        switch (direction)
        {
            case 1:
                x -= veclocity;
                y -= veclocity;
                break;
            case 2:
                x += veclocity;
                y -= veclocity;
                break;
            case 3:
                x -= veclocity;
                y += veclocity;
                break;
            case 4:
                x += veclocity;
                y += veclocity;
                break;
        }
    }
    void draw()
    {
        DrawCircle(x, y, radius, BLACK);
    }

};