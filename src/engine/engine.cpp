#include "engine.h"
#include "logger/logger.h"
#include <functional>

Engine::Engine(Window &window, Shader &shader) : m_window(window), m_shader(shader)
{
}

void Engine::init()
{
    LOG_INFO("Starting program!");

    // GLFW
    m_window.init();
    {
        using namespace std::placeholders;
        m_window.setKeyPressCallback(std::bind(Engine::handleKeyPress, this, _1));
        m_window.setResizeCallback(std::bind(Engine::handleResize, this, _1, _2));
    }

    m_shader.init();
}

void Engine::start()
{
    if (m_buffers.empty())
    {
        LOG_WARN("No buffers to draw!");
        return;
    }


    while (!m_window.shouldClose())
    {
        render();
        glfwPollEvents();
    }

}

void Engine::render()
{
    glClear(GL_COLOR_BUFFER_BIT);

    for (const Buffer &buffer : m_buffers)
    {
        buffer.render();
    }

    m_window.swapBuffers();
}

void Engine::addBuffers(const std::vector<Buffer> &buffers)
{
    m_buffers.insert(m_buffers.end(), buffers.begin(), buffers.end());
}

void Engine::addBuffer(const Buffer &buffer)
{
    m_buffers.push_back(buffer);
}

void Engine::handleKeyPress(Engine* engine, int keyCode)
{
    switch (keyCode)
    {
    case GLFW_KEY_Q:
        engine->m_window.setToClose();
        break;
    }
}

void Engine::handleResize(Engine *engine, int width, int height)
{
    engine->m_window.setSize(width, height);
    engine->render();
}