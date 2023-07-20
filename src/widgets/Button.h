#ifndef GUI_BUTTON_H
#define GUI_BUTTON_H
#include <SDL.h>
#include <functional>
#include "Widget.h"

using namespace gui;

class Button: public Widget {
public:
    explicit Button(Widget* parent, void (*callback)() = nullptr, SDL_Color bg = Colors::WHITE);
private:
    void (*m_callback) ();

    void draw(SDL_Renderer* renderer) override;
    void on_click(int x, int y) override;
    void update_children() override;
public:
    void pack(Side side, Direction anchor) override;
};


#endif //GUI_BUTTON_H
