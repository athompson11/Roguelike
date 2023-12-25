#include <ncurses.h>
#include <iostream> // Include for cout and endl
#include "./tiles.h"
#include "./map.h"
#include "./rooms.h"

using namespace std; // Correct namespace usage

int size_x = 80;
int size_y = 20;

//# = Wall
//. = Floor
//@ = Player
//+ = Door
//< = Stairs up
//> = Stairs down

int player_x = 1;
int player_y = 1;

Map *map = nullptr;