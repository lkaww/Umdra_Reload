#pragma once

#include "graphics/vertex.h"

class Renderer
{
public:
    void Init();
    void BeginFrame();

    void Draw(const Vertex* vertex);
    void DrawText(const char* text);

    void EndFrame();
    void Shutdown();
};