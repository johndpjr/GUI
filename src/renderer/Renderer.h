#ifndef GUI_RENDERER_H
#define GUI_RENDERER_H
#include "../sdl/types.h"

class Renderer {
private:
    sdl::types::Renderer *m_rend;
public:
    Renderer();
    Renderer(sdl::types::Window *window, int index, uint32_t flags);
    ~Renderer();

    Renderer& operator=(const Renderer& other);

    sdl::types::Renderer* rend() { return m_rend; }

    int clear();
    void present();
    int set_draw_color(sdl::types::Color color);
    int draw_rect(sdl::types::Rect *rect);
};


#endif //GUI_RENDERER_H
