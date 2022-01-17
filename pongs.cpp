#pragma once
#include "include/raylib.h"

//Class that defines Pong bars their propreties and how they work
class Pongs
{
private:
    const int velocity = 10;
    int x = 100, y = 250;
    int up, down;
    int pongHeight = 100, pongWidth = 20;
    char side;
public:
    char getPongSide() const
    {
        return this->side;
    }
    int getXPos()
    {
        return x;
    }
    int getYPos()
    {
        return y;
    }
    Rectangle rec{(float)x, (float)y, (float)pongHeight, (float)pongWidth};

    Pongs(char _side) : side(_side)
    {
        if (side == 'l')
        {
            up = KEY_W;
            down = KEY_S;
        }
        else
        {
            up = KEY_UP;
            down = KEY_DOWN;
            x = 880;
        }
    };
    Pongs(const Pongs &pong) 
    {
        
    }
    //Update the pong x and y verticies based on user input (up and down for right W and S for left)
    void update()
    {
        if (IsKeyDown(up) && y >= 0)
            y -= velocity;
            
        if (IsKeyDown(down) && y <= 500)
            y += velocity;
        
    }
    void draw()
    {
        DrawRectangle(x, y, pongWidth, pongHeight, BLACK);
    }
};