#include "object/mesh.h"
#include <algorithm>

Mesh::Mesh(const std::vector<Triangle> &triangles)
    : m_triangles(triangles)
{
}

Mesh::Mesh(const Mesh &other) : m_triangles(other.m_triangles)
{
}

Mesh &Mesh::operator=(const Mesh &other)
{
    m_triangles = other.m_triangles;

    return *this;
}

std::vector<Vertice> Mesh::getVertices() const
{
    std::vector<Vertice> vertices;
    for (const Triangle &triangle : m_triangles)
    {
        vertices.insert(vertices.begin(), {triangle.m_p1, triangle.m_p2, triangle.m_p3});
    }
    return vertices;
}

uint32_t Mesh::getTriangleCount() const
{
    return m_triangles.size();
}