#include "font.h"

Font::~Font()
{
    SDL_DestroyTexture(this->texture);
    TTF_CloseFont(this->font);

    this->texture = NULL;
    this->font = NULL;
}

void Font::init(string path, int s)
{
    this->font = TTF_OpenFont(path.c_str(), s);
    if (this->font == NULL)
    {
        cout << "TTF file could not be found\nPath: " << path << "\nError: " << TTF_GetError() << endl;
        return;
    }
}

void Font::render(SDL_Renderer *renderer, string text, SDL_Color color)
{
    SDL_DestroyTexture(this->texture);

    SDL_Surface* surface = TTF_RenderText_Solid(this->font, text.c_str(), color);
    if (surface == NULL)
    {
        cout << "Unable to render text surface!\nSDL_ttf Error: " << TTF_GetError() << endl;
        return;
    }

    this->texture = SDL_CreateTextureFromSurface(renderer, surface);
    if (texture == NULL)
    {
        cout << "Unable to create texture from surface!\nSDL Error: " << SDL_GetError() << endl;
        return;
    }

    this->rect.w = surface->w;
    this->rect.h = surface->h;

    SDL_FreeSurface(surface);
}

void Font::update(SDL_Renderer *renderer, int x, int y, SDL_Rect *clip, double angle, SDL_Point *center, SDL_RendererFlip flip)
{
    this->rect.x = x;
    this->rect.y = y;

    SDL_RenderCopyEx(renderer, this->texture, clip, &this->rect, angle, center, flip);
}