#include "Button.h"

Button::Button(Widget *parent, void (*callback)(), sdl::types::Color bg)
    : Widget(parent, new sdl::types::Rect{
        parent->rect()->x + parent->rect()->w / 2 - 20,
        parent->rect()->y + parent->rect()->h / 2 - 8,
        40,20}, bg), m_callback{callback}
{
    if (m_parent != nullptr)
        m_parent->add_child(this);
}

void Button::draw(sdl::types::Renderer *renderer) {
    if (!is_shown())
        return;
    sdl::render::set_draw_color(renderer, m_bg_color.r, m_bg_color.g, m_bg_color.b, m_bg_color.a);
    sdl::render::fill_rect(renderer, m_rect);
}

void Button::on_click(int x, int y) {
    printf("Button %p was clicked\n", this);
    if (m_callback != nullptr)
        m_callback();
}

void Button::update_children() {
}

void Button::pack(Side side, Direction anchor) {
    m_is_shown = true;
}
