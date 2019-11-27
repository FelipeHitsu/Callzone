#pragma once
#include "Game_Obj.h"

class Bala :public Game_Obj
{
private:

	float m_x;
	float m_y;
	float i_m_x;
	float i_m_y;
	float vel_x = 50.0;
	float vel_y = 50.0;
	int ladoBala;
	int anguloBala;

public:
	bool isActive = false;
	void Update();
	void setAngulo(int ang);
	void Render(SDL_Renderer* renderer, SDL_Texture* textureB);
	void SetActive(bool state);
	void SetPosition(float x, float y);
	void setLadoBala(int lado);
	void setInicialPos(int ix, int iy);
	void backInicialPos();
	Bala();
	~Bala();

};