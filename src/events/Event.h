#ifndef GUI_EVENT_H
#define GUI_EVENT_H
#include "../sdl/sdl.h"

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
    sdl::types::Event m_einfo;
public:
    explicit Event(sdl::types::Event e);
    EventType type() { return m_type; }
    sdl::types::Event einfo() { return m_einfo; }
};


#endif //GUI_EVENT_H
