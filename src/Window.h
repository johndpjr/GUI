#ifndef GUI_WINDOW_H
#define GUI_WINDOW_H
#include <SDL.h>
#include <iostream>
#include <string>
#include "widgets/Frame.h"

class Window {
public:
    Window(const std::string& title, int width, int height);
    ~Window();
private:
    SDL_Window* m_window;
    SDL_Renderer* m_renderer;
    bool m_quit;
    Frame* m_root_frame;
public:
    Frame* root_frame();
    void mainloop();
    void update();
};


#endif //GUI_WINDOW_H
