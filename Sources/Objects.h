#pragma once

#include "Defines.h"

struct Plate
{
    float StartX() const
    {
        return x;
    }

    float EndX() const
    {
        return x + PLATE_WIDTH;
    }

    float TopY() const
    {
        return y;
    }

    float BottomY() const
    {
        return y + 14;
    }

    float x, y; // virsutinio kairiojo kampo koordinates
};

struct Player
{
    Player(float coordX, float coordY)
    {
        x = coordX;
        y = coordY;
    }

    float LegsStartX() const
    {
        return x + 20;
    }

    float LegsEndX() const
    {
        return x + 60;
    }

    float LegsY() const
    {
        return y + 70;
    }

    float x, y; // virsutinio kairiojo kampo koordinates
};
