#ifndef GAME_H
#define GAME_H
#include <iostream>
#include <vector>
#include "card.h"
#include "player.h"
#include "deck.h"
#include <memory>

class Game {
    private:
    const int NUM_PLAYERS = 4;
    const int CARD_PER_PLAYER = 13;
    vector<int> allScores;
    bool firstTurn;
    vector<shared_ptr<Player>> allPlayers;
 //   Deck gameDeck;
 vector<Card> gameCards;
//vector<Card> allLegalPlays;
//list of each suit and whats been played, ordered in ascending order. (ensure to make A T J Q K)
    vector<char> clubRanksonTable;
    vector<char> spadeRanksonTable;
    vector<char> diamondRanksonTable;
    vector<char> heartRanksonTable;
//Player firstPlayer;
    int firstPlayer;
 //   int currentPlayerTurn;
//int currentPlayer;
//Player currentPlayer;
    bool quitter;

    public:
    Game(vector<bool> humancheck);
  // virtual ~Game();
    vector<Card> getgameCards();
    void setgameCards(vector<Card> givenCards);
   // void gameStart();
    void dealCards();
    bool getQuitter();
    void updateQuitter();
    void doRound();
    bool isRoundOver();
    bool isGameOver();
   // void invitePlayer();
    //void rageQuit();
   // int getCurrentPlayer();
   // void updateCurrentPlayer();
    int getFirstPlayer();
    int getCurrentID();
    void updateCurrentID(int newID);
    Player getCurrentPlayer(int id);
 //   Game(vector<int> scores, bool turn1, ...)
    vector<char> getPlayedClubs();
   // vector<int> updatePlayedClubs(Card card_played);
    vector<char> getPlayedSpades();
   // vector<int> updatePlayedSpades(Card card_played1);
    vector<char> getPlayedDiamonds();
   // vector<int> updatePlayedDiamonds(Card card_played2);
    vector<char> getPlayedHearts();
   // vector<int> updatePlayedHearts(Card card_played3);
   void setPlayedClubs(vector<char> givenClubs);
   void setPlayedSpades(vector<char> givenSpades);
   void setPlayedDiamonds(vector<char> givenDiamonds);
   void setPlayedHearts(vector<char> givenHearts);
    void updatePlayedSuit(Card card_played, char card_suit);
    vector<Card> getAllLegalPlays();
    vector<shared_ptr<Player>> getAllPlayers();
    void updateFirstTurn();
    vector<int> getAllScores();
    void resetTable();
  //  void updateAllLegalPlays;
};
int checkArray(char charnum);
void print( std::vector<Card> const & v );
void print_char( std::vector<char> const & v );
#endif
