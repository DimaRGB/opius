//---------------------------------------------------------------------------
#ifndef Main_Form_UnitH
#define Main_Form_UnitH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.ExtCtrls.hpp>
#include <Vcl.ComCtrls.hpp>
#include <Vcl.Grids.hpp>
#include <Vcl.Dialogs.hpp>
#include <VCLTee.Chart.hpp>
#include <VCLTee.Series.hpp>
#include <VCLTee.TeEngine.hpp>
#include <VCLTee.TeeProcs.hpp>
#include <Vcl.CheckLst.hpp>
#include <Vcl.Buttons.hpp>
#include "cspin.h"
//---------------------------------------------------------------------------
class TMainForm : public TForm {
__published:	// IDE-managed Components
	TOpenDialog *openDialog;
	TListBox *ListBox2;
	TPageControl *Pages;
	TTabSheet *TabSheet1;
	TTabSheet *TabSheet5;
	TMemo *atrMemo;
	TTabSheet *TabSheet2;
	TStringGrid *paramGrid;
	TMemo *paramMemo;
	TTabSheet *TabSheet3;
	TStringGrid *anlgGrid;
	TMemo *anlgMemo;
	TTabSheet *TabSheet4;
	TMemo *snglMemo;
	TStringGrid *snglGrid;
	TCheckListBox *checkListChannel;
	TSplitter *Splitter1;
	TPanel *Panel1;
	TPanel *fcPanel;
	TSpeedButton *fcButton;
	TPanel *cPanel;
	TSpeedButton *cButton;
	TSplitter *Splitter2;
	TSplitter *Splitter3;
	TSplitter *Splitter4;
	TPanel *Panel2;
	TChart *Chart;
	TPanel *Panel3;
	TComboBox *ChannelBox;
	TCSpinEdit *CSpinEdit1;
	TLabel *Label2;
	TCSpinEdit *CSpinEdit2;
	TLabel *Label3;
	TButton *Button1;
	TButton *Button2;
	TButton *Button3;
	TButton *Button4;
	void __fastcall FormCreate(TObject *Sender);
	void __fastcall FormDestroy(TObject *Sender);
	void __fastcall FormResize(TObject *Sender);
	void __fastcall openButtonClick(TObject *Sender);
	void __fastcall checkListChannelClickCheck(TObject *Sender);

private:	// User declarations
public:		// User declarations
	__fastcall TMainForm(TComponent* Owner);

	void __fastcall loadAndPrintAll();
	void __fastcall clearGrid(TStringGrid* grid);
	void __fastcall clearAll();
	void __fastcall defaultFill();
};

//---------------------------------------------------------------------------
extern PACKAGE TMainForm *MainForm;
//---------------------------------------------------------------------------
#endif
