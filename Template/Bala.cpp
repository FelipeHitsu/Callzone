#include "Bala.h"

void Bala::Update()
{
	if (m_x > 1366 || m_x < 0 || m_y > 768 || m_y < 0)
		SetActive(false);


	if (isActive)
	{
		if (ladoBala == 0)
		{
			m_x += vel_x;
			
		}
		else if (ladoBala == 1)
		{

			m_x -= vel_x;
			
		}
		else if (ladoBala == 2)
		{
			m_y -= vel_y;
			
		}
		else if (ladoBala == 3)
		{
			m_y += vel_y;
			
		}
	}
}
void Bala::Render(SDL_Renderer* renderer, SDL_Texture* textureB)
{
		destination = { static_cast<int>(m_x) , static_cast<int>(m_y) , 32, 32 };

	if (isActive)
		SDL_RenderCopyEx(renderer, textureB, 0, &destination, anguloBala, NULL, SDL_FLIP_NONE);

}
Bala::Bala()
{

}
Bala::~Bala()
{


}
void Bala::SetActive(bool state)
{
	isActive = state;
}
void Bala::SetPosition(float x, float y)
{
	this->m_x = x;
	this->m_y = y;

}
void Bala::setLadoBala(int lado)
{
	ladoBala = lado;
}
void Bala::setAngulo(int ang)
{
	anguloBala = ang;
}
void Bala::setInicialPos(int ix,int iy)
{
	i_m_x = ix;
	i_m_y = iy;

}
void Bala::backInicialPos()
{
	m_x = i_m_x;
	m_y = i_m_y;
}