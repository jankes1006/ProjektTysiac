#include "Licytacja.h"

Licytacja::Licytacja():musik(0), kwotaLicytacji(100)
{
        for(int i=0; i<3; i++)
        {
                czyPas[i]=false;
                bomby[i]=false;
                kartyLicytacji[i]=NULL;
        }
}

void Licytacja::podbijPasuj(bool wybor, int kto)
{
        if(wybor==true)
        {
                kwotaLicytacji+=10;
                zwyciezca=kto;
        }else
        {
                czyPas[kto]=true;
        }
}

int Licytacja::dajKwoteLicytacji()
{
        return kwotaLicytacji;
}

bool Licytacja::czyGraczUgral(int punktyGracza)
{
        if(punktyGracza<kwotaLicytacji)
        {
                return false;
        }else
        {
                return true;
        }
}

void Licytacja::resetUstawien()
{
        kwotaLicytacji=100;
        for(int i=0; i<3; i++)
        {
                czyPas[i]=false;
                kartyLicytacji[i]=NULL;
        }
        musik++;

        if(musik==3) musik=0;
}

int Licytacja::ktoMusik()
{
        return musik;
}

bool Licytacja::czyTrwaLicytacja()
{
        int ilePasow=0;

        for(int i=0; i<3; i++)
        {
                if(czyPas[i]==true) ilePasow++;
        }

        if(ilePasow==2) return false; else return true;
}

void Licytacja::wezKarte(Karta *k)
{
        for(int i=0; i<3; i++)
        {
                if(kartyLicytacji[i]==NULL)
                {
                        kartyLicytacji[i]=k;
                        break;
                }
        }
}

Karta* Licytacja::dajKarteWyswietlenie(int ktora)
{
        if(ktora<=0) return NULL;
        int ktoraPom=0;

        for(int i=0; i<3; i++)
        {
                if(kartyLicytacji[i]!=NULL)
                {
                        ktoraPom++;
                        if(ktora==ktoraPom) return kartyLicytacji[i];
                }
        }

        return NULL;
}

bool Licytacja::czyGraczPosowal(int ktory)
{
        if(czyPas[ktory]==false)return false; else return true;
}

int Licytacja::dajZwyciezce()
{
        for(int i=0; i<3; i++)
        {
                if(czyPas[i]==false) return i;
        }
}

void Licytacja::ustawZwyciezce()
{
        zwyciezca=0; //zwyciezyl gracz
}
