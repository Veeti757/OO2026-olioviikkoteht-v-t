#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;
int game(int maxnum)
{
    int maara = 0;
    srand(time(nullptr)); // käytetään aikaa siemeneä niin tulee aina eri luku
    long luku = rand() % maxnum + 1; // rand antaa aina saman satunnaisluvun ilman srand
    int arvaus;
    cout << "Anna arvaus valilta yksi - maksimi numero" << endl;
    cin >> arvaus;
    cout << luku << endl; // tämä tässä vaan, että näkee luvun koodia varten
    while(luku!=arvaus)
    {
        if(luku>arvaus)
        {
            cout << "Arvaus on liian pieni, anna uusi arvaus" << endl;
            cin >> arvaus;
            maara++;
        }
        if(luku<arvaus)
        {
            cout << "Arvaus on liian iso, anna uusi arvaus" << endl;
            cin >> arvaus;
            maara++;
        }
    }
    if(luku==arvaus)
    {
        cout << "Oikein!!" << endl;
        cout << "arvausten maara = ";
    }
    return maara;
}
int main()
{
    int maxnum;
    cout << "Anna maksimi numero" << endl;
    cin >> maxnum;
    cout << game(maxnum) << endl;
    getchar();
    getchar();
    return 0;
}
