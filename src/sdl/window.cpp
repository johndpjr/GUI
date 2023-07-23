#include "window.h"
#include <SDL_video.h>

namespace sdl::window {
    types::Window* create_window(const char *title, int x, int y, int w, int h, uint32_t flags) {
        return SDL_CreateWindow(title, x, y, w, h, flags);
    }

    void destroy_window(types::Window *window) {
        SDL_DestroyWindow(window);
    }
} // sdl::window
