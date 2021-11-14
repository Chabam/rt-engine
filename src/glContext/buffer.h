#include <GL/glew.h>
#include <initializer_list>
#include <vector>
#include <array>

class Buffer
{
  public:
    typedef std::array<float, 3> ClipCoord;
    typedef std::vector<ClipCoord> Coords;

    Buffer(const Coords &coords);
    Buffer(const std::initializer_list<ClipCoord> &coords);

    void render() const;

  private:
    const Coords m_coords;
    GLuint m_vertexBuffer;
    GLuint m_vertexArray;
    void init();
};