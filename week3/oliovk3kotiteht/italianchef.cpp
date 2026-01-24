#include "italianchef.h"
#include <iostream>
#include <string>
using namespace std;
ItalianChef::ItalianChef(string s) : Chef(s)
{
    cout << "ItalianChef " << chefName << " constructor!!" << endl;
}

ItalianChef::~ItalianChef()
{
    cout << "ItalianChef " << chefName << " deconstructor!!" << endl;
}
bool ItalianChef::askSecret(string e, int flour, int water)
{
    if(password == e)
    {
        cout << "Password ok!!" << endl;
        makepizza(flour,water);
        return true;
    }
    else
    {
        cout << "Wrong, no pizza for you" << endl;
        return false;
    }
}

int ItalianChef::makepizza(int o, int r)
{
    int f = flour;
    int w = water;
    int amount = 0;
    while(f >= 5 && w >= 5)
    {
        f -= 5;
        w -= 5;
        amount++;
    }
    cout << "ItalianChef " << chefName << " with " << flour << " flour and " << water << " water can make " << amount << " pizzas" << endl;
    return amount;
};



