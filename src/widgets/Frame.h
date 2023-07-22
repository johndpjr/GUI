#ifndef GUI_FRAME_H
#define GUI_FRAME_H
#include <SDL.h>
#include <algorithm>
#include <vector>
#include "../misc/colors.h"
#include "Widget.h"

class Frame: public Widget {
public:
    explicit Frame(Frame* parent_frame, SDL_Color bg = Colors::WHITE);
    /**
     * Ctor for Window's m_root_frame (NOT used by user - I am a bad person)
     * @param window_rect The rect bounding the entire window
     */
    explicit Frame(SDL_Rect* window_rect);

    friend class Window;
private:

    // Updates all child rects to new dimensions.
    void update_children() override;

    // Draws the frame and all its children.
    void draw(SDL_Renderer* renderer) override;
public:
    void on_click(int x, int y) override;
    void pack(Side side, Direction anchor) override;
};


#endif //GUI_FRAME_H
