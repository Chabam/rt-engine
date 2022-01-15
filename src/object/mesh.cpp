#include "object/mesh.h"

static const std::vector<Vertice> getVerticesFromTriangles(const std::vector<Triangle> &triangles)
{
    std::vector<Vertice> vertices;
    for (const Triangle &triangle : triangles)
    {
        vertices.insert(vertices.begin(), {triangle.m_p1, triangle.m_p2, triangle.m_p3});
    }
    return vertices;
}

Mesh::Mesh(const std::vector<Triangle> &triangles)
    : m_triangles(triangles), m_buffer(getVerticesFromTriangles(triangles))
{
}

Mesh::Mesh(const Mesh &other) : m_triangles(other.m_triangles), m_buffer(getVerticesFromTriangles(other.m_triangles))
{
}

Mesh &Mesh::operator=(const Mesh &other)
{
    m_triangles = other.m_triangles;
    m_buffer = Buffer(getVerticesFromTriangles(other.m_triangles));

    return *this;
}

uint32_t Mesh::getTriangleCount() const
{
    return m_triangles.size();
}