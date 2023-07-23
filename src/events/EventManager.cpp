#include "EventManager.h"
#include "EventHooks.h"
#include "EventHandler.h"

void EventManager::Init() {
    RegisterHandlers();
}

void EventManager::RegisterHandlers() {
    register_event_handler(EventType::Quit, event_hook::quit);
    register_event_handler(EventType::KeyDown, event_hook::key_down);
    register_event_handler(EventType::MouseButtonDown, event_hook::mouse_button_down);
    register_event_handler(EventType::EventNotImplemented, event_hook::event_not_implemented);
}

void EventManager::Update(Window *window) {
    sdl::types::Event e;
    while (sdl::events::poll(&e)) {
        Event event {e};
        DispatchEvent(event, window);
    }
}

void EventManager::DispatchEvent(Event e, Window *window) {
    if (e.type() == EventType::EventIgnore)
        return;
    event_fire(e, window);
}
