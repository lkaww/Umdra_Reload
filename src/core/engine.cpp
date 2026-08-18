#include "core/engine.h"
#include "graphics/vertex.h"

#include <pspctrl.h>
#include <pspgu.h>

#include "graphics/texture.h"
#include "loaders/textureloader.h"
#include "graphics/animation.h"

void Engine::Init()
{
    running = true;

    renderer.Init();
    input.Init();
    isDraw = true;
}

void Engine::Run()
{
    while (running)
    {
        input.Update();

        if (input.IsPressed(PSP_CTRL_START))
            running = false;
        
        renderer.BeginFrame();

        if (isDraw)
            renderer.DrawTexture(playerTexture, 240 - playerTexture->width / 2, 136 - playerTexture->height / 2, playerTexture->width, playerTexture->height);
        
        if (input.IsPressed(PSP_CTRL_CROSS))
        {
            isDraw = false;
            textureLoader.UnloadTexture(playerTexture);
        }
        
        renderer.EndFrame();
    }
}

void Engine::Shutdown()
{
    renderer.Shutdown();
}