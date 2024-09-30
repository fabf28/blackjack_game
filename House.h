#ifndef HOUSE_H
#define HOUSE_H
#include "GenericPlayer.h"

class House: public GenericPlayer
{

public:
    //constructors
    House();
    void flipFirstCard();
};

#endif
