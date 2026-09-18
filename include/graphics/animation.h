#pragma once

#include <vector>
#include "graphics/texture.h"

class Animation
{
public:
    std::vector<Texture*> sprites;
    float frameDuration;

    void Update(float deltaTime);

    Texture* GetCurrentFrame();

    void Reset();

private:
    size_t currentFrame = 0;
    float timer = 0.0f;
};
