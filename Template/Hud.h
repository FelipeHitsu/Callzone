#pragma once 
#include <SDL.h>
#include <SDL_ttf.h>
#include <iostream>
class Hud
{
private:

	int M_WIDHT;
	int M_HEIGHT;


public:

	void Init(SDL_Renderer* renderer);
	Hud(int x,int y);
	void Render(SDL_Texture* texture_c, SDL_Renderer* renderer, int vida, int x, int y);
	~Hud();
};