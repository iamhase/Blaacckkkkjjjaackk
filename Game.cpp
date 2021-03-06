#include "Player.h"
#include "Deck.h"
#include "Card.h"
#include <iostream>
#include <time.h>  
using namespace std;

bool is_finished(int status) {
	if (status == 1 || status == 2) {
		return true;
	}
	else
		return false;
}

void run() {
	int budget = 1000;
	char state = 'g';
	bool status = false;
    int numberOfDealerCards = 0;
    int numberOfPlayerCards = 0;
    int playerValueTotal = 0;
    int dealerValueTotal = 0;

	Deck deck;
    
    /*
    Hand playerHand;
    Hand DealerHand;
    // make a hand class identical to deck class but without creating an entire full array
    //just have it be of size 20.
    */
    
	deck.printDeck();
	Player *player = new Player(budget, state, cards);

	while (!is_finished(status)) {
		cout << "Bank Roll: $" << player->getBudget() << endl;
		player->setBudget(player->getBudget() - 100);
		cout << "You bet $100. You have $" << player->getBudget() << " left." << endl;
        
        Card* handDealer[20];
        Card* handPlayer[20];
        
        handDealer[numberOfDealerCards] = deck.getCard();
        numberOfDealerCards++;
        handDealer[numberOfDealerCards] = deck.getCard();
        numberOfDealerCards++;
        handPlayer[numberOfPlayerCards] = deck.getCard();
        numberOfPlayerCards++;
        handPlayer[numberOfPlayerCards] = deck.getCard();
        numberOfPlayerCards++;
        
        while (!is_finished(status)) {
            cout << "Dealer shows a " << handDealer[0];
            for(int dealerCard = 0; dealerCard <= numberOfDealerCards; dealerCard++) {
                cout<<handPlayer[dealerCard] -> rank<<", ";
            }
            cout << "Your hand: ";
            for(int playerCard = 0; playerCard <= numberOfPlayerCards; playerCard++) {
                cout<<handPlayer[playerCard] -> rank<<", ";
            }
            cout<<endl;
            cout << "(S)tand, (H)it:  ? " << endl;
            cin >> state;
            deck.printDeck();
        
            switch(state) {
                case 'H': handPlayer[numberOfPlayerCards + 1] = deck.getCard();
                    numberOfPlayerCards++;
                    break;
                case 'S': { /* case s calls for evaluation of all the cards*/
                    for (int i = 0; i < numberOfPlayerCards; i++) {
                        playerValueTotal += handPlayer[i]->value();
                    }
                    for (int i = 0; i < numberOfDealerCards; i++) {
                        playerValueTotal += handDealer[i]->value();
                    }
                    if (playerValueTotal == 21) {
                        player -> budget(player -> getBudget() + 200);
                    } else if (playerValueTotal > 21) {
                        cout << "you lose. " << endl;
                    } else if (playerValueTotal > dealerValueTotal) {
                        cout << "you won! " << endl;
                        player -> budget(player -> getBudget() + 200 )
                    } else {
                        cout << "you lose. " << endl;
                    }
                    break;
                }
            }
        }
        if(player->getBudget() < 0) {
            status = true;
        }
    }
}

int main() {
	run();
}
