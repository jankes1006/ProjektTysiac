#ifndef _Gracz_h
#define _Gracz_h
#include "Karta.h"
#include <vcl.h>
#include <iostream>

class Gracz
{
    protected:
        String nazwaGracza;
        Karta* taliaGracza[10]; 
        int punkty;

    public:
        Gracz();
        Gracz(String _nazwa);
        String dajNazwe(); //funkcja zwracajace nazwe gracza
        void wezKarte(Karta* wsk); //funkcja pobierajaca karty i ukladajace je w kolejnosci malejacej
        Karta* dajKarteWyswietlenie(int ktora); //funkcja zwracajaca wskaznik na karte, nie zmienia zawartosci talii
        virtual bool licytuj(int aktualnaKwota){}; //funkcja wirtualna dla klasy gracz, uzywana tylko przez klase komputer
        virtual Karta* dajKarteLicytacja(){}; //funkcja wirtualna dla klasy gracz, uzywana tylko przez klase komputer
        virtual Karta* dajKarteRozgrywka(int &meldunek, int ktora); //funkcja zwracajaca karte wybrana przez uzytkownika
        void zmienNazwe(String nazwa);
};

#endif
