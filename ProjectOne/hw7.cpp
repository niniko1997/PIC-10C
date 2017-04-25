//Project 1
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <ctime>
#include <cstdlib>
#include "cards.h"

//The goal of this Project is to program the Spanish game "Siete y Medio"
// The goal of the total game is to get as close as possible to 7.5 without going over it


// initial starting values for the game

int PLAYER_MONEY = 100;
const int MAX_DEALER_LOSS = 900;

const int NUM_OF_RANKS = 10;
const int NUM_OF_SUITS = 4;

int main() {
	

	// how much money the dealer has lost thus far
	int dealerLoss = 0;

	// Starting the game with no bets
	std::cout << "\nBienvenidos to Siete y Medio. You currently have " << PLAYER_MONEY << " pesos. \n";
	int betMoney = 0;
	std::string bet = "";
	char ans;
	bool isInt = false;

	do {

		bet = "";
		betMoney = 0;

		//Prompt user to input how much he would like to bet and read the value 
		std::cout << "Please enter how much you would like to bet (enter an int between 0 and " << PLAYER_MONEY << ") \n";
		getline(std::cin, bet);
		std::cin.ignore(10000, '\n');
		std::cout << "Bet: " << bet;
		
		//Convert string input into an integer
		for (int i = 0; i < bet.length(); i++) {
			if (!bet.empty() || (isdigit(bet[i]) && (bet[i] != '-') && (bet[i] != '+'))) {
				isInt = true;
			}
			else {
				isInt = false;
			}
		}

		if (isInt) {
			betMoney = atoi(bet.c_str());
		}

		// check if input was valid, i.e. the player didn't bet over the given amount
		if (betMoney <= PLAYER_MONEY && betMoney > 0 && isInt) {

			Player Dealer(MAX_DEALER_LOSS-dealerLoss);
			Player firstPlayer(PLAYER_MONEY);

			// have the player draw cards until his card value goes over 7.5 or until he chooses to stop
			do {

				firstPlayer.add_card(new Card());

				std::cout << "Your card is " << firstPlayer.getCurrentCard() << "\n";
				std::cout << "The current value of your cards is: " << firstPlayer.get_hand_value() << "\n";

				if (firstPlayer.get_hand_value() < 7.5) {
					std::cout << "Would you like to draw another card? (y/n) \n";
					std::cin >> ans;
				}
				else {
					std::cout << "You cannot draw any more cards, because your total exceeds 7 1/2. \n";
					ans = 'n';
				}

			} while (ans == 'y');

			std::cout << "\n";

			// have the dealer draw cards until his card value goes over 5.5
			do {
				Dealer.add_card(new Card());
				std::cout << "The Dealer's Card is " << Dealer.getCurrentCard() << "\n";
				std::cout << "The current value of the Dealer's cards is: " << Dealer.get_hand_value() << "\n";
			} while (Dealer.get_hand_value() < 5.5);


			if (Dealer.get_hand_value() > 7.5 && firstPlayer.get_hand_value() <= 7.5) {
				std::cout << "You win " << betMoney << " pesos! \n";
				dealerLoss = dealerLoss + betMoney;
				PLAYER_MONEY = PLAYER_MONEY + betMoney;
			}
			else if (firstPlayer.get_hand_value() > 7.5 && Dealer.get_hand_value() <= 7.5) {
				std::cout << "You lose " << betMoney << " pesos! \n";
				PLAYER_MONEY = PLAYER_MONEY - betMoney;
			}
			else if (Dealer.get_hand_value() > 7.5 && firstPlayer.get_hand_value() > 7.5) {
				std::cout << "You lose " << betMoney << " pesos! \n";
				PLAYER_MONEY = PLAYER_MONEY - betMoney;
			}
			else if (7.5 - firstPlayer.get_hand_value() < 7.5 - Dealer.get_hand_value()) {
				std::cout << "You win " << betMoney << " pesos! \n";
				PLAYER_MONEY = PLAYER_MONEY + betMoney;
				dealerLoss = dealerLoss + betMoney;
			}
			else if (7.5 - firstPlayer.get_hand_value() > 7.5 - Dealer.get_hand_value()) {
				std::cout << "You lose " << betMoney << " pesos! \n";
				PLAYER_MONEY = PLAYER_MONEY - betMoney;
			}
			else if (7.5 - firstPlayer.get_hand_value() == 7.5 - Dealer.get_hand_value()) {
				std::cout << "It's a tie. There is no exchange of money. \n";
			}

			std::cout << "\nNew Round: \n";
		}else {
			std::cout << "Your input was invalid \n";
		}
     }while (PLAYER_MONEY >= 0 || dealerLoss <= MAX_DEALER_LOSS);
}// end main
