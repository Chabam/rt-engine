#pragma once
#include "glContext/buffer.h"
#include "object/triangle.h"
#include "object/vertice.h"
#include <vector>

class Mesh
{
  public:
    Mesh(const std::vector<Triangle> &triangles);
    Mesh(const Mesh &other);
    Mesh &operator=(const Mesh &other);
    uint32_t getTriangleCount() const;

  private:
    std::vector<Triangle> m_triangles;
    Buffer m_buffer;
};