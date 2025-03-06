#ifndef WINDOW_H
#define WINDOW_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_opengl.h>
#include <SDL2/SDL_ttf.h>
#include<SDL2/SDL_stdinc.h>
#include <iostream>
#include"../engine/main_loop.h"

extern SDL_Window* game_window;
extern SDL_Window* additional_window;
extern SDL_Renderer* game_renderer;
extern SDL_Renderer* text_renderer;
extern SDL_Renderer* additional_renderer;

//Sets the window to fullscreen
extern Uint64 fullscreen;
//Sets the window to Borderless
extern Uint64 borderless;
//Sets the window to resizable
extern Uint64 resizable;
//Sets the window to borderless_fullscreen
extern Uint64 borderless_fulllscreen;
//Sets the window as an openGL Renderer
extern Uint64 OpenGL;
//Sets the window to vsync
extern Uint64 vsync;

//width of the window
extern int width;
//height of the window
extern int height;

extern SDL_Surface* game_sruface = SDL_GetWindowSurface(game_window);
extern const char* window_name;
extern Uint64 window_mode;
extern bool enable_vsync;


/*Create Window for your Program
(NOTE: ODK only supports up to 2 window creations in a single project)
(NOTE: ODK only supports up to 3 renderers in a single project)
*/
void create_window(SDL_Window*& window, SDL_Renderer*& renderer, const char* window_name, int width, int height, Uint64 window_mode, bool enable_vsync);
#endif // !WINDOW_H