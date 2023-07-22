#ifndef GUI_EVENTHOOKS_H
#define GUI_EVENTHOOKS_H
#include "Event.h"
#include "../Window.h"

namespace event_hook {
    void quit(Event e, Window *win);
    void key_down(Event e, Window *win);
    void mouse_button_down(Event e, Window *win);
    void event_not_implemented(Event e, Window *win);
}

#endif //GUI_EVENTHOOKS_H
