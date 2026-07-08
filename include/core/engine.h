#pragma once

#include "graphics/renderer.h"
#include "input/input.h"

class Engine
{
public:
    void Init();
    void Run();
    void Shutdown();

private:
    bool running;    
    Renderer renderer;
    Input input;
};