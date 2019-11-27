#include "Personagem.h"

Personagem::Personagem(int pvida, int pdano, float px, float py, int pfacing) : Game_Obj()
{
	
	vida = pvida;
	dano = pdano;
	x = px;
	y = py;
	facing = pfacing;

	if (pfacing == 0)
		angulo = 360;
	if (pfacing == 1)
		angulo = 180;
	if (pfacing == 2)
		angulo = -90;
	if (pfacing == 3)
		angulo = 90;

	/*Mix_OpenAudio(44100, AUDIO_S16SYS, 2, 4096);
	Mix_Chunk* vrum_snd;
	vrum_snd = Mix_LoadWAV("vrum.wav");
	Mix_VolumeChunk(vrum_snd, 64);
	Mix_AllocateChannels(2);
	Mix_Volume(-1, 128);
*/

}

void Personagem::SetMovUp()
{
	angulo = -90;
	facing = 2;
	lastSpeedY = speedY;
	speedY--;
}
void Personagem::SetMovDown()
{
	angulo = 90;
	facing = 3;
	lastSpeedY = speedY;
	speedY++;
}
void Personagem::SetMovLeft()
{
	angulo = 180;
	facing = 1;
	lastSpeedX = speedX;
	speedX--;
}
void Personagem::SetMovRight()
{
	angulo = 360;
	facing = 0;
	lastSpeedX = speedX;
	speedX++;

}
void Personagem::Atira()
{
	bala.setLadoBala(facing);
	bala.setAngulo(angulo);
	bala.SetPosition((x + 16), (y + 16.0));
	bala.SetActive(true);

}
void Personagem::Renderer(SDL_Renderer*renderer, SDL_Texture*texture, SDL_Texture* textureB,SDL_Texture* texture_c)
{
	destination = { static_cast<int>(x), static_cast<int>(y), 64, 64 };
	SDL_RenderCopyEx(renderer, texture, 0, &destination, angulo, NULL, SDL_FLIP_NONE);

	bala.Render(renderer, textureB);	
}
void Personagem::FreioX(float a)
{
	if (lastSpeedX> 0)
	{
		if (speedX > 0)
			speedX -= a;
		else
			speedX = 0;
	}
	else if (lastSpeedX < 0)
	{
		if (speedX < 0)
			speedX += a;
		else
			speedX = 0;
	}
}
void Personagem::FreioY(float a)
{
	if (lastSpeedY > 0)
	{
		if (speedY > 0)
			speedY -= a;
		else
			speedY = 0;
	}
	else if (lastSpeedY < 0)
	{
		if (speedY < 0)
			speedY += a;
		else
			speedY = 0;
	}
}
void Personagem::SetSpeedX(float speed)
{
	speedX = speed;
}
void Personagem::SetSpeedY(float speed)
{
	speedY = speed;
}
void Personagem::Update()
{
	x += speedX;
	if (speedX >= V_Limite)
		speedX = V_Limite;
	else if (speedX <= V_Limite_N)
		speedX = V_Limite_N;
	
	y += speedY;
	if (speedY >= V_Limite)
		speedY = V_Limite;
	else if (speedY <= V_Limite_N)
		speedY = V_Limite_N;


	if (facing == 0)
	{
		FreioY(0.7);
		//player1.speedY = 0;
		if (speedX > 0)
			speedX -= 0.4;
		else
			speedX = 0;
	}
	else if (facing == 1)
	{
		FreioY(0.7);
		//player1.speedY = 0;
		if (speedX < 0)
			speedX += 0.4;
		else
			speedX = 0;
	}
	else if (facing == 2)
	{
		FreioX(0.7);
		//player1.speedX = 0;
		if (speedY < 0)
			speedY += 0.4;
		else
			speedY = 0;
	}
	else if (facing == 3)
	{
		FreioX(0.7);
		//player1.speedX = 0;
		if (speedY > 0)
			speedY -= 0.4;
		else
			speedY = 0;
	}

	if (x >= 1240)
		x = 1240;
	if (y >= 700)
		y = 700;
	if (x <= 70)
		x = 70;
	if (y <= 0)
		y = 0;

	bala.Update();
	bala.setInicialPos((x + 16), (y + 16.0));
	
}
void Personagem::setX(float px)
{
	x = px;
}
void Personagem::setY(float py)
{
	y = py;
}
int Personagem::getFacing() const
{
	return facing;
}
int Personagem::getVida() const
{
	return vida;
}
float Personagem::getX() const
{
	return x;
}
float Personagem::getY() const
{
	return y;
}
int Personagem::getScore() const
{
	return Score;
}
Bala Personagem::getBala() const
{
	return bala;
}
void Personagem::setScore(int pontos)
{
	Score = pontos;
}
void Personagem::decVida(int dec)
{
	vida = vida - dec;
}
void Personagem::puxaBala()
{
	bala.backInicialPos();
	bala.SetActive(false);
}
Personagem::~Personagem()
{

}
