#pragma once
#include <SDL.h>
#include <SDL_ttf.h>
#include <iostream>
class Texto
{
private:
	SDL_Texture* txtTextura = NULL;
	SDL_Surface* surface = NULL;
	SDL_Rect textoRect;
	SDL_Color txtCor;
	TTF_Font* fonte = NULL;
	int m_limitePixels;
	int m_x;
	int m_y;
	int tamanho;

public:
	Texto(int p_x, int p_y, int m_limitePixels);
	~Texto();
	
	void escreverTexto(std::string texto, int blue, int green, int red, int alpha, SDL_Renderer*renderer);
	void Desenhar(SDL_Renderer* renderer);
	void setTamanho(int t);
};

