# Project One:

The assignment is to write a single-player version of the card game known as 'Siete y Medio' (seven and a half).
The goal of the game is to get cards whose total value comes the closest to 7.5 without going over it. 

* Copyright: Public domain.
* Filename:  cards.h, cards.cpp, hw7.cpp
* Purpose:   The purpose is to practice working with github and version control while praciticing C++ skills such as reference and pointers.
* Contact:   Nino Migineishvili <m.nino97@gmail.com>.
* Mod history:   2017-04-30

When playing the game, the program generates a file called "GameLog.txt" and writes relevant game information into that file. For the purposes of displaying test data, I will use to output of the command line to display the progression of the game. 

### Game 1: 

You currently have $50.  Enter Bet: 20
Your cards:
        Tres de Copas (Three of Cups).
Your total is: 3. Do you want another card? (y/n)y

New Card:
        Dos de Oros (Two of Golds).
Your cards:
        Tres de Copas (Three of Cups).
        Dos de Oros (Two of Golds).
Your total is: 5. Do you want another card? (y/n)y

New Card:
        Cuatro de Oros (Four of Golds).
Your cards:
        Tres de Copas (Three of Cups).
        Dos de Oros (Two of Golds).
        Cuatro de Oros (Four of Golds).
Your total is: 9.
You cannot draw any more cards, because your total exceeds 7 1/2.

Dealer's cards:
        Rey de Espadas (King of Swords).
The dealer's total is: 5.

New Card:
        Seis de Bastos (Six of Clubs).
Dealer's cards:
        Rey de Espadas (King of Swords).
        Seis de Bastos (Six of Clubs).
The dealer's total is: 11.

You lose $20.

### Game 2

You currently have $30.  Enter Bet: 15
Your cards:
        Caballo de Bastos (Knight of Clubs).
Your total is: 0.5. Do you want another card? (y/n)y

New Card:
        Dos de Oros (Two of Golds).
Your cards:
        Caballo de Bastos (Knight of Clubs).
        Dos de Oros (Two of Golds).
Your total is: 2.5. Do you want another card? (y/n)y

New Card:
        Tres de Copas (Three of Cups).
Your cards:
        Caballo de Bastos (Knight of Clubs).
        Dos de Oros (Two of Golds).
        Tres de Copas (Three of Cups).
Your total is: 5.5. Do you want another card? (y/n)n

Dealer's cards:
        Dos de Oros (Two of Golds).
The dealer's total is: 2.

New Card:
        Tres de Oros (Three of Golds).
Dealer's cards:
        Dos de Oros (Two of Golds).
        Tres de Oros (Three of Golds).
The dealer's total is: 5.

New Card:
        Siete de Bastos (Seven of Clubs).
Dealer's cards:
        Dos de Oros (Two of Golds).
        Tres de Oros (Three of Golds).
        Siete de Bastos (Seven of Clubs).
The dealer's total is: 12.

You win $15.

### Game 3

You currently have $45.  Enter Bet: 15
Your cards:
        Caballo de Espadas (Knight of Swords).
Your total is: 0.5. Do you want another card? (y/n)y

New Card:
        Seis de Espadas (Six of Swords).
Your cards:
        Caballo de Espadas (Knight of Swords).
        Seis de Espadas (Six of Swords).
Your total is: 6.5. Do you want another card? (y/n)n

Dealer's cards:
        Caballo de Copas (Knight of Cups).
The dealer's total is: 0.5.

New Card:
        Tres de Oros (Three of Golds).
Dealer's cards:
        Caballo de Copas (Knight of Cups).
        Tres de Oros (Three of Golds).
The dealer's total is: 3.5.

New Card:
        Cuatro de Copas (Four of Cups).
Dealer's cards:
        Caballo de Copas (Knight of Cups).
        Tres de Oros (Three of Golds).
        Cuatro de Copas (Four of Cups).
The dealer's total is: 7.5.

You lose $15.

### Game 4

You currently have $30.  Enter Bet: 20
Your cards:
        Sota de Espadas (Jack of Swords).
Your total is: 0.5. Do you want another card? (y/n)y

New Card:
        Seis de Oros (Six of Golds).
Your cards:
        Sota de Espadas (Jack of Swords).
        Seis de Oros (Six of Golds).
Your total is: 6.5. Do you want another card? (y/n)n

Dealer's cards:
        Cinco de Bastos (Five of Clubs).
The dealer's total is: 5.

New Card:
        Rey de Bastos (King of Clubs).
Dealer's cards:
        Cinco de Bastos (Five of Clubs).
        Rey de Bastos (King of Clubs).
The dealer's total is: 10.

You win $20.

### Game 5

You currently have $50.  Enter Bet: 20
Your cards:
        Siete de Oros (Seven of Golds).
Your total is: 7. Do you want another card? (y/n)n

Dealer's cards:
        Dos de Bastos (Two of Clubs).
The dealer's total is: 2.

New Card:
        Rey de Bastos (King of Clubs).
Dealer's cards:
        Dos de Bastos (Two of Clubs).
        Rey de Bastos (King of Clubs).
The dealer's total is: 7.

It's a tie. There is no exchange of money.


You currently have $50.  Enter Bet: 20
Your cards:
        Siete de Bastos (Seven of Clubs).
Your total is: 7. Do you want another card? (y/n)n

Dealer's cards:
        As de Espadas (Ace of Swords).
The dealer's total is: 1.

New Card:
        Rey de Oros (King of Golds).
Dealer's cards:
        As de Espadas (Ace of Swords).
        Rey de Oros (King of Golds).
The dealer's total is: 6.

You win $20.

### Game 6

You currently have $70.  Enter Bet: 50
Your cards:
        As de Espadas (Ace of Swords).
Your total is: 1. Do you want another card? (y/n)y

New Card:
        Caballo de Bastos (Knight of Clubs).
Your cards:
        As de Espadas (Ace of Swords).
        Caballo de Bastos (Knight of Clubs).
Your total is: 1.5. Do you want another card? (y/n)y

New Card:
        Siete de Copas (Seven of Cups).
Your cards:
        As de Espadas (Ace of Swords).
        Caballo de Bastos (Knight of Clubs).
        Siete de Copas (Seven of Cups).
Your total is: 8.5.
You cannot draw any more cards, because your total exceeds 7 1/2.

Dealer's cards:
        As de Copas (Ace of Cups).
The dealer's total is: 1.

New Card:
        Dos de Copas (Two of Cups).
Dealer's cards:
        As de Copas (Ace of Cups).
        Dos de Copas (Two of Cups).
The dealer's total is: 3.

New Card:
        Cinco de Copas (Five of Cups).
Dealer's cards:
        As de Copas (Ace of Cups).
        Dos de Copas (Two of Cups).
        Cinco de Copas (Five of Cups).
The dealer's total is: 8.

You lose $50.

### Game 7

You currently have $20.  Enter Bet: 10
Your cards:
        Dos de Espadas (Two of Swords).
Your total is: 2. Do you want another card? (y/n)y

New Card:
        Rey de Copas (King of Cups).
Your cards:
        Dos de Espadas (Two of Swords).
        Rey de Copas (King of Cups).
Your total is: 7. Do you want another card? (y/n)n

Dealer's cards:
        Dos de Copas (Two of Cups).
The dealer's total is: 2.

New Card:
        Caballo de Espadas (Knight of Swords).
Dealer's cards:
        Dos de Copas (Two of Cups).
        Caballo de Espadas (Knight of Swords).
The dealer's total is: 2.5.

New Card:
        Rey de Espadas (King of Swords).
Dealer's cards:
        Dos de Copas (Two of Cups).
        Caballo de Espadas (Knight of Swords).
        Rey de Espadas (King of Swords).
The dealer's total is: 7.5.

You lose $10.

## Game 8

You currently have $10.  Enter Bet: 10
Your cards:
        Tres de Espadas (Three of Swords).
Your total is: 3. Do you want another card? (y/n)y

New Card:
        Seis de Bastos (Six of Clubs).
Your cards:
        Tres de Espadas (Three of Swords).
        Seis de Bastos (Six of Clubs).
Your total is: 9.
You cannot draw any more cards, because your total exceeds 7 1/2.

Dealer's cards:
        Caballo de Bastos (Knight of Clubs).
The dealer's total is: 0.5.

New Card:
        Rey de Espadas (King of Swords).
Dealer's cards:
        Caballo de Bastos (Knight of Clubs).
        Rey de Espadas (King of Swords).
The dealer's total is: 5.5.

You lose $10.


THE GAME IS OVER. THANK YOU FOR PLAYING.

