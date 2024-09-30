#ifndef DECK_H
#define DECK_H
#include <vector>
#include "GenericPlayer.h"
#include "Hand.h"

class Deck: public Hand
{

private:
    int loc;

public:
    //constructors
    Deck();

    //members
    void populate();
    void shuffle();
    void deal(Hand& hand);
    void additionalCards(GenericPlayer& gp);
    void setLoc(int);
};

#endif
