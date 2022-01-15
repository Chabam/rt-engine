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
    static const auto COORD_DATA = 2; // x, y
    static const auto COLOR_DATA = 4; // r, g, b, a
    static const auto VERTICE_DATA_SIZE = COORD_DATA + COLOR_DATA;
    static const auto VERTICE_POINTER_SIZE = VERTICE_DATA_SIZE * sizeof(GLfloat);
    typedef std::array<GLfloat, VERTICE_DATA_SIZE> VerticeData;

    Buffer(const std::vector<Vertice> &vertices);
    ~Buffer();

  private:
    GLuint m_VBO;
    GLuint m_VAO;
};
