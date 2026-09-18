#pragma once

#include "graphics/texture.h"
#include "graphics/animation.h"

class Renderer
{
public:
    void Init();
    void BeginFrame();
    
    void DrawAnimation(Animation animation, float x, float y);

    void DrawTexture(Texture* texture, float x, float y, float w, float h);
    void DrawText(const char* text);

    void EndFrame();
    void Shutdown();
};