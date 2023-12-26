#include <ncurses.h>
#include <iostream> // Include for cout and endl
#include "tiles.h"
#include "map.h"
#include "rooms.h"
#include "game.h"
#include "render.h"
#include <exception>
using namespace std; // Correct namespace usage

int main() {
    try {
        Game *game = new Game();
        game->init();
        game->mainLoop();
        return 0;
    }
    catch (const std::exception& e) {
        std::cerr << "Caught exception: " << e.what() << std::endl;
        return 1; // Indicate error
    }

    return 0;
}