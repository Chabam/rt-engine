#include "object/triangle.h"

Triangle::Triangle(const Vertice &p1, const Vertice &p2, const Vertice &p3) : m_p1(p1), m_p2(p2), m_p3(p3)
{
}

Triangle::Triangle(const Triangle& other): m_p1(other.m_p1), m_p2(other.m_p2), m_p3(other.m_p3)
{
}

Triangle& Triangle::operator=(const Triangle& other)
{
	m_p1 = other.m_p1;
	m_p2 = other.m_p2;
	m_p3 = other.m_p3;

	return *this;
}