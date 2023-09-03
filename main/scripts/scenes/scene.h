#pragma once

#include "../main.h"

class Scene
{
public:
    virtual void init(SDL_Renderer *renderer) {};
    virtual void update(SDL_Renderer *renderer) {};
    virtual void destroy() {};
};