#ifndef GUI_SDL_WINDOW_H
#define GUI_SDL_WINDOW_H
#include "types.h"

namespace sdl::window {
    const uint32_t WINDOW_SHOWN { SDL_WINDOW_SHOWN };

    types::Window* create_window(const char *title, int x, int y, int w, int h, uint32_t flags);
    void destroy_window(types::Window *window);
} // sdl::window

#endif //GUI_SDL_WINDOW_H
