#include "seuraaja.h"
#include "notifikaattori.h"
using namespace std;

int main()
{
    Notifikaattori n;
    Seuraaja A("A");
    Seuraaja B("B");
    Seuraaja C("C");
    n.lisaa(&A);
    n.lisaa(&B);
    n.lisaa(&C);
    n.tulosta();
    n.postita("Tassa viesti 1");
    n.poista(&B);
    n.postita("Tassa viesti 2");
    n.tulosta();
    getchar();
    getchar();
    return 0;
}
