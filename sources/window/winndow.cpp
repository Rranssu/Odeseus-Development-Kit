#include"../../headers/window/window.h"

SDL_Window* game_window;
SDL_Window* additional_window;
SDL_Renderer* game_renderer;
SDL_Renderer* text_renderer;
SDL_Renderer* additional_renderer;

Uint64 fullscreen = SDL_WINDOW_FULLSCREEN;
Uint64 borderless = SDL_WINDOW_BORDERLESS;
Uint64 resizable = SDL_WINDOW_RESIZABLE;
Uint64 borderless_fulllscreen = SDL_WINDOW_FULLSCREEN_DESKTOP;
//Sets the window as an openGL Renderer
Uint64 OpenGL = SDL_WINDOW_OPENGL;
//Sets the window to vsync
Uint64 vsync;

const char* window_name;
Uint64 window_mode;
bool enable_vsync;
SDL_Surface* game_sruface = SDL_GetWindowSurface(game_window);
SDL_Surface* additional_sruface = SDL_GetWindowSurface(additional_window);

void create_window(SDL_Window*& window, SDL_Renderer*& renderer, const char* window_name, int width, int height, Uint64 window_mode, bool enable_vsync)
{
    if (SDL_Init(SDL_INIT_VIDEO) != 0)
    {
        std::cout << "Unable to launch program: " << SDL_GetError() << "\n";
    }
    window = SDL_CreateWindow(window_name, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, width, height, window_mode);

    if (enable_vsync == true)
    {
        vsync = SDL_RENDERER_PRESENTVSYNC;
    }
    else
    {
        vsync = 0;
    }

    renderer = SDL_CreateRenderer(window, -1, vsync);
    if (!window || !renderer)
    {
        std::cout << "Window and Renderer could not be created see error: " << SDL_GetError() << "\n";
        SDL_Quit();
    }

    main_loop();

    bool quit = false;
    SDL_Event e;

    while (!quit)
    {
        while (SDL_PollEvent(&e) != 0)
        {
            if (e.type == SDL_QUIT)
            {
                quit = true;
                if (renderer)
                {
                    SDL_DestroyRenderer(renderer);
                }

                if (window)
                {
                    SDL_DestroyWindow(window);
                }

                SDL_Quit();
            }
        }
    }
}