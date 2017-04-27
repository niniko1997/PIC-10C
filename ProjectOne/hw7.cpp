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
	
	srand(time(0));
	ofstream fileStream;
	fileStream.open("GameLog.txt");
	int gameNumber = 0;	    


	// how much money the dealer has lost thus far
	int dealerLoss = 0;

	// Starting the game with no bets
	std::cout << "\nBienvenidos a Siete y Medio.\n";
	int betMoney = 0;
	char ans;

	do {

		betMoney = 0;

		//Display how much user currently has
		std::cout<<"You currently have $" << PLAYER_MONEY <<".";

		//Prompt user to input how much he would like to bet and read the value 
		std::cout << "\t Enter Bet: ";
		std::cin >> betMoney;
		bool wentOnce = false;

		// check if input was valid, i.e. the player didn't bet over the given amount
		if (betMoney <= PLAYER_MONEY && betMoney > 0) {

			fileStream << "----------------------------------------------\n\n";
			fileStream << "Game Number: " << gameNumber << "\t Money Left: " << PLAYER_MONEY << "\n";
			fileStream << "Bet: " << betMoney << "\n\n"; 

			Player Dealer(MAX_DEALER_LOSS-dealerLoss);
			Player firstPlayer(PLAYER_MONEY);

			// have the player draw cards until his card value goes over 7.5 or until he chooses to stop
			do {

				firstPlayer.add_card(new Card());

				if (wentOnce) {
					std::cout << "\nNew Card: \n";
					std::cout << firstPlayer.getLastCard() <<"\n";
				}

				std::cout << "Your cards: \n";
				std::cout << firstPlayer.getCards();

				std::cout << "Your total is: " << firstPlayer.get_hand_value() << ". ";

				if (firstPlayer.get_hand_value() < 7.5) {
					std::cout << "Do you want another card? (y/n)";
					std::cin >> ans;
				}else {
					std::cout << "\nYou cannot draw any more cards, because your total exceeds 7 1/2. \n";
					ans = 'n';
				}

				wentOnce = true;
			} while (ans == 'y');

			fileStream << "Your cards: \n";
			fileStream << firstPlayer.getCards();
			fileStream << "Your total: " << firstPlayer.get_hand_value() << ". \n\n";

			std::cout << "\n";
			wentOnce = false;

			// have the dealer draw cards until his card value goes over 5.5
			do {
				Dealer.add_card(new Card());

				if (wentOnce) {
					std::cout << "New Card: \n";
					std::cout << Dealer.getLastCard() << "\n";
				}

				std::cout << "Dealer's cards: \n";
				std::cout << Dealer.getCards();

				std::cout << "The dealer's total is: " << Dealer.get_hand_value() << "\n";
				wentOnce = true;
			} while (Dealer.get_hand_value() < 5.5);

			fileStream << "Dealer's cards: \n";
			fileStream << Dealer.getCards();
			fileStream << "Dealer's total: " << Dealer.get_hand_value() << ". \n\n";


			if (Dealer.get_hand_value() > 7.5 && firstPlayer.get_hand_value() <= 7.5) {
				std::cout << "You win $" << betMoney << ".\n";
				dealerLoss = dealerLoss + betMoney;
				PLAYER_MONEY = PLAYER_MONEY + betMoney;
			}
			else if (firstPlayer.get_hand_value() > 7.5 && Dealer.get_hand_value() <= 7.5) {
				std::cout << "You lose $" << betMoney << ".\n";
				PLAYER_MONEY = PLAYER_MONEY - betMoney;
			}
			else if (Dealer.get_hand_value() > 7.5 && firstPlayer.get_hand_value() > 7.5) {
				std::cout << "You lose $" << betMoney << ".\n";
				PLAYER_MONEY = PLAYER_MONEY - betMoney;
			}
			else if (7.5 - firstPlayer.get_hand_value() < 7.5 - Dealer.get_hand_value()) {
				std::cout << "You win $" << betMoney << ".\n";
				PLAYER_MONEY = PLAYER_MONEY + betMoney;
				dealerLoss = dealerLoss + betMoney;
			}
			else if (7.5 - firstPlayer.get_hand_value() > 7.5 - Dealer.get_hand_value()) {
				std::cout << "You lose $" << betMoney << ".\n";
				PLAYER_MONEY = PLAYER_MONEY - betMoney;
			}
			else if (7.5 - firstPlayer.get_hand_value() == 7.5 - Dealer.get_hand_value()) {
				std::cout << "It's a tie. There is no exchange of money. \n";
			}

			std::cout << "\n\n";
		}else {
			std::cout << "Your input was invalid. \n";
		}

		wentOnce = false;
		gameNumber = gameNumber + 1 ;
     }while (PLAYER_MONEY > 0 && dealerLoss <= MAX_DEALER_LOSS);

	 std::cout << "\n THE GAME IS OVER. THANK YOU FOR PLAYING.\n";
}// end main
