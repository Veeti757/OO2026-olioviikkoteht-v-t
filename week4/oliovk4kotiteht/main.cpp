#include <iostream>
#include "pankkitili.h"
#include "luottotili.h"
#include "asiakas.h"
#include <string>
using namespace std;

int main()
{
    int num;
    Asiakas sinun("Albert",1000);
    sinun.showSaldo();
    cout << endl;
    sinun.talletus(250);
    sinun.luotonNosto(150);
    sinun.showSaldo();
    cout << endl;
    Asiakas minun("Bertta",1000);
    minun.showSaldo();
    cout << endl;
    sinun.tilisiirto(50,minun);
    cout << "Bertta: ";
    minun.showSaldo();
    cout << "Albert: ";
    sinun.showSaldo();
    getchar();
    getchar();
    return 0;
}
