#include "card.h"
#include <iostream>
#include <string>
using namespace std;

// Card Constructori
// returns: a constructed Card Object with a rank and suit
Card::Card(int rank, char suit) {
    cardSuit = suit;
    cardRank = rank;
}

// returns the Card's rank
int Card::findRank() const {
    return cardRank;
}

// returns the Card's suit
char Card::findSuit() const {
    return cardSuit;
}

// updates the Card's rank with the given rank
void Card::updateRank(int rank2) {
    cardRank = rank2;
}

// updates the Card's suit with  the given suit
void Card::updateSuit(char suit2) {
    cardSuit = suit2;
}

// returns: if card is identical based on its suit and rank - true if it is
bool operator==(const Card &c1, const Card &c2) {
    return c1.findRank() == c2.findRank() && c1.findSuit() == c2.findSuit();
}

// returns: outputs rank and suit
std::ostream &operator<<(std::ostream &out, const Card &car){
    string allRanks[14] = {"A", "2", "3", "4", "5", "6", "7", "8", "9", "T", "J", "Q", "K"};
    int idx = car.findRank() - 1;
    out << allRanks[idx] << car.findSuit();
    return out;
}

// returns: reads in input and updates relative rank and suit and returns in
std::istream &operator>>(std::istream &in, Card &car) {
    string allRanks[14] = {"A", "2", "3", "4", "5", "6", "7", "8", "9", "T", "J", "Q", "K"};
    
    string rank1;
    in >> rank1;
    for(int i=0; i < 14; ++i){
        if(rank1 == allRanks[i]) {
		int u = i + 1;
            car.cardRank = u;
            break;
        }
    }
    char suit1;
    in >> suit1;
    car.cardSuit = suit1;
    return in;
}

