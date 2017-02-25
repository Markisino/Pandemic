#include "stdafx.h"
#include "InfectionCard.h"
#include <iostream>

using namespace std;


InfectionCard::InfectionCard()
{
}

InfectionCard::InfectionCard(string name)
{
	this->name = name;
}


InfectionCard::~InfectionCard()
{
}

void InfectionCard::infectCity()
{
	cout << this->name << " has been infected!";
}
