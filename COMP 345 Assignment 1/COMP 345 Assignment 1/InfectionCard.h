#pragma once

#include <string>

using namespace std;


class InfectionCard
{
public:
	InfectionCard();
	InfectionCard(string);
	~InfectionCard();

	void infectCity();

private:
	string name;
};

