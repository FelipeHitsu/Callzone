#include "Ingrediente.h"


Ingrediente::Ingrediente()
{

}


Ingrediente::~Ingrediente()
{
	
}

void Ingrediente::Desenha_Ingrediente(SDL_Renderer* renderer, SDL_Texture* textureIG)
{
	

		destination = { m_x, m_y, 32, 32 };


		if (!coletado)
			SDL_RenderCopy(renderer, textureIG, 0, &destination);
		 


		
	
}

void Ingrediente::Sorteia_Pos_X()
{
	int pos_rand_x = 0;
	
	
	
	
	
	pos_rand_x = getRandom(75, 1200);

		

		m_x = pos_rand_x;
	

}
void Ingrediente::Sorteia_Pos_Y()
{
	
	int pos_rand_y;

	

	
		
		pos_rand_y = rand() % (760 - 64);
		

		
		m_y =  pos_rand_y;
	

}
int Ingrediente::Get_X() const
{
	return m_x;
}
int Ingrediente::Get_Y() const
{
	return m_y;
}
int Ingrediente::getRandom(int de, int ate)
{
	ate -= de;
	return rand() % (ate + 1) + de;
}
void Ingrediente::Matar()
{
	coletado = true;
}
void Ingrediente::Respawn()
{
	coletado = false;
}
bool Ingrediente::getState() const
{
	return coletado;
}
void Ingrediente::setXd()
{
	m_x = depx;
}
void Ingrediente::setYd()
{
	m_y = depy;
}