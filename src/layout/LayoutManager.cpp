#include "LayoutManager.h"
#include "../widgets/Widget.h"

void LayoutManager::Grid(Widget *widget, int row, int col) {
    if (widget->m_parent == nullptr)
        return;
    widget->m_is_shown = true;
    widget->m_parent->update_children();
}
