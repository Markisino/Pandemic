#include "stdafx.h"
#include "Pawn.h"


Pawn::Pawn()
{
}

Pawn::Pawn(RoleCard role)
{
	this->role = role;
	name = role.getName();
	color = role.getColor();
}


Pawn::~Pawn()
{
}

RoleCard Pawn::getRole()
{
	return role;
}

string Pawn::getColor()
{
	return color;
}

string Pawn::getName()
{
	return name;
}


