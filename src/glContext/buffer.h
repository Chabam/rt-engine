#pragma once
#include "object/color.h"
#include "object/vertice.h"
#include <GL/glew.h>
#include <array>
#include <initializer_list>
#include <vector>

class Buffer
{
  public:
    static const auto VERTICE_DATA_SIZE = 2 + 4; // x, y, r, g, b, a
    static const auto VERTICE_POINTER_SIZE = VERTICE_DATA_SIZE * sizeof(GLfloat);
    typedef std::array<GLfloat, VERTICE_DATA_SIZE> VerticeData;

    Buffer();
    Buffer(const std::vector<Vertice> &vertices);
    virtual ~Buffer();
    Buffer &operator=(const Buffer &other);

  private:
    GLuint m_VBO;
    GLuint m_VAO;
};
