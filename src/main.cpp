#include "engine/engine.h"
#include "logger/logger.h"
#include "object/cube.h"
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

        // clang-format off
        Cube cube;
        engine.setMeshes({cube});
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
