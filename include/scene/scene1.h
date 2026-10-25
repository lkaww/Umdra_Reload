#pragma once

#include "scene/scene_template.h"
#include "graphics/texture.h"

class Scene1 : public SceneTemplate
{
public:
    using SceneTemplate::SceneTemplate;

private:
    void Start() override;
    void Update(float deltaTime) override;
};