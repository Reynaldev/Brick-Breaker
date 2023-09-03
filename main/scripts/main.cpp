#include "main.h"
#include "scenes/mainmenu.h"
#include "scenes/scene.h"

int main(int argc, const char** argv) 
{
    SDL_Window* window = NULL;
    SDL_Renderer* renderer = NULL;
    SDL_Surface* surface = NULL;

    if (SDL_Init(SDL_INIT_VIDEO) < 0) 
    {
        cout << "SDL could not be initialized!\nError: " << SDL_GetError() << endl;
        exit(1);
    }

    window = SDL_CreateWindow("Brick Breaker", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 
        SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
    if (window == NULL)
    {
        cout << "Window could not be created!\nError: " << SDL_GetError() << endl;
        exit(1);
    }

    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    if (renderer == NULL)
    {
        cout << "Renderer coul not be initialized!\nError: " << SDL_GetError() << endl;
        exit(1);
    }

    int imgFlags = IMG_INIT_PNG;
    if (!(IMG_Init(imgFlags) & imgFlags))
    {
        cout << "SDL_image could not be initialized!\nError: " << IMG_GetError() << endl;
        exit(1);
    }

    if (TTF_Init() == -1)
    {
        cout << "SDL_ttf could not be initialized!\nError: " << TTF_GetError() << endl;
        exit(1);
    }

    surface = SDL_GetWindowSurface(window);

    Scene* scene;
    MainMenu mainMenu;
    scene = &mainMenu;

    scene->init(renderer);

    SDL_Event e;
    bool quit = false;
    while (!quit) 
    {
        while (SDL_PollEvent(&e))
        {
            if (e.type == SDL_QUIT)
                quit = true;
        }

        SDL_SetRenderDrawColor(renderer, 0x0, 0x0, 0x0, 0xff);
        SDL_RenderClear(renderer);

        // Update here
        scene->update(renderer);

        SDL_RenderPresent(renderer);
    }

    scene->destroy();
    delete(scene);

    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);

    window = NULL;
    renderer = NULL;
    surface = NULL;

    TTF_Quit();
    IMG_Quit();
    SDL_Quit();
}