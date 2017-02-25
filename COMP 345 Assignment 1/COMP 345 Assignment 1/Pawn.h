#pragma once

#include <iostream>
#include "RoleCard.h"

using namespace std;

#ifndef PAWN_H
#define PAWN_H
#endif // !PAWN_H



class Pawn
{
public:
	Pawn();		//Constructor
	Pawn(RoleCard);
	~Pawn();	//Destructor

	//Accessors
	RoleCard getRole();
	string getColor();
	string getName();

private:
	RoleCard role;
	string name, color;
	
};

