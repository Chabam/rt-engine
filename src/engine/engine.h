#include "glContext/buffer.h"
#include "glContext/shader.h"
#include "glContext/window.h"
#include "object/mesh.h"
#include <vector>
class Engine
{
  public:
    Engine(const Window &window, const Shader &shader);

    void init();
    void setMeshes(const std::vector<Mesh> &meshes);
    void start();

  private:
    Window m_window;
    Shader m_shader;
    uint64_t m_triangleCount;
    std::vector<std::pair<Mesh, Buffer>> m_renderTargets;

    void render();
    static void handleKeyPress(Engine *engine, int keyCode);
    static void handleResize(Engine *engine, int width, int height);
    static void APIENTRY handleGlError(GLenum source, GLenum type, GLuint id, GLenum severity, GLsizei length,
                                       const GLchar *message, const void *userParam);
};