#include "stdafx.h"
#include "PlayerCard.h"


PlayerCard::PlayerCard()
{
}

PlayerCard::PlayerCard(string name, string type)
{
	this->name = name;
	this->type = type;
}


PlayerCard::~PlayerCard()
{
}

string PlayerCard::getName()
{
	return name;
}

string PlayerCard::getType()
{
	return type;
}
