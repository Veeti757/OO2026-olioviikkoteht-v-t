#include "asiakas.h"
#include <iostream>
Asiakas::Asiakas(string ni,double raja) : käyttötili(ni), luottotili(ni,raja)
{
    nimi = ni;
    cout << "Asiakkuus luotu " << nimi << ":lle" << endl;
}

string Asiakas::getNimi()
{
    return nimi;
}

void Asiakas::showSaldo()
{
    käyttötili.getBalance();
    cout << "luotto";
    luottotili.getBalance();
}

bool Asiakas::talletus(double amount)
{
    if(käyttötili.deposit(amount))
    {
        return true;
    }
    else
    return false;
}

bool Asiakas::nosto(double amount)
{
    if(käyttötili.withdraw(amount))
    {
        return true;
    }
    else
        return false;
}

bool Asiakas::luotonMaksu(double amount)
{
    if( luottotili.deposit(amount))
    {
        return true;
    }
    else
        return false;
}

bool Asiakas::luotonNosto(double amount)
{
    if(luottotili.withdraw(amount))
    {
        return true;
    }
    else
        return false;
}

bool Asiakas::tilisiirto(double amount, Asiakas & toinen)
{
    if(amount<=0)
    {
        cout << "Et voi antaa negatiivista lukua tai nollaa" << endl;
        return false;
    }
    if(käyttötili.withdraw(amount)==false)
    {
        cout << "Tama maara ylittaa tilisi saldon." << endl;
        return false;
    }
    else
    {
        toinen.talletus(amount);
        cout << nimi << " Siirtaa " << amount << " " << toinen.getNimi() << ":lle" << endl;
        return true;
    }

}
