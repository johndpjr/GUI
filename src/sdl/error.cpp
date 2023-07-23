#include "error.h"
#include <SDL_error.h>

namespace sdl::error {
    const char* get_error() {
        return SDL_GetError();
    }
} // sdl::error
