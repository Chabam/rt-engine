#include "glContext/buffer.h"
#include "glContext/shader.h"
#include "glContext/window.h"
#include "object/object.h"
#include <vector>
class Engine
{
  public:
    Engine(const Window& window, const Shader &shader);

    void init();
    void addTriangles(const uint64_t &triangleCount);
    void start();

  private:
    Window m_window;
    Shader m_shader;
    uint64_t m_triangleCount;

    void render();
    static void handleKeyPress(Engine *engine, int keyCode);
    static void handleResize(Engine *engine, int width, int height);
};