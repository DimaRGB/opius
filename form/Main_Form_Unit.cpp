#pragma link "cspin"
#include <vcl.h>
#pragma hdrstop

#include <IniFiles.hpp>
#include "../lib/flightDataProcessingForm.h"


using namespace std;

#pragma package(smart_init)
#pragma resource "*.dfm"

const int rand_series_at_start = 3;

TMainForm *MainForm;

struct od_cop    OD;    // onozNavatelNue daNNue
struct atr_pol   APOL;  // atpibytu noleta
struct AP      **p_AP;  // aNalogovui napametp
struct RK      **p_RK;  // pazovaja komaNda

vector<Analog_parameter> anlg_param_vec;

String fc_path;  // store path to file there, not in caption!!
String c_path;
const String curDir = GetCurrentDir() + "\\";
const String iniFile = curDir + "OpiusForm.ini";
bool isCorrect = false; // нельзя удалять память, если она не выделена

bool checkList_changed = false;

// Form
__fastcall TMainForm::TMainForm(TComponent* Owner) : TForm(Owner) {}

void __fastcall TMainForm::FormCreate(TObject *Sender) {
	start_init();
	TIniFile *ini = new TIniFile(iniFile);
	try {
		fc_path = ini->ReadString("FileName", "file-copy", curDir + "data\\C_wzl");
		fcPanel->Caption = fc_path;
		c_path = ini->ReadString("FileName", "cyclogram", curDir + "data\\CB_4z");
		cPanel->Caption = c_path;
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
		ini->WriteString( "FileName", "file-copy", fc_path );
		ini->WriteString( "FileName", "cyclogram", c_path );
	} __finally {
		ini->Free();
		clearAll();
	}
}

void __fastcall TMainForm::FormResize(TObject *Sender) {
	fcPanel->Width = Panel1->Width / 2;

	// checkListChannel constarints
//	int under_chart_space = MainForm->Width - checkListChannel->Width;
	int min_under_chart_space = MainForm->Constraints->MinWidth
						- checkListChannel->Constraints->MinWidth;
	checkListChannel->Constraints->MaxWidth = MainForm->Width - min_under_chart_space;

	normalize_caption();
}

void TMainForm::normalize_caption()
{
	// panels
	// укорочение длины пути к файлу

	int width = fcPanel->Font->Size; // ширина символа

	fcPanel->Caption = fc_path;
	fcPanel->Caption = normalize_path_length(fcPanel->Caption, width,
		(fcPanel->Width - fcButton->Width) );

	cPanel->Caption = c_path;
	cPanel->Caption = normalize_path_length(cPanel->Caption, width,
		(cPanel->Width - cButton->Width) );
}

UnicodeString TMainForm::normalize_path_length(UnicodeString text,
	const int font_size, const int space_width)
{
	const int min_str_front = 8;
	const int min_str_back = 4;
	const int max_str_sz = 20;
	const int min_path_parts = 4; // при котором сохраняется корневая папка

	bool contin = true;
	while ( ((static_cast<double>(text.Length()) * font_size) >= space_width)
				&& contin )
	{
		vector<UnicodeString> path;
		UnicodeString cur_dir;
		int cur_beg = 1;
		int cur_end = 1;
		while(cur_end <= text.Length()) // разбивка пути на папки (части)
		{
			if(text[cur_end] == WideChar('\\') || text[cur_end] == WideChar('/'))
			{
				path.push_back(text.SubString(cur_beg,cur_end-cur_beg));
				cur_beg = cur_end + 1;
			}
        cur_end++;
		}
		if(cur_beg<= text.Length()) // осталась последняя часть
		{ path.push_back(text.SubString(cur_beg,text.Length()-cur_beg + 1));}

		bool improved = false;
		for (unsigned int i=0; i<path.size(); i++)  // сокращение длиных папок
		{
			if(path[i].Length() > max_str_sz)
			{
				path[i] = path[i].SubString(0,min_str_front) + "..."
				+ path[i].SubString(path[i].Length()-min_str_back,min_str_back);
				improved = true;
			}
			if(improved)
			{ break;}
		}
		if(!improved)             // удаление лишних папок
		{
			if(path.size() > min_path_parts)
			{
				if( path[1] != "...")
				{ path[1] = "...";}
				else
				{ path.erase(path.begin()+2);}

				improved = true;
			}
			else if(path.size() > 2)
			{
				if( path[0] != "...")
				{ path[0] = "...";}
				else
				{ path.erase(path.begin()+1);}

				improved = true;
			}
			else if(path.size() > 1)
			{
				path.erase(path.begin());
				improved = true;
			}
			else
			{contin = false;}
        }

		text = "";
		for(unsigned int i=0; i<path.size(); i++)
		{
			text.Insert(path[i],text.Length()+1);
			text.Insert("\\",text.Length()+1);
		}
	} // end of improvement
	return text;
}

// Load and print all data
void __fastcall TMainForm::loadAndPrintAll() {

	normalize_caption();

	if( !checkFileName(fc_path, 0) ||
		!checkFileName(c_path, 1) )
	{
		defaultFill();
		return;
	}

	Pages->TabIndex = 0;
	clearAll();
	if( data_load(fc_path, c_path) == FL_OK ) {
		PrintAtrFK( atrMemo->Lines, true );
		PrintOD( atrMemo->Lines, false ); // nechat onozNavatelNux daNNux
		PrintAtrFlight( atrMemo->Lines, false ); // nechat atpibutov noleta
		PrintParam( paramGrid, paramMemo->Lines ); // nechat koda napametpov (kadp byp)
		PrintFreeZone_v2( anlgMemo->Lines, anlgGrid,
			snglMemo->Lines, snglGrid, checkListChannel->Items,
			ChannelBox->Items); // nechat "fiziki" napametpov (free-zoNa)
		for(int i=0; i<rand_series_at_start; i++)
		{ add_random_channelClick(0);}
		isCorrect = true;
		output_label->Caption = "Data loaded ";
		return;
	}
	else
	{
		defaultFill();
		output_label->Caption = "Data not loaded ";
	}
}

// Open Buttons
void __fastcall TMainForm::openButtonClick(TObject *Sender) {
	TButton* button = static_cast<TButton*>(Sender);

    openDialog->InitialDir = curDir;
	if( openDialog->Execute() )
	{
		if(	checkFileName(openDialog->FileName, button->Tag) )
			if( button->Tag )
			{
				c_path = openDialog->FileName;
				cPanel->Caption = c_path;
            }
			else
			{
				fc_path = openDialog->FileName;
				fcPanel->Caption = fc_path;
            }

		loadAndPrintAll();
	}
	else
	{ output_label->Caption = " Files not selected ";}
}

// Build graphics
void __fastcall TMainForm::checkListChannelClickCheck(TObject *Sender) {
	if( isCorrect )
	{
		int index = checkListChannel->ItemIndex;

		if( checkListChannel->Checked[index] )
		{
			add_series(index);
			output_label->Caption = " Series added ";
		}
		else
		{
			delete_series(index);
			output_label->Caption = " Series deleted ";
		}
	}
	else {
		output_error(UnicodeString(" Data not loaded! Choose correct files "));
		output_label->Caption = "Data not loaded! Choose correct files ";
	}
	checkList_changed = true;
}

void TMainForm::delete_series(const int index)
{
	UnicodeString id = anlg_param_vec[index].id.c_str();
	for( int i = 0; i < Chart->SeriesCount(); i++ )
	{
		if( !CompareStr(Chart->Series[i]->Name, id) )
		{
			Chart->Series[i]->Free();
			break;
		}
	}
}

// use it to add series
void TMainForm::add_series(const int index)
{
    checkListChannel->Checked[index] = true;

	if(auto_scale_all_btn->Tag)
	{
	  auto_scale_all();
	  for(int i=0; i<checkListChannel->Items->Count; i++)
	  {
		  if(checkListChannel->Checked[i])
		  {
		  	delete_series(i);
			draw_series(i);
		  }
      }
	}
	else
	{ draw_series(index);}
}

// don't use it directly
void TMainForm::draw_series(const int index)
{
	TChartSeries *newSeries = new TLineSeries(Chart);
	newSeries->Name = UnicodeString(anlg_param_vec[index].id.c_str());

	for (unsigned int frame=0; frame<anlg_param_vec[index].values.size(); frame++)
	{
		double y = anlg_param_vec[index].values[frame]
			* anlg_param_vec[index].scale
			+ anlg_param_vec[index].offset;
		newSeries->AddXY(frame,y);
	}

	newSeries->Color = anlg_param_vec[index].color;
	Chart->AddSeries(newSeries);
}

void TMainForm::auto_scale_all()
{

}

// производит коррекцию цвета для лучшего воссприятия



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
	ChannelBox->Clear();
	while( Chart->SeriesCount() )
		Chart->Series[0]->Free();

	output_label->Caption = "Data cleared";
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

	output_label->Caption = " Графики аналоговых параметров ";
}

void __fastcall TMainForm::scale_editKeyPress(TObject *Sender, System::WideChar &Key)
{
	if(Key=='.')
	{
		Key = ',';
	}
	else if( !(isdigit(Key) || Key==',' || Key==vkBack || Key=='-'))
	{
		Key=0;
		MessageBeep(-1);
    }
}
//---------------------------------------------------------------------------


void __fastcall TMainForm::offset_editKeyPress(TObject *Sender, System::WideChar &Key)
{
	if(Key=='.')
	{ Key = ','; }
	else if( !(isdigit(Key) || Key==',' || Key==vkBack || Key=='-'))
	{
		Key=0;
		MessageBeep(-1);
	}
}
//---------------------------------------------------------------------------



void __fastcall TMainForm::uncheck_all_channelsClick(TObject *Sender)
{
	checkListChannel->CheckAll(cbUnchecked,false,false);
	while(Chart->SeriesCount())
	{ Chart->Series[0]->Free();}
	output_label->Caption = " All series deleted ";
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::add_random_channelClick(TObject *Sender)
{
	vector<int> unchecked;
	for(int i=0; i<checkListChannel->Items->Count; i++) // get all unchecked
	{
		if(checkListChannel->Checked[i] == false)
		{ unchecked.push_back(i);}
	}

	if(unchecked.size() == 0) // нет неотмеченых
	{
		output_label->Caption = " All series already added ";
		return;
	}
	else
	{
	  int random = rand() % unchecked.size();
	  checkListChannel->Checked[unchecked[random]] = true;
	  add_series(unchecked[random]);
	  change_check_list_channel_item(unchecked[random]);
	  checkListChannel->ItemIndex = unchecked[random];
	  output_label->Caption = " Series added ";
	}
}
//---------------------------------------------------------------------------

void TMainForm::start_init()
{
    srand(static_cast<unsigned int> (time(0)));
}



void __fastcall TMainForm::checkListChannelClick(TObject *Sender)
{
	change_check_list_channel_item(checkListChannel->ItemIndex);
	if(!checkList_changed)
	{ output_label->Caption = "";}
	else
	{checkList_changed = false;}
}
//---------------------------------------------------------------------------


void TMainForm::change_check_list_channel_item(const int index)
{
	ChannelBox->ItemIndex = index;
	scale_edit->Text = FloatToStr(anlg_param_vec[index].scale);
	offset_edit->Text = FloatToStr(anlg_param_vec[index].offset);
}



void __fastcall TMainForm::ChannelBoxChange(TObject *Sender)
{
	change_check_list_channel_item(ChannelBox->ItemIndex);
	output_label->Caption = "";
}
//---------------------------------------------------------------------------




void __fastcall TMainForm::auto_scale_all_btnClick(TObject *Sender)
{
	if(auto_scale_all_btn->Tag)
	{
		auto_scale_all_btn->Kind = bkCancel;
		auto_scale_all_btn->Caption = "Auto Scale OFF";
		auto_scale_all_btn->Tag = 0;
	}
	else
	{
		auto_scale_all_btn->Kind = bkOK;
		auto_scale_all_btn->Caption = "Auto Scale ON";
		auto_scale_all_btn->Tag = 1;
	}

	output_label->Caption = "";
}
//---------------------------------------------------------------------------


void __fastcall TMainForm::Splitter1Moved(TObject *Sender)
{
/*
	int under_chart_space = MainForm->Width - checkListChannel->Width;
	int min_under_chart_space = MainForm->Constraints->MinWidth
						- checkListChannel->Constraints->MinWidth;
	if(under_chart_space < min_under_chart_space)
	{ checkListChannel->Width = MainForm->Width - min_under_chart_space; }
*/
}
//---------------------------------------------------------------------------




void __fastcall TMainForm::scale_btnClick(TObject *Sender)
{
	if(isCorrect)
	{
		int index = ChannelBox->ItemIndex;

		bool all_correct = true;

		try
		{
			double new_scale = StrToFloat(scale_edit->Text);
			anlg_param_vec[index].scale = new_scale;
			output_label->Caption = " Series scaled ";
		}
		catch (EConvertError&)
		{
			scale_edit->Text = FloatToStr(anlg_param_vec[index].scale);
			output_label->Caption = " Incorrect input ";
 			all_correct = false;
		}

		try
		{
			double new_offset = StrToFloat(offset_edit->Text);
			anlg_param_vec[index].offset = new_offset;
			if(all_correct)
			{ output_label->Caption = " Series scaled ";}
		}
		catch(EConvertError&)
		{
			offset_edit->Text = FloatToStr(anlg_param_vec[index].offset);
			output_label->Caption = " Incorrect input ";
			all_correct = false;   // for nothing
		}

		if(checkListChannel->Checked[index])
		{
			delete_series(index);
        }

		add_series(index);
		checkListChannel->Checked[index] = true;
		checkListChannel->ItemIndex = index;

	}
	else
	{ output_label->Caption = " Data not loaded! "; }

}
//---------------------------------------------------------------------------

void __fastcall TMainForm::Reset_btnClick(TObject *Sender)
{
	if(isCorrect)
	{
		int index = ChannelBox->ItemIndex;

		anlg_param_vec[index].scale = 1;
		anlg_param_vec[index].offset = 0;

		scale_edit->Text = "1";
		offset_edit->Text = "0";

		output_label->Caption = " Series reseted ";

		if(checkListChannel->Checked[index])
		{
			delete_series(index);
			add_series(index);
		}
	}
	else
	{ output_label->Caption = " Data not loaded! ";}
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::reset_all_btnClick(TObject *Sender)
{
	if(isCorrect)
	{
		for(int i=0; i<anlg_param_vec.size(); i++)
		{
			anlg_param_vec[i].scale = 1;
			anlg_param_vec[i].offset = 0;

			if(checkListChannel->Checked[i])
			{
			  delete_series(i);
			  add_series(i);
			}
		}

		scale_edit->Text = "1";
		offset_edit->Text = "0";

		output_label->Caption = " All series reseted ";
	}
	else
	{ output_label->Caption = " Data not loaded! ";}
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::change_color_btnClick(TObject *Sender)
{
	if(isCorrect)
	{
		int index = checkListChannel->ItemIndex;

		if(checkListChannel->Checked[index])
		{
			anlg_param_vec[index].color = optimal_rand_color();
			delete_series(index);
			draw_series(index);
			output_label->Caption = "Color changed ";
		}
	}
	else
	{ output_label->Caption = " Data not loaded! ";}
}
//---------------------------------------------------------------------------

