#include "pankkitili.h"
#include <iostream>
#include <string>
using namespace std;
Pankkitili::Pankkitili(string nimi)
{
    omistaja = nimi;
}

double Pankkitili::getBalance()
{
    cout << "saldosi: " << saldo << endl;
    return saldo;
}

bool Pankkitili::deposit(double amount)
{
    if(amount<=0)
    {
        cout << "Pankkitili: Et voi tallettaa nollaa tai negatiivista summaa" << endl;
        return false;
    }
    else
    {
        saldo+=amount;
        cout << "Pankkitili: talletit " << amount << ", saldosi on nyt " << saldo << endl;
        return true;
    }
}

bool Pankkitili::withdraw(double amount)
{
    if(amount<=0)
    {
        cout << "Pankkitili: Et voi nostaa nollaa tai negatiivista summaa" << endl;
        return false;
    }
    if(saldo<amount)
    {
        cout << "Pankkitili: tama " << amount << " summa ylittaa saldosi" << endl;
        getBalance();
        return false;
    }
    else
    {
        saldo-=amount;
        cout << "Pankkitili: Nostit " << amount << ", saldosi on nyt " << saldo << endl;
        return true;
    }

}
