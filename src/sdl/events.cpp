#include "events.h"

namespace sdl::events {
    int poll(types::Event *event) {
        return SDL_PollEvent(event);
    }
}
