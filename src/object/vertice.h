#pragma once
#include "object/color.h"

struct Vertice
{
    struct Coord
    {
        float x, y, z;
    };

    Coord m_coord;
    Color::RGB m_color = {255, 255, 255, 255};
};
