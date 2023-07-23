#ifndef GUI_FRAME_H
#define GUI_FRAME_H
#include "Widget.h"
#include "../sdl/sdl.h"
#include "../misc/colors.h"

class Frame: public Widget {
public:
    explicit Frame(Frame* parent_frame, sdl::types::Color bg = Colors::WHITE);
    /**
     * Ctor for Window's m_root_frame (NOT used by user - I am a bad person)
     * @param window_rect The rect bounding the entire window
     */
    explicit Frame(sdl::types::Rect *window_rect);

    friend class Window;
private:

    // Updates all child rects to new dimensions.
    void update_children() override;

    // Draws the frame and all its children.
    void draw(Renderer *renderer) override;
public:
    void on_click(int x, int y) override;
    void pack(Side side, Direction anchor) override;
};


#endif //GUI_FRAME_H
