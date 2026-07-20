#include "core/engine.h"
#include "graphics/vertex.h"

#include <pspctrl.h>
#include <pspgu.h>

#include "graphics/texture.h"
#include "graphics/textureloader.h"

void Engine::Init()
{
    running = true;

    renderer.Init();
    input.Init();
}

void Engine::Run()
{
    while (running)
    {
        input.Update();

        if (input.IsPressed(PSP_CTRL_START))
            running = false;

        renderer.BeginFrame();
        renderer.EndFrame();
    }
}

void Engine::Shutdown()
{
    renderer.Shutdown();
}