#include "Event.h"

Event::Event(sdl::types::Event e)
    : m_einfo{e}
{
    switch (e.type) {
        case sdl::events::QUIT:
            m_type = EventType::Quit;
            break;
        case sdl::events::KEYDOWN:
            m_type = EventType::KeyDown;
            break;
        case sdl::events::MOUSEBUTTONDOWN:
            m_type = EventType::MouseButtonDown;
            break;
        default:
            m_type = EventType::EventIgnore;
    }
}
