#include <iostream>
#include "Game.h"
#include <vector>
using namespace std;

void Game::play()
{
    //dealing initial cards
    for (int turn{0}; turn < turns; turn++)
    {
        pile.deal(players[turn]);
        pile.deal(players[turn]);
    }
    pile.deal(host);
    pile.deal(host);
    host.flipFirstCard();

    //displaying initial cards
    displayPlayers();

    //hitting
    for (int turn{0}; turn < turns; turn++)
        pile.additionalCards(players[turn]);

    host.flipFirstCard();
    host.display();

    if (!host.isBusted())
        pile.additionalCards(host);

    //change winning announcements
    if (host.isBusted())
    {
        for (int turn{0}; turn < turns; turn++)
        {
            if (!players[turn].isBusted())
                players[turn].win();
        }
        cout << endl;
    } else {
        for (int turn{0}; turn < turns; turn++)
        {
            if (!players[turn].isBusted())
            {
                if (players[turn].getTotal() > host.getTotal())
                    players[turn].win();
                else if (players[turn].getTotal() < host.getTotal()){
                    players[turn].lose();
                } else
                    players[turn].push();
            }
        }
    }

    for (int i{0}; i < players.size(); i++)
        players[i].clear();
    pile.setLoc(0);
    pile.shuffle();
}

Game::Game(int n, House h, Deck p)
{
    host = h;
    turns = n;
    pile = p;
}

void Game::addPlayer(Player person)
{
    players.push_back(person);
}

void Game::printPlayers()
{
    for (auto elem: players)
        cout << elem.name << endl;
}

void Game::displayPlayers() const
{
    for (int turn{0}; turn < turns; turn++)
        players[turn].display();
    host.display();
}

