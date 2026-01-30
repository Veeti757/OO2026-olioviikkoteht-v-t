#include "luottotili.h"
#include <iostream>
#include <string>
Luottotili::Luottotili(string nimi,double raja) : Pankkitili(nimi)
{
    luottoRaja = raja;
    saldo = 0;
    cout << "Pankkitili luotu " << nimi << ":lle" << endl;
    cout << "Luottotili luotu " << nimi << ":lle, luottoraja " << luottoRaja << endl;
}

bool Luottotili::deposit(double amount)
{
    if(amount<=0)
    {
        cout << "Luottotili: Et voi antaa nollaa tai negatiivista summaa" << endl;
        return false;

    }
    if(saldo+amount>0)
    {
        cout << "Luottotili: Tama luku menee yli nollan" << endl;
        return false;
    }
    else
    {
        saldo+=amount;
        cout << "Luottotili: Talletit " << amount << ", luottosaldosi on nyt " << saldo << endl;
        return true;
    }
}

bool Luottotili::withdraw(double amount)
{
    if(amount<=0)
    {
        cout << "Luottotili: Et voi nostaa nollaa tai negatiivista summaa" << endl;
        return false;
    }
    if(saldo-amount<-luottoRaja)
    {
        cout << "Luottotili: luottoRajasi ei salli tata maaraa" << endl;

        return false;
    }
    else
    {
        saldo-=amount;
        cout << "Luottotili: Nostit " << amount << " luottosaldosi on " << saldo << endl;
        return true;
    }
}

