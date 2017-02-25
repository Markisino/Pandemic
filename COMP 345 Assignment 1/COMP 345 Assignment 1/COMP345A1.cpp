// COMP345A1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Player.h"
#include "Pawn.h"
#include "RoleCard.h"
#include <iostream>
#include "COMP345A1.h"
#include <cstdlib>
#include <ctime>
#include <vector>
#include <array>
#include "InfectionCard.h"

using namespace std;

int main()
{

	//COMMON PART

	cout << "START OF COMMON PART" << endl << endl;

	//START OF INITIALIZATION OF GAME

	srand(time(NULL));

	vector<PlayerCard> playCard;

	for (int i = 0; i < 6; i++) {	//Creating Epidemic Cards
		playCard.push_back(PlayerCard("Name", "Epidemic"));
	}

	for (int i = 6; i < 11; i++) {	//Creating Event Cards
		playCard.push_back(PlayerCard("Name", "Event"));
	}

	for (int i = 11; i < 59; i++) {	//Creating City Cards
		playCard.push_back(PlayerCard("Name", "City"));
	}

	random_shuffle(&playCard[6], &playCard[58]);	//Shuffle Event and City Cards

	RoleCard scientistRole("Scientist", "White"), medicRole("Medic", "Orange"), dispatcherRole("Dispatcher", "Pink"), quarantineRole("Qurantine Specialist", "Green"), operationsRole("Operations Expert", "Lime"), contingencyRole("Contingency Planner", "Blue"), researcherRole("Researcher", "Brown");	//Initialized all 7 roles
	Pawn scientistPawn(scientistRole), medicPawn(medicRole), dispatcherPawn(dispatcherRole), quarantinePawn(quarantineRole), operationsPawn(operationsRole), contingencyPawn(contingencyRole), researcherPawn(researcherRole); //Initialized all 7 pawns
	Player player[2]; //Initialized 2 players

	int random[2] = { (rand() % 7 + 1), (rand() % 7 + 1) };	//Randomize player roles

	while (random[0] == random[1]) {	//If selected roles are the same change second player's role until different
		random[1] = rand() % 7 + 1;
	}

	for (int i = 0; i < 2; i++) { 	//Apply role to player

		if (random[i] == 1) {
			player[i].setPawn(scientistPawn);
			player[i].setName(scientistPawn.getName());
			player[i].setColor(scientistPawn.getColor());
		}

		else if (random[i] == 2) {
			player[i].setPawn(medicPawn);
			player[i].setName(medicPawn.getName());
			player[i].setColor(medicPawn.getColor());
		}

		else if (random[i] == 3) {
			player[i].setPawn(dispatcherPawn);
			player[i].setName(dispatcherPawn.getName());
			player[i].setColor(dispatcherPawn.getColor());
		}

		else if (random[i] == 4) {
			player[i].setPawn(quarantinePawn);
			player[i].setName(quarantinePawn.getName());
			player[i].setColor(quarantinePawn.getColor());
		}

		else if (random[i] == 5) {
			player[i].setPawn(operationsPawn);
			player[i].setName(operationsPawn.getName());
			player[i].setColor(operationsPawn.getColor());
		}

		else if (random[i] == 6) {
			player[i].setPawn(contingencyPawn);
			player[i].setName(contingencyPawn.getName());
			player[i].setColor(contingencyPawn.getColor());
		}

		else if (random[i] == 7) {
			player[i].setPawn(researcherPawn);
			player[i].setName(researcherPawn.getName());
			player[i].setColor(researcherPawn.getColor());
		}
	} 

	PlayerCard pOneCards[4];	//Initialize player[0] cards

	for (int i = 0; i < 4; i++) {	//Draw from player deck
		pOneCards[i] = playCard.back();
		playCard.pop_back();
	}

	PlayerCard pTwoCards[4];	//Initialize player[1] cards

	for (int i = 0; i < 4; i++) {	//Draw from player deck
		pTwoCards[i] = playCard.back();
		playCard.pop_back();
	}

	player[0].setPlayCard(pOneCards[0], pOneCards[1], pOneCards[2], pOneCards[3]);	//Set player cards to players
	player[1].setPlayCard(pTwoCards[0], pTwoCards[1], pTwoCards[2], pTwoCards[3]);

	//END OF INITIALIZATION OF GAME

	cout << "Player 1 Info" << endl <<	//Display information for player[0]
		"Role: " << player[0].getName() << endl <<
		"Color: " << player[0].getColor() << endl <<
		"Reference Card: " << player[0].getRefCard().getHasCard() << endl <<
		"Player Cards: " << player[0].getPlayCard(0).getType() << " " << player[0].getPlayCard(1).getType() << " " << player[0].getPlayCard(2).getType() << " " << player[0].getPlayCard(3).getType() << endl;

	cout << endl << endl;

	cout << "Player 2 Info" << endl <<	//Display information for player[1]
		"Role: " << player[1].getName() << endl <<
		"Color: " << player[1].getColor() << endl <<
		"Has Reference Card: " << player[1].getRefCard().getHasCard() << endl <<
		"Player Cards: " << player[1].getPlayCard(0).getType() << " " << player[1].getPlayCard(1).getType() << " " << player[1].getPlayCard(2).getType() << " " << player[1].getPlayCard(3).getType() << endl;

	cout << endl << endl;

	cout << "END OF COMMON PART" << endl << endl;

	//END OF COMMON PART

	//DISTINCT PART 2

	cout << "START OF DISTINCT PART 2" << endl << endl;

	Player anotherPlayer;	//Initialize player
	vector<InfectionCard> infCard;	//Initialize Infection Card deck

	infCard.push_back(InfectionCard("Miami"));	//Add cards to ifection deck
	infCard.push_back(InfectionCard("Rome"));
	infCard.push_back(InfectionCard("Tokyo"));
	infCard.push_back(InfectionCard("Paris"));
	infCard.push_back(InfectionCard("Munich"));

	random_shuffle(&infCard[0], &infCard[4]);	//Shuffle infection deck

	

	while(!infCard.empty()){	//While infection deck not empty, infect cities
		cout << "Enter any integer to infect a city" << endl;

		int y;
		cin >> y;

		infCard.back().infectCity();
		infCard.pop_back();

		cout << endl;

	}

	cout << "All cities infected!";

	int x;
	cin >> x;	//Used to not shut down program righ away

	//END OF DISTINCT PART 2

    return 0;
}

