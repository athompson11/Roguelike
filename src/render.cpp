#include "render.h"
#include <stdexcept>
#ifdef USE_SDL
#include <SDL2/SDL.h>
#include <stdexcept>
void Renderer::init()
{
    this->window = new Window();
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
    initscr();
    keypad(stdscr, TRUE);
    noecho();
    start_color();
    this->window = new Window();
    this->window->initWindow();
    box(this->window->getWindow(), 0, 0); // 0, 0 gives default characters for the vertical and horizontal lines
    this->refreshWindow();
}
void Renderer::refreshWindow()
{
    wrefresh(this->window->getWindow());
    refresh();
}
void Renderer::renderViewport(Viewport *viewport)
{
    
}
Renderer::~Renderer(){
    delwin(this->window->getWindow());
    endwin();
}
#endif
