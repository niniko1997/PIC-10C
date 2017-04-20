//Header File

/* *************************************
  Nino Migineishvili, April 16th, 2017

   Interface of Card Class
   ************************************* */

#include <string>
#include <vector>
#include <fstream>

#ifndef CARDS_H
#define CARDS_H

enum suit_t {OROS, COPAS, ESPADAS, BASTOS};

//The values for this type start at 0 and increase by one afterwards until they get to SIETE. 
//The rank reported by the function Card::get_rank() below is the value listed here plus one.
enum rank_t {AS, DOS, TRES, CUATRO, CINCO, SEIS, SIETE, SOTA=9, CABALLO=10, REY=11};

class Card {
   public: 
      // Constructor assigns random rank & suit to card.
      Card();
      
      // Accessors 
      std::string get_spanish_suit() const;
      std::string get_spanish_rank() const; 
      std::string get_english_suit() const;
      std::string get_english_rank() const; 

      // Converts card rank to number.
      // The possible returns are: 1, 2, 3, 4, 5, 6, 7, 10, 11 and 12
      int get_rank() const;

      // Returns the value of the corresponding rank
      // The possible returns are 1, 2, 3, 4, 5, 6, 7, 0.5, 0.5, 0.5
      double get_value(rank_t r) const;

      // Compare rank of two cards. E.g: Eight<Jack is true.
      // Assume Ace is always 1. 
      bool operator < (Card card2) const;

   private:
      suit_t suit;
      rank_t rank;
};


class Hand {
   public:
      // A vector of Cards
      Hand();

      // Returns the value of the current hand
      // Adds up the values on the cards in the hand
      double handNumer() const;

   private:
      std::vector<Card> hand; //stores the hand of cards that have been pulled from the deck
      int hand_size; //stores the size of the vector
};


class Player {
   public:
      // Default constructor 
      // Set amount of money to zero
      Player();

      // Constructor. 
      // Assigns initial amount of money
      Player(int m);

      // gets the current amount of money
      int get_money() const;
   private:
      int money;
      Hand hand;
};

#endif 
