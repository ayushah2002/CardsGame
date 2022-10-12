#include "player.h"
#include <vector>
#include <iostream>

class Human : public Player {
    public:
    Human(int score, int id, string ptype, vector<Card> hand, vector<Card> discards);
};
