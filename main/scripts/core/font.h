#pragma once

#include "../main.h"

class Font
{
private:
    SDL_Texture* texture = NULL;
    TTF_Font* font = NULL;
public:
    SDL_Rect rect;

    ~Font();

    void init(string path, int s);
    void render(SDL_Renderer *renderer, string text, SDL_Color color);
    void update(SDL_Renderer *renderer, int x, int y, SDL_Rect* clip = NULL, double angle = 0, SDL_Point* center = NULL, SDL_RendererFlip flip = SDL_FLIP_NONE);
};