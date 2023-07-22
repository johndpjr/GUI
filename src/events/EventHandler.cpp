#include "EventHandler.h"

event_handler EVENT_HANDLERS[EventType::NUM_EVENT_TYPES] = {};
void register_event_handler(EventType e_type, event_handler handler) {
    EVENT_HANDLERS[e_type] = handler;
}

void event_fire(Event e, Window *window) {
    EVENT_HANDLERS[e.type()](e, window);
}
