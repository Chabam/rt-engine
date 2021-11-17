#pragma once
#include "glContext/buffer.h"
#include "object/vertice.h"
#include <vector>

class Object
{
  public:
    typedef std::vector<Vertice> Vertices;
    Object(Vertices vertices = Vertices());

    void addVertice(const Vertice& vertice);
    void addVertices(const Vertices &vertices);

  private:
    Vertices m_vertices;
    Buffer m_buffer;
};