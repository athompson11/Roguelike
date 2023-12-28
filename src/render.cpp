#include "render.h"
#include "map.h"
#include <stdexcept>
#ifdef USE_SDL
#include <SDL2/SDL.h>
#include <stdexcept>
void Renderer::init()
{
    this->window = new Window();
    this->window->initWindow();
}
void Renderer::refreshWindow()
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
    this->window = new Window();
    this->window->initWindow();
    box(this->window->getWindow(), 0, 0); // 0, 0 gives default characters for the vertical and horizontal lines
}

void Renderer::refreshWindow()
{
    refresh();
    wrefresh(this->window->getWindow());
}
void Renderer::refreshWindow(Map *map)
{
    for (int i = 0; i < map->getMapHeight(); ++i) {
        for (int j = 0; j < map->getMapWidth(); ++j) {
            mvwaddch(this->window->getWindow(), i, j, map->getMapTile(i,j)->getSymbol());
        }
    }
    refresh();
    wrefresh(this->window->getWindow());
}
Renderer::~Renderer(){
    delwin(this->window->getWindow());
    endwin();
}
#endif
