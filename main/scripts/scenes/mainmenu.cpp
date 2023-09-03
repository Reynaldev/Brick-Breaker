#include "mainmenu.h"

MainMenu::~MainMenu()
{
    this->fTitle.~Font();
}

void MainMenu::init(SDL_Renderer *renderer)
{
    fTitle.init("main/src/kenney_pixel.ttf", 32);
}   

void MainMenu::update(SDL_Renderer *renderer)
{
    SDL_Color textColor = { 0xff, 0xff, 0xff, 0xff };
    fTitle.render(renderer, "Brick Breaker", textColor);
    fTitle.update(renderer, (SCREEN_WIDTH - fTitle.rect.w) / 2, (SCREEN_HEIGHT - fTitle.rect.h) / 2);
}

void MainMenu::destroy()
{
    this->~MainMenu();
}