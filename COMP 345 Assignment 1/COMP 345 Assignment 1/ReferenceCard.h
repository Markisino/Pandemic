#pragma once

#include <iostream>
#include <string>

using namespace std;

class ReferenceCard
{
public:
	ReferenceCard();
	~ReferenceCard();

	string getHasCard();

private:
	string hasCard;
};

