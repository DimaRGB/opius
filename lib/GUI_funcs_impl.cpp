// GUI functions
// by B-GangsteR 2013.05.15

#include "GUI_funcs.h"

//---------------------------------------------------------------------------
// show msg
// инкапсулирует способ вывода сообщения
void show_msg(const std::string& msg)
{
//	ShowMessage(UnicodeString(msg.c_str()));
	Application->MessageBoxW(UnicodeString(msg.c_str()).w_str(), UnicodeString("Message").w_str(), MB_OK | MB_ICONINFORMATION);

}

//---------------------------------------------------------------------------
// show warning
// инкапсулирует способ вывода предупреждения
void show_warning(const std::string& msg)
{
//	ShowMessage(UnicodeString(msg.c_str()));
	Application->MessageBoxW(UnicodeString(msg.c_str()).w_str(), UnicodeString("Warning").w_str(), MB_OK | MB_ICONWARNING);
}

//----------------------------------------------------------------------------
// output error
void output_error (const std::string& msg)
{
	//ShowMessageUser(UnicodeString(msg.c_str()));
	Application->MessageBoxW(UnicodeString(msg.c_str()).w_str(), UnicodeString("Error").w_str(), MB_OK | MB_ICONERROR);
}

void output_error (UnicodeString& msg)
{
	//ShowMessageUser(UnicodeString(msg.c_str()));
	Application->MessageBoxW(msg.w_str(), UnicodeString("Error").w_str(), MB_OK | MB_ICONERROR);
}

std::string Num_with_nulls::get_str_number() const
{
	char buf[50];
	itoa(value,buf,10);
	int dif = digits_num - strlen(buf); // количество требуемых символов минус количество имеющихся
	// dif<0 == символов слишком много, действие не требутся

	if(dif<=0)
		return buf;

	std::string res;

	while (dif--)
	{res.push_back('0');}

	return res+buf;
}

bool checkFileName(String fileName, int fileType) {
	if( !FileExists(fileName) ) {
		std::string str = fileType ? "Cyclogram" : "File-Copy";
		show_warning( str + " файл не существует, выберите пожалуйста другой файл" );
		return false;
	}
	return true;
}
