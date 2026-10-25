#include "scene/scene_manager.h"

//INCLUDED SCENES
#include "scene/scene1.h"

#include <utility>

void SceneManager::Setup(TextureLoader& textureLoader, Input& input, Renderer& renderer)
{
    _textureLoader = &textureLoader;
    _input = &input;
    _renderer = &renderer;

    sceneFactories.clear();

    //SCENES
    sceneFactories.push_back([this]()
    {
        return std::make_unique<Scene1>(
            *_textureLoader,
            *_input,
            *_renderer,
            *this
        );
    });

    ChangeScene(0);
}

void SceneManager::Update(float deltaTime)
{
    if (!curScene)
        return;

    isUpdating = true;
    curScene->Update(deltaTime);
    isUpdating = false;

    if (pendingScene)
    {
        auto nextScene = std::move(pendingScene);
        ApplyScene(std::move(nextScene));
    }
}

void SceneManager::ChangeScene(std::unique_ptr<SceneTemplate> scene)
{
    if (!scene)
        return;

    if (isUpdating)
    {
        pendingScene = std::move(scene);
        return;
    }

    ApplyScene(std::move(scene));
}

void SceneManager::ChangeScene(int number)
{
    if (number < 0 ||
        number >= static_cast<int>(sceneFactories.size()))
    {
        return;
    }

    ChangeScene(sceneFactories[number]());
}

void SceneManager::ApplyScene(std::unique_ptr<SceneTemplate> scene)
{
    if (curScene)
    {
        curScene->Exit();
        curScene.reset();
    }

    curScene = std::move(scene);
    curScene->Start();
}

void SceneManager::Shutdown()
{
    pendingScene.reset();

    if (curScene)
    {
        curScene->Exit();
        curScene.reset();
    }
}