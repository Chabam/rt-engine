#include "engine/engine.h"
#include "logger/logger.h"
#include "object/triangle.h"
#include "object/vertice.h"

#include <array>
#include <stdexcept>
#include <vector>

int main(void)
{
    // clang-format off
    Engine engine(
        Window(800, 800),
        Shader("../src/shaders/shader.vert", "../src/shaders/shader.frag")
    );
    // clang-format on
    try
    {
        engine.init();
        const Color::RGB RED = {255, 0, 0};
        const Color::RGB GREEN = {0, 255, 0};
        const Color::RGB BLUE = {0, 0, 255};

        // clang-format off
        Triangle triangle(
            {{-0.5f, -0.5f, 0.f}, RED},
            {{0.5f, -0.5f, 0.f}, GREEN},
            {{0.0f, 0.5f, 0.f}, BLUE}
        );
        engine.setMeshes({Mesh({triangle})});
        // clang-format on
        engine.start();
    }
    catch (const std::runtime_error& e)
    {
        LOG_ERROR("Engine failed: " << e.what());
        return 1;
    }

    return 0;
}
