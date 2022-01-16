#include "object/quad.h"

Quad::Quad(const Vertice &p1, const Vertice &p2, const Vertice &p3, const Vertice &p4)
    : Mesh({Triangle(p1, p2, p3), Triangle(p1, p3, p4)}), m_p1(p1), m_p2(p2), m_p3(p3), m_p4(p4)
{
}

Quad::Quad(const Quad &other)
    : Mesh({Triangle(other.m_p1, other.m_p2, other.m_p3), Triangle(other.m_p1, other.m_p3, other.m_p4)}),
      m_p1(other.m_p1), m_p2(other.m_p2), m_p3(other.m_p3), m_p4(other.m_p4)
{
}

Quad &Quad::operator=(const Quad &other)
{
    m_p1 = other.m_p1;
    m_p2 = other.m_p2;
    m_p3 = other.m_p3;
    m_p4 = other.m_p4;

    return *this;
}