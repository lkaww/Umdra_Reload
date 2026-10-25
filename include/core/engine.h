#pragma once

#include "graphics/renderer.h"
#include "input/input.h"
#include "loaders/textureloader.h"
#include "scene/scene_manager.h"

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
        TextureLoader textureLoader;
        SceneManager sceneManager;
};