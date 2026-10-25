#pragma once

#include "loaders/textureloader.h"
#include "input/input.h"
#include "graphics/renderer.h"

class SceneManager;

class SceneTemplate
{
public:
    SceneTemplate(
        TextureLoader& textureLoader,
        Input& input,
        Renderer& renderer,
        SceneManager& sceneManager
    );

    virtual ~SceneTemplate() = default;

    virtual void Start();
    virtual void Update(float deltaTime);
    void Exit();

protected:
    TextureLoader& _textureLoader;
    Input& _input;
    Renderer& _renderer;
    SceneManager& _sceneManager;
};