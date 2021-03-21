#include "Karta.h"
#include <iostream>
#include <windows.h>
Karta::Karta(){}

Karta::Karta(Kolor _kolor, Figura _figura, int _punkty): kolor(_kolor), figura(_figura), punkty(_punkty){}

int Karta::dajPunkty(){return punkty;}


Figura Karta::dajFigure(){return figura;}

Kolor Karta::dajKolor(){return kolor;}

void tasujKarty(int T[])
{
    srand(time(NULL));

    for(int i=0; i<24; i++)
    {
        T[i]=rand()%24;

        for(int j=0; j<i; j++)
        {
            if(T[j]==T[i]){i--;}
        }
    }
}

AnsiString nazwaPliku(Karta *k)
{
        Kolor kolorPom=k->dajKolor();
        Figura figuraPom=k->dajFigure();

        switch(figuraPom)
        {
                case dziewiec:
                        switch(kolorPom)
                        {
                                case pik:
                                        return "card/s09.bmp";
                                break;

                                case kier:
                                        return "card/h09.bmp";
                                break;

                                case trefl:
                                        return "card/c09.bmp";
                                break;

                                case karo:
                                        return "card/d09.bmp";
                                break;
                        }
                break;

                case dziesiec:
                        switch(kolorPom)
                        {
                                case pik:
                                        return "card/s10.bmp";
                                break;

                                case kier:
                                        return "card/h10.bmp";
                                break;

                                case trefl:
                                        return "card/c10.bmp";
                                break;

                                case karo:
                                        return "card/d10.bmp";
                                break;
                        }
                break;

                case jupek:
                        switch(kolorPom)
                        {
                                case pik:
                                        return "card/s11.bmp";
                                break;

                                case kier:
                                        return "card/h11.bmp";
                                break;

                                case trefl:
                                        return "card/c11.bmp";
                                break;

                                case karo:
                                        return "card/d11.bmp";
                                break;
                        }
                break;

                case dama:
                        switch(kolorPom)
                        {
                                case pik:
                                        return "card/s12.bmp";
                                break;

                                case kier:
                                        return "card/h12.bmp";
                                break;

                                case trefl:
                                        return "card/c12.bmp";
                                break;

                                case karo:
                                        return "card/d12.bmp";
                                break;
                        }
                break;

                case krol:
                        switch(kolorPom)
                        {
                                case pik:
                                        return "card/s13.bmp";
                                break;

                                case kier:
                                        return "card/h13.bmp";
                                break;

                                case trefl:
                                        return "card/c13.bmp";
                                break;

                                case karo:
                                        return "card/d13.bmp";
                                break;
                        }
                break;

                case as:
                        switch(kolorPom)
                        {
                                case pik:
                                        return "card/s01.bmp";
                                break;

                                case kier:
                                        return "card/h01.bmp";
                                break;

                                case trefl:
                                        return "card/c01.bmp";
                                break;

                                case karo:
                                        return "card/d01.bmp";
                                break;
                        }
                break;

        }
}



