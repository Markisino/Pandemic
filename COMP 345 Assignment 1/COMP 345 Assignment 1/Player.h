#pragma once

#include <iostream>
#include "Pawn.h"
#include "RoleCard.h"
#include "ReferenceCard.h"
#include "PlayerCard.h"
#include "InfectionCard.h"
#include <vector>

using namespace std;

#ifndef PLAYER_H
#define PLAYER_H
#endif // !PLAYER_H

class Player
{
public:
	Player();
	Player(Pawn);
	~Player();

	Pawn getPawn();
	string getName();
	string getColor();
	ReferenceCard getRefCard();
	PlayerCard getPlayCard(int i);

	void setPawn(Pawn);
	void setName(string);
	void setColor(string);
	void setRefCard(ReferenceCard);
	void setPlayCard(PlayerCard, PlayerCard, PlayerCard, PlayerCard);
	void drawInfCard(vector<InfectionCard> infCard);

private:
	Pawn pawn;
	string name, color;
	ReferenceCard refCard;
	PlayerCard playCard[4];

};

