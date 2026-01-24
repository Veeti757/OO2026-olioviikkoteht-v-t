#include <iostream>
#include "chef.h"
#include "italianchef.h"
using namespace std;

int main()
{
    int flour = 20;
    int water = 43;
    string pass;
    Chef chef("Gordon");
    chef.makeSalad(43);
    chef.makeSoup(11);
    ItalianChef Italian("Mario");
    cout << "Give password: " << endl;
    cin >> pass;
    Italian.askSecret(pass,flour,water);
    getchar();
    return 0;
}
