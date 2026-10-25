#pragma once

#include "graphics/texture.h"
#include <vector>

class TextureLoader
{
    public:
        Texture* LoadTexture(const char* filename);
        void UnloadTexture(Texture* texture);

        std::vector<Texture*> textures;
};
