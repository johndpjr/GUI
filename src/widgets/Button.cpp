#include "Button.h"

Button::Button(Widget* parent, void (*callback)(), SDL_Color bg)
    : Widget(parent, new SDL_Rect{
        parent->rect()->x + parent->rect()->w / 2 - 20,
        parent->rect()->y + parent->rect()->h / 2 - 8,
        40,20}, bg), m_callback{callback}
{
    if (m_parent != nullptr)
        m_parent->addChild(this);
}

void Button::draw(SDL_Renderer* renderer) {
    if (!is_shown())
        return;
    SDL_SetRenderDrawColor(renderer, m_bg_color.r, m_bg_color.g, m_bg_color.b, m_bg_color.a);
    SDL_RenderFillRect(renderer, m_rect);
}

void Button::on_click(int x, int y) {
    printf("Button %p was clicked\n", this);
    if (m_callback != nullptr)
        m_callback();
}

void Button::update_children() {
    // TODO: updating children buttons
}

void Button::pack(Side side, Direction anchor) {
    m_is_shown = true;
}