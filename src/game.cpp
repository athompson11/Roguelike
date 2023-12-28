#include "game.h"
#include "render.h"
#include "map.h"
#include <SDL2/SDL.h>
#include <stdexcept>
void Game::init(){
    /*Need to fill the following:
        Player *player = nullptr;
        Renderer *renderer = nullptr;
        Map *maps = nullptr;
        Map *currentMap = nullptr;
        RNG *rng = nullptr;*/

    #ifdef USE_SDL
    if( SDL_Init( SDL_INIT_EVERYTHING ) < 0 )
    {
        throw std::runtime_error(SDL_GetError());
    }
    #endif
    #ifdef USE_NCURSES
    initscr();
    keypad(stdscr, TRUE);
    noecho();
    start_color();
    #endif
    this->renderer = new Renderer();
    this->renderer->init();
    this->rng = new RNG();
}
void Game::mainLoop(){
    this->currentMap = new Map();
    this->currentMap->generateMap();
    #ifdef USE_NCURSES
    while(true) {
        int ch = getch(); // Get a character from the user
        this->renderer->refreshWindow(this->currentMap);
        if(ch == 'q') { // If 'q' is pressed, break the loop
            break;
        }
    }
    #endif
}