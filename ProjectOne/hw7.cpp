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
   
const int PLAYER_MONEY = 100; 
const int MAX_DEALER_LOSS = 900;

const int NUM_OF_RANKS = 10;
const int NUM_OF_SUITS = 4;

int main(){
	Player Dealer(MAX_DEALER_LOSS);
	Player firstPlayer(PLAYER_MONEY);

	int dealerLoss = 0;
	std::cout<< "Bienvenidos to Siete y Medio. You currently have " << PLAYER_MONEY << " pesos. \n";	
	int betMoney = 0;

	char ans;
	do{

	   std::cout<< "Please enter how much you would like to bet (enter an int between 0 and " << PLAYER_MONEY << ") \n";
	   std::cin >> betMoney;
	   Dealer.add_card(new Card());

	   if(betMoney <= PLAYER_MONEY && betMoney > 0){
	   		do{
	   		    firstPlayer.add_card(new Card());

	   		    std::cout << "Your card is " << firstPlayer.getCurrentCard() << "\n";
	   		    std::cout << "The current value of your cards is: " << firstPlayer.get_hand_value() << "\n";
	   		    
	   		    if(firstPlayer.get_hand_value() < 7.5){
	   		    	std::cout << "Would you like to draw another card? (y/n) \n";
	   		   		std::cin >> ans;
	   		    }
	   		    else{
	   		    	std::cout << "You cannot draw any more cards, because your total exceeds 7 1/2."
	   		    	ans = 'n';
	   		    }
 		 
	   		}while(ans == 'y');

	       std::cout << "The Dealer's Card is " << Dealer.getCurrentCard() << "\n";

	       while(Dealer.get_hand_value() < 5.5){
	       	 	Dealer.add_card(new Card());

	       	 	std::cout << "The Dealer drew " << Dealer.getCurrentCard() << "\n";
	   		    std::cout << "The current value of the Dealer's cards is: " << Dealer.get_hand_value() << "\n";
	      }

	      if(dealer.get_hand_value() > 7.5 && firstPlayer.get_hand_value() <= 7.5){
	      		std::cout << "You win " << betMoney << " pesos! \n";
	      		firstPlayer.increase_money(betMoney);
	      		Dealer.decrease_money(betMoney);
	      		dealerLoss = dealerLoss + betMoney;
	      } else if (firstPlayer.get_hand_value() > 7.5 && dealer.get_hand_value() <= 7.5){
	      		std::cout << "You lose " << betMoney << " pesos! \n";
	      		firstPlayer.decrease_money(betMoney);
	      		Dealer.increase_money(betMoney);
	      } else if (dealer.get_hand_value() > 7.5 && firstPlayer.get_hand_value() > 7.5){
	      		std::cout << "You lose " << betMoney << " pesos! \n";
	      		firstPlayer.decrease_money(betMoney);
	      		Dealer.increase_money(betMoney);
	      } else if (7.5-firstPlayer.get_hand_value() < 7.5 - Dealer.get_hand_value()){
	      		std::cout << "You win " << betMoney << " pesos! \n";
	      		firstPlayer.increase_money(betMoney);
	      		Dealer.decrease_money(betMoney);
	      	    dealerLoss = dealerLoss + betMoney;
	      } else if (7.5-firstPlayer.get_hand_value() > 7.5 - Dealer.get_hand_value()){
	      		std::cout << "You lose " << betMoney << " pesos! \n";
	      		firstPlayer.decrease_money(betMoney);	
	      		Dealer.increase_money(betMoney);
	      } else if (7.5-firstPlayer.get_hand_value() == 7.5 - Dealer.get_hand_value()){
	      		std::cout << "It's a tie. There is no exchange of money. \n";
	      }

	   }
	   else{
	   	std::cout<< "Your input was invalid \n";
	   }

	   std::cout<< "New Round: \n";
	}while(firstPlayer.get_money() <= 0 || dealerLoss >= MAX_DEALER_LOSS);
}// end main
