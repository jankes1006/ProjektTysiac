#include "Komputer.h"

Komputer::Komputer(AnsiString nazwa): Gracz(nazwa){poprzedniRuch=NULL;}

bool Komputer::licytuj(int aktualnaKwota)
{
        int ileAsow=0;
        bool czyPosiadaJakisMeldunek=false;

        for(int i=0;i<7;i++)//sprawdzenie ile asow ma komputer, czy posiada jakis meldunek etc...
        {                   //sprawdzamy to kolorami poniewaz zeby miec meldunek musimy miec np dama kier, krol kier
                switch(taliaGracza[i]->dajKolor())
                {
                        case pik:
                                if(taliaGracza[i]->dajFigure()==as){ileAsow++;}
                                if(taliaGracza[i]->dajFigure()==krol)
                                {
                                        if((i+1)<7 && taliaGracza[i+1]->dajKolor()==pik && taliaGracza[i]->dajFigure()==dama)
                                        {
                                                czyPosiadaJakisMeldunek=true;
                                                i++;
                                        }
                                }
                                break;

                        case kier:
                                if(taliaGracza[i]->dajFigure()==as) {ileAsow++;}
                                if(taliaGracza[i]->dajFigure()==krol)
                                {
                                        if((i+1)<7 && taliaGracza[i+1]->dajKolor()==kier && taliaGracza[i]->dajFigure()==dama)
                                        {
                                                czyPosiadaJakisMeldunek=true;
                                                i++;
                                        }
                                }
                                break;

                        case karo:
                                if(taliaGracza[i]->dajFigure()==as) {ileAsow++;}
                                if(taliaGracza[i]->dajFigure()==krol)
                                {
                                        if((i+1)<7 && taliaGracza[i+1]->dajKolor()==karo && taliaGracza[i]->dajFigure()==dama)
                                        {
                                                czyPosiadaJakisMeldunek=true;
                                                i++;
                                        }
                                }
                                break;

                        case trefl:
                                if(taliaGracza[i]->dajFigure()==as) {ileAsow++;}
                                if(taliaGracza[i]->dajFigure()==krol)
                                {
                                        if((i+1)<7 && taliaGracza[i+1]->dajKolor()==trefl && taliaGracza[i]->dajFigure()==dama)
                                        {
                                                czyPosiadaJakisMeldunek=true;
                                                i++;
                                        }
                                }
                                break;

                }
        }

        if(czyPosiadaJakisMeldunek==false && aktualnaKwota>=120)//nie mo¿e komputer ju¿ licytowac poniewaz jezeli nie ma sie meldunku, nie mozna licytowac powyzej 120
        {
                return false;
        }


        switch(ileAsow) //przyjecie taktyki ¿e jezeli ma od 2 do 4 asow to zawsze licytuje (moze tylko do 120, poprzedni warunek blokuje sytuacje niedozwolona), natomiast jezeli ma
        {               //jednego asa to w zaleznosci od tego czy ma jakikolwiek meldunek bedzie licytowal, badz tez nie

                case 4:
                        return true;
                        break;

                case 3:
                        return true;
                        break;

                case 2:
                        return true;
                        break;

                case 1:
                        if(czyPosiadaJakisMeldunek==false) return false;
                        break;
        }

    return false;
}

Karta* Komputer::dajKarteLicytacja()
{
    Karta *pom;

    for(int i=0; i<10; i++)
    {
        pom=taliaGracza[i];

        if(pom!=NULL && pom->dajFigure()==dziewiec)   //Komputer próbuje pozbyc sie 9
        {
            taliaGracza[i]=NULL;
            return pom;
        }
    }

    for(int i=0; i<10; i++)
    {
        pom=taliaGracza[i];

        if(pom!=NULL && pom->dajFigure()==jupek ) //Komputer próbuje pozbyc sie jupka
        {
            taliaGracza[i]=NULL;
            return pom;
        }
    }

    for(int i=0; i<10; i++)
    {
        pom=taliaGracza[i];

        if(pom!=NULL && pom->dajFigure()==dziesiec) //Komputer próbuje pozbyc sie dziesiatki
        {
            taliaGracza[i]=NULL;
            return pom;
        }
    }

    for(int i=0; i<10; i++)
    {
        pom=taliaGracza[i];

        if(pom!=NULL && pom->dajFigure()!=as) //Komputer próbuje pozbyc sie damy lub krola(stracenie dowolnej oznacza zniszczenie meldunku)
        {
            taliaGracza[i]=NULL;
            return pom;
        }
    }
}

Karta* Komputer::dajKarteRozgrywka(int &meldunek, int jakieKarty)
{
    Kolor pomocniczy;
    bool czyWszystkie=false;

    switch(jakieKarty) //Jezeli jakie karty == 0 znaczy, ¿e komputer daje 1 karte, w przeciwnym razie, musi dac karte na stol, ktos inny narzucil kolor
    {
        case 0:
            czyWszystkie=true;
        break;

        case 1:
            pomocniczy=pik;
        break;

        case 2:
            pomocniczy=kier;
        break;

        case 3:
            pomocniczy=trefl;
        break;

        case 4:
            pomocniczy=karo;
        break;
    }

    int nr;
    bool czyDanoKarte=false;//zmienna wykorzystywana aby upewnic sie ze komputer wybral jakas karte

    int nrAsow[4]={-3,-3,-3,-3}; //przypisujemy liczby ktore nie istnieja, zeby mozna bylo latwo reagowac
    int ileAsow=0;               //do tablicy bedziemy zapisywac nr indeksow Asow

    int nrMeldunkow[4]={-3,-3,-3,-3};
    int ileMeldunkow=0;

    int ileKart=0;
    for(int i=0; i<10; i++)
    {
        if(taliaGracza[i]!=NULL) ileKart++;
    }

    if(czyWszystkie==true)//gracze bedzie dawal karte jako pierwszy
    {
        for(int i=0; i<10; i++) //namierzenie asow i meldunkow
        {
                if(taliaGracza[i]!=NULL && taliaGracza[i]->dajFigure()==as)
                {
                        nrAsow[ileAsow]=i;
                        ileAsow++;
                }

                if(taliaGracza[i]!=NULL && taliaGracza[i]->dajFigure()==krol)
                {
                        for(int j=i+1; j<10; j++)
                        {
                                if(taliaGracza[j]!=NULL && taliaGracza[j]->dajKolor()==taliaGracza[i]->dajKolor() && taliaGracza[j]->dajFigure()==dama)
                                {
                                        nrMeldunkow[ileMeldunkow]=i;
                                        ileMeldunkow++;
                                        i=j;
                                        break;
                                }
                        }
                }
        }

        if(ileKart==7)//poczatek gry, nie bylo zadnych poprzednich ruchow(komputer 1 raz w turze rzuca karte)
        {
                if(ileAsow!=0)
                {
                        nr=nrAsow[ileAsow-1]; //minus 1 poniewaz jest przechowywana inforamacja, ile ich jest liczona od 1
                        czyDanoKarte=true;
                }else // cokolwiek nie da bedzie stracone, wiec niech rzuci meldunek
                {
                        if(ileMeldunkow!=0)
                        {
                                nr=nrMeldunkow[ileMeldunkow-1];
                                czyDanoKarte=true;
                        }else //jezeli nie ma, to niech da najmniej co moze
                        {
                                for(int i=0; i<10; i++)//proba dania 9
                                {
                                        if(taliaGracza[i]!=NULL && taliaGracza[i]->dajFigure()==dziewiec)
                                        {
                                                nr=i;
                                                czyDanoKarte=true;
                                                break;
                                        }
                                }

                                if(czyDanoKarte!=true)
                                {
                                        for(int i=0; i<10; i++)//proba dania jupka
                                        {
                                                if(taliaGracza[i]!=NULL && taliaGracza[i]->dajFigure()==jupek)
                                                {
                                                         nr=i;
                                                         czyDanoKarte=true;
                                                         break;
                                                }
                                        }
                                }

                                if(czyDanoKarte!=true)
                                {
                                        for(int i=0; i<10; i++)//proba dania damy
                                        {
                                                if(taliaGracza[i]!=NULL && taliaGracza[i]->dajFigure()==dama)
                                                {
                                                         nr=i;
                                                         czyDanoKarte=true;
                                                         break;
                                                }
                                        }
                                }

                                if(czyDanoKarte!=true)
                                {
                                        for(int i=0; i<10; i++)//proba dania krola
                                        {
                                                if(taliaGracza[i]!=NULL && taliaGracza[i]->dajFigure()==krol)
                                                {
                                                         nr=i;
                                                         czyDanoKarte=true;
                                                         break;
                                                }
                                        }
                                }

                                if(czyDanoKarte!=true)
                                {
                                        for(int i=0; i<10; i++)//proba dania dziesiatki
                                        {
                                                if(taliaGracza[i]!=NULL && taliaGracza[i]->dajFigure()==dziesiec)
                                                {
                                                         nr=i;
                                                         czyDanoKarte=true;
                                                         break;
                                                }
                                        }
                                }

                        }
                }
        }else//Jezeli komputer nie ma 7 kart oznacza ze wygral wczesniejsza karta, ktora jest zapisana
        {

                if(poprzedniRuch!=NULL && poprzedniRuch->dajFigure()==as)
                {
                        for(int i=0; i<10; i++)//szukanie sekwencji ze dal asa w kolorze, no to teraz niech da 10 w tym samym
                        {
                                if(taliaGracza[i]!=NULL && poprzedniRuch->dajKolor()==taliaGracza[i]->dajKolor() && taliaGracza[i]->dajFigure()==dziesiec)
                                {
                                        nr=i;
                                        czyDanoKarte=true;
                                        break;
                                }
                        }
                }else if(poprzedniRuch!=NULL && poprzedniRuch->dajFigure()==dziesiec)
                {
                        for(int i=0; i<10; i++)//szukanie sekwencji ze dal dziesiatke w kolorze, no to teraz niech da krola w tym samym
                        {
                                if(taliaGracza[i]!=NULL && poprzedniRuch->dajKolor()==taliaGracza[i]->dajKolor() && taliaGracza[i]->dajFigure()==krol)
                                {
                                        nr=i;
                                        czyDanoKarte=true;
                                        break;
                                }
                        }
                }else if(poprzedniRuch!=NULL && poprzedniRuch->dajFigure()==krol)
                {
                        for(int i=0; i<10; i++)//szukanie sekwencji ze dal krola w kolorze, no to teraz niech da dame w tym samym
                        {
                                if(taliaGracza[i]!=NULL && poprzedniRuch->dajKolor()==taliaGracza[i]->dajKolor() && taliaGracza[i]->dajFigure()==dama)
                                {
                                        nr=i;
                                        czyDanoKarte=true;
                                        break;
                                }
                        }
                }else if(poprzedniRuch!=NULL && poprzedniRuch->dajFigure()==dama)
                {
                        for(int i=0; i<10; i++)//szukanie sekwencji ze dal dame w kolorze, no to teraz niech da jupka w tym samym
                        {
                                if(taliaGracza[i]!=NULL && poprzedniRuch->dajKolor()==taliaGracza[i]->dajKolor() && taliaGracza[i]->dajFigure()==jupek)
                                {
                                        nr=i;
                                        czyDanoKarte=true;
                                        break;
                                }
                        }
                }else if(poprzedniRuch!=NULL && poprzedniRuch->dajFigure()==jupek)
                {
                        for(int i=0; i<10; i++)//szukanie sekwencji ze dal jupka w kolorze, no to teraz niech da dziewiatke w tym samym
                        {
                                if(taliaGracza[i]!=NULL && poprzedniRuch->dajKolor()==taliaGracza[i]->dajKolor() && taliaGracza[i]->dajFigure()==dziewiec)
                                {
                                        nr=i;
                                        czyDanoKarte=true;
                                        break;
                                }
                        }
                }

                if(czyDanoKarte==false)
                {
                        if(ileAsow!=0)//nie bylo nic z poprzedniej sekwencji, sproboj rzucic asa
                        {
                                nr=nrAsow[ileAsow-1];
                                czyDanoKarte=true;
                        }else//sprawdzenie czy nie masz meldunku
                        {
                                if(ileMeldunkow!=0)
                                {
                                        nr=nrMeldunkow[ileMeldunkow-1];
                                        czyDanoKarte=true;
                                }else //jezeli nie ma to niech da najwiecej co moze
                                {
                                        if(czyDanoKarte!=true)
                                        {
                                                for(int i=0; i<10; i++)//proba dania dziesiatki
                                                {
                                                        if(taliaGracza[i]!=NULL && taliaGracza[i]->dajFigure()==dziesiec)
                                                        {
                                                                nr=i;
                                                                czyDanoKarte=true;
                                                                break;
                                                        }
                                                }
                                        }

                                        if(czyDanoKarte!=true)
                                        {
                                                for(int i=0; i<10; i++)//proba dania krola
                                                {
                                                        if(taliaGracza[i]!=NULL && taliaGracza[i]->dajFigure()==krol)
                                                        {
                                                                nr=i;
                                                                czyDanoKarte=true;
                                                                break;
                                                        }
                                                }
                                        }

                                        if(czyDanoKarte!=true)
                                        {
                                                for(int i=0; i<10; i++)//proba dania damy
                                                {
                                                        if(taliaGracza[i]!=NULL && taliaGracza[i]->dajFigure()==dama)
                                                        {
                                                                nr=i;
                                                                czyDanoKarte=true;
                                                                break;
                                                        }
                                                }
                                        }

                                        if(czyDanoKarte!=true)
                                        {
                                                for(int i=0; i<10; i++)//proba dania jupek
                                                {
                                                        if(taliaGracza[i]!=NULL && taliaGracza[i]->dajFigure()==jupek)
                                                        {
                                                                nr=i;
                                                                czyDanoKarte=true;
                                                                break;
                                                        }
                                                }
                                        }

                                        if(czyDanoKarte!=true)
                                        {
                                                for(int i=0; i<10; i++)//proba dania dziewiatki
                                                {
                                                        if(taliaGracza[i]!=NULL && taliaGracza[i]->dajFigure()==dziewiec)
                                                        {
                                                                nr=i;
                                                                czyDanoKarte=true;
                                                                break;
                                                        }
                                                }
                                        }

                                }
                        }
                }

        }
    }

        if(czyWszystkie==false)//komputer musi dostosowac karte do aktualnie znajdujacej sie na stole
        {
            for(int i=0; i<10; i++)
            {
                if(taliaGracza[i]!=NULL && taliaGracza[i]->dajKolor()==pomocniczy)//komputer posiada kolor karty, ktora wybral ktos inny musi dac, szuka najslabszej jaka tylko moze dac
                {                                                                 //najslabsza karta ma indeks najbardziej na prawo
                    nr=i;
                    for(int j=nr+1;j<10;j++)
                    {
                        if(taliaGracza[j]!=NULL && taliaGracza[j]->dajKolor()==pomocniczy)
                        {
                                nr=j;
                        }
                    }
                    czyDanoKarte=true;
                    break;
                }
            }
        }

    if(czyDanoKarte==false) // Gracz nie dal karty, poniewaz nie posiadal koloru. Szukamy karty o najmniejeszej wartosci, bo i tak idzie na straty. Zasada ta sama co przy dawaniu karty do licytacji
    {
        for(int i=0; i<10; i++)
        {
                if(taliaGracza[i]!=NULL && taliaGracza[i]->dajFigure()==dziewiec)   //Komputer próbuje pozbyc sie 9
                {
                        nr=i;
                        czyDanoKarte=true;
                        goto koniecSprawdzania;
                }
        }

        for(int i=0; i<10; i++)
        {
                if(taliaGracza[i]!=NULL && taliaGracza[i]->dajFigure()==jupek ) //Komputer próbuje pozbyc sie jupka
                {
                        nr=i;
                        czyDanoKarte=true;
                        goto koniecSprawdzania;
                }
        }

        for(int i=0; i<10; i++)
        {
                if(taliaGracza[i]!=NULL && taliaGracza[i]->dajFigure()==dziesiec) //Komputer próbuje pozbyc sie dziesiatki
                {
                        nr=i;
                        czyDanoKarte=true;
                        goto koniecSprawdzania;
                }
        }

        for(int i=0; i<10; i++)
        {
                if(taliaGracza[i]!=NULL && taliaGracza[i]->dajFigure()!=as) //Komputer próbuje pozbyc sie damy lub krola
                {
                        nr=i;
                        czyDanoKarte=true;
                        break;
                }
        }
        koniecSprawdzania:
    }

    //reszta tak samo jak u osoby
    //od tad

    if(czyDanoKarte==false)//zabezpieczenie przed nierozpatrzonym jakims warunkiem
    {
        for(int i=0; i<10; i++)
        {
                if(taliaGracza[i]!=NULL)
                {
                        nr=i;
                        czyDanoKarte=true;
                        break;
                }
        }
    }
    bool czyMeldunek=false;

    if(taliaGracza[nr]->dajFigure()==dama || taliaGracza[nr]->dajFigure()==krol)
    {
        if(taliaGracza[nr]->dajFigure()==dama)
        {
            for(int i=0; i<10; i++)
            {
                if(taliaGracza[i]!=NULL && taliaGracza[i]->dajFigure()==krol && taliaGracza[i]->dajKolor()==taliaGracza[nr]->dajKolor())
                {
                    czyMeldunek=true;
                    break;
                }
            }
        }else if(taliaGracza[nr]->dajFigure()==krol)
        {
            for(int i=0; i<10; i++)
            {
                if(taliaGracza[i]!=NULL && taliaGracza[i]->dajFigure()==dama && taliaGracza[i]->dajKolor()==taliaGracza[nr]->dajKolor())
                {
                    czyMeldunek=true;
                    break;
                }
            }
        }
    }

    if(czyMeldunek==true)
    {
       switch(taliaGracza[nr]->dajKolor())
       {
            case kier:
                meldunek=100;
                break;

            case karo:
                meldunek=80;
                break;

            case trefl:
                meldunek=60;
                break;

            case pik:
                meldunek=40;
                break;
       }
    }else
    {
        meldunek=0;
    }
    
    Karta* pom=taliaGracza[nr];
    taliaGracza[nr]=NULL;
    poprzedniRuch=pom;
    return pom;
}

