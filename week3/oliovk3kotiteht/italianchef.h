#ifndef ITALIANCHEF_H
#define ITALIANCHEF_H
#include "chef.h"
#include <iostream>
#include <string>
using namespace std;
class ItalianChef : public Chef
{
public:
    ItalianChef(string s);
    ~ItalianChef();
    bool askSecret(string e, int flour, int water);
private:
    string password = "pizza";
    int flour = 32;
    int water = 21;
    int makepizza(int flour, int water);
};

#endif // ITALIANCHEF_H
