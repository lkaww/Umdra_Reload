#include "core/engine.h"

#include <pspctrl.h>

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

        if (input.IsPressed(PSP_CTRL_HOME))
            running = false;

        renderer.BeginFrame();
        renderer.EndFrame();
    }
}

void Engine::Shutdown()
{
    renderer.Shutdown();
}