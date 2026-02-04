#include "seuraaja.h"
#include <string>
#include <iostream>
Seuraaja::Seuraaja(string s)
{
    nimi=s;
    cout << "Luodaan seuraaja " << nimi << endl;

}

string Seuraaja::getNimi()
{
    return nimi;
}

void Seuraaja::paivitys(string viesti)
{
    cout << "Seuraaja " << nimi << " sai viestin " << viesti << endl;
}
