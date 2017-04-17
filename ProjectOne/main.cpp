//Project 1
#include <iostream>
#include <string>
//The goal of this Project is to program the Spanish game "Siete y Medio"
	// The goal of the total game is to get as close as possible to 7.5 without going over it


// initial starting values for the game
const int PLAYER_MONEY = 100; 
const int MAX_DEALER_LOSS = 900;

const int NUM_OF_RANKS = 10;
const int NUM_OF_SUITS = 4;

// this function creates a 10*4 board for the 10 cards with 4 suits and 
// fills the ij-th entry of the array with the value of that card
void createBoard(double *a){
	for(int i=0; i< NUM_OF_RANKS; i++){
			if(i>=7){
				a[i]= 0.5;
			} // end if
			else{
				a[i]= i+1;
			}// end else
	}// end for loop
}// end function


int main(){

	double board[NUM_OF_RANKS];
	createBoard(board);

	for(int i=0; i< NUM_OF_RANKS; i++){
			std::cout << board[i] <<" ";
	}// end for loop


}// end main
