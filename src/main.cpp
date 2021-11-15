#include "engine/engine.h"
#include "logger/logger.h"

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
        engine.addBuffer({
            {{-0.5f, -0.5f}},
            {{0.5f, -0.5f}},
            {{0.0f, 0.5f}},
        });
        engine.start();
    }
    catch (std::runtime_error e)
    {
        LOG_ERROR("Engine failed: " << e.what());
        return 1;
    }

    return 0;
}
