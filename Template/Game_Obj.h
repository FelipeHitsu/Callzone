#pragma once 
#include <SDL.h>
#include <iostream>
#include <vector>

using namespace std;
class Game_Obj
{
protected:
	SDL_Rect destination;
	


public:
	bool Colisao(Game_Obj objeto_1);
	bool getColisaoBala(Game_Obj objeto);
	
};
