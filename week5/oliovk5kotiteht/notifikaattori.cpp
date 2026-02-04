#include "notifikaattori.h"
#include <iostream>
Notifikaattori::Notifikaattori()
{
    cout << "Luodaan notifikaattori" << endl;
}

void Notifikaattori::lisaa(Seuraaja*s)
{
    s->next = seuraajat;
    seuraajat = s;
    cout << "notifikaattori lisaa seuraajan " << s->getNimi() << endl;
}

void Notifikaattori::poista(Seuraaja*s)
{
    if(seuraajat==nullptr || s==nullptr)
    {
        return;
    }
    if(seuraajat==s)
    {
        seuraajat=seuraajat->next;
        s->next=nullptr;
        cout << "notifikaattori poistaa seuraajan " << s->getNimi() << endl;
        return;
    }
    Seuraaja*ptr1 = seuraajat;
    Seuraaja*ptr2 = seuraajat->next;
    while(ptr2!=nullptr)
    {
        if(ptr2==s)
        {
            ptr1->next=ptr2->next;
            ptr2->next=nullptr;
            cout << "notifikaattori poistaa seuraajan " << ptr2->getNimi() << endl;
            return;
        }
        ptr1=ptr2;
        ptr2=ptr2->next;
    }
}

void Notifikaattori::tulosta()
{
    Seuraaja *ptr = seuraajat;
    cout << "notifikaattorin seuraajat: " << endl;
    while(ptr!=nullptr)
    {
        cout << "Seuraaja " << ptr->getNimi() << endl;
        ptr=ptr->next;
    }
}

void Notifikaattori::postita(string viesti)
{
    Seuraaja*ptr = seuraajat;
    cout << "notifikaattori postaa viestin " << viesti << endl;
    while(ptr!=nullptr)
    {
        ptr->paivitys(viesti);
        ptr=ptr->next;
    }
}
