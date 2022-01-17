//Made By Youva Chaou 2022-01-17

#include "include/raylib.h"
#include "pongs.cpp"
#include "ball.cpp"
#include "timer.cpp"

void checkForCollision();
void update();
void draw();

Pongs pong1('l');
Pongs pong2('r');
Ball *ball = new Ball();
Timer *timer = new Timer();
int lScore = 0;
int rScore = 0;
bool hasAnyOneWon = false;

int main(void)
{
    const int screenWidth = 1000;
    const int screenHeight = screenWidth/2+100;
    
    InitWindow(screenWidth, screenHeight, "Pong Game");
    SetTargetFPS(60);               
    while (!WindowShouldClose())    
    {   
        BeginDrawing();
            checkForCollision();
            update();
            draw();
        EndDrawing();
    }
    CloseWindow();
    return 0;
}
void checkForCollision()
{
    char a = ball->scoreHandling();
    ball->collisionHandling(pong1.getYPos(), pong2.getYPos());
    switch (a)
    {
        case 'l':
            lScore++;
            break;
        case 'r':
            rScore++;
            break;
        case 'n':
            break; 
    }
    if (lScore == 10)
        hasAnyOneWon = true;
    if (rScore == 10)
        hasAnyOneWon = true;
}
void update()
{
    timer->update();
    ball->update();
    pong1.update();
    pong2.update();
}
void draw()
{
    ClearBackground(WHITE);
    timer->draw();
    ball->draw();
    pong1.draw();
    pong2.draw();
} 
