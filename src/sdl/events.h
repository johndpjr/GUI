#ifndef GUI_SDL_EVENTS_H
#define GUI_SDL_EVENTS_H
#include "types.h"

namespace sdl::events {
    const uint32_t QUIT { SDL_QUIT };
    const uint32_t KEYDOWN { SDL_KEYDOWN };
    const uint32_t MOUSEBUTTONDOWN { SDL_MOUSEBUTTONDOWN };

    int poll(types::Event *event);
}

#endif //GUI_SDL_EVENTS_H
