#ifndef GUI_COLORS_H
#define GUI_COLORS_H
#include "../sdl/types.h"

namespace gui::Colors {

static sdl::types::Color WHITE  {255, 255, 255, 255};
static sdl::types::Color RED    {255, 0,   0,   255};
static sdl::types::Color YELLOW {255, 255, 0,   255};
static sdl::types::Color GREEN  {0,   255, 0,   255};
static sdl::types::Color BLUE   {0,   0,   255, 255};
static sdl::types::Color BLACK  {0,   0,   0,   255};

}

#endif //GUI_COLORS_H
