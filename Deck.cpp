#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <random>
#include <chrono>
#include <sstream>
#include "Hand.h"
#include "Deck.h"
#include "GenericPlayer.h"
using namespace std;



//constructors
Deck::Deck()
{
    loc = 1;
    populate();
    shuffle();
}

void Deck::populate()
{
    //vector<string> types = {"2d", "3d", "4d", "5d", "6d", "7d", "8d", "9d", "jd", "qd", "kd", "ad", "2s", "3s", "4s", "5s", "6s", "7s", "8s", "9s", "js", "qs", "ks", "as", "2h", "3h", "4h", "5h", "6h", "7h", "8h", "9h", "jh"}
    string nums = "23456789jqka";
    string types = "dshc";

    string type;
    Card x;
    char c1, c2;
    stringstream ss;
    int card_val;

    for (int t{0}; t < 4; t++)
    {
        for (int i{0}; i < 12; i++)
        {
            //creating type
            c1 = nums[i];
            c2 =  types[t];
            ss << c1 << c2;
            ss >> type;
            ss.clear();

            //creating value
            card_val = (i == 11) ? i: (i > 8)? 10: i + 2;
            x = Card(type, card_val);
            add(x);
        }
    }
}

void shuffleVector(std::vector<int>& nums) {
    // Create a random number generator
    random_device rd;
    mt19937 gen(rd());

    // Shuffle the vector using Fisher-Yates algorithm
    for (int i = nums.size() - 1; i > 0; --i) {
        uniform_int_distribution<int> dis(0, i);
        int j = dis(gen);
        swap(nums[i], nums[j]);
    }
}

void Deck::shuffle() // edit seed
{
    vector<int> indexes;
    for (int x{0}; x < stack.size(); x++)
        indexes.push_back(x);

    shuffleVector(indexes);
    vector<Card> s;
    for (auto i: indexes)
        s.push_back(stack[i]);
    stack = s;

}

void Deck::deal(Hand& hand)
{
    hand.add(stack[loc]);
    loc += 1;
}

void Deck::additionalCards(GenericPlayer& gp)
{
    bool hit;
    do {
        hit = gp.isHitting();
        if (hit == true)
            deal(gp);
        gp.display();
    } while (gp.getTotal() < gp.max && hit);
    if (gp.isBusted())
        gp.bust();
    cout << endl;
}

void Deck::setLoc(int l )
{
    loc = l;
}
