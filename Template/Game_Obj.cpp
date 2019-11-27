#include "Game_Obj.h"

bool Game_Obj::Colisao(Game_Obj objeto_1)
{
	SDL_Rect Asereheradere;
	return SDL_IntersectRect(&destination, &objeto_1.destination, &Asereheradere);
}
//bool Game_Obj::getColisaoBala(Game_Obj objeto) 
//{
//	
//}
