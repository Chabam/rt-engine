#include "glContext/buffer.h"
#include "glContext/shader.h"
#include "glContext/window.h"
#include <vector>

class Engine
{
  public:
    Engine(Window &window, Shader &shader);

    void init();
    void addBuffer(const Buffer &buffer);
    void addBuffers(const std::vector<Buffer> &buffers);
    void start();

  private:
    Window m_window;
    Shader m_shader;
    std::vector<Buffer> m_buffers;
    
    void render();
    static void handleKeyPress(Engine* engine, int keyCode);
    static void handleResize(Engine *engine, int width, int height);
};