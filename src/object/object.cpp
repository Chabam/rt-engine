#include "object/object.h"

Object::Object(Vertices vertices) : m_vertices(vertices), m_buffer(vertices)
{
}

void Object::addVertices(const Vertices &vertices)
{
    m_vertices.insert(m_vertices.end(), vertices.begin(), vertices.end());
    m_buffer = Buffer(m_vertices);
}

void Object::addVertice(const Vertice &vertice)
{
    m_vertices.push_back(vertice);
    m_buffer = Buffer(m_vertices);
}