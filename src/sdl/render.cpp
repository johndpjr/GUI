#include "render.h"
#include <SDL_render.h>

namespace sdl::render {
    types::Renderer* create_renderer(types::Window *window, int index, uint32_t flags) {
        return SDL_CreateRenderer(window, index, flags);
    }

    void destroy_renderer(types::Renderer *renderer) {
        SDL_DestroyRenderer(renderer);
    }

    int clear(types::Renderer *renderer) {
        return SDL_RenderClear(renderer);
    }

    void present(types::Renderer *renderer) {
        return SDL_RenderPresent(renderer);
    }

    int set_draw_color(types::Renderer *renderer, uint8_t r, uint8_t g, uint8_t b, uint8_t a) {
        return SDL_SetRenderDrawColor(renderer, r, g, b, a);
    }

    int fill_rect(types::Renderer *renderer, types::Rect const *rect) {
        return SDL_RenderFillRect(renderer, rect);
    }
} // sdl::render
