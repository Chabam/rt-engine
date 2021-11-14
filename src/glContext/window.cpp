#include "glContext/window.h"
#include "glContext/buffer.h"
#include "glContext/shader.h"
#include "logger/logger.h"
#include <math.h>

Window::Window(int width, int height, const char *title)
    : m_width(width), m_height(height), m_title(title), m_impl(nullptr)
{
}

Window::~Window()
{
    glfwTerminate();
}

void Window::setSize(int width, int height)
{
    m_width = width;
    m_height = width;
    glViewport(0, 0, m_width, m_height);
}

void Window::close()
{
    LOG_INFO("Closing window");
    glfwSetWindowShouldClose(m_impl, GLFW_TRUE);
}

void Window::handleKey(int key)
{
    switch (key)
    {
    case GLFW_KEY_Q:
        close();
        break;
    }
}

void Window::keyCallback(GLFWwindow *glfwWindow, int key, int scancode, int action, int mods)
{
    Window *window = static_cast<Window *>(glfwGetWindowUserPointer(glfwWindow));
    if (window == NULL)
    {
        LOG_ERROR("Provided pointer to window is NULL!");
        return;
    }

    if (action == GLFW_PRESS || action == GLFW_REPEAT)
    {
        window->handleKey(key);
    }
}

void Window::resizeCallback(GLFWwindow *glfwWindow, int width, int height)
{
    Window *window = static_cast<Window *>(glfwGetWindowUserPointer(glfwWindow));
    if (window == NULL)
    {
        LOG_ERROR("Provided pointer to window is NULL!");
        return;
    }

    window->setSize(width, height);
}

void Window::init()
{
    if (!glfwInit())
        throw std::runtime_error("Could not initialize GLWF!");

    m_impl = glfwCreateWindow(m_width, m_height, m_title, nullptr, nullptr);
    if (!m_impl)
    {
        glfwTerminate();
        throw std::runtime_error("Could not create a GLWF window!");
    }

    // Events
    glfwSetWindowUserPointer(m_impl, this);
    glfwSetKeyCallback(m_impl, keyCallback);
    glfwSetWindowSizeCallback(m_impl, resizeCallback);
    glfwMakeContextCurrent(m_impl);

    LOG_INFO("Window succesfully initialized");
}

void Window::display(std::vector<Buffer> buffers)
{
    while (!glfwWindowShouldClose(m_impl))
    {
        glClear(GL_COLOR_BUFFER_BIT);

        for (const Buffer &buffer : buffers)
        {
            buffer.render();
        }

        glfwSwapBuffers(m_impl);
        glfwPollEvents();
    }
}