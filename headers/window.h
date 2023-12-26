#ifndef WINDOW_H
#define WINDOW_H
#include "viewport.h"
#ifdef USE_SDL
#include <SDL2/SDL.h>
#endif
#ifdef USE_NCURSES
#include <ncurses.h>
#endif

class Window{
    protected:
        Viewport *viewport = nullptr;
    private:
    #ifdef USE_NCURSES
        int dimensionX = 80;
        int dimensionY = 20;
        int statusX = 80;
        int statusY = 15;
        WINDOW *win = nullptr;
        public:
            void initWindow();
            ~Window();
    #endif
    #ifdef USE_SDL
        int dimensionX = 1280;
        int dimensionY = 720;
        SDL_Window *win = nullptr;
        SDL_Surface* viewportSurface = nullptr;
        public:
            void initWindow();
            ~Window();
    #endif
    
};
#endif