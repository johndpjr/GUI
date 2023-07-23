#include "utils.h"

bool intersects(sdl::types::Rect *rect, int x, int y) {
    return ((x >= rect->x && x <= rect->x + rect->w)
            && (y >= rect->y && y <= rect->y + rect->h));
}
