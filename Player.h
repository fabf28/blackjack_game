#ifndef PLAYER_H
#define PLAYER_H
#include "GenericPlayer.h"
#include <vector>

class Player: public GenericPlayer
{

public:
    //constuctors
    Player();
    Player(std::string);

    void win() const;
    void lose() const;
    void push() const;
};

#endif
