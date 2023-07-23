#ifndef GUI_RENDER_H
#define GUI_RENDER_H
#include "types.h"

namespace sdl::render {
    const uint32_t RENDERER_ACCERLERATED { SDL_RENDERER_ACCELERATED };

    types::Renderer* create_renderer(types::Window *window, int index, uint32_t flags);
    void destroy_renderer(types::Renderer *renderer);

    int clear(types::Renderer *renderer);
    void present(types::Renderer *renderer);

    int set_draw_color(types::Renderer *renderer, uint8_t r, uint8_t g, uint8_t b, uint8_t a);
    int fill_rect(types::Renderer *renderer, types::Rect const *rect);
} // sdl::render

#endif //GUI_RENDER_H
