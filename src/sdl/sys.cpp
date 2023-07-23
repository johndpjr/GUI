#include "sys.h"
#include <SDL.h>

namespace sdl::sys {
    int init(uint32_t flags) {
        return SDL_Init(flags);
    }

    void quit() {
        SDL_Quit();
    }
} // sdl::sys
