#include "Deck.h"
#include "Card.h"
#include <iostream>
#include <time.h> 
using namespace std;

int numberOfCards = 260;

Deck::Deck() {
	
	char suit = ' ';
	int counter = 0;
	char c = ' ';
	for (int i = 0; i <= 4; i++) {
		for (int j = 1; j <= 13; j++) {

			switch (j) {
			case 1:  c = 'A';
				break;
			case 2:  c = '2';
				break;
			case 3:  c = '3';
				break;
			case 4:  c = '4';
				break;
			case 5:  c = '5';
				break;
			case 6:  c = '6';
				break;
			case 7:  c = '7';
				break;
			case 8:  c = '8';
				break;
			case 9:  c = '9';
				break;
			case 10:  c = '0';
				break;
			case 11:  c = 'J';
				break;
			case 12:  c = 'Q';
				break;
			case 13:  c = 'K';
				break;
			}
			for (int n = 0; n <= 3; n++)
			{
				switch (n) {
				case 0: suit = 'C';
					break;
				case 1: suit = 'D';
					break;
				case 2: suit = 'S';
					break;
				case 3: suit = 'H';
				}
				deck[counter] = new Card(suit, c);
				counter++;
			}
		}
	}
}


void Deck::shuffle() {
	Card temp;
	srand(time(0));
	int randomNumber1;
	int randomNumber2;
	for (int i = 0; i < 10000; i++) {
		randomNumber1 = rand() % 260;
		randomNumber2 = rand() % 260;
		temp = *deck[randomNumber1];
		deck[randomNumber1] = deck[randomNumber2];
		deck[randomNumber2] = &temp;
	}
}

Card* Deck::getCard() {
    Card* newCard =  deck[numberOfCards];
    numberOfCards--;
    return newCard;
}

void Deck::printDeck() {
	for (int i = 0; i < numberOfCards; i++) {
		cout << deck[i]->rank << " ";
	}
}
