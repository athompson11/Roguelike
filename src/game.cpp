#include "game.h"
#include "render.h"
#include "player.h"
#include "map"
#include <SDL2/SDL.h>
void Game::init(){
    /*Need to fill the following:
        Player *player = nullptr;
        Renderer *renderer = nullptr;
        Map *maps = nullptr;
        Map *currentMap = nullptr;*/
    #ifdef USE_SDL
    if( SDL_Init( SDL_INIT_EVERYTHING ) < 0 )
    {
        throw std::exception(SDL_GetError());
    }
    #endif
    this->renderer = new Renderer();
    this->renderer->init();
}
void Game::mainLoop(){
    #ifdef USE_SDL
    SDL_Event e; bool quit = false; while( quit == false ){ while( SDL_PollEvent( &e ) ){ if( e.type == SDL_QUIT ) quit = true; } }
    this->renderer->~Renderer();
    SDL_Quit();
    return 0;
    #endif
}