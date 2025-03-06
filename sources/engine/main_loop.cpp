#include"../../headers/engine/main_loop.h"

void delay(double milliseconds)
{
	Uint64 start = SDL_GetTicks64();
    bool quit = false;
    SDL_Event e;
	while (SDL_GetTicks() - start < milliseconds)
	{
        while (SDL_PollEvent(&e) != 0)
        {
            if (e.type == SDL_QUIT)
            {
                quit = true;
                if (game_renderer)
                {
                    SDL_DestroyRenderer(game_renderer);
                }
                else if (text_renderer)
                {
                    SDL_DestroyRenderer(text_renderer);
                }

                if (game_window)
                {
                    SDL_DestroyWindow(game_window);
                }
                else if (additional_window)
                {
                    SDL_DestroyWindow(additional_window);
                }


                SDL_Quit();
            }
        }
	}
	SDL_Delay(10);
}