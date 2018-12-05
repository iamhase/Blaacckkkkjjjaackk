#pragma once
#include "Card.h"
#ifndef _DECK_H
#define _DECK_H

class Deck {
public:
	
	Deck();

	void shuffle();

	Card* getCard();

	void printDeck();
private:
	Card * deck[260];

};

#endif 
