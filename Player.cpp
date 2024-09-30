#include <iostream>
#include <string>
#include <vector>
#include "Player.h"
#include "GenericPlayer.h"
using namespace std;

Player::Player()
{}

Player::Player(string n)
{
    buss = false;
    name = n;
    max = 21;
}

void Player::win() const
{
    cout << name << " wins." << endl;
}

void Player::lose() const
{
    cout << name << " loses." << endl;
}

void Player::push() const
{
    cout << name << " pushes." << endl;
}

