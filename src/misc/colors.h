#ifndef GUI_COLORS_H
#define GUI_COLORS_H
#include <SDL.h>

namespace gui::Colors {

static SDL_Color WHITE  {255, 255, 255, 255};
static SDL_Color RED    {255, 0,   0,   255};
static SDL_Color YELLOW {255, 255, 0,   255};
static SDL_Color GREEN  {0,   255, 0,   255};
static SDL_Color BLUE   {0,   0,   255, 255};
static SDL_Color BLACK  {0,   0,   0,   255};

}

#endif //GUI_COLORS_H
