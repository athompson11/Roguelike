#include "window.h"
#include <stdexcept>
#ifdef USE_SDL
void Window::initWindow()
{
    this->win = SDL_CreateWindow( "Engine Test", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, this->dimensionX, this->dimensionY, SDL_WINDOW_SHOWN);
    if( this->win == NULL )
        {
            throw std::runtime_error(SDL_GetError());
        }
    else{
        this->viewportSurface = SDL_GetWindowSurface(this->win);
        SDL_FillRect( this->viewportSurface, NULL, SDL_MapRGB( this->viewportSurface->format, 0x00, 0x00, 0x00 ) );
        SDL_UpdateWindowSurface( this->win );
    }
}
Window::~Window(){
    SDL_DestroyWindow(this->win);
}
#endif
#ifdef USE_NCURSES

#endif