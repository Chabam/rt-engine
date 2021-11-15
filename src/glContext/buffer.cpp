#include "buffer.h"

Buffer::Buffer(const Coords &coords) : m_coords(coords)
{
    init();
}

Buffer::Buffer(const std::initializer_list<ClipCoord> &coords) : m_coords(coords)
{
    init();
}

void Buffer::init()
{
    glGenBuffers(1, &m_vertexBuffer);
    glGenVertexArrays(1, &m_vertexArray);

    glBindVertexArray(m_vertexArray);
    glBindBuffer(GL_ARRAY_BUFFER, m_vertexBuffer);

    glBufferData(GL_ARRAY_BUFFER, m_coords.size() * sizeof(GLfloat) * 2, m_coords.data(), GL_STATIC_DRAW);

    glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 2 * sizeof(GLfloat), (void *)0);
    glEnableVertexAttribArray(0);
}

void Buffer::render() const
{
    static const float black[] = {0.0f, 0.0f, 0.0f, 0.0f};
    glClearBufferfv(GL_COLOR, 0, black);

    glBindVertexArray(m_vertexArray);
    glDrawArrays(GL_TRIANGLES, 0, m_coords.size());
}