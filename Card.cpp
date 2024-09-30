#include <iostream>
#include <vector>
#include "Card.h"
using namespace std;

//constructors
Card::Card(string t, int v)
{
    val = v;
    type = t;
    face = true;
}

Card::Card(string t, int v, bool f)
{
    val = v;
    type = t;
    face = f;
}

Card::Card()
{}

//methods

bool Card::ifFaceUp() const
{
    return face;
}

int Card::getValue() const
{
    if (ifFaceUp())
        return val;
    else return 0;
}

void Card::flip()
{
    if (face == true)
        face = false;
    else face = true;
}

void Card::setValue(int v)
{
    val = v;
}

string Card::show() const
{
    if (ifFaceUp())
        return type;
    else return "XX";
}






