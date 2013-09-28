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
void show_msg(const UnicodeString& msg)
{
//	ShowMessage(UnicodeString(msg.c_str()));
	Application->MessageBoxW(msg.w_str(), UnicodeString("Message").w_str(), MB_OK | MB_ICONINFORMATION);
}

//---------------------------------------------------------------------------
// show warning
// инкапсулирует способ вывода предупреждения
void show_warning(const std::string& msg)
{
//	ShowMessage(UnicodeString(msg.c_str()));
	Application->MessageBoxW(UnicodeString(msg.c_str()).w_str(), UnicodeString("Warning").w_str(), MB_OK | MB_ICONWARNING);
}
void show_warning(const UnicodeString& msg)
{
//	ShowMessage(UnicodeString(msg.c_str()));
	Application->MessageBoxW(msg.w_str(), UnicodeString("Warning").w_str(), MB_OK | MB_ICONWARNING);
}

//----------------------------------------------------------------------------
// output error
void output_error (const std::string& msg)
{
	//ShowMessageUser(UnicodeString(msg.c_str()));
	Application->MessageBoxW(UnicodeString(msg.c_str()).w_str(), UnicodeString("Error").w_str(), MB_OK | MB_ICONERROR);
}

void output_error(const UnicodeString& msg)
{
	//ShowMessageUser(UnicodeString(msg.c_str()));
	Application->MessageBoxW(msg.w_str(), UnicodeString("Error").w_str(), MB_OK | MB_ICONERROR);
}

bool checkFileName(String fileName, int fileType) {
	if( !FileExists(fileName) ) {
		std::string str = fileType ? "Cyclogram" : "File-Copy";
		show_warning( str + " файл не существует, выберите пожалуйста другой файл" );
		return false;
	}
	return true;
}

//------------------------------
// color info
void Color_generator::procces()
{
	red = GetRValue(color);
	green = GetGValue(color);
	blue = GetBValue(color);
	brightness = red_coef * red + green_coef * green + blue_coef * blue;

	color_str = ColorToString(color);
	color_rgb = ColorToRGB(color);
	color_web_name = ColorToWebColorName(color);
	color_web_str = ColorToWebColorStr(color);
	ColorToHLS(color,hue,luminance, saturation);
}

UnicodeString Color_generator::get_color_info_full()
{
	return
	" Current series color = " + FloatToStr(color)
	+ "\n Color string = " + color_str
	+ "\n Color RGB code = " + IntToStr(color_rgb)
	+ "\n Color Web Name = " + color_web_name
	+ "\n Color Web Str = " + color_web_str
	+ "\n"
	+ "\n Color [Hue;Luminance;Saturation] = ["
	+ IntToStr(hue)+ "; " + IntToStr(luminance) + "; "
	+ IntToStr(saturation) + "]"
	+ "\n"
	+ "\n Color [Red;Green;Blue] = ["
	+ IntToStr(red) + "; " + IntToStr(green) + "; "
	+ IntToStr(blue) + "]"
	+ "\n"
	+ "\n Color Brightness = " + IntToStr(brightness);
}

UnicodeString Color_generator::get_color_info()
{
	return
	"\n Color [Hue;Luminance;Saturation] = ["
	+ IntToStr(hue)+ "; " + IntToStr(luminance) + "; "
	+ IntToStr(saturation) + "]"
	+ "\n"
	+ "\n Color [Red;Green;Blue] = ["
	+ IntToStr(red) + "; " + IntToStr(green) + "; "
	+ IntToStr(blue) + "]"
	+ "\n"
	+ "\n Color Brightness = " + IntToStr(brightness);
}

int Color_generator::generate_rand_color(const int max_bright, int max_iteration)
{
	if (max_bright<0 || max_iteration<1)
	{
		color = RGB(0,0,0);
		procces();
		return 1;
	}

	do
	{
		color = RGB(rand()% max_color_intensity, rand()% max_color_intensity,
							rand()% max_color_intensity);
		procces();
	}
	while (brightness>max_bright && --max_iteration);

	if(max_iteration==0)
	{
		color = RGB(0,0,0);
		procces();
		return 2;
	}

	return 0;
}

// производит коррекцию цвета для лучшего воссприятия
TColor optimal_rand_color()
{
	Color_generator color_gen;
	color_gen.generate_rand_color(Color_generator::optimal_bright);
	return color_gen.get_color();
}
