#include <iostream>
#include <string>
#include <vector>
#include "House.h"
#include "GenericPlayer.h"
using namespace std;

House::House()
{
    buss = false;
    name = "House";
    max = 16;
}

void House::flipFirstCard()
{
    stack[0].flip();
}
