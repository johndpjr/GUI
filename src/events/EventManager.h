#ifndef GUI_EVENTMANAGER_H
#define GUI_EVENTMANAGER_H
#include "Event.h"

class Window;
class EventManager {
private:
    static void RegisterHandlers();
    static void DispatchEvent(Event e, Window *window);
public:
    static void Init();
    static void Update(Window *window);
};


#endif //GUI_EVENTMANAGER_H
