#include "Window.h"
#include "widgets/Button.h"
#include "misc/colors.h"

void doSomething() {
    printf("Hello, World!\n");
}

int main() {
    if (sdl::sys::init(sdl::INIT_VIDEO) < 0)
        throw std::runtime_error(sdl::error::get_error());

    Window window ("GUI", 640, 480);
    std::cout << "Root Frame: " << window.root_frame() << std::endl;

    Frame frameA (window.root_frame(), gui::Colors::RED);
    std::cout << "Frame A: " << &frameA << std::endl;
    frameA.grid(0, 0);

    Frame frameB (window.root_frame(), gui::Colors::GREEN);
    std::cout << "Frame B: " << &frameB << std::endl;
    frameB.grid(0, 1);

    Button button1 {&frameA, &doSomething};
    std::cout << "Button 1: " << &button1 << std::endl;
    button1.grid(1, 0);

    Button button2 {&frameB, &doSomething};
    std::cout << "Button 2: " << &button2 << std::endl;
    button2.grid(0, 1);

    window.mainloop();

    return 0;
}
