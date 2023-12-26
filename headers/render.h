#ifndef RENDERER_H
#define RENDERER_H
#include "./window.h"
class Renderer {
    protected:
        Window *window = nullptr;
    public:
        Renderer(){};
        virtual void init();
        virtual void renderViewport(Viewport *viewport);
        virtual void refreshWindow(Window *window);
};
#endif