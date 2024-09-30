#ifndef HAND_H
#define HAND_H
#include <vector>
#include "Card.h"

class Hand
{

public:
    Hand();
    std::vector<Card> stack;

    void printCards() const;
    void add(Card&);
    void clear();
    int getTotal() const;

};
#endif
