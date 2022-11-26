#include <SDL2/SDL.h>
#include <iostream>

#include "ppm.h"
#include "window.h"

constexpr auto TITLE = "PPM Viewer";

using PPM_view::PPM;
using PPM_view::Window;

int main(int argc, char** argv)
{
    if (argc < 2)
    {
        std::cout << "No file provided." << std::endl;
        return 1;
    }

    const PPM image(argv[1]);

    Window wnd(TITLE, image.width(), image.height());
    wnd.draw_image(&image);
    wnd.run();

    return 0;
}
