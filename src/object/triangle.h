#pragma once
#include "object/vertice.h"

class Triangle
{
  public:
    Triangle(const Vertice &p1, const Vertice &p2, const Vertice &p3);
    Triangle(const Triangle &other);
    Triangle& operator=(const Triangle &other);

    Vertice m_p1;
    Vertice m_p2;
    Vertice m_p3;
};