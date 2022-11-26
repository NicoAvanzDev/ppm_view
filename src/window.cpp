#include "window.h"

namespace PPM_view
{

Window::Window(const std::string title, int width, int height)
{
    // Initialize SDL system
    if (SDL_Init(SDL_INIT_VIDEO) < 0)
    {
        SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "Couldn't initialize SDL: %s", SDL_GetError());
        Window::~Window();
        exit(1);
    }

    if (width > 1200)
        width = 1200;
    if (height > 800)
        height = 800;

    // Create window
    m_window = SDL_CreateWindow(title.c_str(), SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height,
                                SDL_WINDOW_RESIZABLE);

    if (m_window == NULL)
    {
        SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "Couldn't create window and renderer: %s", SDL_GetError());
        Window::~Window();
        exit(1);
    }

    // Create renderer
    m_renderer = SDL_CreateRenderer(m_window, -1, 0);

    if (m_renderer == NULL)
    {
        SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "Couldn't create renderer: %s", SDL_GetError());
        Window::~Window();
        exit(1);
    }
}

void Window::draw_image(const PPM* image)
{
    m_image = image;

    m_texture =
        SDL_CreateTexture(m_renderer, SDL_PIXELFORMAT_RGB24, SDL_TEXTUREACCESS_STATIC, image->width(), image->height());

    if (m_texture == NULL)
    {
        SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "Couldn't create texture: %s", SDL_GetError());
        Window::~Window();
        exit(1);
    }
}

// Main window loop
void Window::run()
{
    SDL_Event event;
    bool running = true;

    while (running)
    {
        SDL_UpdateTexture(m_texture, NULL, m_image->data(), m_image->width() * 3);

        // Event loop
        while (SDL_PollEvent(&event))
        {
            if (event.type == SDL_QUIT)
            {
                running = false;
            }
        }

        // Draw
        SDL_RenderClear(m_renderer);

        if (m_texture)
        {
            SDL_RenderCopy(m_renderer, m_texture, NULL, NULL);
        }

        SDL_RenderPresent(m_renderer);
    }
}

Window::~Window()
{
    if (m_texture != NULL)
    {
        SDL_DestroyTexture(m_texture);
    }
    if (m_renderer != NULL)
    {
        SDL_DestroyRenderer(m_renderer);
    }
    if (m_window != NULL)
    {
        SDL_DestroyWindow(m_window);
    }
    SDL_Quit();
}

} // namespace PPM_view
