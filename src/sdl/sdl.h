#ifndef GUI_SDL_H
#define GUI_SDL_H

#include "error.h"
#include "events.h"
#include "render.h"
#include "sys.h"
#include "types.h"
#include "video.h"
#include "window.h"

namespace sdl {
    const uint32_t INIT_VIDEO { SDL_INIT_VIDEO };
    const uint32_t WINDOWPOS_UNDEFINED { SDL_WINDOWPOS_UNDEFINED };
} // sdl

#endif //GUI_SDL_H
