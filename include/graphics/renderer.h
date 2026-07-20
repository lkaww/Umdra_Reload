#pragma once

#include "graphics/texture.h"

class Renderer
{
public:
    void Init();
    void BeginFrame();

    void DrawText(const char* text);
    void DrawTexture(Texture * texture, float x, float y, float w, float h);

    void EndFrame();
    void Shutdown();
};