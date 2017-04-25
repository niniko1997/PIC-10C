#include "cards.h"
#include <algorithm>

#include <cstdlib>
#include <iostream>
#include <iomanip>


// *************************************************
// CARDS CLASS

/*
Default constructor for the Card class.
It could give repeated cards. This is OK.
Most variations of Blackjack are played with
several decks of cards at the same time.
*/
Card::Card() {
	int r = 1 + rand() % 4;

	switch (r) {
	case 1: suit = OROS;
		break;
	case 2: suit = COPAS;
		break;
	case 3: suit = ESPADAS;
		break;
	case 4: suit = BASTOS;
		break;
	default: break;
	}

	r = 1 + rand() % 10;
	switch (r) {
	case  1: rank = AS; break;
	case  2: rank = DOS; break;
	case  3: rank = TRES; break;
	case  4: rank = CUATRO; break;
	case  5: rank = CINCO; break;
	case  6: rank = SEIS; break;
	case  7: rank = SIETE; break;
	case  8: rank = SOTA; break;
	case  9: rank = CABALLO; break;
	case 10: rank = REY; break;
	default: break;
	}
}

// Accessor: returns a string with the suit of the card in Spanish 
std::string Card::get_spanish_suit() const {
	std::string suitName;
	switch (suit) {
	case OROS:
		suitName = "Oros";
		break;
	case COPAS:
		suitName = "Copas";
		break;
	case ESPADAS:
		suitName = "Espadas";
		break;
	case BASTOS:
		suitName = "Bastos";
		break;
	default: break;
	}

	return suitName;
}

// Accessor: returns a string with the rank of the card in Spanish 
std::string Card::get_spanish_rank() const {
	std::string rankName;
	switch (rank) {
	case AS:
		rankName = "As";
		break;
	case DOS:
		rankName = "Dos";
		break;
	case TRES:
		rankName = "Tres";
		break;
	case CUATRO:
		rankName = "Cuatro";
		break;
	case CINCO:
		rankName = "Cinco";
		break;
	case SEIS:
		rankName = "Seis";
		break;
	case SIETE:
		rankName = "Siete";
		break;
	case SOTA:
		rankName = "Sota";
		break;
	case CABALLO:
		rankName = "Caballo";
		break;
	case REY:
		rankName = "Rey";
		break;
	default: break;
	}

	return rankName;
}

// Accessor: returns a string with the suit of the card in English 
std::string Card::get_english_suit() const {
	std::string suitName;
	switch (suit) {
	case OROS:
		suitName = "golds";
		break;
	case COPAS:
		suitName = "cups";
		break;
	case ESPADAS:
		suitName = "swords";
		break;
	case BASTOS:
		suitName = "clubs";
		break;
	default: break;
	}

	return suitName;
}

// Accessor: returns a string with the rank of the card in English 
std::string Card::get_english_rank() const {
	std::string rankName;
	switch (rank) {
	case AS:
		rankName = "Ace";
		break;
	case DOS:
		rankName = "Two";
		break;
	case TRES:
		rankName = "Three";
		break;
	case CUATRO:
		rankName = "Four";
		break;
	case CINCO:
		rankName = "Five";
		break;
	case SEIS:
		rankName = "Six";
		break;
	case SIETE:
		rankName = "Seven";
		break;
	case SOTA:
		rankName = "Jack";
		break;
	case CABALLO:
		rankName = "Knight";
		break;
	case REY:
		rankName = "King";
		break;
	default: break;
	}

	return rankName;
}


// Assigns a numerical value to card based on rank.
// AS=1, DOS=2, ..., SIETE=7, SOTA=10, CABALLO=11, REY=12
int Card::get_rank() const {
	return static_cast<int>(rank) + 1;
}

// Returns the value of the corresponding rank
// The possible returns are 1, 2, 3, 4, 5, 6, 7, 0.5, 0.5, 0.5
double Card::get_value() const {
	int r = this->get_rank();
	double value = 0;

	switch (r) {
	case 1:
		value = 1;
		break;
	case 2:
		value = 2;
		break;
	case 3:
		value = 3;
		break;
	case 4:
		value = 4;
		break;
	case 5:
		value = 5;
		break;
	case 6:
		value = 6;
		break;
	case 7:
		value = 7;
		break;
	case 10:
		value = 0.5;
		break;
	case 11:
		value = 0.5;
		break;
	case 12:
		value = 05;
		break;
	default: break;
	}// end swith 

	return value;
}

// Comparison operator for cards
// Returns TRUE if card1 < card2
bool Card::operator < (Card card2) const {
	return rank < card2.rank;
}

// *************************************************
// HAND CLASS

// Default Constructor constructs an empty hand
Hand::Hand()
	:hand_size(0) {

}

Hand::Hand(Card* c)
	: hand_size(1) {
	hand.push_back(c);
}

// Returns the value of the current hand
// Adds up the values on the cards in the hand
double Hand::handNumber() const {
	double sum = 0;

	for (int i = 0; i<hand_size; i++) {
		sum = sum + hand[i]->get_value();
	}// end for
	return sum;
}

// adds card to the hand
void Hand::add_card(Card* c) {
	hand.push_back(c);
	hand_size++;
}

int Hand::get_hand_size() const {
	return hand_size;
}

//return card at given index
Card* Hand::get_card_at_index(int i) const {
	if (i< hand_size && i>=0)
		return hand[i];

	return NULL;
}

//destructor
Hand::~Hand() {
	std::vector<Card*>::iterator it;

	for (it = hand.begin(); it != hand.end(); ++it) {
		delete * it;
	}
}


// *************************************************
// PLAYER CLASS

Player::Player()
	:money(0), hand() {
}// end default construcor

Player::Player(int m)
	: money(m), hand() {
}// end constructor

 // returns player's current money
int Player::get_money() const {
	return money;
}

// increases money by given parameter
void Player::increase_money(int m) {
	money = money + m;
}

// decreases money by given parameter
void Player::decrease_money(int m) {
	money = money + m;
}

// adds card to the hand
void Player::add_card(Card* c) {
	hand.add_card(c);
}

std::string Player::getCurrentCard() {
	int current_hand_size = hand.get_hand_size();
	if (current_hand_size>0) {
		Card c = *(hand.get_card_at_index(current_hand_size - 1));
		std::string suit = c.get_spanish_suit();
		std::string rank = c.get_spanish_rank();

		return "Suit: " + suit + " Rank: " + rank;
	}

	return "";
}

// gets the value of the currect hand;
double Player::get_hand_value() const {
	return hand.handNumber();
}
