#include "stdafx.h"
#include "Player.h"


Player::Player()
{
	refCard = ReferenceCard();
}

Player::Player(Pawn)
{
	this->pawn = pawn;
	setName(pawn.getName());
	color = pawn.getColor();
	refCard = ReferenceCard();
}


Player::~Player()
{
}

Pawn Player::getPawn()
{
	return pawn;
}

string Player::getName()
{
	return name;
}

string Player::getColor()
{
	return color;
}

ReferenceCard Player::getRefCard()
{
	return refCard;
}

PlayerCard Player::getPlayCard(int i)
{
	return playCard[i];
}

void Player::setPawn(Pawn pawn)
{
	this->pawn = pawn;
}

void Player::setName(string name)
{
	this->name = name;
}

void Player::setColor(string color)
{
	this->color = color;
}

void Player::setRefCard(ReferenceCard refCard)
{
	this->refCard = refCard;
}

void Player::setPlayCard(PlayerCard pc0, PlayerCard pc1, PlayerCard pc2, PlayerCard pc3)
{
	playCard[0] = pc0;
	playCard[1] = pc1;
	playCard[2] = pc2;
	playCard[3] = pc3;
}

void Player::drawInfCard(vector<InfectionCard> infCard)
{
	infCard.back().infectCity();
	infCard.pop_back();
}

