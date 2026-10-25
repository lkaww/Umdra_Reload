#pragma once

#include <memory>
#include <vector>
#include <functional>

#include "scene/scene_template.h"

class SceneManager
{
public:
    void Setup(
        TextureLoader& textureLoader,
        Input& input,
        Renderer& renderer
    );

    void Update(float deltaTime);
    void Shutdown();

    void ChangeScene(std::unique_ptr<SceneTemplate> scene);
    void ChangeScene(int number);

private:
    void ApplyScene(std::unique_ptr<SceneTemplate> scene);

    std::unique_ptr<SceneTemplate> curScene;
    std::unique_ptr<SceneTemplate> pendingScene;

    std::vector<std::function<std::unique_ptr<SceneTemplate>()>> sceneFactories;

    TextureLoader* _textureLoader = nullptr;
    Input* _input = nullptr;
    Renderer* _renderer = nullptr;

    bool isUpdating = false;
};