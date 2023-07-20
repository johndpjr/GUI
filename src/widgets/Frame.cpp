#include "Frame.h"

Frame::Frame(Frame* parent_frame, SDL_Color bg)
    : Widget(parent_frame, new SDL_Rect{0,0,0,0}, bg)
{
    if (m_parent != nullptr)
        m_parent->addChild(this);
}

Frame::Frame(SDL_Rect* window_rect)
    : Widget(nullptr, window_rect, Colors::WHITE, true)
{
}

void Frame::update_children() {
    int numChildrenShown = std::count_if(m_children.begin(), m_children.end(), [](Widget* w){return w->is_shown();});
    int x {m_rect->x}, y {0};
    int new_width = m_rect->w / numChildrenShown;
    for (auto child: m_children) {
        if (child->is_shown()) {
            delete child->m_rect;
            auto new_rect = new SDL_Rect {x, y, new_width, m_rect->h};
            child->m_rect = new_rect;
            x += new_width;
        }
    }
}

void Frame::pack(Side side, Direction anchor) {
    // pack() *should* never be called on Window m_root_frame, so this check
    // isn't strictly necessary
    if (m_parent != nullptr) {
        m_is_shown = true;
        m_parent->update_children();
    }
}

void Frame::draw(SDL_Renderer* renderer) {
    if (!is_shown())
        return;
    // Draw this rect
    SDL_SetRenderDrawColor(renderer, m_bg_color.r, m_bg_color.g, m_bg_color.b, m_bg_color.a);
    SDL_RenderFillRect(renderer, m_rect);
    // Draw all child rects
    for (auto child: m_children)
        child->draw(renderer);
}

void Frame::on_click(int x, int y) {
    printf("Frame %p was clicked\n", this);
    for (auto child: m_children) {
        if (child->is_shown() && child->contains(x, y)) {
            child->on_click(x, y);
            break;
        }
    }
}