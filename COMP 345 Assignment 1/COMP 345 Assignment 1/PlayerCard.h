#pragma once

#include <string>

using namespace std;

class PlayerCard
{
public:
	PlayerCard();
	PlayerCard(string, string);
	~PlayerCard();

	string getName();
	string getType();

private:
	string name, type;

};

