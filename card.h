#ifndef CARD_H
#define CARD_H
#include <iostream>

class Card {

friend std::istream &operator>>(std::istream &in, Card &car);



    private:
    int cardRank;
    char cardSuit;

    public:
    int findRank() const ;
    char findSuit() const ;
    Card(int rank, char suit);
    void updateRank(int rank2);
    void updateSuit(char suit2);
};
bool operator==(const Card &c1, const Card &c2);
std::ostream &operator<<(std::ostream &out, const Card &car);
//std::istream &operator>>(std::istream &in, Card &car);
#endif
