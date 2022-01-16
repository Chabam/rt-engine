#pragma once
#include "glContext/buffer.h"
#include "object/triangle.h"
#include "object/vertice.h"
#include <glm/glm.hpp>
#include <vector>

class Mesh
{
  public:
    Mesh(const std::vector<Triangle> &triangles);
    Mesh(const Mesh &other);
    Mesh &operator=(const Mesh &other);

    uint32_t getTriangleCount() const;
    std::vector<Vertice> getVertices() const;
    const glm::mat4 &getModel() const;
    void applyTransformation(const glm::mat4 &trans);

  private:
    std::vector<Triangle> m_triangles;
    glm::mat4 m_model;
};