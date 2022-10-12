#include "game.h"
#include <vector>
#include "deck.h"
#include "player.h"
#include "card.h"
#include "computer.h"
#include "human.h"
#include <iostream>
#include <sstream>
#include <memory>
using namespace std;

// Game Constructor
// returns: a constructed Game Object
Game::Game(vector<bool> humancheck) {
    for(int i=0; i < 4; i++){
        allScores.emplace_back(0);
    }
    vector<Card> empty1 = {};
    for(int i=0; i < 4; ++i) {
        if(humancheck[i] == true) {
            allPlayers.emplace_back(new Human(0, i+1, "HUMAN", empty1, empty1));
        } else {
            allPlayers.emplace_back(new Computer(0, i+1, "COMPUTER", empty1, empty1));
        }
    }
    firstTurn = true;
    quitter = false;
} 

// modifies: updates all players hands to deal the cards
void Game::dealCards() {
    vector<Card> temp = getgameCards();
    int k=0;
    for(int i=0; i < NUM_PLAYERS; ++i) {
        vector<Card> givenHand = {};
        for(int j = 0; j < CARD_PER_PLAYER; j++) {
                givenHand.emplace_back(temp[k]);
            if(temp[k].findRank() == 7 && temp[k].findSuit() == 'S') {
                firstPlayer = i;
            }
            k++;
        }
        allPlayers[i]->setHand(givenHand);
    }
}

// returns: if the quitter is true
bool Game::getQuitter() {
    return quitter;
}

// modifies: quitter to true
void Game::updateQuitter() {
    quitter = true;
}

// returns: all of the player's scores
vector<int> Game::getAllScores() {
    return allScores;
}

// returns: the deck of cards in vector form
vector<Card> Game::getgameCards() {
    return gameCards;
}

// modifies: the deck of cards to set it to the given cards
void Game::setgameCards(vector<Card> givenCards) {
    gameCards = givenCards;
}

// returns: the clubs played so far
vector<char> Game::getPlayedClubs() {
    return clubRanksonTable;
}

// returns: the spades played so far
vector<char> Game::getPlayedSpades() {
    return spadeRanksonTable;
}

// returns: the diamonds played so far
vector<char> Game::getPlayedDiamonds() {
    return diamondRanksonTable;
}

// returns: the hearts played so far
vector<char> Game::getPlayedHearts() {
    return heartRanksonTable;
}

// modifies: the clubs on the table to the given clubs
void Game::setPlayedClubs(vector<char> givenClubs) {
    clubRanksonTable = givenClubs;
}

// modifies: the spades on the table to the given spades
void Game::setPlayedSpades(vector<char> givenSpades) {
    spadeRanksonTable = givenSpades;
}

// modifies: the diamonds on the table to the given diamonds
void Game::setPlayedDiamonds(vector<char> givenDiamonds) {
    diamondRanksonTable = givenDiamonds;
}

// modifies: the hearts on the table to the given hearts
void Game::setPlayedHearts(vector<char> givenHearts) {
    heartRanksonTable = givenHearts;
}

// modifies: the respective suit by adding the given rank in char form
void Game::updatePlayedSuit(Card card_played, char card_suit) {
    int num = card_played.findRank();
    int len = 0;
  //  std::vector<char>::iterator idx;
    char allRanks[14] = {'A', '2', '3', '4', '5', '6', '7', '8', '9', 'T', 'J', 'Q', 'K'};

    if(card_suit == 'C') {
        if(clubRanksonTable.size() == 0 || num > 7) {
            clubRanksonTable.emplace_back(allRanks[num - 1]);
            return;
        } else if (num < 7) {
            clubRanksonTable.insert(clubRanksonTable.begin(), allRanks[num -1]);
        }
    }
    if(card_suit == 'S') {
        if (spadeRanksonTable.size() == 0 || num > 7) {
            spadeRanksonTable.emplace_back(allRanks[num - 1]);
            return;
        } else if (num < 7) {
            spadeRanksonTable.insert(spadeRanksonTable.begin(), allRanks[num - 1]);
        }
    }
    if(card_suit == 'D') {
        if (diamondRanksonTable.size() == 0 || num > 7) {
            diamondRanksonTable.emplace_back(allRanks[num - 1]);
            return;
        } else if (num < 7) {
            diamondRanksonTable.insert(diamondRanksonTable.begin(), allRanks[num -1]);
        }
    }
    if(card_suit == 'H') {
        if(heartRanksonTable.size() == 0 || num > 7) {
            heartRanksonTable.emplace_back(allRanks[num - 1]);
            return;
        } else if (num < 7) {
            heartRanksonTable.insert(heartRanksonTable.begin(), allRanks[num-1]);
        }
    }
}

// modifies: all the suits on the table to empty vectors to reset them
void Game::resetTable() {
	vector<char> clearTable = {};
	clubRanksonTable = clearTable;
	diamondRanksonTable = clearTable;
	heartRanksonTable = clearTable;
	spadeRanksonTable = clearTable;
}

// returns: the index on which the given char is located in the array
int checkArray(char charnum) {
    int index = 0;
    char allRanks[14] = {'A', '2', '3', '4', '5', '6', '7', '8', '9', 'T', 'J', 'Q', 'K'};
    for(int i = 0; i < 14; ++i) {
        if(allRanks[i] == charnum) {
            index = i;
        }
    }
    return index;
}

// returns: all the legal plays possible based on what's been played
vector<Card> Game::getAllLegalPlays() {
    vector<Card> allLegalPlays;
    int aRank = 0;
    if(firstTurn == true) {
        Card SevenOfSpades = Card(7, 'S');
        allLegalPlays.emplace_back(SevenOfSpades);
        return allLegalPlays;
    } else {
	if(spadeRanksonTable.empty() == true) { allLegalPlays.emplace_back(Card(7, 'S')); }
        if(clubRanksonTable.empty() == true) { allLegalPlays.emplace_back(Card(7, 'C')); }
        if(diamondRanksonTable.empty() == true) { allLegalPlays.emplace_back(Card(7, 'D')); }
        if(heartRanksonTable.empty() == true) { allLegalPlays.emplace_back(Card(7, 'H')); }

        //checks the lowest spade played so far and the highest spade, then adds one lower and one higher spade Card to allLegalPlays
        if(spadeRanksonTable[0] != 'A') {
            aRank = checkArray(spadeRanksonTable[0]);
            allLegalPlays.emplace_back(Card(aRank, 'S'));
        }
        if(spadeRanksonTable[spadeRanksonTable.size() - 1] != 'K') {
            aRank = checkArray(spadeRanksonTable[spadeRanksonTable.size() - 1]);
            allLegalPlays.emplace_back(Card(aRank + 2, 'S'));
        }

        //check if the suit pile is empty on the table, if not it adds one lower and one higher of the suit Card to allLegalPlays
        if(clubRanksonTable.empty() == false) {
            if(clubRanksonTable[0] != 'A') {
                aRank = checkArray(clubRanksonTable[0]);
                allLegalPlays.emplace_back(Card(aRank, 'C'));
            }
            if(clubRanksonTable[clubRanksonTable.size() - 1] != 'K') {
                aRank = checkArray(clubRanksonTable[clubRanksonTable.size() - 1]);
                allLegalPlays.emplace_back(Card(aRank + 2, 'C'));
            }
        }
        if(diamondRanksonTable.empty() == false) {
            if(diamondRanksonTable[0] != 'A') {
                aRank = checkArray(diamondRanksonTable[0]);
                allLegalPlays.emplace_back(Card(aRank, 'D'));
            }
            if(diamondRanksonTable[diamondRanksonTable.size() - 1] != 'K') {
                aRank = checkArray(diamondRanksonTable[diamondRanksonTable.size() - 1]);
                allLegalPlays.emplace_back(Card(aRank + 2, 'D'));
            }
        }
        if(heartRanksonTable.empty() == false) {
            if(heartRanksonTable[0] != 'A') {
                aRank = checkArray(heartRanksonTable[0]);
                allLegalPlays.emplace_back(Card(aRank, 'H'));
            }
            if(heartRanksonTable[heartRanksonTable.size() - 1] != 'K') {
                aRank = checkArray(heartRanksonTable[heartRanksonTable.size() - 1]);
                allLegalPlays.emplace_back(Card(aRank + 2, 'H'));
            }
        }
    }
    return allLegalPlays;
}

// returns: if the game is over
bool Game::isGameOver() {
    if(allScores[0] >= 80 || allScores[1] >= 80 || allScores[2] >= 80 || allScores[3] >= 80) {
        return true;
    }
    return false;
}

// returns: the index of the first player
int Game::getFirstPlayer() {
    return firstPlayer;
}

// returns: a vector of players to all the players in the game
vector<shared_ptr<Player>> Game::getAllPlayers() {
     return allPlayers;
 }

// modifies: goes through a whole round updating necessary components
void Game::doRound() {
    int currTurn = firstPlayer;
    while(!isRoundOver()) {
    // print the table
        std::cout << "Clubs: ";
        print_char(clubRanksonTable);
        std::cout << "Diamonds: ";
        print_char(diamondRanksonTable);
        std::cout << "Hearts: ";
        print_char(heartRanksonTable);
        std::cout << "Spades: ";
        print_char(spadeRanksonTable);
    // print current players hand
        vector<Card> yourHand = allPlayers[currTurn]->findHand();
        std::cout << "Your hand: ";
        print(yourHand);
    // print current players legal options
        vector<Card> allLegals = getAllLegalPlays();
        vector<Card> legalHand = allPlayers[currTurn]->getLegalCards(allLegals);
        std::cout << "Legal plays: ";
        print(legalHand);

         // check if human
        if(allPlayers[currTurn]->findType() == "HUMAN") {
            bool valid = false;
            string com;
            Card humCard = Card(0, '0');
            while(!valid) {
                string line;
                getline(cin, line);
                std::stringstream myss{line};
                string command;
                myss >> command;
                com = command;

                char rr;
                myss >> rr;
                int num = -1;
        
                        if(rr >= '2' && rr <= '9') {
                                num = rr - '2' + 2;
                        } else if (rr == 'A') {
                                num = 1;
                        } else if (rr == 'T') {
                                num = 10;
                        } else if (rr == 'J') {
                                num = 11;
                        } else if (rr == 'Q') {
                                num = 12;
                        } else if (rr == 'K') {
                                num = 13;
                        }
            
                char mysuit;
                myss >> mysuit;
                humCard.updateRank(num);
                humCard.updateSuit(mysuit);

                if(command == "play" && legalHand.size() != 0) {
                    int len = legalHand.size();
                    for(int m=0; m < len; ++m) {
                        if(humCard == legalHand[m]) {
                            valid = true;
                            break;
                        }
                    }
                    if(valid == true) {
                        break;
                    } else {
                             std::cout << "This is not a legal play." << std::endl;
                    }

                } else if (command == "discard" && yourHand.size() != 0 && legalHand.size() == 0) {
                    valid = true;
                    break;
                } else if (command == "deck") {
                    vector<Card> dd = getgameCards();
                    print(dd);
                    continue;
                } else if (command == "quit") {
                    updateQuitter();
                    return;
                } else if (command == "ragequit") {
                    allPlayers[currTurn]->setType("COMPUTER");
                    std::cout << "Player" << (currTurn + 1) << " ragequits. A computer will now take over." << std::endl;
                    break;
                } else if (valid == false) {
                    if(command == "play") {
                        std::cout << "This is not a legal play." << std::endl;
                    } else if (command == "discard") {
                        std::cout << "You have a legal play. You may not discard." << std::endl;
                    }
                }
            }
        // Now valid input given, deal with play or discard of a card.
            if(com == "play" && valid == true) {
                std::cout << ">Player" << (currTurn + 1) << " plays " << humCard << "." << std::endl;
                allPlayers[currTurn]->playCard(humCard);
                updatePlayedSuit(humCard, humCard.findSuit());
            }
            if(com == "discard" && valid == true) {
                std::cout << ">Player" << (currTurn + 1) << " discards " << humCard << "." << std::endl;
                allPlayers[currTurn]->discardCard(humCard);
            }
        }


   // check if computer
        if(allPlayers[currTurn]->findType() == "COMPUTER") {
            if(legalHand.empty() == false) {
                Card compPlay = legalHand[0];
    // print the card the computer plays
                std::cout << ">Player" << (currTurn + 1) << " plays " << compPlay << "." << std::endl;
    // play the card
                allPlayers[currTurn]->playCard(compPlay);
                updatePlayedSuit(compPlay, compPlay.findSuit());
            } else {
    // get the card from player hand to discard as legalplays empty
                Card compDiscard = yourHand[0];
    // print the card the computer discards
                std::cout << ">Player" << (currTurn + 1) << " discards " << compDiscard << "." << std::endl;
    // discard the card and update score
                allPlayers[currTurn]->discardCard(compDiscard);
            }
        }
        updateFirstTurn();
        if(currTurn == 3) {
            currTurn = 0;
        } else {
            currTurn++;
        }
    }
    std::cout << "Player1's discards: ";
    print(allPlayers[0]->findDiscards());
    std::cout << "Player1's score: ";
    std::cout << allPlayers[0]->findScore() << " + " << allPlayers[0]->roundScore() << " = ";
    allPlayers[0]->updateScore();
    std::cout << allPlayers[0]->findScore() << std::endl;
    allScores[0] = allPlayers[0]->findScore();

    std::cout << "Player2's discards: ";
    print(allPlayers[1]->findDiscards());
    std::cout << "Player2's score: ";
    std::cout << allPlayers[1]->findScore() << " + " << allPlayers[1]->roundScore() << " = ";
    allPlayers[1]->updateScore();
    std::cout << allPlayers[1]->findScore() << std::endl;
    allScores[1] = allPlayers[1]->findScore();

    std::cout << "Player3's discards: ";
    print(allPlayers[2]->findDiscards());
    std::cout << "Player3's score: ";
    std::cout << allPlayers[2]->findScore() << " + " << allPlayers[2]->roundScore() << " = ";
    allPlayers[2]->updateScore();
    std::cout << allPlayers[2]->findScore() << std::endl;
    allScores[2] = allPlayers[2]->findScore();


    std::cout << "Player4's discards: ";
    print(allPlayers[3]->findDiscards());
    std::cout << "Player4's score: ";
    std::cout << allPlayers[3]->findScore() << " + " << allPlayers[3]->roundScore() << " = ";
    allPlayers[3]->updateScore();
    std::cout << allPlayers[3]->findScore() << std::endl;
    allScores[3] = allPlayers[3]->findScore();

    return;
}

// returns: if the round is over or not
bool Game::isRoundOver() {
   bool end = false;
   for(int i=0; i < NUM_PLAYERS; i++) {
       if(allPlayers[i]->HandEmpty() == true) {
           return true;
       }
    } //check last player or all players cards
    return false;
}

// modifies: the first turn to false
void Game::updateFirstTurn() {
    firstTurn = false;
}

// prints the vector of cards
void print( std::vector<Card> const & v ) {
        for ( Card i : v ) std::cout << i << ' ';
        std::cout << std::endl;
}

// prints the vector of characters
void print_char( std::vector<char> const & v ) {
        for( char i : v ) std::cout << i << ' ';
        std::cout << std::endl;
}


