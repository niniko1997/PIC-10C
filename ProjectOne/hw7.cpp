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

	std::cout<< "Bienvenidos to Siete y Medio. You currently have " << PLAYER_MONEY << " pesos. \n";	
	int betMoney = 0;
	do{

	   std::cout<< "Please enter how much you would like to bet (enter an int between 0 and " << PLAYER_MONEY << ") \n";
	   std::cin>> betMoney;

	   if(betMoney <= PLAYER_MONEY && betMoney > 0){
	   		do{
	   		    Dealer.add_card(new Card());
	   		    firstPlayer.add_card(new Card());
	   		}while(false);
	   }
	   else{
	   	std::cout<< "Your input was invalid \n";
	   }

	}while(false);
}// end main
