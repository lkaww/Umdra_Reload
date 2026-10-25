#include "core/engine.h"

#include <pspctrl.h>
#include <psprtc.h>

void Engine::Init()
{
    running = true;

    renderer.Init();
    input.Init();
    sceneManager.Setup(textureLoader, input, renderer);
}

void Engine::Run()
{
    //DELTA TIME INIT
    u32 res = sceRtcGetTickResolution();

    u64 curTick;
    u64 lastTick;

    sceRtcGetCurrentTick(&lastTick);

    while (running)
    {
        input.Update();

        //DELTA TIME UPDATE
        sceRtcGetCurrentTick(&curTick);

        u64 deltaTicks = curTick - lastTick;

        float deltaTime = (float)deltaTicks / (float)res;

        lastTick = curTick;

        if (input.IsPressed(PSP_CTRL_HOME))
            running = false;
        
        renderer.BeginFrame();

        sceneManager.Update(deltaTime);
        
        renderer.EndFrame();
    }
}

void Engine::Shutdown()
{
    sceneManager.Shutdown();
    renderer.Shutdown();
}