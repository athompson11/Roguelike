#ifndef RENDERER_H
#define RENDERER_H
#include "window.h"
#include "map.h"
class Renderer {
    protected:
        Window *window = nullptr;
    public:
        Renderer(){};
        virtual void init();
        virtual void refreshWindow(Map *map);
        virtual void refreshWindow();
        ~Renderer();
};
#endif