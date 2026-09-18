#include <vector>

#include "graphics/animation.h"

void Animation::Update(float deltaTime)
{
    timer += deltaTime;

    if (timer >= frameDuration)
    {
        timer -= frameDuration;

        currentFrame++;

        if (currentFrame >= sprites.size())
            currentFrame = 0;
    }
}

Texture* Animation::GetCurrentFrame()
{
    return sprites[currentFrame];
}

void Animation::Reset()
{
    currentFrame = 0;
    timer = 0.0f;
}