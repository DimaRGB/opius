//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "About_form.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
Tabout_inf_form *about_inf_form;
//---------------------------------------------------------------------------
__fastcall Tabout_inf_form::Tabout_inf_form(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall Tabout_inf_form::FormCreate(TObject *Sender)
{
	about_label->Caption =
	"\n Flight Data Processing version 1.0"
	"\n"
	"\n Authors:"
	"\n"
	"\n Alexander Sergeyevich Ostapenko,"
	"\n Senior lecturer in the Insitute of \n Computer Information Technology:"
	"\n Console Flight Data Processing \n functions library."
	"\n"
	"\n Belyak Vitaliy Y.,"
	"\n Skavulyak Dmitry O.,"
	"\n Students of the Institute of \n Computer Information Technologies"
	"\n (ICIT-412):"
	"\n Graphical User Interface."
	"\n"
	"\n National Aviation University, 2013";

}
//---------------------------------------------------------------------------


