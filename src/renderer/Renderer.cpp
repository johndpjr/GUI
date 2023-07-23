#include "Renderer.h"
#include <stdexcept>
#include "../sdl/render.h"
#include "../sdl/error.h"

Renderer::Renderer()
    : m_rend{nullptr}
{}

Renderer::Renderer(sdl::types::Window *window, int index, uint32_t flags)
    : m_rend{sdl::render::create_renderer(window, index, flags)}
{
    if (m_rend == nullptr)
        throw std::runtime_error(sdl::error::get_error());
}

Renderer::~Renderer()
{
    if (m_rend != nullptr)
        sdl::render::destroy_renderer(m_rend);
}

Renderer& Renderer::operator=(const Renderer& other) {
    if (this != &other)
        m_rend = nullptr;
    return *this;
}

int Renderer::clear() {
    return sdl::render::clear(m_rend);
}

void Renderer::present() {
    sdl::render::present(m_rend);
}

int Renderer::set_draw_color(sdl::types::Color color) {
    return sdl::render::set_draw_color(m_rend, color.r, color.g, color.b, color.a);
}

int Renderer::draw_rect(sdl::types::Rect *rect) {
    return sdl::render::fill_rect(m_rend, rect);
}
