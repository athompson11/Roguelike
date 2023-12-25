#include "./player.h"
#include "./window.h"
class Game{
    protected:
        Player *player = nullptr;
        Window *window = nullptr;
    public:
        Game(Player *player, Window *window)
        : player(player), window(window){}

        virtual ~Game() {}
};