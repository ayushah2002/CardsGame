#ifndef COMPUTER_H
#define COMPUTER_H
#include "player.h"
#include <vector>
#include <iostream>

class Computer : public Player {
    public:
    Computer(int score, int id, string ptype, vector<Card> hand, vector<Card> discards);//, vector<Card> legals);
    Card firstLegalPlay(vector<Card> allLegalPlays2); // if legal plays is empty just stay in player / game class and discard and never call this function
};
#endif

