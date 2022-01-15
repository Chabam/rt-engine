#include "buffer.h"

Buffer::Buffer(const std::vector<Vertice> &vertices)
{
    glGenBuffers(1, &m_VBO);
    glBindBuffer(GL_ARRAY_BUFFER, m_VBO);

    glGenVertexArrays(1, &m_VAO);
    glBindVertexArray(m_VAO);

    // Converting the vertice object to a flat array of GLfloat
    std::vector<VerticeData> verticesData;
    for (const Vertice &vertice : vertices)
    {
        Color::Normalized color = Color::normalize(vertice.m_color);
        // clang-format off
        verticesData.push_back(VerticeData{{
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
    const auto TOTAL_DATA_SIZE = sizeof(GLfloat) * VERTICES_COUNT * VERTICE_DATA_SIZE;
    const auto START_COORD = (void *)0;
    const auto START_COLOR = (void *)(2 * sizeof(GLfloat));

    // Coord at the start of the buffer
    glVertexAttribPointer(0, VERTICES_COUNT, GL_FLOAT, GL_FALSE, VERTICE_POINTER_SIZE, START_COORD);
    glEnableVertexAttribArray(0);

    // Color at the end
    glVertexAttribPointer(1, VERTICES_COUNT, GL_FLOAT, GL_FALSE, VERTICE_POINTER_SIZE, START_COLOR);
    glEnableVertexAttribArray(1);

    glBufferData(GL_ARRAY_BUFFER, TOTAL_DATA_SIZE, verticesData.data(), GL_STATIC_DRAW);
}

Buffer &Buffer::operator=(const Buffer &other)
{
    m_VAO = other.m_VAO;
    m_VBO = other.m_VBO;
}

Buffer::~Buffer()
{
    glDeleteBuffers(1, &m_VBO);
    glDeleteVertexArrays(1, &m_VAO);
}
