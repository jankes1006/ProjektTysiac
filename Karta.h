#ifndef _Karta_h
#define _Karta_h
#include <vcl.h>

enum Kolor{pik, kier, trefl, karo};
enum Figura{dziewiec, dziesiec, jupek, dama, krol, as};

class Karta
{
    private:
        Kolor kolor;
        Figura figura;
        int punkty;

    public:
        Karta();
        Karta(Kolor _k, Figura _f, int _p);
        int dajPunkty();
        Figura dajFigure();
        Kolor dajKolor();
};

void tasujKarty(int T[]); //funkcja losujaca kolejnosc kart wg jakiej beda one przypisane uzytkownikom
AnsiString nazwaPliku(Karta *k); //funkcja zwracajaca nazwe do obrazu bmp pod jakim jest zapisana aktualna karta
#endif
