#ifndef GUI_RENDERER_H
#define GUI_RENDERER_H


class Renderer {
public:
    virtual void clear() = 0;
    virtual void draw_rect() = 0;
    virtual void present() = 0;
};


#endif //GUI_RENDERER_H
