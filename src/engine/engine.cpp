#include "engine.h"
#include "config.h"
#include "logger/logger.h"
#include <chrono>
#include <functional>
#include <thread>

Engine::Engine(const Shader &shader, const Window &window) : m_window(window), m_shader(shader), m_fps(60)
{
}

Engine::RenderTarget::RenderTarget(const Mesh &mesh, Buffer &&buffer) : m_mesh(mesh), m_buffer(std::move(buffer))
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

    glEnable(GL_DEBUG_OUTPUT);
    glDebugMessageCallback(handleGlError, nullptr);
}

void Engine::start()
{
    if (m_renderTargets.empty())
    {
        LOG_WARN("Nothing to draw!");
        return;
    }

    while (!m_window.shouldClose())
    {
        typedef std::chrono::duration<double, std::milli> miliseconds;
        using namespace std::chrono_literals;
        auto beforeRender = std::chrono::system_clock::now();

        render();
        glfwPollEvents();

        auto afterRender = std::chrono::system_clock::now();
        miliseconds elapsed = afterRender - beforeRender;
        const miliseconds maxTimePerFrame(1000ms / m_fps);

        std::this_thread::sleep_for(maxTimePerFrame - elapsed);
    }
}

void Engine::render()
{
    static Color::Normalized BLACK = {0.0f, 0.0f, 0.0f, 0.0f};
    glClearBufferfv(GL_COLOR, 0, BLACK.data());

    glClear(GL_COLOR_BUFFER_BIT);

    for (RenderTarget &renderTarget : m_renderTargets)
    {
        m_shader.bind();
        m_shader.setUniforms(renderTarget.m_mesh.getModel(), VIEW_MATRIX, PROJECTION_MATRIX);
        renderTarget.m_mesh.applyTransformation(glm::rotate(rotation, glm::normalize(glm::vec3(1.f, 1.f, 1.f))));
        glDrawArrays(GL_TRIANGLES, 0, renderTarget.m_mesh.getTriangleCount() * 3);
        m_shader.unbind();
    }
    rotation += (m_fps) / 360.f;

    m_window.swapBuffers();
}

void Engine::setMeshes(const std::vector<Mesh> &meshes)
{
    for (const Mesh &mesh : meshes)
    {
        m_renderTargets.emplace_back(mesh, mesh.getVertices());
    }
}

void Engine::handleKeyPress(Engine *engine, int keyCode)
{
    switch (keyCode)
    {
    case GLFW_KEY_Q:
        LOG_INFO("Closing!");
        engine->m_window.setToClose();
        break;
    case GLFW_KEY_R:
        LOG_INFO("Reloading shaders");
        engine->m_shader.reload();
        break;
    }
}

void Engine::handleResize(Engine *engine, int width, int height)
{
    engine->m_window.setSize(width, height);
    engine->PROJECTION_MATRIX = glm::perspective(glm::radians(90.f), static_cast<float>(width) / height, 0.1f, 100.0f);
    engine->render();
}

void Engine::handleGlError(GLenum source, GLenum type, GLuint id, GLenum severity, GLsizei length,
                           const GLchar *message, const void *userParam)
{
    switch (severity)
    {
    case GL_DEBUG_SEVERITY_HIGH:
        LOG_ERROR("OpenGL: " << message);
        break;
    case GL_DEBUG_SEVERITY_MEDIUM:
        LOG_WARN("OpenGL: " << message);
        break;
    default:
    case GL_DEBUG_SEVERITY_LOW:
    case GL_DEBUG_SEVERITY_NOTIFICATION:
        LOG_DEBUG("OpenGL: " << message);
        return;
    }

    throw std::runtime_error("OpenGL fatal error!");
}