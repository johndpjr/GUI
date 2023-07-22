#ifndef GUI_WIDGET_H
#define GUI_WIDGET_H
#include <SDL.h>
#include <vector>
#include "../misc/colors.h"
#include "../math/utils.h"
#include "../misc/enums.h"

using namespace gui;

class Widget {
public:
    Widget(Widget* m_parent, SDL_Rect* rect, SDL_Color bg = Colors::WHITE, bool is_shown = false);
    ~Widget();

    friend class Frame;
protected:
    Widget* m_parent;
    std::vector<Widget*> m_children;
    SDL_Rect* m_rect;
    SDL_Color m_bg_color;
    bool m_is_shown;

    virtual void draw(SDL_Renderer* renderer) = 0;
    virtual void on_click(int x, int y) = 0;
    virtual void update_children() = 0;
public:
    [[nodiscard]] SDL_Rect* rect() const;
    [[nodiscard]] bool contains(int x, int y) const;
    [[nodiscard]] bool is_shown() const;
    [[nodiscard]] std::vector<Widget*> children() const;
    void add_child(Widget* child);

    virtual void pack(Side side, Direction anchor) = 0;
};


#endif //GUI_WIDGET_H
