#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <exception>
#include <vector>

class Buffer;

class Window
{
  public:
    Window(int width, int height, const char *title = "rt-engine");
    ~Window();

    void init();
    void display(std::vector<Buffer> buffers);
    void close();
    void setSize(int width, int height);

  private:
    int m_width;
    int m_height;
    const char *m_title;
    GLFWwindow *m_impl;
    void handleKey(int key);

    static void keyCallback(GLFWwindow *glfwWindow, int key, int scancode, int action, int mods);
    static void resizeCallback(GLFWwindow *glfwWindow, int with, int height);
};