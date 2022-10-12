#include "human.h"
#include "player.h"
//#include <vector>
#include <iostream>
using namespace std;

// Human Constructor
// returns: a constructed Human Object
Human::Human(int score, int id, string ptype, vector<Card> hand, vector<Card> discards) : Player{score, id, ptype, hand, discards} {}

