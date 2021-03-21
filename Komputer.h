#ifndef _Komputer_h
#define _Komputer_h
#include "Gracz.h"
#include <vcl.h>

class Komputer:public Gracz
{
    private:
        Karta *poprzedniRuch;
        
    public:
        Komputer();
        Komputer(AnsiString nazwa);
        bool licytuj(int aktualnaKwota);
        Karta* dajKarteLicytacja();
        Karta* dajKarteRozgrywka(int &meldunek, int jakieKarty);
};

#endif
 