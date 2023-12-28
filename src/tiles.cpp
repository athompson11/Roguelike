#include "tiles.h"

void Door::changeState() {
            isOpen = !isOpen;
            if (isOpen) {
                symbol = '/';
                this->tileID = "doorOpen";
                isPassable = true;
            } else {
                symbol = '+';
                this->tileID = "doorClose";
                isPassable = false;
            }
        }