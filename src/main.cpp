#include "engine/engine.h"
#include "logger/logger.h"
#include "object/quad.h"
#include "object/vertice.h"

#include <array>
#include <stdexcept>
#include <vector>

int main(void)
{
    // clang-format off
    Engine engine(
        Shader("../src/shaders/shader.vert", "../src/shaders/shader.frag")
    );
    // clang-format on
    try
    {
        engine.init();
        const Color::RGB RED = {255, 0, 0};
        const Color::RGB GREEN = {0, 255, 0};
        const Color::RGB BLUE = {0, 0, 255};
        const Color::RGB YELLOW = {255, 255, 0};

        // clang-format off
        Quad quad(
            {{0.5f, -0.5f, 0.f}, RED},
            {{0.5f, 0.5f, 0.f}, GREEN},
            {{-0.5f, 0.5f, 0.f}, BLUE},
            {{-0.5f, -0.5f, 0.f}, YELLOW}
        );
        engine.setMeshes({quad});
        // clang-format on
        engine.start();
    }
    catch (const std::runtime_error& e)
    {
        LOG_ERROR(e.what());
        return 1;
    }

    return 0;
}
