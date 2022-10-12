#include <iostream>
#include <vector>
#include "card.h"
#include "player.h"
#include "computer.h"
#include "deck.h"
#include "game.h"
#include <chrono>
#include <random>
#include <algorithm>

int main(int argc, char * argv[]) {

    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
    if ( argc > 1 ) {
        try {
            seed = std::stoi( std::string{ argv[1] } );
        } catch( std::invalid_argument & e ) {
            std::cerr << e.what() << std::endl;
            return 1;
        } catch( std::out_of_range & e ) {
            std::cerr << e.what() << std::endl;
            return -1;
        } // catch
    }
    Deck theDeck = Deck(seed);
  /*  print(theDeck.findDeck());
    theDeck.shuffle();
    print(theDeck.findDeck()); */


    vector<bool> isHuman = {false, false, false, false};
    char input1;
    char input2;
    char input3;
    char input4;

    std::cout << "Is Player1 a human (h) or a computer (c)?" << std::endl;
    std::cin >> input1;
    std::cout << "Is Player2 a human (h) or a computer (c)?" << std::endl;
    std::cin >> input2;
    std::cout << "Is Player3 a human (h) or a computer (c)?" << std::endl;
    std::cin >> input3;
    std::cout << "Is Player4 a human (h) or a computer (c)?" << std::endl;
    std::cin >> input4;

    if(input1 == 'h') { isHuman[0] = true; }
    if(input2 == 'h') { isHuman[1] = true; }
    if(input3 == 'h') { isHuman[2] = true; }
    if(input4 == 'h') { isHuman[3] = true; }

    bool start_game = true;
    Game myGame = Game(isHuman);
    while(!myGame.isGameOver()) {
	    theDeck.shuffle();
	    myGame.setgameCards(theDeck.findDeck());
	    myGame.dealCards();
	    if(start_game == true) {
	    	int firstplayer = myGame.getFirstPlayer();
	    	std::cout << "A new round begins. It's Player" << (firstplayer+1) << "'s turn to play." << std::endl;
	       start_game = false;
	    }
	    myGame.doRound();
	    if(myGame.getQuitter() == true) {
		    return -1;
	    }
	    vector<Card> emptyDiscards = {};
	    for(int m=0; m < 4; m++) {
		    myGame.getAllPlayers()[m]->resetDiscards(emptyDiscards);
	    }
	    myGame.resetTable();
	   // std::cout << "round finished*************************" << std::endl;
    }
    int lowest_score = -1;
    for(int u=0; u < 4; u++) {
	    if(u == 0) {
		    lowest_score = myGame.getAllScores()[u];
	    } else if(myGame.getAllScores()[u] < lowest_score) {
		    lowest_score = myGame.getAllScores()[u];
	    }
    } 
    for(int k=0; k < 4; k++) {
	    if(myGame.getAllScores()[k] == lowest_score) {
		    std::cout << "Player" << (k + 1) << " wins!" << std::endl;
	    }
    }
    return 0;
}

