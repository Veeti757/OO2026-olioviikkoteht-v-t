#ifndef ASIAKAS_H
#define ASIAKAS_H
#include "pankkitili.h"
#include "luottotili.h"
#include <string>
using namespace std;

class Asiakas
{
public:
    Asiakas(string,double);
    string getNimi();
    void showSaldo();
    bool talletus(double);
    bool nosto(double);
    bool luotonMaksu(double);
    bool luotonNosto(double);
    bool tilisiirto(double, Asiakas &);
private:
    string nimi;
    Pankkitili käyttötili;
    Luottotili luottotili;
};

#endif // ASIAKAS_H
