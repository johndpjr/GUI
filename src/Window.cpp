#include "Window.h"
#include "events/EventManager.h"

Window::Window(const std::string& title, int width, int height)
    : m_window{nullptr}, m_renderer{nullptr},
      m_quit{false}, m_root_frame{new Frame(new SDL_Rect{0, 0, width, height})}
{
    if (SDL_Init(SDL_INIT_VIDEO) < 0)
        throw std::runtime_error(SDL_GetError());
    m_window = SDL_CreateWindow(title.c_str(), SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, width, height,SDL_WINDOW_SHOWN);
    if (m_window == nullptr)
        throw std::runtime_error(SDL_GetError());
    m_renderer = SDL_CreateRenderer(m_window, -1, SDL_RENDERER_ACCELERATED);
    EventManager::Init();
}

Window::~Window()
{
    SDL_DestroyWindow(m_window);
    SDL_DestroyRenderer(m_renderer);
    delete m_root_frame;
    SDL_Quit();
}

Frame* Window::root_frame() {
    return m_root_frame;
}

void Window::mainloop() {
    while (!m_quit) {
        EventManager::Update(this);
        SDL_RenderClear(m_renderer);
        m_root_frame->draw(m_renderer);
        SDL_RenderPresent(m_renderer);
    }
}

void Window::quit() {
    m_quit = true;
}
