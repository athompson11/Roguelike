#include "./window.h"
#include "./viewport.h"
class Renderer {
    public:
        virtual void renderViewport(Viewport *viewport){};
        virtual void refreshWindow(Window *window){};

        virtual ~Renderer() {}
};



/*
void drawMap(WINDOW *main_win) {
    for (int i = 0; i < size_y; i++) {
        mvwprintw(main_win, i, 0, testMap[i]);
    }
    wrefresh(main_win);
}

void drawPlayer(WINDOW *main_win) {
    mvwprintw(main_win, player_y, player_x, "@");
    wrefresh(main_win);
}
*/