#include "object/mesh.h"
#include <algorithm>

Mesh::Mesh(const std::vector<Triangle> &triangles) : m_triangles(triangles), m_model(1.f)
{
}

Mesh::Mesh(const Mesh &other) : m_triangles(other.m_triangles)
{
}

Mesh::Mesh() : m_triangles(), m_model(1.f)
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
        vertices.insert(vertices.begin(), {triangle.m_p[0], triangle.m_p[1], triangle.m_p[2]});
    }
    return vertices;
}

uint32_t Mesh::getTriangleCount() const
{
    return m_triangles.size();
}

const glm::mat4 &Mesh::getModel() const
{
    return m_model;
}

void Mesh::applyTransformation(const glm::mat4 &trans)
{
    m_model = trans;
}

const std::vector<Triangle> &Mesh::getTriangles() const
{
    return m_triangles;
}