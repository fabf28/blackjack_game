#ifndef CARD_H
#define CARD_H
#include <string>

class Card
{
    //atributes

    public:

    int val;
    std::string type;
    bool face;

    //constructors
        Card();
        Card(std::string, int);
        Card(std::string, int, bool);

    //methods
        bool ifFaceUp() const;
        int getValue() const;
        void flip();

        void setValue(int);
        std::string show() const;
};

#endif
