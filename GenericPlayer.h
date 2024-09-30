#ifndef GENERICPLAYER_H
#define GENERICPLAYER_H
#include "Hand.h"
#include <string>
#include <vector>

class GenericPlayer: public Hand
{

public:

    GenericPlayer();
    GenericPlayer(std::string);

    bool buss;
    std::string name;
    bool hit;
    int max;

    bool isHitting() const; // virtual

    bool isBusted() const;
    void bust() const;
    void takeHit();
    void display() const;
    std::string getName() const;
};

#endif
