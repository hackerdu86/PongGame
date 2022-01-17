#pragma once
#include <sstream>
#include <string>
#include "include/raylib.h"

class Timer
{
private:
    char timeText[5];
    int lSideMinute = 0, rSideMinute = 0, lSideSecond = 0, rSideSecond = 0;
    int x = 470, y = 20;
    int fontSize = 35;
    int fps = 0;
public:
    Timer()
    {

    }
    void update()
    {
        fps++;
        if (fps == 60)
        {
            rSideSecond++;
            if (rSideSecond == 10)
            {
                rSideSecond = 0;
                lSideSecond++;
            }
            if (lSideSecond == 6)
            {
                rSideMinute++;
                lSideSecond = 0;
            }
            if (rSideMinute == 9)
            {
                rSideMinute = 0;
                lSideMinute++;
            }
            fps = 0;
        }

    }
    void draw()
    {
        timeText[0] = lSideMinute+48;
        timeText[1] = rSideMinute+48;
        timeText[2] = 58;
        timeText[3] = lSideSecond+48;
        timeText[4] = rSideSecond+48;
        
        DrawText(timeText, x, y, fontSize, BLACK);
    }
}; 