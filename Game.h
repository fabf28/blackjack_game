#ifndef GAME_H
#define GAME_H
#include <vector>
#include "Player.h"
#include "House.h"
#include "Deck.h"

/*

Deal players and the house two initial cards
Hide the house's first card
Display players' and house's hands
Deal additional cards to players
Reveal house's first card
Deal additional cards to house
If house is busted
    Everyone who is not busted wins
Otherwise
    For each player
        If player isn't busted
            If player's total is greater than the house's total
                Player wins
            Otherwise if player's total is less than house's total
                Player loses
            Otherwise
                Player pushes

Remove everyone's cards


*/

class Game
{
private:
    House host;
    int turns;
    Deck pile;
public:
    std::vector<Player> players;
    //constructors
    Game(int, House, Deck);

    void play();
    void addPlayer(Player);
    void printPlayers();
    void displayPlayers() const;
};

#endif
