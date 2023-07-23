#include "Window.h"
#include "events/EventManager.h"
#include "sdl/sdl.h"

Window::Window(const std::string& title, int width, int height)
    : m_window{nullptr}, m_renderer{nullptr},
      m_quit{false}, m_root_frame{new Frame(new sdl::types::Rect{0, 0, width, height})}
{
    if (sdl::sys::init(sdl::INIT_VIDEO) < 0)
        throw std::runtime_error(sdl::error::get_error());
    m_window = sdl::window::create_window(title.c_str(), sdl::WINDOWPOS_UNDEFINED, sdl::WINDOWPOS_UNDEFINED, width, height, sdl::window::WINDOW_SHOWN);
    if (m_window == nullptr)
        throw std::runtime_error(sdl::error::get_error());
    m_renderer = sdl::render::create_renderer(m_window, -1, sdl::render::RENDERER_ACCERLERATED);
    EventManager::Init();
}

Window::~Window()
{
    sdl::window::destroy_window(m_window);
    sdl::render::destroy_renderer(m_renderer);
    delete m_root_frame;
    sdl::sys::quit();
}

Frame* Window::root_frame() {
    return m_root_frame;
}

void Window::mainloop() {
    while (!m_quit) {
        EventManager::Update(this);
        sdl::render::clear(m_renderer);
        m_root_frame->draw(m_renderer);
        sdl::render::present(m_renderer);
    }
}

void Window::quit() {
    m_quit = true;
}
