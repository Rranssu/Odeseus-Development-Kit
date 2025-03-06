#include"../../headers/renderer/draw.h"
#include"../../headers/window/window.h"


void draw_color(SDL_Renderer*& renderer, int red, int green, int blue, int alpha)
{
	SDL_SetRenderDrawColor(renderer, red, green, blue, alpha);
	SDL_RenderClear(renderer);
	SDL_RenderPresent(renderer);
}

/*void draw_text(const char* text ,const char* font_file, int size, int x, int y, int red, int green, int blue)
{
	TTF_Init();
	TTF_Font* font = TTF_OpenFont(font_file, size);
	SDL_Color font_color = { red, green, blue };
	SDL_Surface* textsurface = TTF_RenderText_Solid(font, text, font_color);
	SDL_Rect textlocation = { x, y, 0, 0 };
	SDL_BlitSurface(textsurface, NULL, game_sruface, &textlocation);
	SDL_FreeSurface(textsurface);
	TTF_CloseFont(font);
}*/