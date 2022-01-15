#include "engine.h"
#include "logger/logger.h"
#include <functional>

Engine::Engine(const Window &window, const Shader &shader) : m_window(window), m_shader(shader), m_triangleCount(0)
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
    if (m_triangleCount == 0)
    {
        LOG_WARN("Nothing to draw!");
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

    static Color::Normalized BLACK = {0.0f, 0.0f, 0.0f, 0.0f};
    glClearBufferfv(GL_COLOR, 0, BLACK.data());

    // Might want to move that to the objects if we want to selectively render them!
    glDrawArrays(GL_TRIANGLES, 0, m_triangleCount);

    m_window.swapBuffers();
}

void Engine::setMeshes(const std::vector<Mesh> &meshes)
{
    m_meshes = meshes;

    for (const Mesh& mesh : m_meshes)
    {
        m_triangleCount += mesh.getTriangleCount() * 3;
    }
}

void Engine::handleKeyPress(Engine* engine, int keyCode)
{
    switch (keyCode)
    {
    case GLFW_KEY_Q:
        LOG_INFO("Closing!");
        engine->m_window.setToClose();
        break;
    }
}

void Engine::handleResize(Engine *engine, int width, int height)
{
    engine->m_window.setSize(width, height);
    engine->render();
}