#ifndef GUI_EVENTHANDLER_H
#define GUI_EVENTHANDLER_H
#include "Event.h"

class Window;
typedef void (*event_handler)(Event event, Window *window);
extern event_handler EVENT_HANDLERS[EventType::NUM_EVENT_TYPES];

void register_event_handler(EventType e_type, event_handler handler);

void event_fire(Event event, Window *window);

#endif //GUI_EVENTHANDLER_H
