#pragma once
#include <SDL.h>
#include <SDL_mixer.h>
#include "Bala.h"

 
class Personagem:public Game_Obj	
{
private:
	Bala bala;
	int vida;
	int dano;
	int Score = 0;
	float x;
	float y;
	bool alive;
	bool colide;
	float speedX = 0;
	float speedY = 0;
	int facing = 0; //0 == dir, 1 == esq, 2 == cima, 3 == baixo
	float lastSpeedX = 0;
	float lastSpeedY = 0;
	int angulo;
	float V_Limite = 4.00;
	float V_Limite_N = -4.00;
	void FreioY(float a);
	void FreioX(float a);


public:

	Personagem(int pvida, int pdano, float px, float py,int pfacing);
	void SetMovUp();
	void SetMovLeft();
	void SetMovRight();
	void SetMovDown();
	void Atira();
	void Renderer(SDL_Renderer*renderer, SDL_Texture*texture, SDL_Texture* textureB, SDL_Texture* texture_c);
	void SetSpeedX(float speed);
	void SetSpeedY(float speed);
	void Update();
	bool quit = false;
	float getX() const;
	float getY() const;
	void setX(float px);
	void setY(float py);
	int getFacing() const;
	int getVida() const;
	int getScore() const;
	Bala getBala() const;
	void setScore(int pontos);
	void decVida(int dec);
	void puxaBala();
	~Personagem();

};

