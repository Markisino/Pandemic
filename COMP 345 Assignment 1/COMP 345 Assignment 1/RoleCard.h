#pragma once

#include <string>

using namespace std;

#ifndef ROLECARD_H
#define ROLECARD_H
#endif // !ROLECARD_H

class RoleCard
{
public:
	RoleCard();
	RoleCard(string, string);
	~RoleCard();

	string getName();
	string getColor();

private:
	string name;
	string color;
	
};

