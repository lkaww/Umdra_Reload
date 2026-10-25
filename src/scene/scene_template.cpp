#include "scene/scene_template.h"

SceneTemplate::SceneTemplate(
    TextureLoader& textureLoader,
    Input& input,
    Renderer& renderer,
    SceneManager& sceneManager
)
    : _textureLoader(textureLoader),
      _input(input),
      _renderer(renderer),
      _sceneManager(sceneManager)
{
}

void SceneTemplate::Start()
{
}

void SceneTemplate::Update(float deltaTime)
{
}

void SceneTemplate::Exit()
{
    for (size_t i = 0; i < _textureLoader.textures.size(); ++i)
    {
        _textureLoader.UnloadTexture(_textureLoader.textures[i]);
    }

    _textureLoader.textures.clear();
}