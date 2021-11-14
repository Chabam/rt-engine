#include <GL/glew.h>
#include <fstream>
#include <sstream>
#include <string>

class Shader
{
  public:
    Shader(const char *vertPath, const char *fragPath);
    ~Shader();
    void init();
    void reload();

  private:
    const char *m_vertPath;
    const char *m_fragPath;
    GLuint m_vertUid;
    GLuint m_fragUid;
    GLuint m_programUid;

    void load();

    static const std::string readFromFile(const char *relativePath);
    static void compileShaderSource(GLuint &shaderUid, GLenum type, const GLchar *source);
};