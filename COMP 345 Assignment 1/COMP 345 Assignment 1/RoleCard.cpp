#include "stdafx.h"
#include "RoleCard.h"


RoleCard::RoleCard()
{
}

RoleCard::RoleCard(string name, string color)
{
	this->name = name;
	this->color = color;
}

RoleCard::~RoleCard()
{
}

string RoleCard::getName()
{
	return name;
}

string RoleCard::getColor()
{
	return color;
}
