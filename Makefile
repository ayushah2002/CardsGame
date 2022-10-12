straights: card.o game.o player.o deck.o computer.o human.o main.o
	g++ card.o game.o player.o deck.o computer.o human.o main.o -o straights
card.o: card.cc card.h
	g++ -g -std=c++14 -c card.cc
game.o: game.cc game.h
	g++ -g -std=c++14 -c game.cc
player.o: player.cc player.h
	g++ -g -std=c++14 -c player.cc
computer.o: computer.cc computer.h
	g++ -g -std=c++14 -c computer.cc
human.o: human.cc human.h
	g++ -g -std=c++14 -c human.cc
deck.o: deck.cc deck.h
	g++ -g -std=c++14 -c deck.cc
