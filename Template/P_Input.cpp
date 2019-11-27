#include "P_Input.h"

void P_Input::Process_Input()
{
	SDL_Event e;
	if (SDL_PollEvent(&e) != 0)
	{
		if (e.type == SDL_QUIT) //Se evento de Sair (clicou X)
		{
			p1->quit = true;
		}
		const Uint8* currentKeyStates = SDL_GetKeyboardState(NULL);
		if (currentKeyStates[SDL_SCANCODE_UP])
		{
			p1->SetMovUp();
		}
		if (currentKeyStates[SDL_SCANCODE_DOWN])
		{
			p1->SetMovDown();
		}
		if (currentKeyStates[SDL_SCANCODE_LEFT])
		{
			p1->SetMovLeft();
		}
		if (currentKeyStates[SDL_SCANCODE_RIGHT])
		{
			p1->SetMovRight();
		}
		if (currentKeyStates[SDL_SCANCODE_SPACE])
		{
			p1->Atira();
		}
		if (currentKeyStates[SDL_SCANCODE_ESCAPE])
		{
			p1->quit = true;
		}
		if (currentKeyStates[SDL_SCANCODE_W])
		{
			p2->SetMovUp();
		}
		if (currentKeyStates[SDL_SCANCODE_S])
		{
			p2->SetMovDown();
		}
		if (currentKeyStates[SDL_SCANCODE_A])
		{
			p2->SetMovLeft();
		}
		if (currentKeyStates[SDL_SCANCODE_D])
		{
			p2->SetMovRight();
		}
		if (currentKeyStates[SDL_SCANCODE_Q])
		{
			p2->Atira();
		}
	}
}
void P_Input::GetPersonagem_1(Personagem* pp1)
{
	p1 = pp1;
}
void P_Input::GetPersonagem_2(Personagem* pp2)
{
	p2 = pp2;
}