#ifndef GUI_SYS_H
#define GUI_SYS_H
#include <cstdint>

namespace sdl::sys {
    int init(uint32_t flags);
    void quit();
} // sdl::sys

#endif //GUI_SYS_H
