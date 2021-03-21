//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit1.h"
#include "Unit2.h"
#include "Karta.h"
#include "Gracz.h"
#include "Komputer.h"
#include "Licytacja.h"
#include <stdio.h>
#include <time.h>

#include <cstdlib>

//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
//---------------------------------------------------------------------------
//Zmienne dotyczace graczy---------------------------------------------------
//---------------------------------------------------------------------------
Gracz *Gracze[3]={
new Gracz("Player 1"),
new Komputer("Bot 1"),
new Komputer("Bot 2")
};
#define CZAS_ZAKONCZENIE 1000
#define CZAS_ROZGRYWKA 1000
#define CZAS_POKAZANIA_LICYTACJA 1000
int ileKartMaGracz;
int ileKartMaBot1;
int ileKartMaBot2;

int punktyGracz=0;
int punktyBot1=0;
int punktyBot2=0;

int punktyKoncoweGracz=0;
int punktyKoncoweBot1=0;
int punktyKoncoweBot2=0;

String nazwaGracza;
//---------------------------------------------------------------------------
//Zmienne dotyczace Licytacji------------------------------------------------
//---------------------------------------------------------------------------
Licytacja *licytacja = new Licytacja;
AnsiString kartyLicytacja[3]; //sciezki do grafiki kart licytacji
//---------------------------------------------------------------------------
//Zmienne dotyczace rozegrania------------------------------------------------
//---------------------------------------------------------------------------
int meldunekCzas;
int meldunek=0;
int ktoDajeKarte;
//---------------------------------------------------------------------------
//Zmienne dotyczace tali kart------------------------------------------------
//---------------------------------------------------------------------------
Karta *Talia[24]=
{
    new Karta(pik, dziewiec, 0),
    new Karta(kier, dziewiec, 0),
    new Karta(trefl, dziewiec, 0),
    new Karta(karo, dziewiec, 0),

    new Karta(pik, dziesiec, 10),
    new Karta(kier, dziesiec, 10),
    new Karta(trefl, dziesiec, 10),
    new Karta(karo, dziesiec, 10),

    new Karta(pik, jupek, 2),
    new Karta(kier, jupek, 2),
    new Karta(trefl, jupek, 2),
    new Karta(karo, jupek, 2),

    new Karta(pik, dama, 3),
    new Karta(kier, dama, 3),
    new Karta(trefl, dama, 3),
    new Karta(karo, dama, 3),

    new Karta(pik, krol, 4),
    new Karta(kier, krol, 4),
    new Karta(trefl, krol, 4),
    new Karta(karo, krol, 4),

    new Karta(pik, as, 11),
    new Karta(kier, as, 11),
    new Karta(trefl, as, 11),
    new Karta(karo, as, 11),
};

int Rozdanie[24];
//---------------------------------------------------------------------------
//Funkcja mówiaca kto wygral ture--------------------------------------------
//---------------------------------------------------------------------------
int ktoWygral(int &ile, int meldunek, Karta* karty[3]) //ile zwraca ile punktow gracz wygral w turze
{                                                      //funkcja zwraca nam kto wygral
    Kolor kolorZwyciezki;
    int punktyZwyciezcy=0;
    int idZwyciezcy=0;
    int punktySuma=0;

    if(meldunek==0)//brakuje meldunku decuduje kolor pierwszej karty
    {
        kolorZwyciezki=karty[0]->dajKolor();
        punktySuma=karty[0]->dajPunkty();
        idZwyciezcy=0;
        punktyZwyciezcy=karty[0]->dajPunkty();

        for(int i=1; i<=2; i++)
        {
            punktySuma += karty[i] -> dajPunkty();

            if(kolorZwyciezki==karty[i]->dajKolor())
            {
                if(karty[i]->dajPunkty()>punktyZwyciezcy)
                {
                    punktyZwyciezcy=karty[i]->dajPunkty();
                    idZwyciezcy=i;
                }
            }
        }
    }else
    {
        Kolor kolorMeldunku;

        switch(meldunek)
        {
            case 100:
                kolorMeldunku=kier;
                break;

            case 80:
                kolorMeldunku=karo;
                break;

            case 60:
                kolorMeldunku=trefl;
                break;

            case 40:
                kolorMeldunku=pik;
                break;
        }

        kolorZwyciezki=karty[0]->dajKolor();
        punktySuma=karty[0]->dajPunkty();
        idZwyciezcy=0;
        punktyZwyciezcy=karty[0]->dajPunkty();

        for(int i=1; i<=2; i++)
        {
            punktySuma += karty[i] -> dajPunkty();

            if(kolorZwyciezki==karty[i]->dajKolor()) //ten sam kolor
            {
                if(karty[i]->dajPunkty()>punktyZwyciezcy)
                {
                    punktyZwyciezcy=karty[i]->dajPunkty();
                    idZwyciezcy=i;
                }
            }else if(karty[i]->dajKolor()==kolorMeldunku)
            {
                punktyZwyciezcy=karty[i]->dajPunkty();
                kolorZwyciezki=kolorMeldunku;
                idZwyciezcy=i;
            }
        }

    }
    ile=punktySuma;
    return idZwyciezcy;
}
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
int zaokragliDziesiatki(int zaokraglana)
{
    int reszta=zaokraglana%10;
    if(reszta==0)return zaokraglana;
    if(reszta<5)return zaokraglana-reszta;

    while(zaokraglana%10!=0)
    {
        zaokraglana++;
    }
    return zaokraglana;
}
//--------------------------------------------------------------------------
//--------------------------------------------------------------------------
//--------------------------------------------------------------------------
void TForm1::kartyUzytkownikWyswietl(int ile)
{
        AnsiString kartyGracz[10]; //sciezki do grafiki kart gracza
        for(int i=0; i<ile; i++) //pobranie adresow do kart Gracza
        {
                kartyGracz[i]=nazwaPliku(Gracze[0]->dajKarteWyswietlenie(i+1));
        }
        graczK1->Visible=true;
        graczK2->Visible=true;
        graczK3->Visible=true;
        graczK4->Visible=true;
        graczK5->Visible=true;
        graczK6->Visible=true;
        graczK7->Visible=true;
        graczK8->Visible=true;
        graczK9->Visible=true;
        graczK10->Visible=true;

        switch(ile)
        {
                case 10:
                        graczK1->Picture->LoadFromFile(kartyGracz[0]);
                        graczK2->Picture->LoadFromFile(kartyGracz[1]);
                        graczK3->Picture->LoadFromFile(kartyGracz[2]);
                        graczK4->Picture->LoadFromFile(kartyGracz[3]);
                        graczK5->Picture->LoadFromFile(kartyGracz[4]);
                        graczK6->Picture->LoadFromFile(kartyGracz[5]);
                        graczK7->Picture->LoadFromFile(kartyGracz[6]);
                        graczK8->Picture->LoadFromFile(kartyGracz[7]);
                        graczK9->Picture->LoadFromFile(kartyGracz[8]);
                        graczK10->Picture->LoadFromFile(kartyGracz[9]);
                break;

                case 9:
                        graczK1->Picture->LoadFromFile(kartyGracz[0]);
                        graczK2->Picture->LoadFromFile(kartyGracz[1]);
                        graczK3->Picture->LoadFromFile(kartyGracz[2]);
                        graczK4->Picture->LoadFromFile(kartyGracz[3]);
                        graczK5->Picture->LoadFromFile(kartyGracz[4]);
                        graczK6->Picture->LoadFromFile(kartyGracz[5]);
                        graczK7->Picture->LoadFromFile(kartyGracz[6]);
                        graczK8->Picture->LoadFromFile(kartyGracz[7]);
                        graczK9->Picture->LoadFromFile(kartyGracz[8]);
                break;

                case 8:
                        graczK2->Picture->LoadFromFile(kartyGracz[0]);
                        graczK3->Picture->LoadFromFile(kartyGracz[1]);
                        graczK4->Picture->LoadFromFile(kartyGracz[2]);
                        graczK5->Picture->LoadFromFile(kartyGracz[3]);
                        graczK6->Picture->LoadFromFile(kartyGracz[4]);
                        graczK7->Picture->LoadFromFile(kartyGracz[5]);
                        graczK8->Picture->LoadFromFile(kartyGracz[6]);
                        graczK9->Picture->LoadFromFile(kartyGracz[7]);
                break;

                case 7:
                        graczK2->Picture->LoadFromFile(kartyGracz[0]);
                        graczK3->Picture->LoadFromFile(kartyGracz[1]);
                        graczK4->Picture->LoadFromFile(kartyGracz[2]);
                        graczK5->Picture->LoadFromFile(kartyGracz[3]);
                        graczK6->Picture->LoadFromFile(kartyGracz[4]);
                        graczK7->Picture->LoadFromFile(kartyGracz[5]);
                        graczK8->Picture->LoadFromFile(kartyGracz[6]);
                break;

                case 6:
                        graczK3->Picture->LoadFromFile(kartyGracz[0]);
                        graczK4->Picture->LoadFromFile(kartyGracz[1]);
                        graczK5->Picture->LoadFromFile(kartyGracz[2]);
                        graczK6->Picture->LoadFromFile(kartyGracz[3]);
                        graczK7->Picture->LoadFromFile(kartyGracz[4]);
                        graczK8->Picture->LoadFromFile(kartyGracz[5]);
                break;

                case 5:
                        graczK3->Picture->LoadFromFile(kartyGracz[0]);
                        graczK4->Picture->LoadFromFile(kartyGracz[1]);
                        graczK5->Picture->LoadFromFile(kartyGracz[2]);
                        graczK6->Picture->LoadFromFile(kartyGracz[3]);
                        graczK7->Picture->LoadFromFile(kartyGracz[4]);
                break;

                case 4:
                        graczK4->Picture->LoadFromFile(kartyGracz[0]);
                        graczK5->Picture->LoadFromFile(kartyGracz[1]);
                        graczK6->Picture->LoadFromFile(kartyGracz[2]);
                        graczK7->Picture->LoadFromFile(kartyGracz[3]);
                break;

                case 3:
                        graczK4->Picture->LoadFromFile(kartyGracz[0]);
                        graczK5->Picture->LoadFromFile(kartyGracz[1]);
                        graczK6->Picture->LoadFromFile(kartyGracz[2]);
                break;

                case 2:
                       graczK5->Picture->LoadFromFile(kartyGracz[0]);
                       graczK6->Picture->LoadFromFile(kartyGracz[1]);
                break;

                case 1:
                       graczK5->Picture->LoadFromFile(kartyGracz[0]);
                break;

        }

        switch(ile)
        {
                case 0:
                        graczK5->Visible=false;
                case 1:
                        graczK6->Visible=false;
                case 2:
                        graczK4->Visible=false;
                case 3:
                        graczK7->Visible=false;
                case 4:
                        graczK3->Visible=false;
                case 5:
                        graczK8->Visible=false;
                case 6:
                        graczK2->Visible=false;
                case 7:
                        graczK9->Visible=false;
                case 8:
                        graczK1->Visible=false;
                case 9:
                        graczK10->Visible=false;
        }


}

void TForm1::zamienNazweUzytkownika()
{
        Gracze[0]->zmienNazwe(nazwaGracza);
        Form1->player1Label->Caption=nazwaGracza;
        if(licytacja->czyTrwaLicytacja()==false)
        {
                Form1->zwyciezcaLicytacjiKto->Caption=Gracze[licytacja->dajZwyciezce()]->dajNazwe();
        }
}

void TForm1::kartyBot1Wyswietl(int ile)
{
        switch(ile)
        {
                case 10:
                        bot1K1->Picture->LoadFromFile("card/b2pb.bmp");
                        bot1K1->Visible=true;

                case 9:
                        bot1K2->Picture->LoadFromFile("card/b2pb.bmp");
                        bot1K2->Visible=true;

                case 8:
                        bot1K3->Picture->LoadFromFile("card/b2pb.bmp");
                        bot1K3->Visible=true;

                case 7:
                        bot1K4->Picture->LoadFromFile("card/b2pb.bmp");
                        bot1K4->Visible=true;

                case 6:
                        bot1K5->Picture->LoadFromFile("card/b2pb.bmp");
                        bot1K5->Visible=true;

                case 5:
                        bot1K6->Picture->LoadFromFile("card/b2pb.bmp");
                        bot1K6->Visible=true;

                case 4:
                        bot1K7->Picture->LoadFromFile("card/b2pb.bmp");
                        bot1K7->Visible=true;

                case 3:
                        bot1K8->Picture->LoadFromFile("card/b2pb.bmp");
                        bot1K8->Visible=true;

                case 2:
                        bot1K9->Picture->LoadFromFile("card/b2pb.bmp");
                        bot1K9->Visible=true;

                case 1:
                        bot1K10->Picture->LoadFromFile("card/b2fh.bmp");
                        bot1K10->Visible=true;
        }

        switch(ile)
        {
                case 0:
                        bot1K10->Visible=false;
                case 1:
                        bot1K9->Visible=false;
                case 2:
                        bot1K8->Visible=false;
                case 3:
                        bot1K7->Visible=false;
                case 4:
                        bot1K6->Visible=false;
                case 5:
                        bot1K5->Visible=false;
                case 6:
                        bot1K4->Visible=false;
                case 7:
                        bot1K3->Visible=false;
                case 8:
                        bot1K2->Visible=false;
                case 9:
                        bot1K1->Visible=false;
        }

}

void TForm1::kartyBot2Wyswietl(int ile)
{
        switch(ile)
        {
                case 10:
                        bot2K1->Picture->LoadFromFile("card/b2pt.bmp");
                        bot2K1->Visible=true;

                case 9:
                        bot2K2->Picture->LoadFromFile("card/b2pt.bmp");
                        bot2K2->Visible=true;

                case 8:
                        bot2K3->Picture->LoadFromFile("card/b2pt.bmp");
                        bot2K3->Visible=true;

                case 7:
                        bot2K4->Picture->LoadFromFile("card/b2pt.bmp");
                        bot2K4->Visible=true;

                case 6:
                        bot2K5->Picture->LoadFromFile("card/b2pt.bmp");
                        bot2K5->Visible=true;

                case 5:
                        bot2K6->Picture->LoadFromFile("card/b2pt.bmp");
                        bot2K6->Visible=true;

                case 4:
                        bot2K7->Picture->LoadFromFile("card/b2pt.bmp");
                        bot2K7->Visible=true;

                case 3:
                        bot2K8->Picture->LoadFromFile("card/b2pt.bmp");
                        bot2K8->Visible=true;

                case 2:
                        bot2K9->Picture->LoadFromFile("card/b2pt.bmp");
                        bot2K9->Visible=true;

                case 1:
                        bot2K10->Picture->LoadFromFile("card/b2fh.bmp");
                        bot2K10->Visible=true;
        }

        switch(ile)
        {
                case 0:
                        bot2K10->Visible=false;
                case 1:
                        bot2K9->Visible=false;
                case 2:
                        bot2K8->Visible=false;
                case 3:
                        bot2K7->Visible=false;
                case 4:
                        bot2K6->Visible=false;
                case 5:
                        bot2K5->Visible=false;
                case 6:
                        bot2K4->Visible=false;
                case 7:
                        bot2K3->Visible=false;
                case 8:
                        bot2K2->Visible=false;
                case 9:
                        bot2K1->Visible=false;
        }

}

void TForm1::podmienMeldunek()
{
        switch(meldunek)
        {
            case 100:
                meldunekWartosc->Caption="Kier";
                break;

            case 80:
                meldunekWartosc->Caption="Karo";
                break;

            case 60:
                meldunekWartosc->Caption="Trefl";
                break;

            case 40:
                meldunekWartosc->Caption="Pik";
                break;
        }
}

int coMaDacKomputer(Karta *k)//jaki kolor da komputer
{
        switch(k->dajKolor())
        {
                case pik:
                        return 1;
                break;

                case kier:
                        return 2;
                break;

                case trefl:
                        return 3;
                break;

                case karo:
                        return 4;
                break;
        }
        return true;
}
void TForm1::uztkownikDajKarte(Karta* k)
{
        static int ktoraKartaStol=0;
        static Karta *kartyStol[3]={NULL,NULL,NULL};

        if(ileKartMaGracz>8 && licytacja->dajZwyciezce()==0)
        {
                if(ileKartMaGracz==10)
                {
                        Gracze[1]->wezKarte(k);
                        ileKartMaBot2++;
                        kartyBot2Wyswietl(ileKartMaBot2);

                }else
                {
                        Gracze[2]->wezKarte(k);
                        ileKartMaBot1++;
                        kartyBot1Wyswietl(ileKartMaBot1);
                }
                ileKartMaGracz--;
                kartyUzytkownikWyswietl(ileKartMaGracz);
        }else//rozgrywka
        {
                if(ktoDajeKarte==0 && ktoraKartaStol==0)
                {
                        kartyStol[0]=k;
                        ileKartMaGracz--;
                        stolK1->Picture->LoadFromFile(nazwaPliku(kartyStol[0]));
                        stolK1->Visible=true;
                        kartyUzytkownikWyswietl(ileKartMaGracz);
                        if(meldunekCzas!=0)//podmiana meldunku, pierwszy dawal
                        {
                                meldunek=meldunekCzas;
                                punktyGracz+=meldunek;
                                punktyP1->Caption=punktyGracz;
                                podmienMeldunek();
                        }

                        Application->ProcessMessages(); Sleep(CZAS_ROZGRYWKA);

                        int coDajeKomputer=coMaDacKomputer(kartyStol[0]);

                        for(int i=1; i<=2; i++)
                        {
                          kartyStol[i]=Gracze[i]->dajKarteRozgrywka(meldunekCzas,coDajeKomputer);
                        }

                        ileKartMaBot2--; kartyBot2Wyswietl(ileKartMaBot2);
                        stolK2->Picture->LoadFromFile(nazwaPliku(kartyStol[1]));
                        stolK2->Visible=true;
                        Application->ProcessMessages(); Sleep(CZAS_ROZGRYWKA);

                        ileKartMaBot1--; kartyBot1Wyswietl(ileKartMaBot1);
                        stolK3->Picture->LoadFromFile(nazwaPliku(kartyStol[2]));
                        stolK3->Visible=true;

                        int ilePunktow;
                        int zwyciezca=ktoWygral(ilePunktow,meldunek,kartyStol);

                        if(zwyciezca==0)//wygral gracz on wyklada potem kolejna karte
                        {
                                punktyGracz+=ilePunktow;
                                punktyP1->Caption=punktyGracz;
                                ktoraKartaStol=0;
                                ktoDajeKarte=0;
                        }

                        if(zwyciezca==1)
                        {
                                ktoraKartaStol=0;
                                ktoDajeKarte=1;
                                punktyBot1+=ilePunktow;
                                punktyB1->Caption=punktyBot1;
                                if(ileKartMaBot1!=0)
                                {
                                        k=Gracze[1]->dajKarteRozgrywka(meldunekCzas,0);
                                }else
                                {
                                        ktoDajeKarte=100;
                                }
                        }

                        if(zwyciezca==2)
                        {
                                ktoraKartaStol=0;
                                ktoDajeKarte=2;
                                punktyBot2+=ilePunktow;
                                punktyB2->Caption=punktyBot2;
                                if(ileKartMaBot1!=0)
                                {
                                        k=Gracze[2]->dajKarteRozgrywka(meldunekCzas,0);
                                }else
                                {
                                        ktoDajeKarte=100;
                                }
                        }

                        Application->ProcessMessages(); Sleep(CZAS_ZAKONCZENIE);
                        stolK1->Visible=false;
                        stolK2->Visible=false;
                        stolK3->Visible=false;

                }

                if(ktoDajeKarte==0 && ktoraKartaStol==1)
                {
                        kartyStol[1]=k;
                        ileKartMaGracz--;

                        stolK2->Picture->LoadFromFile(nazwaPliku(kartyStol[1]));
                        stolK2->Visible=true;
                        kartyUzytkownikWyswietl(ileKartMaGracz);
                        Application->ProcessMessages(); Sleep(CZAS_ROZGRYWKA);

                        int coDajeKomputer=coMaDacKomputer(kartyStol[0]);
                        kartyStol[2]=Gracze[1]->dajKarteRozgrywka(meldunekCzas,coDajeKomputer);
                        ileKartMaBot2--;
                        kartyBot2Wyswietl(ileKartMaBot2);

                        stolK3->Picture->LoadFromFile(nazwaPliku(kartyStol[2]));
                        stolK3->Visible=true;

                        int ilePunktow;
                        int zwyciezca=ktoWygral(ilePunktow,meldunek,kartyStol);

                        if(zwyciezca==1)//wygral gracz on wyklada potem kolejna karte
                        {
                                punktyGracz+=ilePunktow;
                                punktyP1->Caption=punktyGracz;
                                ktoraKartaStol=0;
                                ktoDajeKarte=0;
                        }

                        if(zwyciezca==0)
                        {
                                ktoraKartaStol=0;
                                ktoDajeKarte=2;
                                punktyBot2+=ilePunktow;
                                punktyB2->Caption=punktyBot2;
                                if(ileKartMaBot1!=0)
                                {
                                        k=Gracze[2]->dajKarteRozgrywka(meldunekCzas,0);//zapisujemy pod k zeby if ponizszy sie wykonal
                                }else
                                {
                                        ktoDajeKarte=100;
                                }
                        }

                        if(zwyciezca==2)//wygral bot pierwszy, pobierzemy od razu karte i rozpoczniemy na nowo rozgrywke
                        {
                                ktoraKartaStol=0;
                                ktoDajeKarte=1;
                                punktyBot1+=ilePunktow;
                                punktyB1->Caption=punktyBot1;
                                if(ileKartMaBot2!=0)
                                {
                                        k=Gracze[1]->dajKarteRozgrywka(meldunekCzas,0);//zapisujemy pod k zeby if ponizszy sie wykonal
                                }else
                                {
                                        ktoDajeKarte=100;
                                }
                        }

                        Application->ProcessMessages(); Sleep(CZAS_ZAKONCZENIE);
                        stolK1->Visible=false;
                        stolK2->Visible=false;
                        stolK3->Visible=false;
                }

                if(ktoDajeKarte==0 && ktoraKartaStol==2)
                {
                        kartyStol[2]=k;
                        stolK3->Picture->LoadFromFile(nazwaPliku(kartyStol[2]));
                        stolK3->Visible=true;
                        ileKartMaGracz--;
                        kartyUzytkownikWyswietl(ileKartMaGracz);

                        int ilePunktow;
                        int zwyciezca=ktoWygral(ilePunktow,meldunek,kartyStol);

                        if(zwyciezca==2)//wygral gracz on wyklada potem kolejna karte
                        {
                                punktyGracz+=ilePunktow;
                                punktyP1->Caption=punktyGracz;
                                ktoraKartaStol=0;
                                ktoDajeKarte=0;
                        }

                        if(zwyciezca==1)
                        {
                                ktoraKartaStol=0;
                                ktoDajeKarte=2;
                                punktyBot2+=ilePunktow;
                                punktyB2->Caption=punktyBot2;
                                if(ileKartMaBot1!=0)
                                {
                                        k=Gracze[2]->dajKarteRozgrywka(meldunekCzas,0);//zapisujemy pod k zeby if ponizszy sie wykonal
                                }else
                                {
                                        ktoDajeKarte=100;
                                }
                        }

                        if(zwyciezca==0)//wygral bot pierwszy, pobierzemy od razu karte i rozpoczniemy na nowo rozgrywke
                        {
                                ktoraKartaStol=0;
                                ktoDajeKarte=1;
                                punktyBot1+=ilePunktow;
                                punktyB1->Caption=punktyBot1;
                                if(ileKartMaBot2!=0)
                                {
                                        k=Gracze[1]->dajKarteRozgrywka(meldunekCzas,0);//zapisujemy pod k zeby if ponizszy sie wykonal
                                }else
                                {
                                        ktoDajeKarte=100;
                                }
                        }

                        Application->ProcessMessages(); Sleep(CZAS_ZAKONCZENIE);
                        stolK1->Visible=false;
                        stolK2->Visible=false;
                        stolK3->Visible=false;
                }

                if(ktoDajeKarte==1 && ktoraKartaStol==0)//pierwszy bot dal pierwsza karte
                {
                        kartyStol[0]=k;

                        if(meldunekCzas!=0)//podmiana meldunku, pierwszy dawal
                        {
                                meldunek=meldunekCzas;
                                punktyBot1+=meldunek;
                                punktyB1->Caption=punktyBot1;
                                podmienMeldunek();
                        }

                        int coDajeKomputer=coMaDacKomputer(kartyStol[0]);
                        kartyStol[1]=Gracze[2]->dajKarteRozgrywka(meldunekCzas,coDajeKomputer); //musisz zmienic drugi parametr zeby komputer rzucil chociaz dobry kolor
                        ktoraKartaStol=2;
                        ktoDajeKarte=0;

                        ileKartMaBot2--; kartyBot2Wyswietl(ileKartMaBot2);
                        stolK1->Picture->LoadFromFile(nazwaPliku(kartyStol[0]));
                        stolK1->Visible=true;
                        Application->ProcessMessages(); Sleep(CZAS_ROZGRYWKA);

                        ileKartMaBot1--; kartyBot1Wyswietl(ileKartMaBot1);
                        stolK2->Picture->LoadFromFile(nazwaPliku(kartyStol[1]));
                        stolK2->Visible=true;
                }

                if(ktoDajeKarte==2 && ktoraKartaStol==0)
                {
                        kartyStol[0]=k;

                        if(meldunekCzas!=0)//podmiana meldunku, pierwszy dawal
                        {
                                meldunek=meldunekCzas;
                                punktyBot2+=meldunek;
                                punktyB2->Caption=punktyBot2;
                                podmienMeldunek();
                        }

                        ktoraKartaStol=1;

                        ileKartMaBot1--;
                        kartyBot1Wyswietl(ileKartMaBot1);

                        stolK1->Picture->LoadFromFile(nazwaPliku(kartyStol[0])); //zaladowanie obrazu kart
                        stolK1->Visible=true;
                        ktoDajeKarte=0;
                }
        }

        if(ileKartMaGracz==0 && ileKartMaBot1==0 && ileKartMaBot2==0)
        {
                nastepnaTura->Visible=true;
                switch(licytacja->dajZwyciezce())
                {
                        case 0:
                                if(licytacja->czyGraczUgral(punktyGracz)==true)
                                {
                                        punktyKoncoweGracz+=licytacja->dajKwoteLicytacji();
                                }else
                                {
                                        punktyKoncoweGracz-=licytacja->dajKwoteLicytacji();
                                }

                                punktyKoncoweBot1+=zaokragliDziesiatki(punktyBot1);
                                punktyKoncoweBot2+=zaokragliDziesiatki(punktyBot2);
                        break;

                        case 1:
                                if(licytacja->czyGraczUgral(punktyBot1)==true)
                                {
                                        punktyKoncoweBot1+=licytacja->dajKwoteLicytacji();
                                }else
                                {
                                        punktyKoncoweBot1-=licytacja->dajKwoteLicytacji();
                                }
                                punktyKoncoweGracz+=zaokragliDziesiatki(punktyGracz);
                                punktyKoncoweBot2+=zaokragliDziesiatki(punktyBot2);
                        break;

                        case 2:
                                if(licytacja->czyGraczUgral(punktyBot2)==true)
                                {
                                        punktyKoncoweBot2+=licytacja->dajKwoteLicytacji();
                                }else
                                {
                                        punktyKoncoweBot2-=licytacja->dajKwoteLicytacji();
                                }
                                punktyKoncoweGracz+=zaokragliDziesiatki(punktyGracz);
                                punktyKoncoweBot1+=zaokragliDziesiatki(punktyBot1);
                        break;

                }

                punktyB1Calosc->Caption=punktyKoncoweBot1;
                punktyB1->Caption=0;
                punktyBot1=0;

                punktyB2Calosc->Caption=punktyKoncoweBot2;
                punktyB2->Caption=0;
                punktyBot2=0;

                punktyP1Calosc->Caption=punktyKoncoweGracz;
                punktyP1->Caption=0;
                punktyGracz=0;
        }
}

//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------


__fastcall TForm1::TForm1(TComponent* Owner)
        : TForm(Owner)
{

}
//---------------------------------------------------------------------------

void __fastcall TForm1::FormCreate(TObject *Sender)
{
        static int ileTur=0;
        if(ileTur!=0)
                licytacja->resetUstawien();
        ileTur++;
        tasujKarty(Rozdanie);
        ileKartMaGracz=0;
        ileKartMaBot1=0;
        ileKartMaBot2=0;
        pasGracz->Visible=true;
        podbicieGracz->Visible=true;
        LicytacjaGraczLabel->Visible=true;
        nastepnaTura->Visible=false;
        stolK1->Visible=true;
        stolK2->Visible=true;
        stolK3->Visible=true;
        meldunek=0;
        meldunekWartosc->Caption="-";
        zwyciezcaLicytacjiKto->Caption="-";
        KwotaLicytacji->Caption=100;

        for(int i=0; i<7; i++)//przypisanie kart graczowi
        {
                Gracze[0]->wezKarte(Talia[Rozdanie[i]]);
                ileKartMaGracz++;
        }

        for(int i=7; i<14; i++)//przypisanie kart botowi 1
        {
                Gracze[1]->wezKarte(Talia[Rozdanie[i]]);
                ileKartMaBot1++;
        }

        for(int i=14; i<21; i++)//przypisane kart botowi 2
        {
                Gracze[2]->wezKarte(Talia[Rozdanie[i]]);
                ileKartMaBot2++;
        }

        for(int i=21; i<24; i++)//pobranie kart do licytacji
        {
                licytacja->wezKarte(Talia[Rozdanie[i]]);
        }

        for(int i=0; i<3; i++) //pobranie adresow do kart o ktore prowadzona jest licytacja
        {
                kartyLicytacja[i]=nazwaPliku(licytacja->dajKarteWyswietlenie(i+1));
        }

        kartyUzytkownikWyswietl(7);
        kartyBot1Wyswietl(7);
        kartyBot2Wyswietl(7);

        //pokazanie zaslonietych kart na stole
        stolK1->Picture->LoadFromFile("card/back.bmp");
        stolK2->Picture->LoadFromFile("card/back.bmp");
        stolK3->Picture->LoadFromFile("card/back.bmp");

        switch(licytacja->ktoMusik())
        {
                case 0: //zaczyna bot z lewej


                        for(int i=1; i<=2; i++)
                        {
                                if(licytacja->czyGraczPosowal(i)==false && Gracze[i]->licytuj(licytacja->dajKwoteLicytacji())==true)
                                {
                                        licytacja->podbijPasuj(true,i);
                                        KwotaLicytacji->Caption=licytacja->dajKwoteLicytacji();
                                }else
                                {
                                        licytacja->podbijPasuj(false,i);
                                }
                        }


                        if(licytacja->czyTrwaLicytacja()==false)
                        {
                                stolK1->Visible=false; //karty pobiera uzytkownik, znikaja ze stolu
                                stolK2->Visible=false;
                                stolK3->Visible=false;

                                LicytacjaGraczLabel->Visible=false;//usuwamy przyciski
                                pasGracz->Visible=false;
                                podbicieGracz->Visible=false;


                                for(int i=1;i<=3;i++)
                                {
                                        Gracze[0]->wezKarte(licytacja->dajKarteWyswietlenie(i));
                                        ileKartMaGracz++;
                                }

                                kartyUzytkownikWyswietl(10);
                                ktoDajeKarte=0;
                                zwyciezcaLicytacjiKto->Caption=Gracze[0]->dajNazwe();

                        }

                break;

                case 1: // zaczyna bot z prawej
                        if(licytacja->czyGraczPosowal(2)==false && Gracze[2]->licytuj(licytacja->dajKwoteLicytacji())==true)
                        {
                                licytacja->podbijPasuj(true,2);
                                KwotaLicytacji->Caption=licytacja->dajKwoteLicytacji();
                        }else
                        {
                                licytacja->podbijPasuj(false,2);
                        }
                break;

        }


}
//---------------------------------------------------------------------------
void __fastcall TForm1::podbicieGraczClick(TObject *Sender)
{
        if(licytacja->czyTrwaLicytacja()!=false)
        {
        if(licytacja->czyTrwaLicytacja()==true)
        {
                licytacja->podbijPasuj(true,0);

                for(int i=1; i<=2; i++)
                {
                        if(licytacja->czyGraczPosowal(i)==false && Gracze[i]->licytuj(licytacja->dajKwoteLicytacji())==true)
                        {
                                licytacja->podbijPasuj(true,i);
                        }else
                        {
                                licytacja->podbijPasuj(false,i);
                        }
                }

                KwotaLicytacji->Caption=licytacja->dajKwoteLicytacji();
        }

        if(licytacja->czyTrwaLicytacja()==false)//wygrales licytacje
        {
                zwyciezcaLicytacjiKto->Caption=Gracze[0]->dajNazwe();

                if(licytacja->dajKwoteLicytacji()!=100)//musisz na chwile pokazac karty o ktore byla toczona licytacja
                {
                        stolK1->Picture->LoadFromFile(kartyLicytacja[0]);
                        stolK2->Picture->LoadFromFile(kartyLicytacja[1]);
                        stolK3->Picture->LoadFromFile(kartyLicytacja[2]);
                        Application->ProcessMessages(); Sleep(CZAS_POKAZANIA_LICYTACJA);
                }

                stolK1->Visible=false; //karty pobiera uzytkownik, znikaja ze stolu
                stolK2->Visible=false;
                stolK3->Visible=false;

                LicytacjaGraczLabel->Visible=false;//usuwamy przyciski
                pasGracz->Visible=false;
                podbicieGracz->Visible=false;

                for(int i=1;i<=3;i++)
                {
                        Gracze[0]->wezKarte(licytacja->dajKarteWyswietlenie(i));
                        ileKartMaGracz++;
                }
                kartyUzytkownikWyswietl(10);
                ktoDajeKarte=0;
        }
        }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::pasGraczClick(TObject *Sender)
{

        if(licytacja->czyTrwaLicytacja())//mozesz jeszcze spasowac boty graja
        {
                licytacja->podbijPasuj(false,0);

                while(licytacja->czyTrwaLicytacja())
                {
                        for(int i=1;i<2;i++)
                        {
                                if(licytacja->czyGraczPosowal(i)==false && Gracze[i]->licytuj(licytacja->dajKwoteLicytacji())==true && licytacja->czyTrwaLicytacja())
                                {
                                    licytacja->podbijPasuj(true,i);
                                }else
                                {
                                   licytacja->podbijPasuj(false,i);
                                   break;//jeden gracz spasowal wiec kolejny juz nie moze
                                }
                        }
                }

                int zwyciezca=licytacja->dajZwyciezce();
                zwyciezcaLicytacjiKto->Caption=Gracze[zwyciezca]->dajNazwe();
                for(int i=1; i<=3; i++)
                {
                        Gracze[zwyciezca]->wezKarte(licytacja->dajKarteWyswietlenie(i));
                }

                Gracze[0]->wezKarte(Gracze[zwyciezca]->dajKarteLicytacja());
                ileKartMaGracz++;


                if(zwyciezca==1)
                {
                        Gracze[2]->wezKarte(Gracze[zwyciezca]->dajKarteLicytacja());
                }else
                {
                        Gracze[1]->wezKarte(Gracze[zwyciezca]->dajKarteLicytacja());
                }

                if(licytacja->dajKwoteLicytacji()!=100)//musisz na chwile pokazac karty o ktore byla toczona licytacja
                {
                        stolK1->Picture->LoadFromFile(kartyLicytacja[0]);
                        stolK2->Picture->LoadFromFile(kartyLicytacja[1]);
                        stolK3->Picture->LoadFromFile(kartyLicytacja[2]);
                        Application->ProcessMessages(); Sleep(CZAS_POKAZANIA_LICYTACJA);
                }
                kartyUzytkownikWyswietl(ileKartMaGracz);
                stolK1->Visible=false; //karty pobiera uzytkownik, znikaja ze stolu, musza byc wyswietlone
                stolK2->Visible=false;
                stolK3->Visible=false;

                ileKartMaBot1++;
                kartyBot1Wyswietl(ileKartMaBot1);
                ileKartMaBot2++;
                kartyBot2Wyswietl(ileKartMaBot2);

                LicytacjaGraczLabel->Visible=false;//przyciski gracza znikaja
                pasGracz->Visible=false;
                podbicieGracz->Visible=false;

                ktoDajeKarte=zwyciezca;
                uztkownikDajKarte(Gracze[ktoDajeKarte]->dajKarteRozgrywka(meldunekCzas,0));
                
        }

}
//---------------------------------------------------------------------------



void __fastcall TForm1::graczK1Click(TObject *Sender)
{
        uztkownikDajKarte(Gracze[0]->dajKarteRozgrywka(meldunekCzas,1));
}
//---------------------------------------------------------------------------

void __fastcall TForm1::graczK2Click(TObject *Sender)
{
        int ktoraKarta=2;
        if(ileKartMaGracz<9) ktoraKarta--;

        uztkownikDajKarte(Gracze[0]->dajKarteRozgrywka(meldunekCzas,ktoraKarta));
}
//---------------------------------------------------------------------------

void __fastcall TForm1::graczK3Click(TObject *Sender)
{
        int ktoraKarta=3;
        if(ileKartMaGracz<9)ktoraKarta--;
        if(ileKartMaGracz<7)ktoraKarta--;

        uztkownikDajKarte(Gracze[0]->dajKarteRozgrywka(meldunekCzas,ktoraKarta));
}
//---------------------------------------------------------------------------

void __fastcall TForm1::graczK4Click(TObject *Sender)
{
        int ktoraKarta=4;
        if(ileKartMaGracz<9)ktoraKarta--;
        if(ileKartMaGracz<7)ktoraKarta--;
        if(ileKartMaGracz<5)ktoraKarta--;

        uztkownikDajKarte(Gracze[0]->dajKarteRozgrywka(meldunekCzas,ktoraKarta));

}
//---------------------------------------------------------------------------

void __fastcall TForm1::graczK5Click(TObject *Sender)
{
        int ktoraKarta=5;
        if(ileKartMaGracz<9)ktoraKarta--;
        if(ileKartMaGracz<7)ktoraKarta--;
        if(ileKartMaGracz<5)ktoraKarta--;
        if(ileKartMaGracz<3)ktoraKarta--;

        uztkownikDajKarte(Gracze[0]->dajKarteRozgrywka(meldunekCzas,ktoraKarta));
}
//---------------------------------------------------------------------------

void __fastcall TForm1::graczK6Click(TObject *Sender)
{
        int ktoraKarta=6;
        if(ileKartMaGracz<9)ktoraKarta--;
        if(ileKartMaGracz<7)ktoraKarta--;
        if(ileKartMaGracz<5)ktoraKarta--;
        if(ileKartMaGracz<3)ktoraKarta--;

        uztkownikDajKarte(Gracze[0]->dajKarteRozgrywka(meldunekCzas,ktoraKarta));
}
//---------------------------------------------------------------------------

void __fastcall TForm1::graczK7Click(TObject *Sender)
{
        int ktoraKarta=7;
        if(ileKartMaGracz<9)ktoraKarta--;
        if(ileKartMaGracz<7)ktoraKarta--;
        if(ileKartMaGracz<5)ktoraKarta--;

        uztkownikDajKarte(Gracze[0]->dajKarteRozgrywka(meldunekCzas,ktoraKarta));
}
//---------------------------------------------------------------------------

void __fastcall TForm1::graczK8Click(TObject *Sender)
{
        int ktoraKarta=8;
        if(ileKartMaGracz<9)ktoraKarta--;
        if(ileKartMaGracz<7)ktoraKarta--;

        uztkownikDajKarte(Gracze[0]->dajKarteRozgrywka(meldunekCzas,ktoraKarta));
}
//---------------------------------------------------------------------------

void __fastcall TForm1::graczK9Click(TObject *Sender)
{
        int ktoraKarta=9;
        if(ileKartMaGracz<9)ktoraKarta--;

        uztkownikDajKarte(Gracze[0]->dajKarteRozgrywka(meldunekCzas,ktoraKarta));
}
//---------------------------------------------------------------------------

void __fastcall TForm1::graczK10Click(TObject *Sender)
{
        uztkownikDajKarte(Gracze[0]->dajKarteRozgrywka(meldunekCzas,10));
}
//---------------------------------------------------------------------------

