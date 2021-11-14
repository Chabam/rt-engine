#include "glContext/buffer.h"
#include "glContext/shader.h"
#include "glContext/window.h"
#include "logger/logger.h"

#include <stdexcept>
#include <array>
#include <vector>

int main(void)
{
    Window window(700, 400);
    Shader shader("../src/shaders/shader.vert", "../src/shaders/shader.frag");

    LOG_INFO("Starting program!");
    try
    {
        window.init();
        shader.init();
    }
    catch (std::runtime_error e)
    {
        LOG_ERROR("Exception thrown during initialization: " << e.what());
        return 1;
    }

    // clang-format off
    window.display({
        {
            {{-0.5f, -0.5f}},
            {{0.5f, -0.5f}},
            {{0.0f,  0.5f}},
        }
    });
    // clang-format on

    return 0;
}
