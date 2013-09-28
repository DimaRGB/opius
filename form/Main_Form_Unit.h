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
#include <Vcl.XPMan.hpp>

#include "About_form.h"

#include <ctime>
#include <vector>
#include <string>

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
	TButton *add_random_channel;
	TButton *uncheck_all_channels;
	TGroupBox *channel_scale_n_offset;
	TComboBox *ChannelBox;
	TLabel *Label2;
	TEdit *scale_edit;
	TLabel *Label3;
	TEdit *offset_edit;
	TBitBtn *auto_scale_all_btn;
	TBitBtn *Reset_btn;
	TBitBtn *reset_all_btn;
	TBitBtn *scale_btn;
	TBitBtn *change_color_btn;
	TLabel *output_label;
	TBitBtn *zoom_in_btn;
	TBitBtn *zoom_out_btn;
	TBitBtn *zoom_reset_btn;
	TBitBtn *info_btn;
	void __fastcall FormCreate(TObject *Sender);
	void __fastcall FormDestroy(TObject *Sender);
	void __fastcall FormResize(TObject *Sender);
	void __fastcall openButtonClick(TObject *Sender);
	void __fastcall checkListChannelClickCheck(TObject *Sender);
	void __fastcall scale_editKeyPress(TObject *Sender, System::WideChar &Key);
	void __fastcall offset_editKeyPress(TObject *Sender, System::WideChar &Key);
	void __fastcall uncheck_all_channelsClick(TObject *Sender);
	void __fastcall add_random_channelClick(TObject *Sender);
	void __fastcall checkListChannelClick(TObject *Sender);
	void __fastcall ChannelBoxChange(TObject *Sender);
	void __fastcall auto_scale_all_btnClick(TObject *Sender);
	void __fastcall Splitter1Moved(TObject *Sender);
	void __fastcall scale_btnClick(TObject *Sender);
	void __fastcall Reset_btnClick(TObject *Sender);
	void __fastcall reset_all_btnClick(TObject *Sender);
	void __fastcall change_color_btnClick(TObject *Sender);
	void __fastcall zoom_in_btnClick(TObject *Sender);
	void __fastcall zoom_out_btnClick(TObject *Sender);
	void __fastcall zoom_reset_btnClick(TObject *Sender);
	void __fastcall info_btnClick(TObject *Sender);


private:	// User declarations
public:		// User declarations
	__fastcall TMainForm(TComponent* Owner);

	void __fastcall loadAndPrintAll();
	void __fastcall clearGrid(TStringGrid* grid);
	void __fastcall clearAll();
	void __fastcall defaultFill();
	void redraw_series();
	void draw_series(const int index); // don't use it directly
	void add_series(const int index);  // use it to add series
	void delete_series(const int index);
	void start_init();
	void change_check_list_channel_item(const int index);
	void auto_scale_set_off();
	void auto_scale_set_on();
	void auto_scale_all();

	// нормализует заголовок панели файлов
	void normalize_caption();

	// укорачивает длину пути к файлу
	UnicodeString normalize_path_length(UnicodeString text, const int font_size,
	const int space_width);

};

//---------------------------------------------------------------------------
extern PACKAGE TMainForm *MainForm;
//---------------------------------------------------------------------------
#endif

