//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit1.h"
#include "Unit2.h"
#include "Unit3.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm2 *Form2;
extern String nazwaGracza;

//---------------------------------------------------------------------------
__fastcall TForm2::TForm2(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------

void __fastcall TForm2::koniecGryClick(TObject *Sender)
{
        Form2->Close();        
}
//---------------------------------------------------------------------------

void __fastcall TForm2::autorzyClick(TObject *Sender)
{
        Form3->ShowModal();
}
//---------------------------------------------------------------------------

void __fastcall TForm2::nowaGraClick(TObject *Sender)
{
        nazwaGracza=nazwaUzytkownika->Text;
        Form1->zamienNazweUzytkownika();
        Form1->ShowModal();
}
//---------------------------------------------------------------------------

