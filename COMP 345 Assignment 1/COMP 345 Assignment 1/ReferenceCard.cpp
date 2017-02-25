#include "stdafx.h"
#include "ReferenceCard.h"


ReferenceCard::ReferenceCard()
{
	hasCard = "This person has a reference card";
}


ReferenceCard::~ReferenceCard()
{
}

string ReferenceCard::getHasCard()
{
	return hasCard;
}
