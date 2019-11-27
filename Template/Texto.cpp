#include "Texto.h"


Texto::Texto(int p_x,int p_y,int p_limitePixels)
{
	m_x = p_x;
	m_y = p_y;
	m_limitePixels = p_limitePixels;
	textoRect = { m_x, m_y, 0, 0 };
	fonte = TTF_OpenFont("fonte_da_isa.ttf", 20);
	if (fonte == NULL)
		std::cout << "Erro no arquivo ttf" << std::endl;
}


Texto::~Texto()
{
}

void Texto::escreverTexto(std::string txt, int blue, int green, int red, int alpha, SDL_Renderer*renderer)
{
	txtCor = { static_cast<Uint8>(blue), static_cast<Uint8>(green), static_cast<Uint8>(red), static_cast<Uint8>(alpha) };
 
	surface = TTF_RenderText_Blended_Wrapped(fonte, txt.c_str(), txtCor, m_limitePixels);
	txtTextura = SDL_CreateTextureFromSurface(renderer, surface);
	SDL_QueryTexture(txtTextura, NULL, NULL, &textoRect.w, &textoRect.h);
	SDL_FreeSurface(surface);
}

void Texto::Desenhar(SDL_Renderer* renderer)
{
	SDL_RenderCopy(renderer, txtTextura, NULL, &textoRect);
	SDL_DestroyTexture(txtTextura);
}
void Texto::setTamanho(int t)
{
	tamanho = t;
}
