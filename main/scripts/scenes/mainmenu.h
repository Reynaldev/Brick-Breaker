#pragma once

#include "../main.h"
#include "../core/font.h"
#include "scene.h"

class MainMenu : public Scene
{
private:
    Font fTitle;
public:
    ~MainMenu();

    void init(SDL_Renderer *renderer);
    void update(SDL_Renderer *renderer);
    void destroy();
};