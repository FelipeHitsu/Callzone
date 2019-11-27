#pragma once
#include <iostream>
#include <SDL.h>
#include "Game_Obj.h"

class Ingrediente:public Game_Obj
{
private:

	int tipo;
	int pos;
	bool coletado = false;
	int m_x;
	int m_y;
	int depx = 0;
	int depy = 0;
	int pos_rand_x;
	int pos_rand_y;
	
public:

	int Get_X() const;
	int Get_Y() const;
	void Sorteia_Pos_X();
	void Sorteia_Pos_Y();
	int getRandom(int de, int ate);
	void Desenha_Ingrediente(SDL_Renderer* renderer, SDL_Texture* textureIG);
	void Matar();
	void Respawn();
	void setXd();
	void setYd();
	bool getState() const;
	Ingrediente();

	~Ingrediente();
};

