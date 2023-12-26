#include "render.h"
#include <stdexcept>
#ifdef USE_SDL
#include <SDL2/SDL.h>
#include <stdexcept>
void Renderer::init()
{
    
    this->window = new Window();
    //Need to load spritesheet and create window
    this->window->initWindow();
}
void Renderer::refreshWindow(Window *window)
{

}
void Renderer::renderViewport(Viewport *viewport)
{

}
Renderer::~Renderer(){
    this->window->~Window();
}
#endif

#ifdef USE_NCURSES
#include <ncurses.h>
void Renderer::init()
{

}
void Renderer::refreshWindow(Window *window)
{
    
}
void Renderer::renderViewport(Viewport *viewport)
{
    
}
Renderer::~Renderer(){

}
#endif
