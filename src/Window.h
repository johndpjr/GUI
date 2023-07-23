#ifndef GUI_WINDOW_H
#define GUI_WINDOW_H
#include <iostream>
#include <string>

#include "widgets/Frame.h"
#include "sdl/types.h"

class Window {
public:
    Window(const std::string& title, int width, int height);
    ~Window();
private:
    sdl::types::Window *m_window;
    sdl::types::Renderer *m_renderer;
    bool m_quit;
    Frame* m_root_frame;
public:
    Frame* root_frame();
    void mainloop();
    void quit();
};


#endif //GUI_WINDOW_H
