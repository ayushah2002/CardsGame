#ifndef PLAYER_H
#define PLAYER_H
#include <vector>
#include "card.h"
#include <iostream>
using namespace std;
//class Card;

class Player {
    private:
    int playerScore;
    int playerID;
    string playerType; // HUMAN or COMPUTER
    vector<Card> playerHand;
    vector<Card> playerDiscards;
   // vector<Card> playerLegalPlays;
   // vector<Card>legalCards;

    public:
    Player(int score, int id, string ptype, vector<Card> hand, vector<Card> discards);// vector<Card> legals);
    int roundScore();
    void updateScore();
    int findScore();
    string findType();
    int findID();
    bool HandEmpty();
    void setType(string newtype);
    vector<Card> findHand();
    vector<Card> findDiscards();
  //  vector<Card> findLegalPlays();
    void addCard(Card theCard);
    void playCard(Card c1);
    void discardCard(Card c1);
    void setHand(vector<Card> hand2);
    void resetDiscards(vector<Card> emptyVec);
    vector<Card> getLegalCards(vector<Card> allLegalPlays1);
    //void trackHand(vector<Card> hand1); // maybe jus card
    //void trackDiscards(vector<Card> discards1);
};
//vector<*Card>playerHand;
#endif
