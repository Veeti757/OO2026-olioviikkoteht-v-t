#include "chef.h"
#include <iostream>
using namespace std;
Chef::Chef(string name)
{
    chefName = name;
    cout << "Chef " << chefName << " constructor!!" << endl;
};

int Chef::makeSalad(int s)
{
    int x = s/5;
    cout << "Chef " << chefName << " with " << s << " can make " << x << " salad portions" << endl;
    return x;
}

int Chef::makeSoup(int i)
{
    int a = i/3;
    cout << "Chef " << chefName << " with " << i << " can make " << a << " soup portions" << endl;
    return a;
}

Chef::~Chef()
{
    cout << "Chef " << chefName << " deconstructor!!" << endl;
    getchar();
}

string Chef::getName()
{
    return chefName;
}

