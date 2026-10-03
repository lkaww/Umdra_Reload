#include "core/engine.h"
#include "graphics/vertex.h"

#include <pspctrl.h>
#include <pspgu.h>

#include "graphics/animation.h"
#include "graphics/texture.h"
#include "loaders/textureloader.h"

void Engine::Init()
{
    running = true;

    renderer.Init();
    input.Init();

    //YOUR INIT CODE HERE//
}

void Engine::Run()
{
    float deltaTime = 0.0166f;

    while (running)
    {
        input.Update();

        if (input.IsPressed(PSP_CTRL_HOME))
            running = false;
        
        renderer.BeginFrame();

        //YOUR RENDER CODE HERE//
        
        renderer.EndFrame();
    }
}

void Engine::Shutdown()
{
    renderer.Shutdown();
}