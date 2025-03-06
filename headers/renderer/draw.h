#ifndef DRAW_H
#define DRAW_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_opengl.h>
#include <SDL2/SDL_ttf.h>
#include<SDL2/SDL_stdinc.h>
#include <iostream>

extern SDL_Surface* textarea;

void draw_color(SDL_Renderer*& renderer, int red, int green, int blue, int alpha);
void draw_text(const char* text, const char* font_file, int size, int x, int y, int red, int green, int blue);


#endif // !DRAW_H
