#ifndef DECK_H
#define DECK_H
#include "card.h"
#include <iostream>
#include <vector>
#include <random>

class Deck {
    private:
	    std::vector<Card> deckOfCards;
 //   int seed;
    std::default_random_engine rng;

    public:
    Deck(int seed1);
 //   void createDeck();
    std::vector<Card> findDeck();
 //   void dealingCard();
 //   void printDeck();
    void shuffle();
  //  void updateDeck(vector<Card> deck1);
};
#endif
