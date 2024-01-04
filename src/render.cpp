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
void Renderer::refreshWindow(Window *window){
    
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
            Tile* tile = map->getMapTile(i, j);
            if (tile == nullptr) {
                // If the tile is null, just print a space character
                mvwaddch(this->window->getWindow(), i, j, static_cast<chtype>(' '));
            } else {
                // If the tile is not null, print its symbol
                mvwaddch(this->window->getWindow(), i, j, static_cast<chtype>(tile->getSymbol()));
            }
        }
    }
    wrefresh(this->window->getWindow());
}
Renderer::~Renderer(){
    delwin(this->window->getWindow());
    endwin();
}
#endif
