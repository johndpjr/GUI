#ifndef GUI_EVENT_H
#define GUI_EVENT_H
#include <SDL_events.h>

enum EventType {
    Quit,
    KeyDown,
    MouseButtonDown,
    EventNotImplemented,
    EventIgnore,
    NUM_EVENT_TYPES
};

class Event {
private:
    EventType m_type;
    SDL_Event m_einfo;
public:
    explicit Event(SDL_Event e);
    EventType type() { return m_type; }
    SDL_Event einfo() { return m_einfo; }
};


#endif //GUI_EVENT_H
