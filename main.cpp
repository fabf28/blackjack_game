#include <iostream>
#include <string>
#include "Card.h"
#include "Hand.h"
#include "Deck.h"
#include "GenericPlayer.h"
#include "Player.h"
#include "House.h"
#include "Game.h"
using namespace std;

int main()
{
    //initializing game
    cout << "Welcome to this game of Blackjack" << endl;
    House the_house;
    cout << "house" << endl;
    Deck the_deck;

    //find num of players
    int playNum;
    cout << "How many players are playing?: ";
    cin >> playNum;
    Game the_game = Game(playNum, the_house, the_deck);

    //adding players to game
    string the_name;
    Player guy;
    for (int p{0}; p < playNum; p++)
    {
        cout << "Enter player " << p + 1 << "'s name: ";
        cin >> the_name;
        guy = Player(the_name);
        the_game.addPlayer(guy);
    }

    //playing the game
    string ans;
    do {
        the_game.play();

        cout << "Do you guys want to play again? (y/n): ";
        cin >> ans;

        while (ans != "y" && ans != "Y" && ans != "n" && ans != "N")
        {
            cout << "Invalid input. Do you guys want to play again with the same players? (y/n): ";
            cin >> ans;
        }
    } while (ans == "y" || ans == "Y");

    return 0;
}
