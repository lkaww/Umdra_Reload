#pragma once

#include "graphics/texture.h"

class TextureLoader
{
public:
    Texture* LoadTexture(const char* filename);
    void UnloadTexture(const Texture* texture);
};
