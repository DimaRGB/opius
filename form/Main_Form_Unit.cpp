#pragma link "cspin"
#include <vcl.h>
#pragma hdrstop

#include <IniFiles.hpp>
#include "../lib/flightDataProcessingForm.h"

using namespace std;

#pragma package(smart_init)
#pragma resource "*.dfm"
TMainForm *MainForm;

struct od_cop    OD;    // onozNavatelNue daNNue
struct atr_pol   APOL;  // atpibytu noleta
struct AP      **p_AP;  // aNalogovui napametp
struct RK      **p_RK;  // pazovaja komaNda

const String curDir = GetCurrentDir() + "\\";
const String iniFile = curDir + "OpiusForm.ini";
bool isCorrect = false; // нельзя удалять память, если она не выделена

// Form
__fastcall TMainForm::TMainForm(TComponent* Owner) : TForm(Owner) {}

void __fastcall TMainForm::FormCreate(TObject *Sender) {
	TIniFile *ini = new TIniFile(iniFile);
	try {
		fcPanel->Caption = ini->ReadString("FileName", "file-copy", curDir + "data\\C_wzl");
		cPanel->Caption = ini->ReadString("FileName", "cyclogram", curDir + "data\\CB_4z");
	} __finally {
		ini->Free();
		loadAndPrintAll();
	}
}

void __fastcall TMainForm::FormDestroy(TObject *Sender) {
	if( !isCorrect ) // если выбраные файлы не открылись, не нужно их сохранять в .ini
		return;

	TIniFile *ini = new TIniFile(iniFile);
	try {
		ini->WriteString( "FileName", "file-copy", fcPanel->Caption );
		ini->WriteString( "FileName", "cyclogram", cPanel->Caption );
	} __finally {
		ini->Free();
		clearAll();
	}
}

void __fastcall TMainForm::FormResize(TObject *Sender) {
	fcPanel->Width = Panel1->Width / 2;
}

// Load and print all data
void __fastcall TMainForm::loadAndPrintAll() {
	if( !checkFileName(fcPanel->Caption, 0) ||
		!checkFileName(cPanel->Caption, 1) )
		return;

	clearAll();
	if( data_load(fcPanel->Caption, cPanel->Caption) == FL_OK ) {
		Pages->TabIndex = 0;
		PrintAtrFK( atrMemo->Lines, true );
		PrintOD( atrMemo->Lines, false ); // nechat onozNavatelNux daNNux
		PrintAtrFlight( atrMemo->Lines, false ); // nechat atpibutov noleta
		PrintParam( paramGrid, paramMemo->Lines ); // nechat koda napametpov (kadp byp)
		PrintFreeZone_v2( anlgMemo->Lines, anlgGrid, snglMemo->Lines, snglGrid, checkListChannel->Items ); // nechat "fiziki" napametpov (free-zoNa)
		isCorrect = true;
		return;
	} else
		defaultFill();
}

// Open Buttons
void __fastcall TMainForm::openButtonClick(TObject *Sender) {
	TButton* button = static_cast<TButton*>(Sender);

	if( openDialog->Execute() ) {
		if(	checkFileName(openDialog->FileName, button->Tag) )
			if( button->Tag )
				cPanel->Caption = openDialog->FileName;
			else
				fcPanel->Caption = openDialog->FileName;

		loadAndPrintAll();
	}
}

// Build graphics
void __fastcall TMainForm::checkListChannelClickCheck(TObject *Sender) {
	if( isCorrect )
	{
		int index = checkListChannel->ItemIndex;
		String name = checkListChannel->Items->Strings[index];
		String id = getChannelId(name);

		if( checkListChannel->Checked[index] ) {
			int channel = getChannel(id);

			TChartSeries *newSeries = new TLineSeries(Chart);
			newSeries->Name = id;
			Chart->AddSeries(newSeries);

			for( int iFr = 0; iFr < dl_fk; iFr++ )
				newSeries->AddXY( (float)iFr, (float)p_AP[channel]->fz[iFr] );
		} else {
			for( int i = 0; i < Chart->SeriesCount(); i++ ) {
				if( !CompareStr(Chart->Series[i]->Name, id) ) {
					Chart->Series[i]->Free();
					break;
				}
			}
		}
	}
	else {
		output_error(" Data not loaded! Choose correct files ");
    }
}

void __fastcall TMainForm::clearGrid(TStringGrid* grid) {
	for( int i = 0; i < grid->RowCount; i++ )
		grid->Rows[i]->Clear();
	grid->RowCount = 0;
	grid->ColCount = 0;
}

void __fastcall TMainForm::clearAll() {
	if( isCorrect )
		clean_up();
	isCorrect = false;

	atrMemo->Lines->Clear();
	paramMemo->Lines->Clear();
	clearGrid(paramGrid);
	anlgMemo->Lines->Clear();
	clearGrid(anlgGrid);
	snglMemo->Lines->Clear();
	clearGrid(snglGrid);
	checkListChannel->Clear();
	while( Chart->SeriesCount() )
		Chart->Series[0]->Free();
}

void __fastcall TMainForm::defaultFill() {
	if( isCorrect )
		clearAll();

	atrMemo->Lines->Add("Choose files to open using 'Open..' buttons");
	atrMemo->Lines->Add("and press 'Processing' button to launch Flight Data Processing.");
	atrMemo->Lines->Add("");
	atrMemo->Lines->Add("Выберите файлы для открытия с помощью кнопок 'Open..'");
	atrMemo->Lines->Add("и нажмите кнопку 'Processing' для запуска Обработки Полетной Информации.");
	atrMemo->Lines->Add("");
	atrMemo->Lines->Add("Вкладка 'Flight Data' (Полетная Информация) содержит:");
	atrMemo->Lines->Add("File-copy attributes - Атрибуты файла-копии;");
	atrMemo->Lines->Add("Flight identification data - Опознавательные данные;");
	atrMemo->Lines->Add("Flight attributes - Атрибуты полета;");

	paramMemo->Lines->Add("Коды параметров.");
	paramMemo->Lines->Add("Печать кодов параметров кадра файла копии.");

	anlgMemo->Lines->Add("Аналоговые Параметры.");
	anlgMemo->Lines->Add("Вывод физических значений аналоговых параметров.");

	snglMemo->Lines->Add("Разовые Команды.");
	snglMemo->Lines->Add("Вывод значений разовых команд.");
}

