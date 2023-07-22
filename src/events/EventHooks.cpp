#include "EventHooks.h"

void event_hook::quit(Event e, Window *win) {
    win->quit();
}

void event_hook::key_down(Event e, Window *win) {
    printf("Key pressed!\n");
}

void event_hook::mouse_button_down(Event e, Window *win) {
    int mposx {e.einfo().button.x}, mposy {e.einfo().button.y};
    printf("x: %d | y: %d\n", mposx, mposy);
    win->root_frame()->on_click(mposx, mposy);
}

void event_hook::event_not_implemented(Event e, Window *win) {
    printf("Event not implemented!\n");
}
