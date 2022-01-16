#include "buffer.h"
#include "logger/logger.h"

Buffer::Buffer(const std::vector<Vertice> &vertices)
{
    glGenBuffers(1, &m_VBO);
    glBindBuffer(GL_ARRAY_BUFFER, m_VBO);

    glGenVertexArrays(1, &m_VAO);
    glBindVertexArray(m_VAO);

    // Converting the vertice object to a flat array of GLfloat
    for (const Vertice &vertice : vertices)
    {
        Color::Normalized color = Color::normalize(vertice.m_color);
        // clang-format off
        m_data.push_back({{
            vertice.m_coord.x,
            vertice.m_coord.y,
            color[0], // r
            color[1], // g
            color[2], // b
            color[3]  // a
        }});
        // clang-format on
    }

    const auto VERTICES_COUNT = vertices.size();
    const auto TOTAL_DATA_SIZE = VERTICES_COUNT * VERTICE_DATA_SIZE * sizeof(GLfloat);
    const auto START_COORD = (void *)0;
    const auto START_COLOR = (void *)(COORD_DATA * sizeof(GLfloat));

    // Coord at the start of the buffer
    glVertexAttribPointer(0, COORD_DATA, GL_FLOAT, GL_FALSE, VERTICE_POINTER_SIZE, START_COORD);
    glEnableVertexAttribArray(0);

    // Color at the end
    glVertexAttribPointer(1, COLOR_DATA, GL_FLOAT, GL_FALSE, VERTICE_POINTER_SIZE, START_COLOR);
    glEnableVertexAttribArray(1);

    glBufferData(GL_ARRAY_BUFFER, TOTAL_DATA_SIZE, m_data.data(), GL_STATIC_DRAW);
}

Buffer::~Buffer()
{
    glDeleteBuffers(1, &m_VBO);
    glDeleteVertexArrays(1, &m_VAO);
}
