#include "computer.h"
#include "player.h"
#include <iostream>
using namespace std;

// Computer constructor
// returns: a construted Computer Object
Computer::Computer(int score, int id, string ptype, vector<Card> hand, vector<Card> discards) : Player{score, id, ptype, hand, discards} {}

// requires: allLegalPlays2 (given vector) is not empty
// returns: the first card in the available plays for the computer
Card Computer::firstLegalPlay(vector<Card> allLegalPlays2) {
    vector<Card> avaialablePlays = getLegalCards(allLegalPlays2);
    return avaialablePlays[0];
}

