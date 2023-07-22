#include "Event.h"

Event::Event(SDL_Event e)
    : m_einfo{e}
{
    switch (e.type) {
        case SDL_QUIT:
            m_type = EventType::Quit;
            break;
        case SDL_KEYDOWN:
            m_type = EventType::KeyDown;
            break;
        case SDL_MOUSEBUTTONDOWN:
            m_type = EventType::MouseButtonDown;
            break;
        default:
            m_type = EventType::EventIgnore;
    }
}
