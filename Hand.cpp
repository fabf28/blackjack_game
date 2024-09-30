#include <iostream>
#include <string>
#include <vector>
#include "Hand.h"
#include "Card.h"
using namespace std;

Hand::Hand()
{
    int a = 1;
}

void Hand::add(Card& card)
{
    stack.push_back(card);
}


void Hand::clear()
{
    stack.clear();
}

int Hand::getTotal() const
{
    int total{0};
    Card x;
    for (int i{0}; i < stack.size(); i++)
    {
        x = stack[i];
        total += x.getValue();
    }
    return total;
}

void Hand::printCards() const
{
    cout << "cards";
    for (int i{0}; i < stack.size(); i++)
        cout << stack[i].show() << " : ";
    cout << stack.size() << endl;
}
