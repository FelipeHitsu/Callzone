#pragma once
#include "Personagem.h"

class P_Input
{
private:

	Game_Obj* ponteiro_de_Game_Obj;
	Personagem* p1;
	Personagem* p2;

public:

	void Process_Input();
	void GetPersonagem_1(Personagem* pp1);
	void GetPersonagem_2(Personagem* pp2);
};