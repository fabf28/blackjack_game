#include <iostream>
#include <string>
#include <vector>
#include "GenericPlayer.h"
#include "Deck.h"
#include "Hand.h"

using namespace std;

GenericPlayer::GenericPlayer()
{
    buss = false;
    hit = false;
}

GenericPlayer::GenericPlayer(string n)
{
    buss = false;
    name = n;
    hit = false;
}

bool GenericPlayer::isBusted() const
{
    if (getTotal() > 21)
        return true;
    return false;
}

void GenericPlayer::bust() const
{
    cout << name << " busts." << endl;
}

bool GenericPlayer::isHitting() const
{
    string ans;
    cout << name << ", Are you taking another hit? (y/n): ";
    cin >> ans;

    while (ans != "y" && ans != "n" && ans != "Y" && ans != "N")
    {
        cout << "Wrong input. Are you taking another hit? (y/n): ";
        cin >> ans;
    }

    if (ans == "y" || ans == "Y")
        return true;
    else return false;
}

void GenericPlayer::display() const
{
    cout << name << ": ";
    for (auto card: stack)
        cout << card.show() << "  ";
    cout << getTotal() << endl;
}

string GenericPlayer::getName() const
{
    return name;
}
