// ConsoleApplication1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include <cstdlib>
#include <iomanip>
using namespace std;

void battingAvg(string, double &);
void proficiencyLevel(double, string &);


int main()
{
	double playerAvg = 0;
	string playerName;
	string proficiency;
	char reset;

	do {

		cout << "Enter the name of the player you would like to know the batting average for: ";
		getline(cin, playerName);
		cout << endl;

		battingAvg(playerName, playerAvg);
		proficiencyLevel(playerAvg, proficiency);
		cout << fixed << setprecision(3);
		cout << "The batting average for " << playerName << " is " << playerAvg << endl;
		cout << playerName << "'s Batting Proficiency is " << proficiency << "!!" << endl << endl; 

		cout << "Would you like to enter a new player? (Enter Y for YES || Enter N to EXIT):";
		cin >> reset;

		if (reset == 'n' || reset == 'N')
		{
			exit(0);
		}
		else if (reset != 'n' || reset != 'N' || reset != 'y' || reset != 'Y')
		{
			do {
				cout << "***ERROR*** Not a valid input --> Re-Enter: ";
				cin >> reset;
			} while (reset != 'n' || reset != 'N' || reset != 'y' || reset != 'Y');
		}

		cin.ignore();

	} while (reset == 'y' || reset == 'Y');

    return 0;
}

//************************************
//      Batting Average Function	 *
//************************************

void battingAvg(string playerName, double &playerAvg) {

	int game = 1;
	int hits = 0;
	int atBat = 0;
	double totalHits = 0;
	double totalAtBat = 0;
	char entry;

	do {
		cout << "***********   GAME " << game << "   ***********" << endl << endl;
		cout << "Enter the hits for " << playerName << ":";

		cin >> hits;
		if (hits < 0) {
			do {
				cout << "***ERROR*** Not a valid input. --> Re-Enter: ";
				cin >> hits;
			} while (hits < 0);
		}

		cout << "Enter the number of at bats for " << playerName << ":";
		cin >> atBat;
		if (atBat < 0) {
			do {
				cout << "***ERROR*** Not a valid input. --> Re-Enter: ";
				cin >> atBat;
			} while (atBat < 0);
		}

		if (hits > atBat) {
			cout << "***ERROR*** Please Re-Enter this game ";
			game--;
			totalAtBat -= atBat;
			totalHits -= hits;
		}
		cout << endl;

		totalAtBat += atBat;
		totalHits += hits;
		game++;


		cout << "Would you like to add another entry? (Enter Y for YES || Enter N for NO):";
		cin >> entry;


			do {
				if (entry == 'n' || entry == 'N') {
					break;
				}
				else if (entry == 'y' || entry == 'Y') {
					break;
				}
				else {
					cout << "***ERROR*** Not a valid input --> Re-Enter: ";
					cin >> entry;
				}
			} while (entry != 'n' || entry != 'N' || entry != 'y' || entry != 'Y');

	} while (entry == 'y' || entry == 'Y');

	playerAvg = totalHits / totalAtBat;
}

//************************************
//       Proficiency Function   	 *
//************************************

void proficiencyLevel(double playerAvg, string &proficiency) {

	if (playerAvg >= .000 && playerAvg < .250) {
		proficiency = "Minor Leaguer";
	}
	else if (playerAvg >= .250 && playerAvg < .300) {
		proficiency = "All Star";
	}
	else if (playerAvg >= .300 && playerAvg < .400) {
		proficiency = "Hall of Famer";
	}
	else if (playerAvg >= .400) {
		proficiency = "King of Baseball";
	}
	else {
		cout << "ERROR Something went wrong";
	}


}