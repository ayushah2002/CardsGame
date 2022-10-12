#include "player.h"
#include <algorithm>

// Player Constructor
// returns: a constructed Player Object
Player::Player(int score, int id, string ptype, vector<Card> hand, vector<Card> discards) {
    playerScore = score;
    playerID = id;
    playerType = ptype;
    playerHand = hand;
    playerDiscards = discards;
}

// returns: the players round score
int Player::roundScore(){
    int round_score = 0;
    int len = playerDiscards.size();
    for(int i=0; i < len; ++i) {
        round_score += playerDiscards[i].findRank();
    }
    return round_score;
}

// modifies: playerScore to add the round score
void Player::updateScore(){
    playerScore += roundScore();
}

// returns: player's score
int Player::findScore() {
    return playerScore;
}

// returns: the player type
string Player::findType() {
    return playerType;
}

// returns: the player's id
int Player::findID() {
    return playerID;
}

// returns: the player's hand
vector<Card> Player::findHand(){
    return playerHand;
}

// returns: the player's discards
vector<Card> Player::findDiscards(){
    return playerDiscards;
}

// modifies: player's hand by updating it to given hand
void Player::setHand(vector<Card> hand2) {
    playerHand = hand2;
}

// modifies: player's discards by setting it to the emptyVec
void Player::resetDiscards(vector<Card> emptyVec) {
    playerDiscards = emptyVec;
}

// modifies: player's hand by adding the given card
void Player::addCard(Card theCard) {
    playerHand.emplace_back(theCard);
}

// returns: if the player's hand is empty
bool Player::HandEmpty() {
    return playerHand.size() == 0;
}

// modifies: player type to the new type given
void Player::setType(string newtype) {
    playerType = newtype;
}

// modifies: player hand by removing the given card
// requires: player hand contains given card
void Player::playCard(Card c1) {
    auto index = find(playerHand.begin(), playerHand.end(), c1);
    if(index != playerHand.end()) {
        playerHand.erase(index);
    }
}

// modifies: player disard's by adding given card and removing from hand
void Player::discardCard(Card c1) {
    playCard(c1);
    playerDiscards.emplace_back(c1);
} 

// returns: all available legal plays for the player's hand based on the given vector
vector<Card> Player::getLegalCards(vector<Card> allLegalPlays1){
   vector<Card> LegalPlays;
    for(int i = 0; i < playerHand.size(); ++i){
        for(int j = 0; j < allLegalPlays1.size(); ++j){
            if(playerHand[i] == allLegalPlays1[j]) {
                LegalPlays.emplace_back(playerHand[i]);
                break;
            }
        }
    }
   return LegalPlays;
}
