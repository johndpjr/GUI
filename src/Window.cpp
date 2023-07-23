#include "Window.h"
#include "events/EventManager.h"
#include "sdl/sdl.h"

Window::Window(const std::string& title, int width, int height)
    : m_window{sdl::window::create_window(title.c_str(), sdl::WINDOWPOS_UNDEFINED, sdl::WINDOWPOS_UNDEFINED, width, height, sdl::window::WINDOW_SHOWN)},
      m_renderer{m_window, -1, sdl::render::RENDERER_ACCERLERATED},
      m_quit{false},
      m_root_frame{new Frame(new sdl::types::Rect{0, 0, width, height})}
{
    if (m_window == nullptr)
        throw std::runtime_error(sdl::error::get_error());
    EventManager::Init();
}

Window::~Window()
{
    sdl::window::destroy_window(m_window);
    delete m_root_frame;
    sdl::sys::quit();
}

Frame* Window::root_frame() {
    return m_root_frame;
}

void Window::mainloop() {
    while (!m_quit) {
        EventManager::Update(this);
        if (m_renderer.clear() < 0) {
            printf("Failed, %s\n", SDL_GetError());
            return;
        }
        m_root_frame->draw(&m_renderer);
        m_renderer.present();
    }
}

void Window::quit() {
    m_quit = true;
}
