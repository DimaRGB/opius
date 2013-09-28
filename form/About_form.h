//---------------------------------------------------------------------------

#ifndef About_formH
#define About_formH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.ExtCtrls.hpp>
#include <Vcl.Imaging.pngimage.hpp>
//---------------------------------------------------------------------------
class Tabout_inf_form : public TForm
{
__published:	// IDE-managed Components
	TPanel *text_panel;
	TLabel *Label1;
	TImage *FDR_img;
	TLabel *about_label;
	void __fastcall FormCreate(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall Tabout_inf_form(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE Tabout_inf_form *about_inf_form;
//---------------------------------------------------------------------------
#endif
