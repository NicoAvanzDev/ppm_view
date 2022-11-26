#ifndef WINDOW_H
#define WINDOW_H

#include <iostream>
#include <memory>
#include <string>
// C
#include "ppm.h"
#include <SDL2/SDL.h>

namespace PPM_view
{

class Window
{
  private:
    SDL_Window* m_window;
    SDL_Renderer* m_renderer;
    SDL_Texture* m_texture;
    const PPM* m_image;

  public:
    Window(const std::string title, int width, int height);

    void draw_image(const PPM* image);
    void run();

    ~Window();
};

} // namespace PPM_view

#endif
