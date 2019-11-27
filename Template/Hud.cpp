#include "Hud.h"

 Hud::Hud(int x, int y)
{
	 x = M_WIDHT;
	 y = M_HEIGHT;
}
void Hud::Render(SDL_Texture* texture_c, SDL_Renderer* renderer,int vida,int x,int y)
{
	int x_p = x;
	int x_r = 20;
	int x_y = y;
	SDL_Rect core;
	

	for (int x = 0; x < vida; x++)
	{
		core = { x_p, y, x_r, 15 };
		SDL_RenderCopy(renderer, texture_c, 0, &core);

		x_p = x_p + x_r;
		
	}

	
}
void Hud::Init(SDL_Renderer* renderer)
{
	
}
Hud::~Hud()
{

}