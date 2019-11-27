#include <SDL.h>
#include <SDL_ttf.h>
#include <SDL_mixer.h>
#include <iostream>
#include <time.h>
#include <Windows.h>
#include <sstream>
#include "Personagem.h"
#include "Ingrediente.h"
#include "Hud.h"
#include "Game_Obj.h"
#include "Bala.h"
#include "Texto.h"
#include "P_Input.h"

/*------------------------------------------------------------------------------------------------------------------------------------------------*/
//Defines
#define SCREEN_WIDTH 1366
#define SCREEN_HEIGHT 768
#define PIXEL_SIZE 64
#define MIXER_DEFAULT_FORMAT AUDIO_S16SYS
/*-----------------------------------------------------------------------------------------------------------------------------------------------*/
//Globais
double dT;
int cont = 0;
int estado = 0;
int heroFacing;
int heroVida;
float heroX;
float heroY;
float inimigoX;
float inimigoY;
int inimigoVida;
int inimigoFacing;
int Score_P1 = 0;
int Score_P2 = 0;
int pontos;
int pontos_2;
bool vivo_1;
bool vivo_2;
bool vivo_3;
bool vivo_4;
bool men_cre = true;
/*---------------------------------------------------------------------------------------------------------------------------------------------*/
//Declaraçoes
void Init();
void Frame_Control();
void Sorteia();
void Checa_Colisao();
void Respawn();
Personagem p1(10, 1, 1227.200195, 50.0, 1);
Personagem p2(10, 1, 75.0, 50.0, 0);
Ingrediente i1;
Ingrediente i2;
Ingrediente i3;
Ingrediente i4;
P_Input Inputs;
Bala b1;
Bala b2;
Hud Fundo(SCREEN_WIDTH, SCREEN_HEIGHT);
Hud Fundo_2(SCREEN_WIDTH, SCREEN_HEIGHT);
/*---------------------------------------------------------------------------------------------------------------------------------------------*/

int main(int argc, char** argv)
{
	Init();
	TTF_Init();
	Texto ScoreP1(1000,27, 400);
	Texto ScoreP2(75, 27, 400);
	Texto Winner(450,440,1000);
	SDL_Init(SDL_INIT_EVERYTHING);
	srand(time(NULL));
	// criando janela
	SDL_Window* window = NULL;
	window = SDL_CreateWindow("CALL ZONE - Zona De Ligacao 1.0", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH, SCREEN_HEIGHT, 0);
	SDL_SetWindowFullscreen(window, 1);
	//criando renderer
	SDL_Renderer* renderer = NULL;
	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_SOFTWARE);
	Fundo.Init(renderer);
	while (men_cre == true)
	{
		{
			Mix_Music* musica_menu;
			musica_menu = Mix_LoadMUS("musica_menu.mp3");
			Mix_FadeInMusic(musica_menu, -1, 50);
			Mix_VolumeMusic(100);

			if (estado == 0)
			{
				SDL_Surface* surfaceINTRO;
				SDL_Texture* textureINTRO;

				surfaceINTRO = SDL_LoadBMP("intro.bmp");
				textureINTRO = SDL_CreateTextureFromSurface(renderer, surfaceINTRO);
				SDL_Rect intro;
				intro = { 0, 0, SCREEN_WIDTH, SCREEN_HEIGHT };


				SDL_RenderCopy(renderer, textureINTRO, 0, &intro);
				SDL_RenderPresent(renderer);


				Sleep(1000);



				SDL_Surface* surfaceMENU;
				SDL_Texture* textureMENU;




				surfaceMENU = SDL_LoadBMP("menu.bmp");
				textureMENU = SDL_CreateTextureFromSurface(renderer, surfaceMENU);
				SDL_Rect menu; //Por algum motivo BIZARRO não podia declarar e atribuir na mesma linha o REct

				menu = { 0, 0, SCREEN_WIDTH, SCREEN_HEIGHT };



				while (estado == 0)
				{
					SDL_Event e;
					if (SDL_PollEvent(&e) != 0)
					{
						if (e.type == SDL_KEYDOWN);
						{
							switch (e.key.keysym.sym)
							{
							case SDLK_RETURN:
								Mix_FadeOutMusic(50);
								Mix_FreeMusic(musica_menu);
								men_cre = false;
								estado = 1;

								break;

							case SDLK_SPACE:
								estado = 3;

								break;

							}
						}
					}

					SDL_RenderCopy(renderer, textureMENU, 0, &menu);
					SDL_RenderPresent(renderer);
				}
			}
			if (estado == 3)
			{
				SDL_Surface* surfaceCR;
				SDL_Texture* textureCR;
				surfaceCR = SDL_LoadBMP("creditos.bmp");
				textureCR = SDL_CreateTextureFromSurface(renderer, surfaceCR);

				SDL_Rect creditos;
				creditos = { 0, 0, SCREEN_WIDTH, SCREEN_HEIGHT };

				while (estado == 3)
				{
					SDL_Event e;
					if (SDL_PollEvent(&e) != 0)
					{
						if (e.type == SDL_KEYDOWN);
						{
							switch (e.key.keysym.sym)
							{

							case SDLK_BACKSPACE:
								estado = 0;

								break;

							}
						}
					}
					SDL_RenderCopy(renderer, textureCR, 0, &creditos);
					SDL_RenderPresent(renderer);
				}

			}

		}
	}

		if (estado == 1)
		{
			SDL_ShowCursor(SDL_DISABLE);

			SDL_Surface* surfaceBG;
			SDL_Texture* textureBG;
			surfaceBG = SDL_LoadBMP("cenario_finalfinalmsm.bmp");
			textureBG = SDL_CreateTextureFromSurface(renderer, surfaceBG);

			// carregando surface
			SDL_Surface* surface;
			SDL_Texture* texture;
			surface = SDL_LoadBMP("T_I_medium.bmp");
			SDL_SetColorKey(surface, SDL_RLEACCEL, SDL_MapRGB(surface->format, 255, 0, 255));
			texture = SDL_CreateTextureFromSurface(renderer, surface);

			SDL_Surface* surface2;
			SDL_Texture* texture2;
			surface2 = SDL_LoadBMP("T_C_medium.bmp");
			SDL_SetColorKey(surface2, SDL_RLEACCEL, SDL_MapRGB(surface2->format, 255, 0, 255));
			texture2 = SDL_CreateTextureFromSurface(renderer, surface2);

			SDL_Surface* surfaceIG;
			SDL_Texture* textureIG;
			surfaceIG = SDL_LoadBMP("Queijo.bmp");
			SDL_SetColorKey(surfaceIG, SDL_RLEACCEL, SDL_MapRGB(surfaceIG->format, 255, 0, 255));
			textureIG = SDL_CreateTextureFromSurface(renderer, surfaceIG);

			SDL_Surface* surfaceIG_2;
			SDL_Texture* textureIG_2;
			surfaceIG_2 = SDL_LoadBMP("mato.bmp");
			SDL_SetColorKey(surfaceIG_2, SDL_RLEACCEL, SDL_MapRGB(surfaceIG_2->format, 255, 0, 255));
			textureIG_2 = SDL_CreateTextureFromSurface(renderer, surfaceIG_2);

			SDL_Surface* surfaceIG_3;
			SDL_Texture* textureIG_3;
			surfaceIG_3 = SDL_LoadBMP("salame.bmp");
			SDL_SetColorKey(surfaceIG_3, SDL_RLEACCEL, SDL_MapRGB(surfaceIG_3->format, 255, 0, 255));
			textureIG_3 = SDL_CreateTextureFromSurface(renderer, surfaceIG_3);

			SDL_Surface* surfaceIG_4;
			SDL_Texture* textureIG_4;
			surfaceIG_4 = SDL_LoadBMP("tomate.bmp");
			SDL_SetColorKey(surfaceIG_4, SDL_RLEACCEL, SDL_MapRGB(surfaceIG_4->format, 250, 0, 250));
			textureIG_4 = SDL_CreateTextureFromSurface(renderer, surfaceIG_4);

			SDL_Surface* surfacePJ;
			SDL_Texture* texturePJ;
			surfacePJ = SDL_LoadBMP("bala.bmp");
			SDL_SetColorKey(surfacePJ, SDL_RLEACCEL, SDL_MapRGB(surfacePJ->format, 255, 0, 255));
			texturePJ = SDL_CreateTextureFromSurface(renderer, surfacePJ);

			SDL_Surface* surfaceS2;
			SDL_Texture* textureS2;
			surfaceS2 = SDL_LoadBMP("S2.bmp");
			SDL_SetColorKey(surfaceS2, SDL_RLEACCEL, SDL_MapRGB(surfaceS2->format, 255, 0, 255));
			textureS2 = SDL_CreateTextureFromSurface(renderer, surfaceS2);

			Mix_Music* musica_jogo;
			musica_jogo = Mix_LoadMUS("musica_jogo.mp3");
			Mix_FadeInMusic(musica_jogo, -1, 50);


			//Loop de Jogo
			Sorteia();

			while (!p1.quit)
			{

				//--------------------- LOOP DE JOGO ------------------------//
				//Fundo.Render(textureBG, renderer);
				SDL_Rect bg = { 0, 0, SCREEN_WIDTH, SCREEN_HEIGHT };
				SDL_RenderCopy(renderer, textureBG, 0, &bg);

				Inputs.GetPersonagem_1(&p1);
				Inputs.GetPersonagem_2(&p2);


				Mix_VolumeMusic(20);


				Checa_Colisao();

				i1.Desenha_Ingrediente(renderer, textureIG);

				i2.Desenha_Ingrediente(renderer, textureIG_2);

				i3.Desenha_Ingrediente(renderer, textureIG_3);

				i4.Desenha_Ingrediente(renderer, textureIG_4);

				p1.Renderer(renderer, texture, texturePJ, textureS2);
				p2.Renderer(renderer, texture2, texturePJ, textureS2);

				heroVida = p1.getVida();
				Fundo.Render(textureS2, renderer, heroVida, 1088, 12);
				Score_P1 = p1.getScore();

				inimigoVida = p2.getVida();
				Fundo_2.Render(textureS2, renderer, inimigoVida, 75, 12);
				Score_P2 = p2.getScore();

				
				
				
				std::stringstream strm;
				strm << Score_P1;
				std::string txt1 = "Francesco: " + strm.str();
				ScoreP1.escreverTexto(txt1, 0, 0, 0, 255, renderer);
				ScoreP1.Desenhar(renderer);

				
				std::stringstream strm2;
				strm2 << Score_P2;
				std::string txt2 = "Mushu: " + strm2.str();
				ScoreP2.escreverTexto(txt2, 0, 0, 0, 255, renderer);
				ScoreP2.Desenhar(renderer);

				SDL_RenderPresent(renderer);
				SDL_RenderClear(renderer);
				//Registra e processa inputs do jogador;
				Inputs.Process_Input();

				//Update de Lógica do jogo

				p1.Update();
				p2.Update();



				//---------------------FIM do LOOP DE JOGO ------------------------//
				Frame_Control();
			}
		}
		if (estado == 2)
		{
			
			SDL_Surface* surfaceOVER;
			SDL_Texture* textureOVER;
			surfaceOVER = SDL_LoadBMP("over.bmp");
			textureOVER = SDL_CreateTextureFromSurface(renderer, surfaceOVER);
			SDL_Rect over; //Por algum motivo BIZARRO não podia declarar e atribuir na mesma linha o REct
			over = { 0, 0, SCREEN_WIDTH, SCREEN_HEIGHT };

			


			Mix_Music* musica_over;
			musica_over = Mix_LoadMUS("musica_over.mp3");
			Mix_FadeInMusic(musica_over, -1,0);
			

			while (estado == 2)
			{
				Mix_VolumeMusic(100);

				SDL_RenderCopy(renderer, textureOVER, 0, &over);
				
				
				std::stringstream strm;
				strm << Score_P1;
				std::string txt1 = "Francesco: " + strm.str();
				ScoreP1.escreverTexto(txt1, 255, 255, 255, 255, renderer);
				ScoreP1.Desenhar(renderer);

				
				std::stringstream strm2;
				strm2 << Score_P2;
				std::string txt2 = "Mushu: " + strm2.str();
				ScoreP2.escreverTexto(txt2, 255, 255, 255, 255, renderer);
				ScoreP2.Desenhar(renderer);

				if (Score_P1 > Score_P2)
				{
					std::string txtwinner = "Francesco The Italian Wins" ;
					Winner.escreverTexto(txtwinner, 218, 165, 32, 255, renderer);
					Winner.Desenhar(renderer);
				}
				if (Score_P1 < Score_P2)
				{
					std::string txtwinner = "Mushu The Chinese Wins" ;
					Winner.escreverTexto(txtwinner, 218, 165, 32, 255, renderer);
					Winner.Desenhar(renderer);
				}
				if (Score_P1 == Score_P2)
				{
					std::string txtwinner = "We Have a Draw" ;
					Winner.escreverTexto(txtwinner, 218, 165, 32, 255, renderer);
					Winner.Desenhar(renderer);
				}

				
				SDL_Event e;

				if (SDL_PollEvent(&e) != 0)
				{
					if (e.type == SDL_KEYDOWN);
					{
						switch (e.key.keysym.sym)
						{
						
						case SDLK_ESCAPE:
							estado = 0;
							break;


						}
					}
				}
				
				SDL_RenderPresent(renderer);
				SDL_RenderClear(renderer);
			}
		}
	return 0;
}
void Init()
{
	SDL_INIT_AUDIO;
	Mix_OpenAudio(44100, MIXER_DEFAULT_FORMAT, 2, 4096);

}
void Frame_Control()
{
	//declarações para gameloop com FrameFixo
	int fps = 60;
	int fpsMill = 1000 / fps; //time of a frame in miliseconds
	int currentFrameTime;

	//variáveis de controle para loop de jogo fixado
	double startTime = SDL_GetTicks();
	currentFrameTime = SDL_GetTicks();

	//controle de frameRate fixo
	int pastTime = SDL_GetTicks() - currentFrameTime;
	if (fpsMill > pastTime)
		SDL_Delay(fpsMill - pastTime);

	//cálculo de dT
	double endTime = SDL_GetTicks();
	dT = (endTime - startTime) / 1000;
}
void Sorteia()
{
	i1.Sorteia_Pos_X();
	i1.Sorteia_Pos_Y();
	
	int xi1 = i1.Get_X();
	int yi1 = i1.Get_Y();

	i2.Sorteia_Pos_X();
	i2.Sorteia_Pos_Y();

	int xi2 = i2.Get_X();
	int yi2 = i2.Get_Y();

	if (xi2 == xi1 && yi2 == yi1)
	{
		i2.Sorteia_Pos_X();
		i2.Sorteia_Pos_Y();
	}

	i3.Sorteia_Pos_X();
	i3.Sorteia_Pos_Y();

	int xi3 = i3.Get_X();
	int yi3 = i3.Get_Y();

	if (xi3 == xi2 && yi3 == yi2
		|| xi3 == xi1 && yi3 == yi1)
	{
		i3.Sorteia_Pos_X();
		i3.Sorteia_Pos_Y();
	}

	i4.Sorteia_Pos_X();
	i4.Sorteia_Pos_Y();

	int xi4 = i4.Get_X();
	int yi4 = i4.Get_Y();

	if (xi4 == xi3 && yi4 == yi3
		|| xi4== xi2 && yi4 == yi2
		|| xi4 == xi1 && yi4 == yi1)
	{
		i4.Sorteia_Pos_X();
		i4.Sorteia_Pos_Y();

	}
}
void Checa_Colisao()
{
	heroFacing = p1.getFacing();
	inimigoFacing = p2.getFacing();
	heroX = p1.getX();
	heroY = p1.getY();
	inimigoX = p2.getX();
	inimigoY = p2.getY();

	if (p1.Colisao(p2))
	{
		if (heroFacing == 0)
		{
			p1.SetSpeedX(0.00);
			p1.setX(heroX - 2.00);
		}

		if (heroFacing == 1)
		{
			p1.SetSpeedX(0.00);
			p1.setX(heroX + 2.00);
		}
			
		if (heroFacing == 2)
		{
			p1.SetSpeedY(0.00);
			p1.setY(heroY + 2.00);
		}
			
		if (heroFacing == 3)
		{
			p1.SetSpeedY(0.00);
			p1.setY(heroY - 2.00);  

		}
		
	} 

	if (p2.Colisao(p1))
	{
		if (inimigoFacing == 0)
		{
			p2.SetSpeedX(0.00);
			p2.setX(inimigoX - 2.00);
		}

		if (inimigoFacing == 1)
		{
			p2.SetSpeedX(0.00);
			p2.setX(inimigoX + 2.00);
		}

		if (inimigoFacing == 2)
		{
			p2.SetSpeedY(0.00);
			p2.setY(inimigoY + 2.00);
		}

		if (inimigoFacing == 3)
		{
			p2.SetSpeedY(0.00);
			p2.setY(inimigoY - 2.00);

		}

	} 

	if (p1.Colisao(p2.getBala()))
	{
		p1.decVida(1);
		p2.puxaBala();
		Score_P2 = Score_P2 + 100;
		p2.setScore(Score_P2);
	}
	if (p2.Colisao(p1.getBala()))
	{
		p2.decVida(1);
		p1.puxaBala();
		Score_P1 = Score_P1 + 100;
		p1.setScore(Score_P1);
	}

	if (i1.Colisao(p1))
	{
		i1.Matar();
		Score_P1 = Score_P1 + 100;
		p1.setScore(Score_P1);
		i1.setXd();
		i1.setYd();
	}
	if (i2.Colisao(p1))
	{
		i2.Matar();
		Score_P1 = Score_P1 + 100;
		p1.setScore(Score_P1);
		i2.setXd();
		i2.setYd();
	}
	if (i3.Colisao(p1))
	{
		i3.Matar();
		Score_P1 = Score_P1 + 100;
		p1.setScore(Score_P1);
		i3.setXd();
		i3.setYd();
	}
	if (i4.Colisao(p1))
	{
		i4.Matar();
		Score_P1 = Score_P1 + 100;
		p1.setScore(Score_P1);
		i4.setXd();
		i4.setYd();
	}

	if (i1.Colisao(p2))
	{
		i1.Matar();
		Score_P2 = Score_P2 + 100;
		p2.setScore(Score_P2);
		i1.setXd();
		i1.setYd();
	}
	if (i2.Colisao(p2))
	{
		i2.Matar();
		Score_P2 = Score_P2 + 100;
		p2.setScore(Score_P2);
		i2.setXd();
		i2.setYd();
	}
	if (i3.Colisao(p2))
	{
		i3.Matar();
		Score_P2 = Score_P2 + 100;
		p2.setScore(Score_P2);
		i3.setXd();
		i3.setYd();
	}
	if (i4.Colisao(p2))
	{
		i4.Matar();
		Score_P2 = Score_P2 + 100;
		p2.setScore(Score_P2);
		i4.setXd();
		i4.setYd();
	}

	

	Respawn();

	int vida_1 = p1.getVida();
	int vida_2 = p2.getVida();
	if (vida_1 <= 0 || vida_2 <= 0)
	{
		estado = 2;
		p1.quit = true;
		Mix_FadeOutMusic(50);
	}
		
}
void Respawn()
{
	vivo_1 = i1.getState();
	vivo_2 = i2.getState();
	vivo_3 = i3.getState();
	vivo_4 = i4.getState();

	if (vivo_1 == true && vivo_2 == true && vivo_3 == true && vivo_4 == true)
	{ 
		i1.Sorteia_Pos_X();
		i1.Sorteia_Pos_Y();
		i1.Respawn();

	
		i2.Sorteia_Pos_X();
		i2.Sorteia_Pos_Y();
		i2.Respawn();

	
	
		i3.Sorteia_Pos_X();
		i3.Sorteia_Pos_Y();
		i3.Respawn();

	
		i4.Sorteia_Pos_X();
		i4.Sorteia_Pos_Y();
		i4.Respawn();
	}
	
}