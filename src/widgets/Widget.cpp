#include "Widget.h"

Widget::Widget(Widget* m_parent, SDL_Rect* rect, SDL_Color bg, bool is_shown)
    : m_parent{m_parent}, m_rect{rect}, m_bg_color{bg}, m_is_shown{is_shown}
{
}

Widget::~Widget()
{
    delete m_rect;
}

SDL_Rect* Widget::rect() const { return m_rect; }

bool Widget::contains(int x, int y) const {
    return intersects(m_rect, x, y);
}

bool Widget::is_shown() const { return m_is_shown; }

std::vector<Widget *> Widget::children() const { return m_children; }

void Widget::addChild(Widget *child) {
    m_children.push_back(child);
}